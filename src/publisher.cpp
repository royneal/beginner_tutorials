/**
 * @file    publisher.cpp
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

#include <string>
#include "tf/transform_broadcaster.h"
#include "beginner_tutorials/publisher.h"
#include "beginner_tutorials/message_rate.h"


int Publisher::msg_rate_ = 1;
/**
 * @brief      default class constructor, advertises the chatter topic
 */
Publisher::Publisher() {
    pub_ = h_.advertise<std_msgs::String>("chatter", 1000);
    transform_.setOrigin(tf::Vector3(0.0, 2.0, 0.0) );
    transform_.setRotation(tf::Quaternion(0, 0, 0, 1) );
}

/**
 * @brief      Service call back function, loads new publising rate
 * @param      req holds service request
 * @param      resp holds service response
 * @return     returns true when method executes
 */
bool Publisher::SetRate(beginner_tutorials::message_rate::Request & req,
                    beginner_tutorials::message_rate::Response &resp ) {
     resp.oldrate = msg_rate_;
     msg_rate_ = req.rate;
     return true;
}

/**
 * @brief      method to set private member msg_rate_ to new rate
 * @param      rate holds new publishing rate requested by client
 *  
 */
void Publisher::SettxRate(const int& rate) {
    msg_rate_ = rate;
}

/**
 * @brief      method to publis messages on chatter topic
 * @param      msg string to be published on topic
 */
void Publisher::Publish(const std::string& msg) {
    ros::Rate loop_rate(msg_rate_);  // rate at which messages get published
    std_msgs::String ros_msg;  // standard ros message type string
    service_ = h_.advertiseService("message_rate", & Publisher::SetRate);

    while (ros::ok()) {
        ros::Rate loop_rate(msg_rate_);  // rate at which messages get published
        ros_msg.data = msg;  // pass message to be sent to ros message object
        pub_.publish(ros_msg);  // publish message to topic
        br_.sendTransform(tf::StampedTransform
        (transform_, ros::Time::now(), "world", "talk"));

        ros::spinOnce();
        loop_rate.sleep();
    }
}
