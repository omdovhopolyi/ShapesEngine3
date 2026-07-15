#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/ShaderProgram.h>

#include <unordered_map>
#include <memory>
#include <string>

namespace shen3
{
    class ShadersManager
        : public Manager
    {
    public:
        void Load();

        ShaderProgram* GetShader(const std::string& id) const;
        void AddShader(const std::string& id, std::unique_ptr<ShaderProgram> shader);

    protected:
        bool LoadShader(const std::string& id, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        bool LoadShadersSource(const std::string& vertexShaderPath, const std::string& fragmentShaderPath,
            std::string& vertexShaderSource, std::string& fragmentShaderSource);

        virtual std::unique_ptr<ShaderProgram> CreateShaderProgram(unsigned int shaderId) = 0;

        virtual unsigned int CreateShaderVertex() = 0;
        virtual unsigned int CreateShaderFragment() = 0;
        virtual unsigned int LoadShaderFromSource(unsigned int shaderId, const std::string& source) = 0;
        virtual unsigned int CompileShader(unsigned int vertexShaderId, unsigned int fragmentShaderId) = 0;
        virtual void ClearShader(unsigned int vertexShaderId, unsigned int fragmentShaderId) = 0;

    private:
        std::unordered_map<std::string, std::unique_ptr<ShaderProgram>> _shaders;
    };
}