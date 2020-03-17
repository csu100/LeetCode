#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/3/4 21:58
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_51_n_queens.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/n-queens/
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
2.实现过程：


"""
import copy

class Solution:
    def solveNQueens(self, n):
        if n < 1:
            return []
        if n == 1:
            return [['Q']]
        result = []
        queen_q = [['.'] * n for i in range(n)]
        mark = [[0] * n for i in range(n)]
        self.get_all_queen(0, n, queen_q, mark, result)
        return result

    def put_down_the_queen(self, x, y, mark):
        dx = [-1, -1, 0, 1, 1, 1, 0, -1]
        dy = [0, 1, 1, 1, 0, -1, -1, -1]
        mark[x][y] = 1
        for i in range(1, len(mark)):
            for j in range(0, 8):
                new_x = x + i * dx[j]
                new_y = y + i * dy[j]
                if new_x >= 0 and new_x < len(mark) and new_y >= 0 and new_y < len(mark[0]):
                    mark[new_x][new_y] = 1

    def get_all_queen(self, k, n, queen_q, mark, result):
        if k == n:
            result.append([''.join(q) for q in queen_q])
            return
        for i in range(0, n):
            if mark[k][i] == 0:
                temp_mark = copy.deepcopy(mark)
                queen_q[k][i] = 'Q'
                self.put_down_the_queen(k, i, mark)
                self.get_all_queen(k + 1, n, queen_q, mark, result)
                mark = temp_mark
                queen_q[k][i] = '.'

    def solveNQueens1(self, n):
        res = []
        if n == 0: return res

        # row为当前行，col为不可再使用的列，master为不可再使用的主对角线，slave为不可再使用的副对角线
        def dfs(row, col, master, slave, cur_res):
            if row == n:
                res.append(["." * cur + "Q" + "." * (n - cur - 1) for cur in cur_res])
                return
            for i in range(n):
                if (i not in col) and (i + row not in slave) and (i - row not in master):
                    dfs(row + 1, col | {i}, master | {i - row}, slave | {i + row}, cur_res + [i])

        dfs(0, set(), set(), set(), [])
        return res


if __name__ == '__main__':
    ss = Solution()
    result =ss.solveNQueens1(4)
    print(result)
