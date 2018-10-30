/**
 * @file    subscriber.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class implementation for demonstrating subscribing a topic in ROS.
 *
 */

#include "subscriber.h"

Subscriber::Subscriber() {
sub_=h_.subscribe("chatter", 1000, &Subscriber::Chattercallback, this);
}

void Subscriber::Chattercallback(const std_msgs::String::ConstPtr& msg) {
ROS_INFO_STREAM("message is: "<< msg->data<< std::endl);

}