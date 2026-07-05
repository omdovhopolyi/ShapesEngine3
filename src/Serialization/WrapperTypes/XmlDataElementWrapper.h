#pragma once

#include <Serialization/DataElementWrapper.h>
#include <tinyxml2.h>
#include <string>
#include <vector>

namespace shen3
{
    class XmlDataElementWrapper final
        : public DataElementWrapper
    {
    public:
        XmlDataElementWrapper(tinyxml2::XMLElement* element);

        void LoadFile(const std::string& filename) override;
        bool IsValid() const override;

        std::shared_ptr<DataElementWrapper> GetChildElement(const std::string& id) const override;
        bool HasElement(const std::string& id) const override;

        bool GetBool(const std::string& id, bool defaultVal = false) const override;
        int GetInt(const std::string& id, int defaultVal = 0) const override;
        float GetFloat(const std::string& id, float defaultVal = 0.f) const override;
        std::string GetStr(const std::string& id, const std::string& defaultVal = {}) const override;
        Vec2 GetVec2(const std::string& id, const Vec2& defaultVal = {}) const override;
        Vec2i GetIntVec2(const std::string& id, const Vec2i& defaultVal = {}) const override;
        Vec3 GetVec3(const std::string& id, const Vec3& defaultVal = {}) const override;
        Vec3i GetIntVec3(const std::string& id, const Vec3i& defaultVal = {}) const override;
        RectF GetFloatRect(const std::string& id, const RectF& defaultVal = {}) const override;
        RectI GetIntRect(const std::string& id, const RectI& defaultVal = {}) const override;
        Vec4ui8 GetColor(const std::string& id, const Vec4ui8& defaultVal = {}) const override;
        std::vector<RectI> GetVectorIntRect(const std::string& id, const std::string& itemId = "item") const override;
        std::vector<std::string> GetVecStr(const std::string& id) const override;
        Transform GetTransform(const std::string& id, const Transform& defaultVal = {}) const override;

        void SetBool(const std::string& id, bool val) override;
        void SetInt(const std::string& id, int val) override;
        void SetFloat(const std::string& id, float val) override;
        void SetStr(const std::string& id, const std::string& val) override;
        void SetVec2(const std::string& id, const Vec2& val) override;
        void SetVec2i(const std::string& id, const Vec2i& val) override;
        void SetVec3(const std::string& id, const Vec3& val) override;
        void SetVec3i(const std::string& id, const Vec3i& val) override;
        void SetFloatRect(const std::string& id, const RectF& val) override;
        void SetIntRect(const std::string& id, const RectI& val) override;
        void SetColor(const std::string& id, const Vec4ui8& val) override;
        void SetVectorIntRect(const std::string& id, const std::vector<RectI>& vec) override;
        void SetVecStr(const std::string& id, const std::vector<std::string>& vec) override;
        void SetTransform(const std::string& id, const Transform& transform) override;

        void ForAllChildren(const std::function<void(const DataElementWrapper& element)>& func) const override;
        void ForAllChildren(const std::string& id, const std::function<void(const DataElementWrapper& element)>& func) const override;

    private:
        tinyxml2::XMLElement* _element = nullptr;
        std::shared_ptr<tinyxml2::XMLDocument> _document;
    };
}
