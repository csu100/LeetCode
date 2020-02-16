#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/30 11:16
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/linked-list-cycle-ii/
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
2.实现过程：


"""


class Soulution:
    def detectCycle(self, head):
        if head is None:
            return None
        fast = head
        slow = head
        while fast is not None:
            fast = fast.next
            slow = slow.next
            if fast is None:
                return None
            fast = fast.next
            if fast == slow:
                break
        if fast is None:
            return None
        fast = head
        while fast is not None:
            if fast == slow:
                return fast
            fast = fast.next
            slow = slow.next
        return None
