#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/31 9:35
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/merge-k-sorted-lists/submissions/
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
2.实现过程：


"""
from leetcoding.ListNode import ListNode


class Solution:
    def mergeKLists(self, lists):
        if lists is None or len(lists) < 1:
            return None
        return self.mergeLists(lists, 0, len(lists) - 1)

    def mergeLists(self, lists, L, R):
        if L >= R:
            return lists[L]
        mid = L + ((R - L) >> 1)
        listA = self.mergeLists(lists, L, mid)
        listB = self.mergeLists(lists, mid + 1, R)
        return self.mergeTwoLists(listA, listB)

    def mergeTwoLists(self, listA, listB):
        result = ListNode(0)
        head = result
        while listA is not None and listB is not None:
            if listA.val < listB.val:
                head.next = ListNode(listA.val)
                listA = listA.next
            else:
                head.next = ListNode(listB.val)
                listB = listB.next
            head = head.next
        if listA is not None:
            head.next = listA
        if listB is not None:
            head.next = listB
        return result.next
