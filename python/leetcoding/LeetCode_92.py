#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/26 13:50
# @Author  : Zheng guoliang
# @Site    : 
# @File    : LeetCode_92.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/reverse-linked-list-ii/submissions/
2.实现过程：


"""
from leetcoding.ListNode import ListNode


class Solution:
    def reverseBetween(self, head, m, n):
        if head is None or m > n:
            return None
        result = head
        pre_head = None
        mn = n - m + 1
        while head and m > 1:
            pre_head = head
            head = head.next
            m -= 1
        modefiy_head = None
        modefiy_headpre = head
        while head and mn > 0:
            node = head.next
            head.next = modefiy_head
            modefiy_head = head
            head = node
            mn -= 1
        if modefiy_headpre is not None:
            modefiy_headpre.next = head
        if pre_head is not None:
            pre_head.next = modefiy_head
        else:
            result = modefiy_head
        return result
