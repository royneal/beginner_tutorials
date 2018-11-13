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
