#pragma once

#include <Managers/BaseManagers/Manager.h>

#include <memory>

namespace shen3
{
    class ShaderProgram;

    class GlobalFactory
        : public Manager
    {
    public:
        virtual std::unique_ptr<ShaderProgram> CreateShaderProgram(unsigned int id) = 0;
    };
}