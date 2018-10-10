#ifndef CLASS6_H_INCLUDED
#define CLASS6_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include "Class5.h"

using namespace std;


class Class6_N1 //����λ��(���ظ�Ԫ��)
{
public:
    int searchInsert(vector<int>& nums,int target);
};

class Class6_N2 // �������
{
public:
    vector<int> searchRange(vector<int>& nums,int target);
private:
    int searchLeft(vector<int>& nums,int target,int L,int R);
    int searchRight(vector<int>& nums,int target,int L,int R);
};

class Class6_N3 // ��ת��������
{
public:
    int Search(vector<int>& nums,int target);
};


class Class6_N4_
{
public:
    void BST_insert(TreeNode* root,TreeNode* target);
    bool BST_search(TreeNode* root,int value);
    void pre_Tree(TreeNode* root);
private:
    void pre_Tree(TreeNode* root,int layer);
};


class Class6_N4 // �������ı��������
{
public:
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
private:
    void serialize(TreeNode* root,string& str);
    TreeNode* deserialize(queue<string>& Q);
    int string_to_int(string str);

};


#endif // CLASS6_H_INCLUDED
