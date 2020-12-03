extern int Main(int /* argc */, char const* const /* argv */[]);

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>  // Bug workaround -- put this before <cstdlib>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
// #include <strstream>    // deprecated
#include <iomanip>
#include <streambuf>
// #include <cstdio>    // Bug workaround -- put this before <cstdlib>

#include <clocale>
#include <locale>

#if __cplusplus >= 201103L
#include <chrono>
#include <cinttypes>
#include <cstdint>
#include <initializer_list>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <typeindex>
#if __cplusplus >= 201703L && __has_include(<cuchar>)
#include <cuchar>  // C++11 header but don't have __has_include until C++17
#endif
#include <array>
#include <cfenv>
#include <forward_list>
#include <random>
#include <ratio>
#include <unordered_map>
#include <unordered_set>
#if __cplusplus < 201703L
#include <codecvt>
#endif
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>
#include <regex>
#include <thread>
#endif  // C++11

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif  // C++14

#if __cplusplus >= 201703L
#include <any>
#include <optional>
#include <variant>
#if __has_include(<memory_resource>)
#include <memory_resource>
#endif
#include <charconv>
#include <string_view>
#if __has_include(<execution>)
//#include <execution>  // Doesn't compile under gcc w/o TBB
#endif
#include <filesystem>
#endif  // C++17

#if __cplusplus > 201703L
#if __has_include(<concepts>) && defined(__cpp_lib_concepts) && __cpp_lib_concepts >= 202002L
#include <concepts>
#endif
#if __has_include(<coroutine>) && __cpp_lib_coroutine >= 201902L
#include <coroutine>
#endif
#if __has_include(<compare>)  // && __cpp_lib_three_way_comparison >= 201907L
#include <compare>
#endif
#include <version>
#if __has_include(<source_location>) && __cpp_lib_source_location >= 201907L
#include <source_location>
#endif
#if __has_include(<format>) && __cpp_lib_format >= 201907L
#include <format>
#endif
#if __has_include(<span>)  // && __cpp_lib_span >= 202002L
#include <span>
#endif
#if __has_include(<ranges>) && __cpp_lib_ranges >= 201911L
#include <ranges>
#endif
#include <bit>
#if __has_include(<numbers>) && __cpp_lib_math_constants >= 201907L
#include <numbers>
#endif
#if __has_include(<syncstream>) && __cpp_lib_syncbuf >= 201803L
#include <syncstream>
#endif
#if __has_include(<stop_token>) && __cpp_lib_jthread >= 201911L
#include <stop_token>
#endif
#if __has_include(<semaphore>) && defined(__cpp_lib_semaphore) && __cpp_lib_semaphore >= 201907L
#include <semaphore>
#endif
#if __has_include(<latch>) && defined(__cpp_lib_latch) && __cpp_lib_latch >= 201907L
#include <latch>
#endif
#if __has_include(<barrier>) && defined(__cpp_lib_barrier) && __cpp_lib_barrier >= 201907L
#include <barrier>
#endif
#endif  // C++20

#include <cool/Out.h>

// Each string is a row
struct Geology : std::vector<std::string> {
    size_t trees1(const size_t right = 3, const size_t down = 1) const {
        const size_t numberRows = size();
        const size_t numberColumns = at(0).size();

        size_t numberTrees = 0;
        size_t column = 0;

        for (size_t row = down; row < numberRows; row += down) {
            column += right;
            column %= numberColumns;
            numberTrees += '#' == at(row).at(column);
        }

        return numberTrees;
    }
};

int Main(int /* argc */, char const* const /* argv */[]) {
    Geology geology;
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>(),
              std::back_inserter(geology));

    std::cout << geology.trees1(3, 1) << '\n';

    return 0;
}

