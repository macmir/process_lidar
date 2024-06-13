// Copyright 2024 111
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PROCESS_LIDAR__PROCESS_LIDAR_HPP_
#define PROCESS_LIDAR__PROCESS_LIDAR_HPP_

#include <cstdint>

#include "process_lidar/visibility_control.hpp"


namespace process_lidar
{

class PROCESS_LIDAR_PUBLIC Process_lidar
{
public:
  Process_lidar();
  int64_t foo(int64_t bar) const;
};

}  // namespace process_lidar

#endif  // PROCESS_LIDAR__PROCESS_LIDAR_HPP_
