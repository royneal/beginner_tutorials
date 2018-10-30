
# Beginner_tutorials

## Overview

ENPM808X ROS Publisher/Subscriber Assignment: Implement a publisher and subscriber using ROS tutorials. 
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
git clone https://github.com/royneal/beginner_tutorials.git

## Build Workspace
in the same terminal:
```
cd ~/catkin_ws
catkin_make 
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
in the first terminal type the following commands:

```
rosrun beginner_tutorials beginner_tutorials_node
```

This starts the publisher and subscriber together 
and prints the recieved message to the console.

you can also listen to the topic by typing:
```
rostopic echo /chatter 
``

# Dependencies

ROS Kinetic
roscpp
std_msgs


