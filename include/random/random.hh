// Copyright 2022 The Aim Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AIM_INCLUDE_RANDOM_RANDOM_HH_
#define AIM_INCLUDE_RANDOM_RANDOM_HH_

// The Mersenne Twister is a pseudorandom number generator (PRNG) algorithm
// developed in 1997 by Makoto Matsumoto and Takuji Nishimura.

#include <cstdint>
#include <random>

namespace aim {
namespace random {
using BiggestInt = std::int64_t;

class RandomAbstractBaseClass {
 public:
  virtual ~RandomAbstractBaseClass() = default;
  virtual BiggestInt Generate() = 0;
};

class Random : public RandomAbstractBaseClass {
 public:
  Random();

  Random(const BiggestInt rto);

  Random(const BiggestInt rfrom, const BiggestInt rto);

  BiggestInt Generate() override;

 private:
  static constexpr BiggestInt kMaxInt = std::numeric_limits<BiggestInt>::max();
  static constexpr BiggestInt kMinInt = std::numeric_limits<BiggestInt>::min();

  BiggestInt rfrom_;
  BiggestInt rto_;
  std::mt19937 generator_;
};
}  // namespace random
}  // namespace aim

#endif  // AIM_INCLUDE_RANDOM_RANDOM_HH_
