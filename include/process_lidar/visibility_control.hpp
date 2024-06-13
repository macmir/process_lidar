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

#ifndef PROCESS_LIDAR__VISIBILITY_CONTROL_HPP_
#define PROCESS_LIDAR__VISIBILITY_CONTROL_HPP_

////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32)
  #if defined(PROCESS_LIDAR_BUILDING_DLL) || defined(PROCESS_LIDAR_EXPORTS)
    #define PROCESS_LIDAR_PUBLIC __declspec(dllexport)
    #define PROCESS_LIDAR_LOCAL
  #else  // defined(PROCESS_LIDAR_BUILDING_DLL) || defined(PROCESS_LIDAR_EXPORTS)
    #define PROCESS_LIDAR_PUBLIC __declspec(dllimport)
    #define PROCESS_LIDAR_LOCAL
  #endif  // defined(PROCESS_LIDAR_BUILDING_DLL) || defined(PROCESS_LIDAR_EXPORTS)
#elif defined(__linux__)
  #define PROCESS_LIDAR_PUBLIC __attribute__((visibility("default")))
  #define PROCESS_LIDAR_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define PROCESS_LIDAR_PUBLIC __attribute__((visibility("default")))
  #define PROCESS_LIDAR_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif

#endif  // PROCESS_LIDAR__VISIBILITY_CONTROL_HPP_
