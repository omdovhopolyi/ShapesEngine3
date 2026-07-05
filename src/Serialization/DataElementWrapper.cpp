#include <Serialization/DataElementWrapper.h>
#include <Common/Assert.h>

namespace shen3
{
    DataElementWrapper::DataElementWrapper() = default;

    DataElementWrapper::~DataElementWrapper() = default;

    void DataElementWrapper::LoadFile(const std::string& filename)
    {
        Assert(false, "");
    }

    bool DataElementWrapper::IsValid() const
    {
        Assert(false, "");
        return false;
    }

    void DataElementWrapper::SetupFirstElement()
    {
        Assert(false, "");
    }

    std::shared_ptr<DataElementWrapper> DataElementWrapper::GetChildElement(const std::string& id) const
    {
        Assert(false, "");
        return nullptr;
    }

    bool DataElementWrapper::HasElement(const std::string& id) const
    {
        Assert(false, "");
        return false;
    }

    bool DataElementWrapper::GetBool(const std::string& id, bool defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    int DataElementWrapper::GetInt(const std::string& id, int defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    float DataElementWrapper::GetFloat(const std::string& id, float defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    std::string DataElementWrapper::GetStr(const std::string& id, const std::string& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    Vec2 DataElementWrapper::GetVec2(const std::string& id, const Vec2& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    Vec2i DataElementWrapper::GetIntVec2(const std::string& id, const Vec2i& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    Vec3 DataElementWrapper::GetVec3(const std::string& id, const Vec3& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    Vec3i DataElementWrapper::GetIntVec3(const std::string& id, const Vec3i& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    RectF DataElementWrapper::GetFloatRect(const std::string& id, const RectF& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    RectI DataElementWrapper::GetIntRect(const std::string& id, const RectI& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    Vec4ui8 DataElementWrapper::GetColor(const std::string& id, const Vec4ui8& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    std::vector<RectI> DataElementWrapper::GetVectorIntRect(const std::string& id, const std::string& itemId) const
    {
        Assert(false, "");
        return {};
    }

    std::vector<std::string> DataElementWrapper::GetVecStr(const std::string& id) const
    {
        Assert(false, "");
        return {};
    }

    Transform DataElementWrapper::GetTransform(const std::string& id, const Transform& defaultVal) const
    {
        Assert(false, "");
        return defaultVal;
    }

    void DataElementWrapper::SetBool(const std::string& id, bool val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetInt(const std::string& id, int val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetFloat(const std::string& id, float val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetStr(const std::string& id, const std::string& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVec2(const std::string& id, const Vec2& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVec2i(const std::string& id, const Vec2i& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVec3(const std::string& id, const Vec3& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVec3i(const std::string& id, const Vec3i& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetFloatRect(const std::string& id, const RectF& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetIntRect(const std::string& id, const RectI& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetColor(const std::string& id, const Vec4& val)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVectorIntRect(const std::string& id, const std::vector<RectI>& vec)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetVecStr(const std::string& id, const std::vector<std::string>& vec)
    {
        Assert(false, "");
    }

    void DataElementWrapper::SetTransform(const std::string& id, const Transform& transform)
    {
        Assert(false, "");
    }

    void DataElementWrapper::ForAllChildren(const std::function<void(const DataElementWrapper& element)>& element) const
    {
        Assert(false, "");
    }

    void DataElementWrapper::ForAllChildren(const std::string& id, const std::function<void(const DataElementWrapper& element)>& element) const
    {
        Assert(false, "");
    }
}
