#include <Serialization/WrapperTypes/XmlDataElementWrapper.h>
#include <Common/Assert.h>

namespace shen3
{
    XmlDataElementWrapper::XmlDataElementWrapper() = default;

    XmlDataElementWrapper::XmlDataElementWrapper(tinyxml2::XMLElement* element)
        : _element(element)
    { }

    void XmlDataElementWrapper::LoadFile(const std::string& filename)
    {
        _document = std::make_shared<tinyxml2::XMLDocument>();

        _document->LoadFile(filename.c_str());
        if (!_document->Error()) {
            _element = _document->RootElement();
        }
        else {
            Assert(false, std::format("[XmlDataElementWrapper::LoadFile] Can not read file '{}'", filename));
        }
    }

    bool XmlDataElementWrapper::IsValid() const
    {
        return _element != nullptr;
    }

    std::shared_ptr<DataElementWrapper> XmlDataElementWrapper::GetChildElement(const std::string& id) const
    {
        if (_element) {
            return std::make_shared<XmlDataElementWrapper>(_element->FirstChildElement(id.c_str()));
        }
        return nullptr;
    }

    bool XmlDataElementWrapper::HasElement(const std::string& id) const
    {
        if (_element) {
            const bool hasChild = _element->FirstChildElement(id.c_str()) != nullptr;
            const bool hasAttr = _element->FindAttribute(id.c_str()) != nullptr;
            return hasChild || hasAttr;
        }
        return false;
    }

    bool XmlDataElementWrapper::GetBool(const std::string& id, bool defaultVal) const
    {
        if (_element) {
            if (const auto attr = _element->FindAttribute(id.c_str())) {
                return attr->BoolValue();
            }
        }
        return defaultVal;
    }

    int XmlDataElementWrapper::GetInt(const std::string& id, int defaultVal) const
    {
        if (_element) {
            if (const auto attr = _element->FindAttribute(id.c_str())) {
                return attr->IntValue();
            }
        }
        return defaultVal;
    }

    float XmlDataElementWrapper::GetFloat(const std::string& id, float defaultVal) const
    {
        if (_element) {
            if (const auto attr = _element->FindAttribute(id.c_str())) {
                return attr->FloatValue();
            }
        }
        return defaultVal;
    }

    std::string XmlDataElementWrapper::GetStr(const std::string& id, const std::string& defaultVal) const
    {
        if (_element) {
            if (const auto attr = _element->FindAttribute(id.c_str())) {
                return attr->Value();
            }
        }

        return defaultVal;
    }

