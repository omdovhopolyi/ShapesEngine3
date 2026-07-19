#include <Graphics/MaterialsManager.h>
#include <Graphics/ShadersManager.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Common/FilePath.h>
#include <Managers/ManagersController.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(MaterialsManager)

    void MaterialsManager::Load()
    {
        auto elementWrapper = DataElementWrapperFactory::Get(FilePath::Path("assets/configs/materials.xml"));
        elementWrapper->ForAllChildren("material", [&](const DataElementWrapper& element) {
            const auto id = element.GetStr("id");
            const auto filename = element.GetStr("file");
            LoadMaterial(id, filename);
        });
    }

    Material* MaterialsManager::GetMaterial(const std::string& id) const
    {
        auto it = _materials.find(id);
        return (it != _materials.end()) ? it->second.get() : nullptr;
    }

    void MaterialsManager::AddMaterial(const std::string& id, std::unique_ptr<Material> material)
    {
        _materials[id] = std::move(material);
    }

    void MaterialsManager::LoadMaterial(const std::string& id, const std::string& filename)
    {
        auto material = std::make_unique<Material>();

        auto materialElement = DataElementWrapperFactory::Get(FilePath::Path(filename));

        const auto shaderId = materialElement->GetStr("shader");

        auto shader = GetManagers()->GetManager<ShadersManager>()->GetShader(shaderId);
        material->SetShader(shader);
        
        materialElement->ForAllChildren("param", [&](const DataElementWrapper& paramElement) {
            const auto paramName = paramElement.GetStr("name");
            const auto paramType = paramElement.GetStr("type");
            if (paramType == "float") {
                const auto value = paramElement.GetFloat("value");
                material->SetParam(paramName, value);
            }
            else if (paramType == "vec2") {
                const auto value = paramElement.GetVec2("value");
                material->SetParam(paramName, value);
            }
        });

        AddMaterial(id, std::move(material));
    }
}