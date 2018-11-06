// "Copyright [2018] <Bharat Mathur>"
/** @file ModifyString.cpp
  *  @brief ModifyString.cpp is a node that serves as a client to request a
  *ChangeString service.
  *
  *  @author Bharat Mathur (bharatm11)
  *  @bug No known bugs.
  *  @copyright GNU Public License.
*/
#include <cstdlib>
#include "beginner_tutorials/message_rate.h"
#include "ros/ros.h"


int main(int argc, char **argv) {
  ros::init(argc, argv, "client_node");
  if (argc != 2) {
    ROS_ERROR("Error: no imput arguments  ");
    return -1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::message_rate>
  ("message_rate");
  beginner_tutorials::message_rate srv;
  srv.request.rate = std::stoi(argv[1]); 
 
  if (client.call(srv)) {
    ROS_INFO_STREAM("Old Message Rate: "<< srv.response.oldrate);
    ROS_INFO_STREAM("New Message Rate: "<< srv.request.rate);
  } else {
    ROS_FATAL("Failed to call service message_rate");
    return 1;
  }

  return 0;
}