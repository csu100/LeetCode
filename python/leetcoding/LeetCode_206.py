#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/24 14:42
# @Author  : Zheng guoliang
# @Site    :
# @File    : LeetCode_206.py
# @Software: PyCharm
"""
1.需求功能：
  https://leetcode.com/problems/reverse-linked-list/description/
2.实现过程：


"""
from leetcoding.ListNode import ListNode


class Solution:
    def reverseList(self, head):
        if head is None or head.next is None:
            return head
        head_node = None
        while head:
            node = head.next
            head.next = head_node
            head_node = head
            head = node
        return head_node


def printList(head):
    while head:
        print(head.val)
        head = head.next


if __name__ == '__main__':
    a1 = ListNode(1)
    a2 = ListNode(2)
    a3 = ListNode(3)
    a4 = ListNode(4)
    a5 = ListNode(5)
    a1.next = a2
    a2.next = a3
    a3.next = a4
    a4.next = a5

    solution = Solution()
    result = solution.reverseList(a1)
    printList(result)
