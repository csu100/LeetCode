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

class My_stack  // ���ö���ʵ��ջ
{
public:
    void push(int x);
    int top();
    int pop();
    bool empty();
private:
    queue<int> data;
};

class My_queue  // ����ջʵ�ֶ���
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

class MinStack  // ����min������ջ
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

class valid_order //�ж��Ƿ�Ϊ�Ϸ�����
{
public:
    bool check_is_valid_order(queue<int>& Q);
};

class Calculate_N5  // ���׵ļ�����
{
public:
    int calculate(string str);
private:
    vector<int> calculates(string str,int i);
    void add_num(deque<string>& data,string num);
    int get_num(deque<string>& data);
    int string_to_int(string str);
};

class FindKth_N6  //�����е�K�����
{
public:
    int findKthLargest(vector<int>& nums,int k);
};

class FindMedian_N6 // Ѱ����λ��
{
public:
    void addNum(int num);
    double findMedian();
private:
    priority_queue<int,vector<int>,greater<int> > Qmin;//�����
    priority_queue<int,vector<int>,less<int> > Qmax;//��С��
};

#endif // CLASS2_H_INCLUDED
