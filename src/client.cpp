/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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

  if (argc != 2) {  // check if user provided arguments
    ROS_ERROR("Error: no imput arguments  ");
    return -1;
  }
  ros::NodeHandle nh;
  ros::ServiceClient client =
  nh.serviceClient<beginner_tutorials::message_rate>
  ("message_rate");  // register service client
  ros::Rate loop_rate(10);
  beginner_tutorials::message_rate srv;  // create a service object
  while (ros::ok) {
  srv.request.rate = std::stoi(argv[1]);  // read command line argument
  ROS_DEBUG_STREAM("DEBUG MESSAGE CHECK ARG VALUE:" << srv.request.rate);
  if (client.call(srv)) {  // check if service request was successfull
    ROS_INFO_STREAM("Old Message Rate: " << srv.response.oldrate);
    ROS_INFO_STREAM("New Message Rate: " << srv.request.rate);
  } else {
    ROS_FATAL("Failed to call service message_rate");
    return 1;
  }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
