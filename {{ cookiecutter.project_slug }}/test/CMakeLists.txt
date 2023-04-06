
catkin_add_gtest(${PROJECT_NAME}_tests
    {{cookiecutter.project_slug}}_main.cpp
    {{cookiecutter.project_slug}}_test.cpp
    )

target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
    ${catkin_INCLUDE_DIRS}
    )

target_link_libraries(${PROJECT_NAME}_tests
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
    ${GTEST_LIBRARIES}
    )
