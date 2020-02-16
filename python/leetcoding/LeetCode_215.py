#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/2 21:58
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/kth-largest-element-in-an-array/submissions/
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
2.实现过程：


"""
import heapq


class Solution:
    def findKthLargest(self, nums, k):
        return heapq.nlargest(k,nums)[-1]

    def findKthLargest1(self, nums, k):
        if nums is None or len(nums) < k:
            return 0
        index = 0
        while index < k:
            self.modify(nums, index)
            index += 1
        while index < len(nums):
            if nums[0] < nums[index]:
                nums[0], nums[index] = nums[index], nums[0]
                self.heapinsert(nums, 0, k)
            index += 1
        return nums[0]

    def heapinsert(self, nums, index, length):
        left = 2 * index + 1
        while left < length:
            lagest = left + 1 if left + 1 < length and nums[left + 1] < nums[left] else left
            lagest = lagest if nums[lagest] < nums[index] else index
            if lagest == index:
                break
            nums[index], nums[lagest] = nums[lagest], nums[index]
            index = lagest
            left = 2 * index + 1

    def modify(self, nums, index):
        while nums[int((index - 1) / 2)] > nums[index]:
            nums[int((index - 1) / 2)], nums[index] = nums[index], nums[int((index - 1) / 2)]
            index = int((index - 1) / 2)


if __name__ == '__main__':
    solution = Solution()
    arr = [3, 2, 1, 5, 6, 4]
    k = 2
    result = solution.findKthLargest(arr, k)
    print(result)
