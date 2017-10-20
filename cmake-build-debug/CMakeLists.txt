cmake_minimum_required(VERSION 3.8)
project(Lab5_Stacks_And_Queues_Postfix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ../main.cpp ../node.cpp ../node.h ../stack.cpp ../stack.h ../queue.cpp ../queue.h ../expression.cpp ../expression.h)
add_executable(Lab5_Stacks_And_Queues_Postfix ${SOURCE_FILES})