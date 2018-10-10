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


class Class3_N1 //���ǹ�
{
public:
    int findContentChildren(vector<int>& g,vector<int>& s);
};

class Class3_N2 //ҡ�����е�������еĳ���
{
public:
    int wiggleMaxLength(vector<int>& nums);
};

class Class3_N3 // �Ƴ�K�����֣������С�Ŀ���������
{
public:
    string removeKdigits(string num,int k);
};

class Class3_N4
{
public:
    bool canJump(vector<int>& nums);//�Ƿ��ܹ���Ծ�����һ��λ��Ԫ��
    int jump(vector<int>& nums);//������Ծ����
};


class Class3_N5 // ����������⣬������Ҫ���ٸ�������
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
