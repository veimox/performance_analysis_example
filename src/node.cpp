#include <performance_analysis_example/hard_worker.h>
#include <ros/ros.h>
#include <std_msgs/Float64.h>

/**
 * @brief main Creates a dummy node that has one instance of a Hard worker and
 * calls the simple operation and the opration uninterruptedly
 */
int main() {
  // Initilize the node and the node handler
  int argc(0);
  ros::init(argc, nullptr, "performance_analysis_example");
  ros::NodeHandle nh("~");

  // Create publishers
  auto publiser_simple = nh.advertise<std_msgs::Float64>("simple", 1);
  auto publiser_complicated = nh.advertise<std_msgs::Float64>("complicated", 1);

  // Instantiate the class
  HardWorker performance_analysis;

  // Sleeping rate
  ros::Rate rate(100);

  while (ros::ok()) {
    // Process data
    std_msgs::Float64 simple_msg, complicated_msg;
    simple_msg.data = performance_analysis.verySimpleStuff();
    complicated_msg.data = performance_analysis.veryComplicatedStuff();
    // Publish
    publiser_simple.publish(simple_msg);
    publiser_simple.publish(complicated_msg);
    // Log because of yes
    ROS_INFO_STREAM_THROTTLE(
        5, "Simple random number: " << std::to_string(simple_msg.data));
    ROS_INFO_STREAM_THROTTLE(5, "Complicated random number: "
                                    << std::to_string(complicated_msg.data));
    // Sleep
    rate.sleep();
  }

  std::exit(0);
}
