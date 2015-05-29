#include "object.h"
#include "gameobject.h"

#include "meshrenderer.h"
#include "meshfilter.h"
#include "component.h"
#include "debug.h"
#include "graphics.h"

#include <string>

using namespace Hodhr;

GameObject::GameObject(const std::string& name)
{
    this->name = name;
    mTransform = new Transform();
}

GameObject::~GameObject()
{
    delete mTransform;
}

GameObject* GameObject::createPrimitive(PrimitiveType type)
{
   GameObject *ret = new GameObject("Primitive");
   ret->AddComponent<MeshRenderer>();
   ret->AddComponent<MeshFilter>();

   Mesh* mesh = new Mesh();

   const float shapeSize = 5.5f;

   if (type == GAMEOBJECT_QUAD) {
       mesh->vertices.push_back(glm::vec3(-shapeSize,0,-shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize,0,shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize,0,-shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize,0,shapeSize));

       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));

       mesh->uvs.push_back(glm::vec2(0,0));
       mesh->uvs.push_back(glm::vec2(0,1));
       mesh->uvs.push_back(glm::vec2(1,0));
       mesh->uvs.push_back(glm::vec2(1,1));

       mesh->colors.push_back(Color::Red());
       mesh->colors.push_back(Color::Green());
       mesh->colors.push_back(Color::Blue());
       mesh->colors.push_back(Color::Pink());

       mesh->triangles.push_back(0);
       mesh->triangles.push_back(2);
       mesh->triangles.push_back(1);
       mesh->triangles.push_back(0);
       mesh->triangles.push_back(3);
       mesh->triangles.push_back(1);
   }

   if (type == GAMEOBJECT_CUBE) {
       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize, shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize, -shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize,-shapeSize, shapeSize));

       mesh->vertices.push_back(glm::vec3(-shapeSize,  shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize,  shapeSize,  shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize,  shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize,  shapeSize,  shapeSize));

       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize,-shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize,shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize, shapeSize,-shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize, shapeSize,shapeSize));

       mesh->vertices.push_back(glm::vec3(shapeSize, -shapeSize,-shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize, -shapeSize,shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize, shapeSize,-shapeSize));
       mesh->vertices.push_back(glm::vec3(shapeSize, shapeSize,shapeSize));

       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize, shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize,  shapeSize, shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize, -shapeSize, shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize,  shapeSize, shapeSize));

       mesh->vertices.push_back(glm::vec3(-shapeSize, -shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3(-shapeSize,  shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize, -shapeSize, -shapeSize));
       mesh->vertices.push_back(glm::vec3( shapeSize,  shapeSize, -shapeSize));

       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));
       mesh->normals.push_back(glm::vec3(0,1,0));

       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));

       mesh->normals.push_back(glm::vec3(-1,0,0));
       mesh->normals.push_back(glm::vec3(-1,0,0));
       mesh->normals.push_back(glm::vec3(-1,0,0));
       mesh->normals.push_back(glm::vec3(-1,0,0));

       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));
       mesh->normals.push_back(glm::vec3(1,0,0));

       mesh->uvs.push_back(glm::vec2(0,0));
       mesh->uvs.push_back(glm::vec2(0,1));
       mesh->uvs.push_back(glm::vec2(1,0));
       mesh->uvs.push_back(glm::vec2(1,1));

       mesh->colors.push_back(Color::Red());
       mesh->colors.push_back(Color::Green());
       mesh->colors.push_back(Color::Blue());
       mesh->colors.push_back(Color::Pink());


       mesh->colors.push_back(Color::Red());
       mesh->colors.push_back(Color::Green());
       mesh->colors.push_back(Color::Blue());
       mesh->colors.push_back(Color::Pink());


       mesh->colors.push_back(Color::Red());
       mesh->colors.push_back(Color::Green());
       mesh->colors.push_back(Color::Blue());
       mesh->colors.push_back(Color::Pink());


       mesh->colors.push_back(Color::Red());
       mesh->colors.push_back(Color::Green());
       mesh->colors.push_back(Color::Blue());
       mesh->colors.push_back(Color::Pink());


       mesh->triangles.push_back(0);
       mesh->triangles.push_back(1);
       mesh->triangles.push_back(2);
       mesh->triangles.push_back(1);
       mesh->triangles.push_back(3);
       mesh->triangles.push_back(2);

       mesh->triangles.push_back(4);
       mesh->triangles.push_back(5);
       mesh->triangles.push_back(6);
       mesh->triangles.push_back(5);
       mesh->triangles.push_back(7);
       mesh->triangles.push_back(6);

       mesh->triangles.push_back(8);
       mesh->triangles.push_back(9);
       mesh->triangles.push_back(10);
       mesh->triangles.push_back(9);
       mesh->triangles.push_back(11);
       mesh->triangles.push_back(10);

       mesh->triangles.push_back(12);
       mesh->triangles.push_back(13);
       mesh->triangles.push_back(14);
       mesh->triangles.push_back(13);
       mesh->triangles.push_back(15);
       mesh->triangles.push_back(14);
   }


   Graphics::uploadMesh(mesh);

   //MeshFilter* mf = dynamic_cast<MeshFilter*>(ret->getComponent("MeshFilter"));
   MeshFilter *mf = ret->GetComponent<MeshFilter>();
   if (mf) {
    mf->setMesh(mesh);
   }

   MeshRenderer *renderer = ret->GetComponent<MeshRenderer>();
   if (renderer)
   {
       Material *newMaterial = new Material();
       Shader *phongShader = Shader::Find("phong");
       newMaterial->setShader(phongShader);

       renderer->material = newMaterial;
   }

   return ret;
}

std::vector<GameObject*> GameObject::findGameObjectsWithTag(const std::string& tag)
{
    std::vector<GameObject*> r;
    return r;
}


Transform * GameObject::transform() const {
    return mTransform;
}
