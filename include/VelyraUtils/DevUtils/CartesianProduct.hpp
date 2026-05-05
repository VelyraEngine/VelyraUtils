#pragma once

#include <tuple>

namespace Velyra::Utils {

template<typename... Ts>
struct TypeList {
};

template<typename TL1, typename TL2>
struct Add;

template<typename... Ts1, typename... Ts2>
struct Add<TypeList<Ts1...>, TypeList<Ts2...>> {
    using type = TypeList<Ts1..., Ts2...>;
};

template<typename... TL>
struct Concat;

template<typename TL, typename... TLs>
struct Concat<TL, TLs...> {
    using type = typename Add<TL, typename Concat<TLs...>::type>::type;
};

// base case
template<typename TL>
struct Concat<TL> {
    using type = TL;
};

// Prepends each element of T1 to the list T2.
template<typename TL1, typename TL2>
struct MultiOne;

template<typename... T1s, typename... T2s>
struct MultiOne<TypeList<T1s...>, TypeList<T2s...>> {
    using type = typename Concat<TypeList<TypeList<T1s, T2s...>...>>::type;
};

// Prepends each element of TL to all type lists in TLL.
template<typename TL, typename TLL>
struct MultiAll;

template<typename TL, typename... TLs>
struct MultiAll<TL, TypeList<TLs...>> {
    using type = typename Concat<typename MultiOne<TL, TLs>::type...>::type;
};

// Internal cartesian product (produces TypeList<TypeList<...>, ...>)
template<typename TL, typename... TLs>
struct CartesianProductImpl {
    using type = typename MultiAll<TL, typename CartesianProductImpl<TLs...>::type>::type;
};

template<typename... Ts>
struct CartesianProductImpl<TypeList<Ts...>> {
    using type = TypeList<TypeList<Ts>...>;
};

// Convert a TypeList to std::tuple
template<typename TL>
struct TypeListToTuple;

template<typename... Ts>
struct TypeListToTuple<TypeList<Ts...>> {
    using type = std::tuple<Ts...>;
};

// Convert all inner TypeLists to std::tuples
// TODO: Someday, I will be able to generate std::tuples directly
template<typename TLL>
struct ConvertToTuples;

template<typename... TLs>
struct ConvertToTuples<TypeList<TLs...>> {
    using type = TypeList<typename TypeListToTuple<TLs>::type...>;
};

// Now cartesian product! (produces TypeList<std::tuple<...>, ...>)
template<typename TL, typename... TLs>
struct CartesianProduct {
    using type = typename ConvertToTuples<typename CartesianProductImpl<TL, TLs...>::type>::type;
};

#if defined(VL_TESTING)

template<typename... TL>
struct ToGTestTypes;

template<typename... TLs>
struct ToGTestTypes<TypeList<TLs...>> {
    using type = ::testing::Types<TLs...>;
};

#endif


}