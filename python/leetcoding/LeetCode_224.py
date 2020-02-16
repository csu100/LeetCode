#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/1 12:41
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : {NAME}.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/basic-calculator/
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
2.实现过程：


"""


class Solution:
    index = 0

    def calculate(self, s):
        if len(s) < 1:
            return 0
        self.index = 0
        return self.helpcalculate(s)

    def helpcalculate(self, s):
        number = 0
        sign = 1
        result = 0
        while self.index < len(s):
            chracter = s[self.index]
            self.index += 1
            if chracter == ' ':
                continue
            if chracter >= '0' and chracter <= '9':
                number = number * 10 + int(chracter)
            elif chracter == '(':
                number = self.helpcalculate(s)
            elif chracter == ')':
                break
            else:
                result += number * sign
                number = 0
                if chracter == '+':
                    sign = 1
                elif chracter == '-':
                    sign = -1
        result += number * sign
        return result


if __name__ == '__main__':
    solution = Solution()
    ss = "(1+((4+5+2))-3)+(6+8)"
    dd = solution.calculate(ss)
    print(dd)
