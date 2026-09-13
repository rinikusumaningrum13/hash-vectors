#include "hash-vectors/work.h"

#include <sstream>
#include <iomanip>

namespace hashvec {

namespace {

std::uint64_t mix(std::uint64_t state, std::uint8_t b, std::size_t i) {
    state = state * 0x100000001b3ull + b + static_cast<std::uint64_t>(i);
    return state;
}

}  // namespace

Job make_job(const std::string& seed) {
    std::uint64_t state = 0x9e3779b97f4a7c15ull;
    for (std::size_t i = 0; i < seed.size(); ++i) {
        state = mix(state, static_cast<std::uint8_t>(seed[i]), i);
    }
    Job job;
    std::ostringstream id;
    id << std::hex << std::setw(8) << std::setfill('0')
       << static_cast<std::uint32_t>(state);
    job.id = id.str();
    job.blob.resize(8);
    for (int i = 7; i >= 0; --i) {
        job.blob[static_cast<std::size_t>(i)] = static_cast<std::uint8_t>(state & 0xff);
        state >>= 8;
    }
    return job;
}

std::uint64_t hash_nonce(const Job& job, std::uint32_t nonce) {
    std::uint64_t state = 0x9e3779b97f4a7c15ull;
    for (std::size_t i = 0; i < job.blob.size(); ++i) {
        state = mix(state, job.blob[i], i);
    }
    for (int i = 0; i < 4; ++i) {
        auto b = static_cast<std::uint8_t>((nonce >> (8 * i)) & 0xff);
        state = mix(state, b, job.blob.size() + static_cast<std::size_t>(i));
    }
    return state;
}

std::uint32_t bench(std::uint32_t rounds) {
    auto job = make_job(algo());
    for (std::uint32_t n = 0; n < rounds; ++n) {
        (void)hash_nonce(job, n);
    }
    return rounds;
}

const char* algo() { return "multi"; }

}  // namespace hashvec
