/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * main node program  that instantiates a publisher and subscirber objects.
 *
 */
#include <string>
#include "beginner_tutorials/publisher.h"
#include "beginner_tutorials/subscriber.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "publisher_subscriber_node");
    ros::NodeHandle nh("~");
    int rate;
    int stat = 0;
    nh.getParam("txstat", stat);
    if (nh.getParam("txrate", rate)) {
      ROS_INFO("Publishing rate set to: %d", rate);
    } else {
      ROS_WARN("Failed to get param 'txrate' setting to Default = 1");
    }

    Publisher pub_object;  // create a publisher object
    pub_object.SettxRate(rate);
    Subscriber sub_object;  // create a subscriber object

    std::string msg = " +++++ B happy +++++ ";  // message to publish

    if (stat == 1) {
      ROS_INFO("Publisher is enabled");
      pub_object.Publish(msg);  // publish message
    } else {
      ROS_WARN_STREAM("stat = " << stat);
      ROS_WARN("Publisher is disabled");
    }
    return 0;
}
