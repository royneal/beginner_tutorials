/**
 * @file    subscriber.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class implementation for demonstrating subscribing a topic in ROS.
 *
 */

#include "beginner_tutorials/subscriber.h"

/**
 * @brief      Default Class Constructor, subscirbes to a topic
 *  
 */
Subscriber::Subscriber() {
sub_ = h_.subscribe("chatter", 1000, &Subscriber::Chattercallback, this);
}

/**
 * @brief      callback to process recieved messages on chatter topic
 * @param      msg to be processed
 */
void Subscriber::Chattercallback(const std_msgs::String::ConstPtr& msg) {
// output recieved message on console feed
// ROS_INFO_STREAM("message is: "<< msg->data<< std::endl);
}

