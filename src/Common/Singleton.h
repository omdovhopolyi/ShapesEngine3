# pragma once

namespace shen3
{
    template <class T>
    class Singleton
    {
    public:
        static T& Instance()
        {
            static T instance;
            return instance;
        }

        virtual ~Singleton() = default;

    protected:
        Singleton() = default;
        
        Singleton(const Singleton&) = delete;
        Singleton& operator = (const Singleton&) = delete;

        Singleton(Singleton&&) = delete;
        Singleton& operator = (Singleton&&) = delete;
    };
}
