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

    if (nh.getParam("txrate", rate)) {
      ROS_INFO("Got param: %d", rate);
    } else {
      ROS_WARN("Failed to get param 'txrate' setting to Default = 1");
    }

    Publisher pub_object;  // create a publisher object
    pub_object.SettxRate(rate);
    Subscriber sub_object;  // create a subscriber object

    std::string msg = " +++++ B happy +++++ ";  // message to publish
    pub_object.Publish(msg);  // publish message

    return 0;
}
