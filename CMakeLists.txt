cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(2.24-1 CD16.cpp) #求最大子矩阵的大小
###########################################################
add_executable(3.20-1 CD5_.cpp)	#设计getMin功能的栈
#add_executable(3.20-2 CD6_.cpp)	#由两个栈组成的队列
add_executable(3.20-3 CD7_.cpp) #用递归函数和栈逆序一个栈

add_executable(4.5 CD5__.cpp) #设计getMin功能的栈
add_executable(4.6 CD6__.cpp)	#由两个栈组成的队列
add_executable(4.7 CD7__.cpp) #用递归函数和栈逆序一个栈
add_executable(4.8 CD100__.cpp) #猫狗队列
add_executable(4.9 CD13__.cpp) #用一个栈实现另一个栈的排序
add_executable(4.10 CD22__.cpp) #用栈来求解汉诺塔问题
add_executable(4.11 CD22___.cpp) #用递归来求解汉诺塔问题
add_executable(4.12 CD15__.cpp) #生成窗口最大值数组
add_executable(4.13 OR34__.cpp) #构造MaxTree
add_executable(4.14-1 CD48__.cpp) #打印两个升序链表的公共部分
add_executable(4.14-2 CD49__.cpp) #在链表中删除倒数第K个节点
add_executable(4.15 CD16__.cpp) #求最大子矩阵的大小
add_executable(4.16 CD18.cpp) #最大值减去最小值小于或等于num的子数组数
add_executable(4.17 CD106.cpp) #删除链表的中间节点

add_executable(4.23 CD107.cpp) #反转单向链表和双向链表
add_executable(4.24 CD108.cpp) #反转部分单向链表
add_executable(4.25 CD109.cpp) #环形链表的约瑟夫问题
add_executable(4.26_01 CD109_.cpp) #环形链表的约瑟夫问题 另一种写法 更符合我最初的设想
add_executable(4.26_02 CD110.cpp) #环形链表的约瑟夫问题 进阶
add_executable(4.27_01 CD111.cpp) #判断一个链表是否为回文结构 全压入栈
add_executable(4.27_02 CD111_.cpp) #判断一个链表是否为回文结构 一半压入栈
add_executable(4.28 CD112.cpp) #判断一个链表是否为回文结构 进阶
add_executable(4.29 CD113.cpp) #将单向链表按某值划分为左边小，中间相等，右边大的形式
add_executable(4.30 CD113_.cpp) #将单向链表按某值划分为左边小，中间相等，右边大的形式 进阶
add_executable(5.1 JZ35.cpp) #复制含有随机指针的链表
add_executable(5.2 JZ35_.cpp) #复制含有随机指针的链表 方法2
add_executable(5.3_01 CD114.cpp) #两个链表生成相加链表 int类型最大只能表示10位数，会溢出，行不通
add_executable(5.3_02 CD114_.cpp) #两个链表生成相加链表 
add_executable(5.4 CD114__.cpp) #两个链表生成相加链表 方法2
add_executable(5.5_01 NC4.cpp) #判断链表中是否有环 方法1 哈希表
add_executable(5.5_02 NC4_.cpp) #判断链表中是否有环 方法2 快慢指针
add_executable(5.5_03 NC4__.cpp) #判断链表中是否有环,且返回进入环的头节点 快慢指针
add_executable(5.6_01 lc_160.cpp) #判断两个无环链表是否相交 方法1 哈希表
add_executable(5.6_02 lc_160_.cpp) #判断两个无环链表是否相交 方法2 快慢指针


