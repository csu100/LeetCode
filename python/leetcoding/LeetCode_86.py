#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/30 12:47
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/partition-list/submissions/
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
2.实现过程：


"""
from leetcoding.ListNode import ListNode


class Solution:
    def partition(self, head, x: int):
        if head is None or head.next is None:
            return head
        small = ListNode(0)
        large = ListNode(0)
        small_head = small
        large_head = large
        while head is not None:
            if head.val < x:
                small_head.next = ListNode(head.val)
                small_head = small_head.next
            else:
                large_head.next = ListNode(head.val)
                large_head = large_head.next
            head = head.next
        small_head.next = large.next
        return small.next
