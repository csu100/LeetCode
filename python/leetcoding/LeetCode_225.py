#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/31 10:37
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/implement-stack-using-queues/
使用队列实现栈的下列操作：
    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空

2.实现过程：


"""
from queue import Queue


class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = Queue()

    def push(self, x):
        """
        Push element x onto stack.
        """
        if self.stack.empty():
            self.stack.put(x)
        else:
            temp = Queue()
            temp.put(x)
            while not self.stack.empty():
                temp.put(self.stack.get())
            while not temp.empty():
                self.stack.put(temp.get())

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.stack.empty():
            raise AttributeError("stack is empty!")
        return self.stack.get()

    def top(self):
        """
        Get the top element.
        """
        if self.stack.empty():
            raise AttributeError("stack is empty!")
        a=self.stack.get()
        self.push(a)
        return a

    def empty(self):
        """
        Returns whether the stack is empty.
        """
        return True if self.stack.empty() else False


if __name__ == '__main__':
    mystack = MyStack()
    print(mystack.empty())
    for i in range(4):
        mystack.push(i * i)
    print(mystack.empty())

    while not mystack.empty():
        print(mystack.pop())
