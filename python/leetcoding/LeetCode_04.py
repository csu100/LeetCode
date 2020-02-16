#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/1/12 21:32
# @Author  : Zheng guoliang
# @Site    : 
# @File    : LeetCode_04.py
# @Software: PyCharm
"""
1.需求功能：
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
2.实现过程：


"""

class Solution:
    def findMedianSortedArrays(self,nums1,nums2):
        if len(nums1)==0:
            return self.findMedian(nums2)
        if len(nums2)==0:
            return self.findMedian(nums1)
        nums1.extend(nums2)
        nums1.sort()
        return self.findMedian(nums1)


    def findMedian(self,nums):
        if len(nums)&1==1:
            return nums[len(nums)>>1]
        else:
            return (nums[len(nums)>>1]+nums[(len(nums)>>1)-1])/2.0


if __name__ == '__main__':
    solution =Solution()
    nums1=[1,2,4]
    nums2=[1,3,5]
    result = solution.findMedianSortedArrays(nums1,nums2)

