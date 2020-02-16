#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/30 10:46
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/?utm_source=LCUS&utm_medium=ip_redirect_q_uns&utm_campaign=transfer2china
求两个相交链表的起始交点。
2.实现过程：


"""

from leetcoding.ListNode import ListNode


class Solution:
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None
        new_headA, len_headA = self.getListLength(headA)
        new_headB, len_headB = self.getListLength(headB)
        if new_headA != new_headB:
            return None
        if len_headA < len_headB:
            new_headA = headB
            new_headB = headA
            len_headA, len_headB = len_headB, len_headA
        else:
            new_headA = headA
            new_headB = headB
        while len_headB != len_headA and new_headA is not None:
            new_headA = new_headA.next
            len_headA -= 1
        while new_headA and new_headB:
            if new_headA == new_headB:
                return new_headA
            new_headA = new_headA.next
            new_headB = new_headB.next
        return None

    def getListLength(self, head):
        n = 0
        while head.next is not None:
            head = head.next
            n += 1
        return head, n


if __name__ == '__main__':
    a1= ListNode(1)
    a2= ListNode(2)
    a3= ListNode(3)
    a4= ListNode(4)
    a5= ListNode(5)
    a6= ListNode(6)

    b1=ListNode(10)
    b2=ListNode(20)
    b3=ListNode(30)
    a1.next =a2
    a2.next =a3
    a3.next =a4
    a4.next =a5
    b1.next=b2
    b2.next =b3
    b3.next =a4

    solution = Solution()
    result = solution.getIntersectionNode(a1,b1)
    if result is not None:
        print(result.val)
    else:
        print("None")

