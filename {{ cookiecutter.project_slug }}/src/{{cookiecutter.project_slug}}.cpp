#include "{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}.hpp"

namespace {{cookiecutter.project_slug}}
{

{{cookiecutter.project_slug | to_camel }}::{{cookiecutter.project_slug | to_camel }}(PongCallBackT pongCallBack):
  pongCallBack_(std::move(pongCallBack))
{
}

void {{cookiecutter.project_slug | to_camel }}::handlePing(const std::string &ping)
{

  auto reply = ping + " -> pong";
  pongCallBack_(reply);
}

}  // namespace {{cookiecutter.project_slug}}
