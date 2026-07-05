#pragma once

#include <Math/Math.h>
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace shen3
{
    class DataElementWrapper
    {
    public:
        DataElementWrapper();
        virtual ~DataElementWrapper();

        virtual void LoadFile(const std::string& filename);
        virtual bool IsValid() const;

        virtual void SetupFirstElement();
        
        virtual std::shared_ptr<DataElementWrapper> GetChildElement(const std::string& id) const;
        virtual bool HasElement(const std::string& id) const;

        virtual bool GetBool(const std::string& id, bool defaultVal = false) const;
        virtual int GetInt(const std::string& id, int defaultVal = 0) const;
        virtual float GetFloat(const std::string& id, float defaultVal = 0.f) const;
        virtual std::string GetStr(const std::string& id, const std::string& defaultVal = {}) const;
        virtual Vec2 GetVec2(const std::string& id, const Vec2& defaultVal = {}) const;
        virtual Vec2i GetIntVec2(const std::string& id, const Vec2i& defaultVal = {}) const;
        virtual Vec3 GetVec3(const std::string& id, const Vec3& defaultVal = {}) const;
        virtual Vec3i GetIntVec3(const std::string& id, const Vec3i& defaultVal = {}) const;
        virtual RectF GetFloatRect(const std::string& id, const RectF& def = {}) const;
        virtual RectI GetIntRect(const std::string& id, const RectI& def = {}) const;
        virtual Vec4ui8 GetColor(const std::string& id, const Vec4ui8& defaultVal = {}) const;
        virtual std::vector<RectI> GetVectorIntRect(const std::string& id, const std::string& itemId = "item") const;
        virtual std::vector<std::string> GetVecStr(const std::string& id) const;
        virtual Transform GetTransform(const std::string& id, const Transform& defaultVal = {}) const;

        virtual void SetBool(const std::string& id, bool val);
        virtual void SetInt(const std::string& id, int val);
        virtual void SetFloat(const std::string& id, float val);
        virtual void SetStr(const std::string& id, const std::string& val);
        virtual void SetVec2(const std::string& id, const Vec2& val);
        virtual void SetVec2i(const std::string& id, const Vec2i& val);
        virtual void SetVec3(const std::string& id, const Vec3& val);
        virtual void SetVec3i(const std::string& id, const Vec3i& val);
        virtual void SetFloatRect(const std::string& id, const RectF& val);
        virtual void SetIntRect(const std::string& id, const RectI& val);
        virtual void SetColor(const std::string& id, const Vec4ui8& val);
        virtual void SetVectorIntRect(const std::string& id, const std::vector<RectI>& vec);
        virtual void SetVecStr(const std::string& id, const std::vector<std::string>& vec);
        virtual void SetTransform(const std::string& id, const Transform& transform);

        virtual void ForAllChildren(const std::function<void(const DataElementWrapper& element)>& element) const;
        virtual void ForAllChildren(const std::string& id, const std::function<void(const DataElementWrapper& element)>& element) const;
    };
}