    Vec2 XmlDataElementWrapper::GetVec2(const std::string& id, const Vec2& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const float x = childElement.GetFloat("x");
                const float y = childElement.GetFloat("y");
                return { x, y };
            }
        }
        return defaultVal;
    }

    Vec2i XmlDataElementWrapper::GetIntVec2(const std::string& id, const Vec2i& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const int x = childElement.GetInt("x");
                const int y = childElement.GetInt("y");
                return { x, y };
            }
        }
        return defaultVal;
    }

    Vec3 XmlDataElementWrapper::GetVec3(const std::string& id, const Vec3& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const float x = childElement.GetFloat("x");
                const float y = childElement.GetFloat("y");
                const float z = childElement.GetFloat("z");
                return { x, y, z };
            }
        }
        return defaultVal;
    }

    Vec3i XmlDataElementWrapper::GetIntVec3(const std::string& id, const Vec3i& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const int x = childElement.GetInt("x");
                const int y = childElement.GetInt("y");
                const int z = childElement.GetInt("z");
                return { x, y, z };
            }
        }
        return defaultVal;
    }

    RectF XmlDataElementWrapper::GetFloatRect(const std::string& id, const RectF& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const float x = childElement.GetFloat("x");
                const float y = childElement.GetFloat("y");
                const float w = childElement.GetFloat("w");
                const float h = childElement.GetFloat("h");
                return { x, y, w, h };
            }
        }
        return defaultVal;
    }

    RectI XmlDataElementWrapper::GetIntRect(const std::string& id, const RectI& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const int x = childElement.GetInt("x");
                const int y = childElement.GetInt("y");
                const int w = childElement.GetInt("w");
                const int h = childElement.GetInt("h");
                return { x, y, w, h };
            }
        }
        return defaultVal;
    }

    Vec4ui8 XmlDataElementWrapper::GetColor(const std::string& id, const Vec4ui8& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto childElement = XmlDataElementWrapper{ child };
                const int r = childElement.GetInt("r");
                const int g = childElement.GetInt("g");
                const int b = childElement.GetInt("b");
                const int a = childElement.GetInt("a");
                return { static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b), static_cast<std::uint8_t>(a) };
            }
        }
        return defaultVal;
    }

    std::vector<RectI> XmlDataElementWrapper::GetVectorIntRect(const std::string& id, const std::string& itemId) const
    {
        std::vector<RectI> result;

        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto item = child->FirstChildElement(itemId.c_str());
                while (item) {
                     auto wrapper = XmlDataElementWrapper{ item };
                     const auto x = wrapper.GetInt("x");
                     const auto y = wrapper.GetInt("y");
                     const auto w = wrapper.GetInt("w");
                     const auto h = wrapper.GetInt("h");

                     result.emplace_back(x, y, w, h);

                     item = item->NextSiblingElement(itemId.c_str());
                }
            }
        }
        return result;
    }

    std::vector<std::string> XmlDataElementWrapper::GetVecStr(const std::string& id) const
    {
        std::vector<std::string> result;

        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto item = child->FirstChildElement("item");
                while (item) {
                    auto wrapper = XmlDataElementWrapper{  item };
                    const auto str = wrapper.GetStr("val");

                    result.push_back(str);

                    item = item->NextSiblingElement("item");
                }
            }
        }
        return result;
    }

    Transform XmlDataElementWrapper::GetTransform(const std::string& id, const Transform& defaultVal) const
    {
        if (_element) {
            if (const auto child = _element->FirstChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                const auto angle = GetVec3("angle");
                const auto scale = wrapper.GetVec3("scale", { 1.f, 1.f, 1.f });
                const auto position = wrapper.GetVec3("position");

                Transform transform;
                transform.SetPosition(position);
                transform.SetRotation(angle);
                transform.SetScale(scale);
                transform.UpdateTransform();

                return transform;
            }
        }
        return defaultVal;
    }

    void XmlDataElementWrapper::SetBool(const std::string& id, bool val)
    {
        if (_element) {
            _element->SetAttribute(id.c_str(), val);
        }
    }

    void XmlDataElementWrapper::SetInt(const std::string& id, int val)
    {
        if (_element) {
            _element->SetAttribute(id.c_str(), val);
        }
    }

    void XmlDataElementWrapper::SetFloat(const std::string& id, float val)
    {
        if (_element) {
            _element->SetAttribute(id.c_str(), val);
        }
    }

    void XmlDataElementWrapper::SetStr(const std::string& id, const std::string& val)
    {
        if (_element) {
            _element->SetAttribute(id.c_str(), val.c_str());
        }
    }

    void XmlDataElementWrapper::SetVec2(const std::string& id, const Vec2& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetFloat("x", val.x);
                wrapper.SetFloat("y", val.y);
            }
        }
    }

    void XmlDataElementWrapper::SetVec2i(const std::string& id, const Vec2i& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetInt("x", val.x);
                wrapper.SetInt("y", val.y);
            }
        }
    }

    void XmlDataElementWrapper::SetVec3(const std::string& id, const Vec3& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetFloat("x", val.x);
                wrapper.SetFloat("y", val.y);
                wrapper.SetFloat("z", val.z);
            }
        }
    }

    void XmlDataElementWrapper::SetVec3i(const std::string& id, const Vec3i& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetInt("x", val.x);
                wrapper.SetInt("y", val.y);
                wrapper.SetInt("z", val.z);
            }
        }
    }

    void XmlDataElementWrapper::SetFloatRect(const std::string& id, const RectF& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetFloat("x", val.x);
                wrapper.SetFloat("y", val.y);
                wrapper.SetFloat("w", val.w);
                wrapper.SetFloat("h", val.h);
            }
        }
    }

    void XmlDataElementWrapper::SetIntRect(const std::string& id, const RectI& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetInt("x", val.x);
                wrapper.SetInt("y", val.y);
                wrapper.SetInt("w", val.w);
                wrapper.SetInt("h", val.h);
            }
        }
    }

    void XmlDataElementWrapper::SetColor(const std::string& id, const Vec4ui8& val)
    {
        if (_element) {
            if (auto child = _element->InsertNewChildElement(id.c_str())) {
                auto wrapper = XmlDataElementWrapper{ child };
                wrapper.SetInt("r", val.r);
                wrapper.SetInt("g", val.g);
                wrapper.SetInt("b", val.b);
                wrapper.SetInt("a", val.a);
            }
        }
    }

    void XmlDataElementWrapper::SetVectorIntRect(const std::string& id, const std::vector<RectI>& vec)
    {
        if (_element) {
            if (const auto child = _element->InsertNewChildElement(id.c_str())) {
                for (const auto& item : vec) {
                    auto itemElement = child->InsertNewChildElement("item");
                    auto wrapper = XmlDataElementWrapper{ itemElement };
                    wrapper.SetInt("x", item.x);
                    wrapper.SetInt("y", item.y);
                    wrapper.SetInt("w", item.w);
                    wrapper.SetInt("h", item.h);
                }
            }
        }
    }

    void XmlDataElementWrapper::SetVecStr(const std::string& id, const std::vector<std::string>& vec)
    {
        if (_element) {
            if (const auto child = _element->InsertNewChildElement(id.c_str())) {
                for (const auto& str : vec) {
                    auto itemElement = child->InsertNewChildElement("item");
                    auto wrapper = XmlDataElementWrapper{ itemElement };
                    wrapper.SetStr("val", str);
                }
            }
        }
    }

    void XmlDataElementWrapper::SetTransform(const std::string&, const Transform&)
    {
        if (_element) {
            //
        }
    }

    void XmlDataElementWrapper::ForAllChildren(const std::function<void(const DataElementWrapper& element)>& func) const
    {
        if (_element && func) {
            auto child = _element->FirstChildElement();

            while (child) {
                auto wrapper = XmlDataElementWrapper{ child };
                func(wrapper);
                child = child->NextSiblingElement();
            }
        }
    }

    void XmlDataElementWrapper::ForAllChildren(const std::string& id, const std::function<void(const DataElementWrapper& element)>& func) const
    {
        if (_element && func) {
            auto child = _element->FirstChildElement(id.c_str());

            while (child) {
                auto wrapper = XmlDataElementWrapper{ child };
                func(wrapper);
                child = child->NextSiblingElement(id.c_str());
            }
        }
    }
}
