#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace hashvec {

struct Job {
    std::string id;
    std::vector<std::uint8_t> blob;
};

Job make_job(const std::string& seed);
std::uint64_t hash_nonce(const Job& job, std::uint32_t nonce);
std::uint32_t bench(std::uint32_t rounds);
const char* algo();

}  // namespace hashvec
