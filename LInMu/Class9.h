#ifndef CLASS9_H_INCLUDED
#define CLASS9_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>


using namespace std;

class Class9_N1  // 跳楼梯
{
public:
    int climbStairs(int n);
};

class Class9_N2  // 打家劫舍
{
public:
    int rob(vector<int>& nums);
};

class Class9_N3  // 最大连续子数组和
{
public:
    int maxSubArray(vector<int>& nums);
};

class Class9_N4  // 找零钱
{
public:
    int coinChange(vector<int>& coins,int amount);
};

class Class9_N5  // 顶端到低端各数字和最小的路径和
{
public:
    int minimunTotal(vector<vector<int> >& triangle);
};

class Class9_N6  // 最长上升子序列
{
public:
    int lengthOfLIS(vector<int>& nums);
private:
    int find_binary(vector<int> dp,int target);
};

class Class9_N7  // 最小路径和
{
public:
    int minPathSum(vector<vector<int> >& grid);
};

class Class9_N8 // 地牢游戏
{
public:
    int calculateMinimunHP(vector<vector<int> >& dungeon);
};

#endif // CLASS9_H_INCLUDED
