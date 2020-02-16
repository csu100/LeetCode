#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/31 17:28
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/implement-queue-using-stacks/submissions/
使用栈实现队列的下列操作：
    push(x) -- 将一个元素放入队列的尾部。
    pop() -- 从队列首部移除元素。
    peek() -- 返回队列首部的元素。
    empty() -- 返回队列是否为空。

2.实现过程：


"""


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._myqueue = []

    def push(self, x):
        """
        Push element x to the back of queue.
        """
        if len(self._myqueue) < 1:
            self._myqueue.append(x)
        else:
            temp = self._myqueue[::-1]
            temp.append(x)
            self._myqueue = temp[::-1]

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self._myqueue) < 1:
            raise AttributeError("queue is empty!")
        return self._myqueue.pop()

    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self._myqueue) < 1:
            raise AttributeError("queue is empty!")
        return self._myqueue[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return True if len(self._myqueue) < 1 else False
