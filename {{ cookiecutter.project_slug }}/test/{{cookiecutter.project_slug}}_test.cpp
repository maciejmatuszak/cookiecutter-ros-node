#include "{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}.hpp"
#include <gtest/gtest.h>

using namespace {{cookiecutter.project_slug}};

class {{cookiecutter.project_slug | to_camel }}Test : public ::testing::Test
{
  protected:
    std::shared_ptr<{{cookiecutter.project_slug | to_camel }}>  test_obj_;
    std::string  pong_reply_;
    uint32_t     pong_calls_ = 0;

    virtual void SetUp()
    {
      test_obj_ = std::make_shared<{{cookiecutter.project_slug | to_camel }}>(
          [this](const std::string& msg)
          {
            pong_calls_++;
            pong_reply_ = msg;
          }
      );
      pong_calls_ = 0;
      pong_reply_ = "";
    }

    virtual void TearDown()
    {
        test_obj_.reset();
    }
};

TEST_F({{cookiecutter.project_slug | to_camel }}Test , Init)
{
  EXPECT_EQ(pong_calls_, 0);
  EXPECT_EQ(pong_reply_, "");
}

TEST_F({{cookiecutter.project_slug | to_camel }}Test , PingPong)
{
  std::string ping_msg = "ping";


  test_obj_->handlePing(ping_msg);
  test_obj_->handlePing(ping_msg);

  EXPECT_EQ(pong_calls_, 2);
  EXPECT_EQ(pong_reply_, "ping -> pong");
}