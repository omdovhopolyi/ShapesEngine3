#pragma once

#include <Managers/ManagersFactory.h>
#include <typeindex>
#include <string>

#define MANAGERS_FACTORY(Type) \
    public: \
        static bool registered; \
        static bool RegisterFactory(); \
        std::type_index GetTypeIndex() override { return std::type_index(typeid(Type)); } \
        std::string GetTypeName() override { return #Type; }

#define REGISTER_MANAGERS_FACTORY(Type) \
    bool Type::RegisterFactory() \
    { \
        shen3::ManagersFactory::Instance().RegisterManagersFactory(#Type, [](){ return std::make_unique<Type>(); }); \
        return true; \
    } \
    bool Type::registered = Type::RegisterFactory();
