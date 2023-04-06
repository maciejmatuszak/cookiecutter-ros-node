#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <{{cookiecutter.project_slug }}/{{cookiecutter.project_slug }}.hpp>

namespace {{cookiecutter.project_slug }}
{

/**
 * @brief
 */
class {{cookiecutter.project_slug | to_camel }}Node
{
  public:
    explicit {{cookiecutter.project_slug | to_camel }}Node(ros::NodeHandle& nh);
    void handle_ping_msg(const std_msgs::String &msg);
    void publish_pong_msg(const std::string &pong);

  private:
    ros::NodeHandle nh_;
    ros::Publisher pong_publisher_;
    ros::Subscriber ping_subscriber_;
    {{cookiecutter.project_slug }}::{{cookiecutter.project_slug | to_camel}} {{cookiecutter.project_slug }}_;

};

}  // namespace {{cookiecutter.project_slug }}
