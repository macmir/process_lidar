cmake_minimum_required(VERSION 3.14)
project(process_lidar)

find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_add_library(${PROJECT_NAME} SHARED
  include/process_lidar/process_lidar.hpp
  include/process_lidar/visibility_control.hpp
  src/process_lidar.cpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  include/process_lidar/process_lidar_node.hpp
  src/process_lidar_node.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "process_lidar::Process_lidarNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_process_lidar
    test/test_process_lidar.cpp
  )
  ament_target_dependencies(test_process_lidar ${TEST_SOURCES})
  target_link_libraries(test_process_lidar ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
