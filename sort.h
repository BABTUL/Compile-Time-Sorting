template< int X, int... Xs >
struct Arr {
    static constexpr int head = X;
    using Tail = Arr< Xs... >;
    template< int Y >
    using Push_back = Arr< X, Xs..., Y >;
    static constexpr size_t value = Arr< Xs... >::size + 1;
};

template< int X >
struct Arr< X > {
    static constexpr int head = X;
    using Tail = int;
    template< int Y >
    using Push_back = Arr< X, Y >;
    static constexpr size_t size = 1;
};

template< typename T1, typename T2 >
struct Add {
    using Result = typename Add< typename T1::template Push_back< T2::head >, typename T2::Tail >::Result;
};

template<>
struct Add< int, int > {
    using Result = int;
};

template< typename T2 >
struct Add< int, T2 > {
    using Result = T2;
};

template< typename T1 >
struct Add< T1, int > {
    using Result = T1;
};

template< template< int > typename F, typename T, typename Enable = void >
struct Filter {
    using Result = int;
};

template< template< int > typename F, typename T >
struct Filter< F, T, typename std::enable_if_t< !std::is_same< T, int >::value && F< T::head >::value > > {
    using Result = typename Add< Arr< T::head >, typename Filter< F, typename T::Tail >::Result >::Result;
};

template< template< int > typename F, typename T >
struct Filter< F, T, typename std::enable_if_t< !std::is_same< T, int >::value && !F< T::head >::value > > {
    using Result = typename Filter< F, typename T::Tail >::Result;
};

template< int X >
struct Cmp {
    template< int Y >
    struct Less {
        static constexpr bool value = X > Y;
    };

    template< int Y >
    struct Equal {
        static constexpr bool value = X == Y;
    };

    template< int Y >
    struct Greater {
        static constexpr bool value = X < Y;
    };
};

template< typename T >
struct Sort {
    template< int X >
    using Lc = typename Cmp< T::head >::template Less   < X >;
    using Ls = typename Sort< typename Filter< Lc, T >::Result >::Result;

    template< int X >
    using Ec = typename Cmp< T::head >::template Equal  < X >;
    using Es = typename Filter< Ec, T >::Result;

    template< int X >
    using Gc = typename Cmp< T::head >::template Greater< X >;
    using Gs = typename Sort< typename Filter< Gc, T >::Result >::Result;

    using Result = typename Add< typename Add< Ls, Es >::Result, Gs >::Result;
};

template<>
struct Sort< int > {
    using Result = int;
};
