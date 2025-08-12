#include <initializer_list>

namespace sid {
template <typename T1, typename T2>
class pair {
   public:
    T1 first;
    T2 second;

    pair() : first(), second() {}

    pair(const T1& first, const T2& second) : first(first), second(second) {}


};
};  // namespace sid