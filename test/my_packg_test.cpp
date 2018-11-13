/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Test node to demo usage of rostest, 
 *
 */
// Bring in gtest
#include <gtest/gtest.h>
#include "ros/ros.h"
#include "beginner_tutorials/publisher.h"
#include "beginner_tutorials/subscriber.h"
// Declare a test
TEST(ServiceTests, Change_Publisher_Rate) {
  ros::NodeHandle nh;
  // Wait on Service to start before begining with testing
  if ( ros::service::waitForService ( "message_rate", 1000))
    ROS_INFO("Service message_rate started successfully");
    else
    ROS_INFO("Service Wait timed out ");

  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::message_rate>
  ("message_rate");  // register service client
  beginner_tutorials::message_rate srv;  // create a service object
  srv.request.rate = 50;  // set service request value
  client.call(srv);
  EXPECT_EQ(1, srv.response.oldrate);  // service responds with old rate = 1 hz
}

// Run all declared tests
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "mypackagetest");
  return RUN_ALL_TESTS();
}
