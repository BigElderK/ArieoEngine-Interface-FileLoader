#pragma once
#include <iostream>
#include "interface/rhi/rhi_enums.h"
namespace Arieo::Interface::FileLoader
{
    class IImageBuffer
    {
    public:
        virtual void* getBuffer() = 0;
        virtual size_t getSize() = 0;
        virtual size_t getWidth() = 0;
        virtual size_t getHeight() = 0;
        virtual size_t getDepth() = 0;
        virtual size_t getMipMapCount() = 0;
        virtual Interface::RHI::Format getFormat() = 0;
    };

    class IImageLoader
    {
    public:
        virtual Base::Interop::SharedRef<IImageBuffer> loadDDS(const Base::Interop::SharedRef<Base::IBuffer>& buffer) = 0;
    };
}




