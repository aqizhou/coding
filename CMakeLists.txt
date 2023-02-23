cmake_minimum_required(VERSION 3.24)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(2.20-1 CD5.cpp) #设计getMin功能的栈
add_executable(2.20-2 CD6.cpp) #由两个栈组成的队列
add_executable(2.20-3 CD7.cpp) #用递归函数和栈逆序一个栈

add_executable(2.21-1 CD100.cpp) #猫狗队列

add_executable(2.22-1 CD13.cpp) #用一个栈实现另一个栈的排序
add_executable(2.22-2 CD22.cpp) #用递归和栈分别求解汉诺塔问题
add_executable(2.22-3 CD15.cpp) #生成窗口最大值数组

add_executable(2.23-1 OR34.cpp) #构造MaxTree
add_executable(2.23-2 CD48.cpp) #打印两个升序链表的公共部分
add_executable(2.23-3 CD49.cpp) #在链表中删除倒数第K个节点

