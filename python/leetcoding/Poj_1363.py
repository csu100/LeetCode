#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/1 9:31
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 http://poj.org/problem?id=1363

2.实现过程：


"""
from collections import deque


class Solution:
    def check_is_valid_order(self, order):
        data = []
        n = len(order)
        for i in range(1, n + 1):
            data.append(i)
            while len(data) > 0 and order[-1] == data[-1]:
                data.pop()
                order.pop()
        if len(data) > 0:
            return False
        else:
            return True


if __name__ == '__main__':
    arr=[3,1,2,4,5]
    order = deque()
    for i in arr:
        order.appendleft(i)

    solution = Solution()
    flag=solution.check_is_valid_order(order)
    print(flag)
