#include "hash-vectors/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = hashvec::make_job("pool");
    auto b = hashvec::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(hashvec::hash_nonce(a, 1) != hashvec::hash_nonce(a, 2));
    CHECK(hashvec::bench(8) == 8);
    CHECK(hashvec::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
