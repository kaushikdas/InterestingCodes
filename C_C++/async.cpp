#include <list>
#include <cstdio>
#include <chrono>
#include <future>

using std::chrono::steady_clock;
using secs = std::chrono::duration<double>;

struct prime_time {
    secs dur{};
    uint64_t count{};
};

prime_time count_primes(const uint64_t& max) {
    prime_time ret{};
    constexpr auto isprime = [](uint64_t n) {
        for(uint64_t i {2}; i < n / 2; ++i) {
            if(n % i == 0) return false;
        }
        return true;
    };
    uint64_t start {2};
    uint64_t end {max};
    auto time_thread_start = steady_clock::now();
    for(auto i = start; i <= end ; ++i) {
        if(isprime(i)) ++ret.count;
    }
    ret.dur = steady_clock::now() - time_thread_start;
    return ret;
}

int main() {
    constexpr uint64_t max_prime {0x1FFFF};  // largest uint64_t is 0xFFFFFFFFFFFFFFFF
    constexpr size_t num_threads {15};
    std::list<std::future<prime_time>> swarm;

    printf("start parallel primes\n");
    auto time_start = steady_clock::now();
    for(auto i = num_threads; i; --i) {
        swarm.emplace_back(std::async(count_primes, max_prime));
    }

    for(auto& f : swarm) {
        static auto i = 0;
        auto [dur, count] = f.get();    // structured binding (C++17)
        printf("thread %2d found %ld primes in %.5f\n", 
               ++i, count, dur.count());
    }

    secs dur_total {steady_clock::now() - time_start};
    printf("total duration: %.5fs\n", dur_total.count());
}
