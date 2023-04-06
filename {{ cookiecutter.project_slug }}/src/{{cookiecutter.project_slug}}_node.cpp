#include "{{cookiecutter.project_slug}}_node.hpp"

namespace {{ cookiecutter.project_slug }}
{
{{cookiecutter.project_slug | to_camel }}Node::{{cookiecutter.project_slug | to_camel }}Node(ros::NodeHandle &nh) :
 nh_{nh},
 pong_publisher_(nh.advertise<std_msgs::String> ("pong", 10)),
 ping_subscriber_(nh_.subscribe ("ping", 10, &{{cookiecutter.project_slug | to_camel }}Node::handle_ping_msg, this)),
 {{ cookiecutter.project_slug }}_([this](const std::string &pong){publish_pong_msg(pong);})
{
}

void
{{cookiecutter.project_slug | to_camel }}Node::handle_ping_msg (const std_msgs::String &msg)
{
  {{cookiecutter.project_slug}}_.handlePing (msg.data);
}

void
{{cookiecutter.project_slug | to_camel }}Node::publish_pong_msg (const std::string &pong)
{
  std_msgs::String msg;
  msg.data = pong;
  pong_publisher_.publish(msg);
}
} // namespace  {{ cookiecutter.project_slug }}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "dep1_node");
    ros::NodeHandle       nh;
    [[maybe_unused]] auto monitor_node = {{cookiecutter.project_slug}}::{{cookiecutter.project_slug | to_camel }}Node{nh};
    ros::spin();
    return 0;
}