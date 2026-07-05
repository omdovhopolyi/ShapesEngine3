#pragma once

#include <string>

namespace shen3
{
    class FilePath
    {
    public:
        static std::string Path(const char* path);
        static std::string Path(const std::string& path);
    };
}
