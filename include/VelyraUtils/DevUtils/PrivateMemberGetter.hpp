#pragma once

#if defined(VL_TESTING)

#define VL_GET_PRIVATE_MEMBER(CLASS, MEMBER) \
    public: \
    inline const decltype(CLASS::MEMBER)& get_##MEMBER() const { return MEMBER; }

#else
#define VL_GET_PRIVATE_MEMBER(CLASS, MEMBER)

#endif