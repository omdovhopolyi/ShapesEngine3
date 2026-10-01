#pragma once

#include <boost/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

namespace shen3
{
    template <class T>
    using IntrusivePtr = boost::intrusive_ptr<T>;

    template <class T>
    class IntrusiveRefCounter
        : public boost::intrusive_ref_counter<T>
    {
    };
}
