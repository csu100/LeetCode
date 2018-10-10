#ifndef CLASS5_H_INCLUDED
#define CLASS5_H_INCLUDED


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

struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Class5_N1  //�������ĵݹ����
{
public:
   void pre_Tree(TreeNode* head);
   void zhong_Tree(TreeNode* head);
   void hou_Tree(TreeNode* head);
private:
    void pre_Tree(TreeNode* head,int layer);
    void zhong_Tree(TreeNode* head,int layer);
    void hou_Tree(TreeNode* head,int layer);
};

class Class5_N1_a  //�������ķǵݹ����
{
public:
   void pre_Tree(TreeNode* head);
   void zhong_Tree(TreeNode* head);
   void hou_Tree(TreeNode* head);
};

class Class5_N1_b  //�������ķǵݹ���� // morris����
{
public:
   void pre_Tree(TreeNode* head);
   void zhong_Tree(TreeNode* head);
   void hou_Tree(TreeNode* head);
};


class Class5_N1_ // ���������������ҳ����дӸ��ڵ㵽Ҷ�ڵ��·���ۼӺ�Ϊsum��·��
{
public:
    vector<vector<int> > pathSum(TreeNode* root,int sum);
private:
    void pathSum(TreeNode* root,vector<int>& path,vector<vector<int> >& result,int sum,int&  target);
};

class Class5_N2 // ���������ڵ�Ķ������������������
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q);
private:
    void findNode(TreeNode* root,TreeNode* target,vector<TreeNode*>& path,vector<TreeNode*>& item,bool& finish);
};

class Class5_N3 // ������ת����
{
public:
    void flatten(TreeNode* root);
    void flatten1(TreeNode* root);
private:
    void flatten(TreeNode* &root,TreeNode* &pre);
    void flatten1(TreeNode* root,vector<TreeNode*>& nums);
};

class Class5_N4  // �Ҳ�۲������
{
public:
    vector<int> rightSideView(TreeNode* root);
};


struct GraphNode
{
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x):label(x){}
};

class Class5_N5 // ͼ����ȺͿ����������
{
public:
    void BFS_graph(GraphNode* node,int visit[]);
    void DFS_graph(GraphNode* node,int visit[]);
};


class Class5_N5_   // �ж��Ƿ��л�
{
public:
    bool canFinish(int numCourses,vector<pair<int,int> >& prerequisites);
    bool canFinish1(int numCourses,vector<pair<int,int> >& prerequisites);

private:
    bool DFS_graph(GraphNode* node,vector<int>& visit);
};







#endif // CLASS5_H_INCLUDED
