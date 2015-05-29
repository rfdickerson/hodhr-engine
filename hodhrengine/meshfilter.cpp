#include "meshfilter.h"

using namespace Hodhr;

MeshFilter::MeshFilter(const GameObject& gameObject)
    : Component(gameObject)
{

}

MeshFilter::~MeshFilter()
{

}

Mesh* MeshFilter::mesh() const
{
    return mMesh;
}

Mesh* MeshFilter::sharedMesh() const
{
    return mSharedMesh;
}

void MeshFilter::setMesh(Mesh * mesh)
{
    mMesh = mesh;
}
