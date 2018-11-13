cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
  tf
)



 add_service_files(
   FILES
   message_rate.srv

 )

generate_messages(DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


include_directories(
  include ${catkin_INCLUDE_DIRS}

)

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(publisher_subscriber_node src/main.cpp src/publisher.cpp src/subscriber.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(publisher_subscriber_node
  ${catkin_LIBRARIES}
)


add_executable(client_node src/client.cpp)
target_link_libraries(client_node 
${catkin_LIBRARIES}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
#  add_executable(message_rate src/publisher.cpp)
#  target_link_libraries(message_rate ${catkin_LIBRARIES})
#  add_dependencies(message_rate  beginner_tutorials_generate_messages_cpp)

# create a gtest executable with target name "test_mynode"
# which is not built by "make all" but only by "make tests"
# add one/multiple source files to the executable target
# register the rostest launch file "test/mynode.test"
#add_rostest_gtest(tests_mynode test/mynode.test src/test/test_mynode.cpp [more cpp files])
if (CATKIN_ENABLE_TESTING)
find_package(rostest REQUIRED)
add_rostest_gtest(mypackagetest test/nodetest.launch test/my_packg_test.cpp)
target_link_libraries(mypackagetest ${catkin_LIBRARIES})
add_dependencies(
  mypackagetest
  publisher_subscriber_node
  ${PROJECT_NAME}_generate_messages_cpp
  ${catkin_EXPORTED_TARGETS}
  )
endif()




