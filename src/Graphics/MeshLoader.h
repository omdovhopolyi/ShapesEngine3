#pragma once

#include <Common/Singleton.h>

namespace shen3
{
    class MeshLoader
        : public Singleton<MeshLoader>
    {
    public:
        void LoadMesh();

    private:
    };
}
