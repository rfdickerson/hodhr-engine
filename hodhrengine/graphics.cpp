#include "graphics.h"
#include "rendertexture.h"
#include "camera.h"
#include "color.h"
#include "debug.h"


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace Hodhr;

// define statics
RenderBuffer* Graphics::activeColorBuffer;
RenderBuffer* Graphics::activeDepthBuffer;


typedef struct  {
    GLfloat x, y, z;          // position
    GLfloat nx, ny, nz;       // normal direction
    GLfloat tx, ty, tz;       // tangents
    GLfloat bx, by, bz;       // bitangents
    GLushort s, t;            // texture coordinates
    GLushort r, g, b;         // vertex colors
} HodhrVertex;




Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

void Graphics::drawMesh(const Mesh & mesh,
                        const glm::vec3 & position,
                        const glm::quat & rotation,
                        const Material & mat)
{

    if (mat.shader() == NULL)
    {
        return;
    }


    if (mesh.mVAO == 0)
    {
        return;
    }

    glUseProgram(mat.shader()->shaderProgramID);

    Camera *currentCamera = Camera::current();
    currentCamera->resetProjectionMatrix();
    checkErrors("Set up camera.");

    const glm::mat4 vm = currentCamera->viewMatrix();
    const glm::mat4 projMatrix = currentCamera->projectionMatrix();

    const glm::mat4 t = glm::translate(
                glm::mat4(1.0f),
                position);

    const glm::mat4 r = glm::toMat4(rotation);

    const glm::mat4 model = t * r;
    const glm::mat4 mvmatrix = vm * model;

    const glm::mat4 mvpMatrix = projMatrix * vm * model;

    const glm::mat3 normalMatrix = glm::inverseTranspose(glm::mat3(mvmatrix));

    const GLint mvpLocation = glGetUniformLocation(mat.shader()->GetProgramID(),"MVP");
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvpMatrix) );

    const GLint mvLocation = glGetUniformLocation(mat.shader()->GetProgramID(),"ModelViewMatrix");
    glUniformMatrix4fv(mvLocation, 1, GL_FALSE, glm::value_ptr(mvmatrix) );

    const GLint projLocation = glGetUniformLocation(mat.shader()->GetProgramID(),"ProjectionMatrix");
    glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projMatrix) );

    const GLint normalMatrixLoc = glGetUniformLocation(mat.shader()->GetProgramID(),"NormalMatrix");
    glUniformMatrix4fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix) );


    checkErrors("Prepare to bind vertex array object.");
    glBindVertexArray(mesh.mVAO);
    checkErrors("Binded the vertex array object");

    glEnableVertexAttribArray(0);

    glEnableVertexAttribArray(1);
    // glEnableVertexAttribArray(2);
    // glEnableVertexAttribArray(3);
    // glEnableVertexAttribArray(4);


    // glEnableVertexAttribArray(5);

    //glDrawArrays(GL_TRIANGLES, 0, mesh.vertices.size());
    glDrawElements(GL_TRIANGLES, mesh.triangles.size(), GL_UNSIGNED_SHORT, NULL);

    checkErrors("Draw elements.");

    glBindVertexArray(0);

    glUseProgram(0);


}

void Graphics::setRenderTarget(RenderTexture *rt)
{
    activeColorBuffer = &rt->colorBuffer;
    activeDepthBuffer = &rt->depthBuffer;
}

void Graphics::uploadMesh( Mesh* mesh )
{

    checkErrors("Preparing to upload mesh to GPU.");
    GLuint vertexBuffer, indiceBuffer;

    // create and set the vertex buffers for the meshes.
    mesh->recalculateTangents();

    // HodhrVertex hvertices = new HodhrVertex[mesh->vertices.size()];
    std::vector<HodhrVertex> hvertices;

    for (unsigned long i=0;i<mesh->vertices.size();i++)
    {
        HodhrVertex hv;
        hv.x = mesh->vertices[i].x;
        hv.y = mesh->vertices[i].y;
        hv.z = mesh->vertices[i].z;

        hv.nx = mesh->normals[i].x;
        hv.ny = mesh->normals[i].y;
        hv.nz = mesh->normals[i].z;

        hv.tx = mesh->tangents[i].x;
        hv.ty = mesh->tangents[i].y;
        hv.tz = mesh->tangents[i].z;
        hv.bx = mesh->bittangents[i].x;
        hv.by = mesh->bittangents[i].y;
        hv.bz = mesh->bittangents[i].z;
        hv.s = mesh->uvs[i].x;
        hv.t = mesh->uvs[i].y;
        hv.r = mesh->colors[i].red()*USHRT_MAX;
        hv.g = mesh->colors[i].green()*USHRT_MAX;
        hv.b = mesh->colors[i].blue()*USHRT_MAX;


        hvertices.push_back(hv);
    }


    glGenVertexArrays(1, &mesh->mVAO);
    glBindVertexArray(mesh->mVAO);
    checkErrors("Bind vertex array");


    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &indiceBuffer);
    checkErrors("Generate buffers.");

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, hvertices.size()*sizeof(HodhrVertex),
                 &hvertices[0], GL_STATIC_DRAW);

    checkErrors("Bind array buffer and load data.");

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          sizeof(HodhrVertex), BUFFER_OFFSET(0));

    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(HodhrVertex), BUFFER_OFFSET(12));

    // vertex tangents
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(HodhrVertex), BUFFER_OFFSET(24));

    // vertex bittangents
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(HodhrVertex), BUFFER_OFFSET(36));

    // vertex uv texture coordinates
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 2, GL_UNSIGNED_SHORT, GL_TRUE, sizeof(HodhrVertex), BUFFER_OFFSET(48));

    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 3, GL_UNSIGNED_SHORT, GL_TRUE, sizeof(HodhrVertex), BUFFER_OFFSET(52));

     checkErrors("Set vertex attribute pointers.");

    // Load the indices

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
                 indiceBuffer);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 mesh->triangles.size()*sizeof(GLushort),
                 &mesh->triangles[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);


    checkErrors("Create vertex array object.");

    glBindVertexArray(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &indiceBuffer);

    Debug::log("Graphics", "Uploaded mesh to GPU.");

}

void removeMesh( Mesh *mesh )
{
    if (mesh->vao()) {
        // glDeleteVertexArrays(1, &mesh->vao());
    }
}

void Graphics::checkErrors(const std::string & label)
{
    GLenum errCode;
    const GLubyte *errString;
    errCode = glGetError();
    if (errCode  != GL_NO_ERROR)
    {

        //errString = gluErrorString(errCode);
        //std::string e((char*)errString);

        // printf("OpenGL Error at %s: %s", label.c_str(), e.c_str());

        //Debug::log(label, e.c_str());

    }
}
