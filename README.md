
# Beginner_tutorials 

## Overview

ENPM808X ROS Service/Launch file Assignment: Implement a service that can change the publishing rate of the previously developed publisher/subscriber tutorial. 
code follows Google style guide and c++/11. 

# Install and Build instructions

## Make catkin workspace
in a terminal type:
```
mkdir -p catkin_ws/src

```
## Initialize catkin workspace
```
cd ~/catkin_ws/src
catkin_init_workspace
```
## Clone package
git clone -b Week10_HW https://github.com/royneal/beginner_tutorials.git

## Build Workspace
first run will fail ! 
in the same terminal:
```
cd ~/catkin_ws
catkin_make 
```
once the devel folder has been added to your workspace 
go to 
```
.../catkin_ws/src/beginner_tutorials/include/dev_inc/
```
and copy all three header files 
``` 
message_rate.h
ressage_rateRequest.h
message_rateResponse.h
```
and paste them into your devel folder 
```
 .../catkin_ws/devel/include/beginner_tutorials/
```

# Running the package

## Source the workspace
```
cd ~/catkin_ws
source devel/setup.bash
```
# Running the Code

## Start ROSMaster
Open a second terminal and type the command ebelow:
```
roscore
```
## Launch Publisher and Subscriber
in the first terminal type the following commands:

```
cd ~/catkin_ws
roslaunch beginner_tutorials demo.launch rate:=5
```
you can set the rate to any value you like of course. 

This starts the publisher and subscriber together 

## To see the messages
since the launch file runs both publisher and subscriber in
the same window, info messages from chatter topic have been disabled.

To view the messages being broadcasted on the chatter topic, open a 
third console and type the following command: 
```
rostopic echo /chatter 
```
## Run Client to Change Publishing Rate

once you have started the publisher and subscriber and can visualize the 
messages in a seperate console, start a new console and run the following 
command to request a change in the topic publishing rate. pass the rate 
as an argument on the command line as follows: 
```
cd catkin_ws/
source devel/setup.bash
cd src/beginner_tutorials
rosrun beginner_tutorials client_node 20
```

## Command Line Sirvice Calls 
you can also change the publishing rate by sending the following Command
in a console. You can set the rate to a different number than ten. 
```
rosservice call /message_rate "rate: 10"
```
## TF
in a new terminal launch the publisher_subscriber_node
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials demo.launch rate:=1
```
in a second window run the following command to see the transform
```
rosrun tf tf_echo world talker
```
to view the tf tree of how frames are connected run the following command 
in a new termianl. 
```
rosrun rqt_tf_tree rqt_tf_tree
```
## RosTest
to run rostest use the commands below:
```
cd ~/catkin_ws
source devel/setup.bash
catkin_make run_tests
```
one test should run and pass if node is launched with rate:=1 which by default it should.
The test examins the service call response, which returns the original publishing rate after 
a service call has changed it. 

## RosBag
to log data broadcasted by /chatter topic , launch the publisher node with the following 
input paramters. Rosbag is disabled by default when no arguments are passed with roslaunch.

### To Record 
in a new terminal enter the following commands: 
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials demo.launch broadcast:=1 rate:=2 record_chatter:=1
```
### To play Back 
we first have to launch our node with rosbag recording disabled, and publisher broacasting disabled. 
in a new terminal enter the following commands: 
```
cd ~/catkin_ws
source devel/setup.bash
roslaunch beginner_tutorials demo.launch broadcast:=0 rate:=2 record_chatter:=0
```
in a second terminal enter (file name is for demonstration only): 
```
rosbag play ../.ros/2018-11-12-20-29-11.bag
```

# Dependencies

ROS Kinetic
roscpp
std_msgs
rostest


