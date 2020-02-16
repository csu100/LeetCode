#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/30 12:56
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/copy-list-with-random-pointer/
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。
2.实现过程：


"""


class Node:
    def __init__(self, x, next=None, random=None):
        self.val = x
        self.next = next
        self.random = random


class Soultion:
    def copyRandomList(self, head):
        if head is None or head.next is None:
            return head
        node_map = {}
        curr = head
        while curr is not None:
            node_map[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        while curr is not None:
            node_map[curr].next = node_map.get(curr.next)
            node_map[curr].random = node_map.get(curr.random)
            curr = curr.next
        return node_map[head]
