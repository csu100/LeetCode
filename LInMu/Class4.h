#ifndef CLASS4_H_INCLUDED
#define CLASS4_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>


using namespace std;

class Class4_N1 // 无重复元素的子集
{
public:
    vector<vector<int> > subsets(vector<int>& nums);
    vector<vector<int> > subsets1(vector<int>& nums);
private:
    void subsets(vector<int>& nums,vector<vector<int> >& result,vector<int>& item,int n);
};

class Class4_N1_b  //有重复元素
{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums);//利用位运算解决子集问题
    vector<vector<int> > combinationSum2(vector<int>& nums,int target); //有重复元素，求目标和为target 子集
};

class Class4_N2 // 生产合法的括号
{
public:
    vector<string> generateParenthesis(int n);
private:
    void generateParenthesis(vector<string>& result,string str,int left,int right);
};


class Class4_N3  // N皇后问题
{
public:
    vector<vector<string> > solveNQueen(int n);
private:
    void putQueen(vector<vector<int> >& mark,int x,int y);
    void sloveNQueen(vector<vector<int> >& mark,vector<vector<string> >& result,vector<string>& Queen,int n,int m);
};

class Class4_N4  //逆序对问题
{
public:
    vector<int> countSmaller(vector<int>& nums);

private:
    void countSmaller(vector<pair<int,int> >& vec_p,vector<int>& result,int L,int R);
    void mergers(vector<pair<int,int> >& vec_p,vector<int>& result,int L,int mid,int R);
};

class Class4_N4_a  //逆序对问题
{
public:
    int countSmaller(vector<int>& nums);

private:
    int countSmaller(vector<int>& nums,int L,int R);
    int mergers(vector<int>& nums,int L,int mid,int R);
};

#endif // CLASS4_H_INCLUDED
