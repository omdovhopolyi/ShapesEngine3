#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/ShaderProgram.h>

#include <unordered_map>
#include <memory>

namespace shen3
{
    class ShadersManager
        : public Manager
    {
        MANAGERS_FACTORY(ShadersManager)

    public:
        void Load();

        ShaderProgram* GetShader(const std::string& id) const;
        void AddShader(const std::string& id, std::unique_ptr<ShaderProgram> shader);

    private:
        bool LoadShader(const std::string& id, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        bool LoadShadersSource(const std::string& vertexShaderPath, const std::string& fragmentShaderPath,
            std::string& vertexShaderSource, std::string& fragmentShaderSource);
        unsigned int CreateShaderVertex();
        unsigned int CreateShaderFragment();
        unsigned int LoadShaderFromSource(unsigned int shaderId, const std::string& source);
        unsigned int CompileShader(unsigned int vertexShaderId, unsigned int fragmentShaderId);
        void ClearShader(unsigned int vertexShaderId, unsigned int fragmentShaderId);

    private:
        std::unordered_map<std::string, std::unique_ptr<ShaderProgram>> _shaders;
    };
}