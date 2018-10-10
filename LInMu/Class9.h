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

class Class9_N1  // ��¥��
{
public:
    int climbStairs(int n);
};

class Class9_N2  // ��ҽ���
{
public:
    int rob(vector<int>& nums);
};

class Class9_N3  // ��������������
{
public:
    int maxSubArray(vector<int>& nums);
};

class Class9_N4  // ����Ǯ
{
public:
    int coinChange(vector<int>& coins,int amount);
};

class Class9_N5  // ���˵��Ͷ˸����ֺ���С��·����
{
public:
    int minimunTotal(vector<vector<int> >& triangle);
};

class Class9_N6  // �����������
{
public:
    int lengthOfLIS(vector<int>& nums);
private:
    int find_binary(vector<int> dp,int target);
};

class Class9_N7  // ��С·����
{
public:
    int minPathSum(vector<vector<int> >& grid);
};

class Class9_N8 // ������Ϸ
{
public:
    int calculateMinimunHP(vector<vector<int> >& dungeon);
};

#endif // CLASS9_H_INCLUDED
