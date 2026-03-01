#pragma once
#include <iostream>
#include "interface/rhi/rhi_enums.h"
#include "interface/rhi/rhi.h"
namespace Arieo::Interface::FileLoader
{
    struct ModelVertex
    {
        Base::Math::Vector3 pos;
        Base::Math::Vector3 color;
        Base::Math::Vector2 tex_coord;
    };

    class IModelBuffer
    {
    public:
        virtual ModelVertex* getVertices() = 0;
        virtual size_t getVertexCount() = 0;
        virtual uint16_t* getIndices() = 0;
        virtual size_t getIndexCount() = 0;
    };

    class IModelLoader
    {
    public:
        virtual Base::Interop::SharedRef<IModelBuffer> loadObj(const Base::Interop::SharedRef<Base::IBuffer>& buffer) = 0;
    };
}




