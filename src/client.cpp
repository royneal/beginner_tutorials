/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * this node is a client that allows changing the publishing rate of
 * the publisher_subscriber_node in this beginner_tutorials package.
 *
 */
#include <cstdlib>
#include "beginner_tutorials/message_rate.h"
#include "ros/ros.h"


int main(int argc, char **argv) {
  ros::init(argc, argv, "client_node"); 

  if (argc != 2) {  //check if user provided arguments 
    ROS_ERROR("Error: no imput arguments  ");
    return -1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::message_rate> // register service client 
  ("message_rate");
  beginner_tutorials::message_rate srv;  // create a service object to hold service request 
  srv.request.rate = std::stoi(argv[1]);  // read command line argument into service object
  ROS_DEBUG_STREAM("DEBUG MESSAGE CHECK ARG VALUE:"<<srv.request.rate);
  if (client.call(srv)) {  // check if service request was successfull and notify user 
    ROS_INFO_STREAM("Old Message Rate: "<< srv.response.oldrate);
    ROS_INFO_STREAM("New Message Rate: "<< srv.request.rate);
  } else {
    ROS_FATAL("Failed to call service message_rate");
    return 1;
  }

  return 0;
}