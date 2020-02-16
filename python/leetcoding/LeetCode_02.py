#!/usr/bin/env python
#-*- coding:utf-8 -*-
# author:  zgl_csu
# name:    LeetCode_No02 
# datetime:2020/1/1 22:24
# software:PyCharm
"""
1.需求功能：


2.实现过程：


"""

class ListNode:
    def __init__(self,x):
        self.val =x
        self.next=None


class Solution:
    def addTwoNumbers(self,l1,l2):
        if l1==None:
            return l2
        if l2==None:
            return l1
        result = ListNode(0)
        res_next=result
        flag=0
        sum_number=0
        while l1 != None and l2 !=None:
            sum_number = l1.val + l2.val + flag
            flag = sum_number // 10
            sum_number = sum_number % 10
            res_next.next = ListNode(sum_number)
            res_next=res_next.next
            l1=l1.next
            l2=l2.next
        l1 = l1 if l1!= None else l2
        while l1!=None:
            sum_number =l1.val +flag
            flag = sum_number // 10
            sum_number = sum_number %10
            res_next.next=ListNode(sum_number)
            res_next = res_next.next
            l1=l1.next
        if flag!=0:
            res_next.next = ListNode(flag)
        return result.next
















