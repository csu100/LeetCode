#ifndef CLASS3_H_INCLUDED
#define CLASS3_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;


class Class3_N1 //分糖果
{
public:
    int findContentChildren(vector<int>& g,vector<int>& s);
};

class Class3_N2 //摇摆序列的最长子序列的长度
{
public:
    int wiggleMaxLength(vector<int>& nums);
};

class Class3_N3 // 移除K个数字，获得最小的可能新数字
{
public:
    string removeKdigits(string num,int k);
};

class Class3_N4
{
public:
    bool canJump(vector<int>& nums);//是否能够跳跃到最后一个位置元素
    int jump(vector<int>& nums);//最少跳跃步数
};


class Class3_N5 // 射击气球问题，至少需要多少个弓箭手
{
public:
    int findMinArrowShots(vector<pair<int,int> >&points);
};

class Class3_N6
{
public:
    int get_mininum_step(int L,int P,vector<pair<int,int> >& step);
};

#endif // CLASS3_H_INCLUDED
