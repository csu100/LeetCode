#ifndef CLASS2_H_INCLUDED
#define CLASS2_H_INCLUDED


#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class My_stack  // 利用队列实现栈
{
public:
    void push(int x);
    int top();
    int pop();
    bool empty();
private:
    queue<int> data;
};

class My_queue  // 利用栈实现队列
{
public:
    void push(int x);
    int peek();
    int pop();
    bool empty();
private:
    stack<int> data;
    stack<int> output;
    void adjust();
};

class MinStack  // 包含min函数的栈
{
public:
    void push(int x);
    int pop();
    int top();
    int getMin();
private:
    stack<int> data;
    stack<int> MinD;
};

class valid_order //判断是否为合法序列
{
public:
    bool check_is_valid_order(queue<int>& Q);
};

class Calculate_N5  // 简易的计算器
{
public:
    int calculate(string str);
private:
    vector<int> calculates(string str,int i);
    void add_num(deque<string>& data,string num);
    int get_num(deque<string>& data);
    int string_to_int(string str);
};

class FindKth_N6  //数组中第K大的数
{
public:
    int findKthLargest(vector<int>& nums,int k);
};

class FindMedian_N6 // 寻找中位数
{
public:
    void addNum(int num);
    double findMedian();
private:
    priority_queue<int,vector<int>,greater<int> > Qmin;//存大数
    priority_queue<int,vector<int>,less<int> > Qmax;//存小数
};

#endif // CLASS2_H_INCLUDED
