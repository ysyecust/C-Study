#include <exception>
#include <iostream>

enum VariantType {
    Int,
    Char
};

struct BadVariantAccess : std::exception {
    BadVariantAccess() = default;
    virtual ~BadVariantAccess() = default;

    char const *what() const noexcept override {
        return "BadVariantAccess";
    }
};

template <typename T1, typename T2>
struct Variant {
private:
    int m_index;
    char m_union[std::max(sizeof(T1),sizeof(T2))];
    union{
    T1 m_value1;
    T2 m_value2;};

public:
    Variant(T1 value) : m_index(1), m_value1(value) {}

    Variant(T2 value) : m_index(2), m_value2(value) {}

    template <int I>
    bool is() const {
        return m_index == I;
    }

    template <int I>
    auto get() const {
        if (m_index != I) {
            throw BadVariantAccess();
        }
        if constexpr (I == 1) {
            return m_value1;
        } else if constexpr (I == 2) {
            return m_value2;
        } else {
            static_assert(I != I, "I out of range!");
        }
    }
};

void print(Variant<int, char> v) {
    if (v.is<1>()) {
        std::cout << v.get<1>() << '\n';
    } else if (v.is<2>()) {
        std::cout << v.get<2>() << '\n';
    }
}

int main() {
    Variant<int, char> v(42);
    print(v);
    v = Variant<int, char>('a');
    print(v);
}
