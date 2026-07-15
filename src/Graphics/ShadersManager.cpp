#include <Graphics/ShadersManager.h>
#include <Common/FilePath.h>
#include <Common/Assert.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Logger/Logger.h>

#include <glad/gl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <format>

namespace shen3
{
    void ShadersManager::Load()
    {
        auto elementWrapper = DataElementWrapperFactory::Get(FilePath::Path("assets/configs/shaders.xml"));
        elementWrapper->ForAllChildren("shader", [&](const DataElementWrapper& element) {
            const auto id = element.GetStr("id");
            const auto vertexShaderFilename = element.GetStr("vert");
            const auto fragmentShaderFilename = element.GetStr("frag");
            LoadShader(id, vertexShaderFilename, fragmentShaderFilename);
        });
    }

    ShaderProgram* ShadersManager::GetShader(const std::string& id) const
    {
        auto it = _shaders.find(id);
        if (it != _shaders.end()) {
            return it->second.get();
        }
        return nullptr;
    }

    void ShadersManager::AddShader(const std::string& id, std::unique_ptr<ShaderProgram> shader)
    {
        _shaders[id] = std::move(shader);
        Logger::Log("[ShadersManager::AddShader] Shader loaded: {}", id);
    }

    bool ShadersManager::LoadShadersSource(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, 
                                                            std::string& vertexShaderSource, std::string& fragmentShaderSource)
    {
        std::ifstream vertexShaderFile(FilePath::Path(vertexShaderPath));
        if (!vertexShaderFile.is_open()) {
            Logger::Log(std::format("[ShadersManager::LoadShader] Can not open vertex shader file {}", vertexShaderPath));
            return false;
        }
        std::ifstream fragmentShaderFile(FilePath::Path(fragmentShaderPath));
        if (!vertexShaderFile.is_open()) {
            Logger::Log(std::format("[ShadersManager::LoadShader] Can not open fragment shader file {}", fragmentShaderPath));
            return false;
        }

        std::stringstream sstream;
        sstream << vertexShaderFile.rdbuf();
        vertexShaderSource = sstream.str();
        sstream.str("");
        sstream.clear();
        sstream << fragmentShaderFile.rdbuf();
        fragmentShaderSource = sstream.str();

        return true;
    }

    bool ShadersManager::LoadShader(const std::string& id, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
    {
        std::string vertexShaderSource;
        std::string fragmentShaderSource;

        const bool isShadersLoaded = LoadShadersSource(vertexShaderPath, fragmentShaderPath, vertexShaderSource, fragmentShaderSource);
        if (!isShadersLoaded) {
            return false;
        }
        unsigned int vertexShaderId = LoadShaderFromSource(CreateShaderVertex(), vertexShaderSource);
        if (vertexShaderId == 0) {
            return false;
        }
        unsigned int fragmentShaderId = LoadShaderFromSource(CreateShaderFragment(), fragmentShaderSource);
        if (fragmentShaderId == 0) {
            return false;
        }
        unsigned int shaderId = CompileShader(vertexShaderId, fragmentShaderId);
        if (shaderId == 0) {
            return false;
        }

        ClearShader(vertexShaderId, fragmentShaderId);
        AddShader(id, CreateShaderProgram(shaderId));

        return true;
    }
}
