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

#include "random/random.hh"

using aim::random::BiggestInt;

// The Mersenne Twister is a pseudorandom number generator (PRNG) algorithm
// developed in 1997 by Makoto Matsumoto and Takuji Nishimura.

aim::random::Random::Random()
    : generator_(std::random_device()()), rfrom_(kMinInt), rto_(kMaxInt) {}

aim::random::Random::Random(const BiggestInt rto)
    : generator_(std::random_device()()), rfrom_(kMinInt), rto_(rto) {}

aim::random::Random::Random(const BiggestInt rfrom, const BiggestInt rto)
    : generator_(std::random_device()()), rfrom_(rfrom), rto_(rto) {}

BiggestInt aim::random::Random::Generate() {
  std::uniform_int_distribution<BiggestInt> distr_(rfrom_, rto_);
  return distr_(generator_);
}
