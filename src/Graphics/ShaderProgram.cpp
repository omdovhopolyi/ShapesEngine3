#include <Graphics/ShaderProgram.h>

namespace shen3
{
    ShaderProgram::ShaderProgram(unsigned int id)
        : _programId(id)
    {}

    unsigned int ShaderProgram::GetProgramId() const 
    { 
        return _programId; 
    }

    void ShaderProgram::SetUniform(const std::string& name, float value)
    {

    }

    void ShaderProgram::SetUniform(const std::string& name, const Vec2& value)
    {

    }

    void ShaderProgram::SetUniform(const std::string& name, const Mat4& value)
    {

    }

    void ShaderProgram::Use() const
    {

    }
}
