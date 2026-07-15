#pragma once

namespace shen3
{
    class ShaderProgram
    {
    public:
        ShaderProgram(unsigned int id);

        unsigned int GetProgramId() const { return _programId; }

    private:
        unsigned int _programId = 0;

    };
}
