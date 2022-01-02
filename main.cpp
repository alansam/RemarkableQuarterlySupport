//  Multiples of 3 or 5
//  @see: https://projecteuler.net/problem=1

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

uint64_t multiples_3_5_A(void) {
  auto constexpr max_val { 1'000ul };
  auto result { 0ul };

  auto nnums = std::vector<uint64_t>();
  for (auto nr = 3ul; nr < max_val; nr += 3) {
    nnums.push_back(nr);
  }

  for (auto nr = 5ul; nr < max_val; nr += 5) {
    nnums.push_back(nr);
  }

  result = std::accumulate(nnums.rbegin(), nnums.rend(), 0ul, std::plus<>{});

  return result;
}

uint64_t multiples_3_5_B(void) {
  auto constexpr max_val { 1'000ul };
  auto result { 0ul };

  for (auto nr { 0ul }; nr < max_val; ++nr) {
    result += (nr % 3 == 0) ? nr : 0;
    result += (nr % 5 == 0) ? nr : 0;
  }

  return result;
}

int main(int argc, char const * argv[]) {
  auto rA = multiples_3_5_A();
  auto rB = multiples_3_5_B();

  std::cout << "multiples_3_5_A: " << std::setw(8) << rA << '\n';
  std::cout << "multiples_3_5_B: " << std::setw(8) << rB << '\n';

  return 0;
}
