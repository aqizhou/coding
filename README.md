 - CD:
 https://www.nowcoder.com/exam/oj/ta?page=1&pageSize=50&search=&tpId=101&type=101
 - OR34:
 https://www.nowcoder.com/practice/a502c7c3c65e41fdaf65eec9e0654dcb?tpId=182&tqId=34760&ru=/exam/oj
 - JZ35:
 https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&ru=/exam/oj
 - NC4:
 https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9?tpId=196&tqId=37048&ru=/exam/oj
 - lc:
 https://leetcode.cn/problems/intersection-of-two-linked-lists/
 ---
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

###########################################################

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

add_executable(5.7_01 lc_160_plus.cpp) #判断两个有环链表是否相交 方法1 哈希表 未测试

add_executable(5.7_02 lc_160_plus_.cpp) #判断两个有环链表是否相交 方法2 双指针 未测试

add_executable(5.8 CD119.cpp) #将单链表的每K个节点之间逆序 方法1 额外使用栈

add_executable(5.9 CD119_.cpp) #将单链表的每K个节点之间逆序 方法2 不使用额外的栈 多个指针

add_executable(5.10_01 CD137.cpp) #删除无序链表中值重复出现的节点 方法1 哈希表

add_executable(5.10_02 CD137_.cpp) #删除无序链表中值重复出现的节点 方法2 类似选择排序 时间复杂度有点高 过不了

add_executable(5.11_01 CD138.cpp) #在链表中删除指定值的节点 方法1 辅助栈

add_executable(5.11_02 CD138_.cpp) #在链表中删除指定值的节点 方法2 双指针

add_executable(5.12 CD156.cpp) #将搜索二叉树转换成双向链表 方法1 辅助队列

add_executable(5.13 CD156_.cpp) #将搜索二叉树转换成双向链表 方法2 双指针

add_executable(5.14 CD139.cpp) #单链表的选择排序

add_executable(5.15_01 CD157.cpp) #一种怪异的节点删除方式

add_executable(5.15_02 CD158.cpp) #向有序的环形单链表中插入新节点

add_executable(5.16_01 CD159.cpp) #合并两个有序的单链表

add_executable(5.16_02 CD160.cpp) #按照左右半区的方式重新组合单链表

add_executable(5.17 CD161.cpp) #实现二叉树先序，中序和后序遍历 递归

add_executable(5.18 CD161_.cpp) #实现二叉树先序，中序和后序遍历 非递归

add_executable(5.19 CD161__.cpp) #实现二叉树先序，中序和后序遍历 非递归 统一迭代法

add_executable(5.20_01 lc_102.cpp) #二叉树的层序遍历

add_executable(5.20_02 lc_107.cpp) #二叉树的层序遍历II

add_executable(5.20_03 lc_199.cpp) #二叉树的右视图

add_executable(5.20_04 lc_637.cpp) #二叉树的层平均值

add_executable(5.20_05 lc_429.cpp) #N叉树的层序遍历

add_executable(5.20_06 lc_515.cpp) #在每个树行中找最大值

add_executable(5.20_07 lc_116.cpp) #填充每个节点的下一个右侧节点指针

add_executable(5.20_08 lc_117.cpp) #填充每个节点的下一个右侧节点指针II

add_executable(5.20_09 lc_104.cpp) #二叉树的最大深度

add_executable(5.20_10 lc_111.cpp) #二叉树的最小深度

add_executable(5.21_01 lc_226.cpp) #翻转二叉树 前序遍历

add_executable(5.21_02 lc_226_.cpp) #翻转二叉树 后序遍历

add_executable(5.21_03 lc_617.cpp) #合并二叉树 前序遍历 递归

add_executable(5.21_04 lc_617_.cpp) #合并二叉树 层序遍历

add_executable(5.22_01 lc_101.cpp) #对称二叉树 后序遍历 递归

add_executable(5.22_02 lc_101_.cpp) #对称二叉树 后序遍历 迭代法

add_executable(5.22_03 lc_100.cpp) #相同的树 后序遍历 递归

add_executable(5.22_04 lc_100_.cpp) #相同的树 后序遍历 迭代法

add_executable(5.22_05 lc_572.cpp) #另一个树的子树 后序遍历 递归

add_executable(5.22_06 lc_572_.cpp) #另一个树的子树 后序遍历 迭代法


