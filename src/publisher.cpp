/**
 * @file    publisher.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class implementation for demonstrating publishing a topic in ROS.
 *
 */
#include <string>
#include "beginner_tutorials/publisher.h"
#include "beginner_tutorials/message_rate.h"

 int Publisher::msg_rate_=10;
 
/**
 * @brief      default class constructor, advertises the chatter topic
 */
Publisher::Publisher() {
    pub_ = h_.advertise<std_msgs::String>("chatter", 1000);
}

bool Publisher::SetRate(beginner_tutorials::message_rate::Request & req, 
                    beginner_tutorials::message_rate::Response &resp ) {
     resp.oldrate = msg_rate_;
     msg_rate_ = req.rate;
     return true;
}

void Publisher::SettxRate(int& rate){
    msg_rate_ = rate;

}
/**
 * @brief      method to publis messages on chatter topic 
 * @param      msg string to be published on topic 
 */
void Publisher::Publish(const std::string& msg) {

    
    ros::Rate loop_rate(msg_rate_);  // rate at which messages get published
    std_msgs::String ros_msg;  // standard ros message type string
    service_=h_.advertiseService("message_rate",& Publisher::SetRate);

    while (ros::ok()) {
        ros::Rate loop_rate(msg_rate_);  // rate at which messages get published
        ros_msg.data = msg;  // pass message to be sent to ros message object
        pub_.publish(ros_msg);  // publish message to topic
        ros::spinOnce();
        loop_rate.sleep();
    }
}
