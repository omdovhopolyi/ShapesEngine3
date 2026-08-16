#include <Common/FilePath.h>
#include <format>

namespace shen3
{
    std::string FilePath::Path(const char* path)
    {
#ifdef NDEBUG
        return path;
#else
        return std::format("../{}", path);
#endif
    }

    std::string FilePath::Path(const std::string& path)
    {
        return Path(path.c_str());
    }
}
