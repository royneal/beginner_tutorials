// Bring in my package's API, which is what I'm testing

// Bring in gtest
#include <gtest/gtest.h>
#include "ros/ros.h"
#include "beginner_tutorials/publisher.h"
#include "beginner_tutorials/subscriber.h"
// Declare a test
TEST(TestSuite, testCase1)
{
  ros::NodeHandle nh;
  nh.serviceClient<beginner_tutorials::message_rate>
  ("message_rate");  // register service client
  beginner_tutorials::message_rate srv;  // create a service object
  srv.request.rate = 50;  // set service request value
  int resp=50;

  EXPECT_EQ(1, srv.response.oldrate); // service responds with old rate which is 1 hz

}


// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "mypackagetest");
  return RUN_ALL_TESTS();
}