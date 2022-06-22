# Copyright 2022 The Aim Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.22.1)
project(aim
	VERSION 1.0.0
	HOMEPAGE_URL https://github.com/joshiayush/aim/wiki
	LANGUAGES C CXX)

add_subdirectory(thirdparty/pybind11)
include_directories(include)

# Note: This requires cmake to be run each time the files have changed to
# configure the build system 
file(GLOB_RECURSE AIM_SRC_FILES "aim/*.cc")

pybind11_add_module(aim ${AIM_SRC_FILES})
