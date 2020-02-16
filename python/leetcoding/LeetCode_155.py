#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/1 9:19
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/min-stack/submissions/
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
    push(x) -- 将元素 x 推入栈中。
    pop() -- 删除栈顶的元素。
    top() -- 获取栈顶元素。
    getMin() -- 检索栈中的最小元素。

2.实现过程：


"""


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.mindata = []

    def push(self, x):
        if len(self.data) < 1:
            self.data.append(x)
            self.mindata.append(x)
        else:
            if self.mindata[-1] >= x:
                self.mindata.append(x)
            self.data.append(x)

    def pop(self):
        if len(self.data) < 1:
            raise AttributeError("stack is empty!")
        if self.data[-1] == self.mindata[-1]:
            self.mindata.pop()
        self.data.pop()

    def top(self):
        if len(self.data) < 1:
            raise AttributeError("stack is empty!")
        return self.data[-1]

    def getMin(self):
        if len(self.mindata) < 1:
            raise AttributeError("min stack is empty!")
        return self.mindata[-1]
