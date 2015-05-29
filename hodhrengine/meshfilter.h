#ifndef MESHFILTER_H
#define MESHFILTER_H

#include "component.h"
#include "mesh.h"

namespace Hodhr {

class MeshFilter : public Component
{
public:
    MeshFilter(const GameObject& gameObject);
    ~MeshFilter();

    Mesh* mesh() const;
    Mesh* sharedMesh() const;

    void setMesh(Mesh * mesh);

private:

    Mesh *mMesh;
    Mesh *mSharedMesh;
};

}

#endif // MESHFILTER_H
