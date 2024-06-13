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

#include "process_lidar/process_lidar_node.hpp"
#include <vector>

namespace process_lidar
{
auto custom_qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
Process_lidarNode::Process_lidarNode(const rclcpp::NodeOptions & options)
:  Node("process_lidar", options)
{
  process_lidar_ = std::make_unique<process_lidar::Process_lidar>();
  // param_name_ = this->declare_parameter("param_name", 456);
  // process_lidar_->foo(param_name_);
  cloud_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "/sensing/lidar/scan", custom_qos, std::bind(
      &Process_lidarNode::cloudCallback, this,
      std::placeholders::_1));
  lidar_means_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("/filtered_lidar", custom_qos);


}

void Process_lidarNode::cloudCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) const
{
 
  std::vector<float>lidar_means;
  float sum=0;
  int div=9; // count of lasers -1
  // int probes=5; //cout of probes to be get from the laser from the left and right
  int cnt=0; //1081
  // bool calculated=false;
  for (auto&el: msg->ranges)
  {
    
    cnt+=1;
    sum=sum+el;
    if(cnt==int(1080/div))
    {
      lidar_means.emplace_back(sum/120);
      sum=0;
      cnt=0;
      
    }
  }
  


  // for (auto&el: msg->ranges)
  // {
  //    cnt+=1;
  //    if(cnt>int(1080/div)-probes && cnt<=int(1080/div)+probes)
  //    {
  //       sum=sum+el;
  //       calculated=true;
  //    }
  //    else
  //    {
  //       if(calculated==true)
  //       {

  //         lidar_means.emplace_back(sum/(2*probes));
  //         calculated=false;
  //         cnt=0;
  //         sum=0;

  //       }
  //    }

  // }

  std_msgs::msg::Float32MultiArray lidar_means_msg;
  lidar_means_msg.data = lidar_means; // Assuming lidar_means is a std::vector<float>

    // Publish the message
  // std::cout<<"START"<<std::endl;
  // for(auto &el: lidar_means)
  // {
  //   std::cout<<el<<std::endl;
  // }
  // std::cout<<"STOP"<<std::endl;
  lidar_means_pub_->publish(lidar_means_msg);
  lidar_means.clear();
  
}

}  // namespace process_lidar

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(process_lidar::Process_lidarNode)

