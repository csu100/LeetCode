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
class Class5_N1  //二叉树的递归遍历
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

class Class5_N1_a  //二叉树的非递归遍历
{
public:
   void pre_Tree(TreeNode* head);
   void zhong_Tree(TreeNode* head);
   void hou_Tree(TreeNode* head);
};

class Class5_N1_b  //二叉树的非递归遍历 // morris遍历
{
public:
   void pre_Tree(TreeNode* head);
   void zhong_Tree(TreeNode* head);
   void hou_Tree(TreeNode* head);
};


class Class5_N1_ // 二叉树与整数，找出所有从根节点到叶节点的路径累加和为sum的路径
{
public:
    vector<vector<int> > pathSum(TreeNode* root,int sum);
private:
    void pathSum(TreeNode* root,vector<int>& path,vector<vector<int> >& result,int sum,int&  target);
};

class Class5_N2 // 给定两个节点的二叉树的最近公共祖先
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q);
private:
    void findNode(TreeNode* root,TreeNode* target,vector<TreeNode*>& path,vector<TreeNode*>& item,bool& finish);
};

class Class5_N3 // 二叉树转链表
{
public:
    void flatten(TreeNode* root);
    void flatten1(TreeNode* root);
private:
    void flatten(TreeNode* &root,TreeNode* &pre);
    void flatten1(TreeNode* root,vector<TreeNode*>& nums);
};

class Class5_N4  // 右侧观察二叉树
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

class Class5_N5 // 图的深度和宽度优先搜索
{
public:
    void BFS_graph(GraphNode* node,int visit[]);
    void DFS_graph(GraphNode* node,int visit[]);
};


class Class5_N5_   // 判断是否有环
{
public:
    bool canFinish(int numCourses,vector<pair<int,int> >& prerequisites);
    bool canFinish1(int numCourses,vector<pair<int,int> >& prerequisites);

private:
    bool DFS_graph(GraphNode* node,vector<int>& visit);
};







#endif // CLASS5_H_INCLUDED
