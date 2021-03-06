#include "resources.hpp"
#include "debug.hpp"

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <utility>
#include <cerrno>

// OpenIL libraries
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

//#include <OpenImageIO/imageio.h>

//OIIO_NAMESPACE_USING

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>



using namespace Hodhr;

Object* Resources::Load(const std::string& path)
{
    return NULL;
}

std::string Resources::LoadFile(const std::string& filename)
  {
    //std::ifstream in(filename, std::ios::in | std::ios::binary);
    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary );

    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }

    throw(errno);
}

Shader* Resources::LoadShader(const std::string& path)
{
    std::string shaderSrc;

    shaderSrc = LoadFile(path);

    Shader *shader;

    shader = new Shader(shaderSrc);

    return shader;

}



Texture2D * Resources::LoadTexture(const std::string & path)
{

  ilInit();
  ilutRenderer(ILUT_OPENGL);

  ilEnable(ILUT_OPENGL_CONV);

  ILuint devilError;
  ILuint imageName;
  ilGenImages(1, &imageName);

  // Bind this image name.
  ilBindImage(imageName);

  // Loads the image specified by the filename
  if (!ilLoadImage(path.c_str())) {

    devilError = ilGetError();
    // printf("Error loading the texture image %s\n", iluGetErrorString(devilError));
  }


  
  int xres = ilGetInteger( IL_IMAGE_WIDTH );
  int yres = ilGetInteger( IL_IMAGE_HEIGHT );
  int depth = ilGetInteger ( IL_IMAGE_DEPTH );

  std::vector<unsigned char> pixels (4*xres*yres*depth);
  
  int numMipLevels = ilGetInteger( IL_NUM_MIPMAPS );

  printf("Loading image %s as %d by %d with %d mipmaps\n", path.c_str(), xres, yres, numMipLevels);

  Texture2D * newTexture = new Texture2D(xres, yres);
  newTexture->setDepth ( depth );
  newTexture->setMipmapCount (numMipLevels );
  newTexture->loadRawTextureData( pixels );
  newTexture->m_devilID = imageName;


  newTexture->apply();
 

  return newTexture;
  
	/**
    ImageInput *in = ImageInput::open( path );
     //ImageInput *in = ImageInput::open( path );
     if (! in )
         return NULL;
     ImageSpec spec = in->spec();
     int xres = spec.width;
     int yres = spec.height;
     int channels = spec.nchannels;
     std::vector<unsigned char> pixels (4*xres*yres*channels);

     int num_miplevels = 0;
     long count = 0;

     while (in->seek_subimage(0, num_miplevels, spec)) {


         int sheight = spec.height;
         int swidth = spec.width;
         //xres = spec.width;
         //yres = spec.height;
         int size = spec.height * spec.width * channels;

         std::vector<unsigned char> subimagepixels (sheight*swidth*channels);

         in->read_image( TypeDesc::UINT8, &subimagepixels[0]);

         pixels.insert(pixels.begin()+count, subimagepixels.begin(), subimagepixels.end());

         ++num_miplevels;
         count += size;
     }

     in->close ();

     Texture2D * newTexture = new Texture2D(xres, yres);

     char out[80];
     sprintf(out, "Created new texture of size %dx%d with %d channels, %d miplevels.", xres, yres, channels, num_miplevels);
     Debug::log(out, NULL);

     newTexture->setDepth(channels);
     newTexture->setMipmapCount(num_miplevels);
     newTexture->loadRawTextureData(pixels);
     newTexture->apply();


    return newTexture;
**/

	return NULL;
}


// load obj object stuff



Mesh* Resources::LoadMesh(const std::string& path)
{
    Assimp::Importer importer;
    char out[80];

    const aiScene* scene = importer.ReadFile( path,
                                              aiProcess_GenSmoothNormals        |
                                              aiProcess_CalcTangentSpace        |
                                              aiProcess_Triangulate             |
                                              aiProcess_JoinIdenticalVertices   |
                                              aiProcess_SortByPType);

    if (!scene)
    {

        sprintf(out, "Could not load the mesh file %s", path.c_str());
        Debug::log(out, NULL);
        return NULL;
    }

    sprintf(out, "Number of meshes is %d", scene->mNumMeshes);
    Debug::log(out, NULL);

    Mesh * newmesh = new Mesh();

    int i;
    for (i=0; i<scene->mNumMeshes;i++)
    {

        aiMesh * mesh = scene->mMeshes[i];

        sprintf(out, "Number of texture coord channels is %d", mesh->mNumUVComponents[0]);
        Debug::log(out, NULL);

        int j;

        // load vertices
        for (j=0;j<mesh->mNumVertices;j++)
        {
            aiVector3D v = mesh->mVertices[j];
            aiVector3D n = mesh->mNormals[j];
            aiVector3D bt = mesh->mBitangents[j];
            aiVector3D t = mesh->mTangents[j];
            aiVector3D * texCoords = mesh->mTextureCoords[0];
            aiVector3D tempTex = texCoords[j];

            newmesh->vertices.push_back(glm::vec3(v.x, v.y, v.z));
            newmesh->normals.push_back(glm::vec3(n.x, n.y, n.z));
            newmesh->tangents.push_back(glm::vec3(t.x, t.y, t.z));
            newmesh->bittangents.push_back(glm::vec3(bt.x, bt.y, bt.z));
            newmesh->colors.push_back(Color::Blue());

            if (texCoords) {
                newmesh->uvs.push_back(glm::vec2(tempTex.x, tempTex.y));
            }
        }

        // load indices
        for (j=0;j<mesh->mNumFaces;j++)
        {
            aiFace f = mesh->mFaces[j];

            int k;
            for (k=0;k<f.mNumIndices;k++)
            {
                unsigned short indice = f.mIndices[k];
                newmesh->triangles.push_back(indice);
            }
        }


    }


    return newmesh;
}
