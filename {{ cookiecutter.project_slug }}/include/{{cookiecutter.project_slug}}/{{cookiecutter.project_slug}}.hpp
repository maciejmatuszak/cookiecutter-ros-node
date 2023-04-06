#pragma once

#include <functional>
#include <ros/time.h>

namespace {{cookiecutter.project_slug}}
{

/**
 * @brief business logic class
 *
 */
class {{cookiecutter.project_slug | to_camel }}
{

  private:
    // type for event raised by {{cookiecutter.project_slug | to_camel }}
    using PongCallBackT = std::function<void(const std::string& pong)>;

  public:
    explicit {{cookiecutter.project_slug | to_camel }}(PongCallBackT pongCallBack);

    void handlePing(const std::string &ping);

  private:
    PongCallBackT pongCallBack_;
};
}  // namespace {{cookiecutter.project_slug}}
