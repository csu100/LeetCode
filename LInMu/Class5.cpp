#include "Class5.h"

/*********************************************
*函数功能：二叉树的递归遍历
*参数说明
*    输入：
*    输出：
*时间复杂度：O(n) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-31-19.25
***********************************************/
void Class5_N1::pre_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    pre_Tree(head,0);
}
void Class5_N1::pre_Tree(TreeNode* head,int layer)
{
    if(head==NULL) return ;
    for(int i=0;i<layer;i++)
    {
        cout<<"--";
    }
    cout<<head->val<<endl;
    pre_Tree(head->left,layer+1);
    pre_Tree(head->right,layer+1);
}
void Class5_N1::zhong_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    zhong_Tree(head,0);
}
void Class5_N1::zhong_Tree(TreeNode* head,int layer)
{
    if(head==NULL) return ;
    zhong_Tree(head->left,layer+1);
    for(int i=0;i<layer;i++)
    {
        cout<<"--";
    }
    cout<<head->val<<endl;
    zhong_Tree(head->right,layer+1);
}
void Class5_N1::hou_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    hou_Tree(head,0);
}

void Class5_N1::hou_Tree(TreeNode* head,int layer)
{
    if(head==NULL) return ;
    hou_Tree(head->left,layer+1);
    hou_Tree(head->right,layer+1);
    for(int i=0;i<layer;i++)
    {
        cout<<"--";
    }
    cout<<head->val<<endl;
}


/*********************************************
*函数功能：二叉树的非递归遍历
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-08-31-19.45
***********************************************/
void Class5_N1_a::pre_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    stack<TreeNode*> S;
    S.push(head);
    while(!S.empty())
    {
        TreeNode* node=S.top();
        S.pop();
        cout<<node->val<<" ";
        if(node->right)
        {
            S.push(node->right);
        }
        if(node->left)
        {
            S.push(node->left);
        }
    }
    cout<<endl;
}
void Class5_N1_a::zhong_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    stack<TreeNode*> S;
    while(head!=NULL || !S.empty())
    {
        if(head)
        {
            S.push(head);
            head=head->left;
        }else
        {
            TreeNode* node=S.top();
            S.pop();
            cout<<node->val<<" ";
            head=node->right;
        }
    }
    cout<<endl;
}
void Class5_N1_a::hou_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    stack<TreeNode*> S1;
    stack<TreeNode*> S2;
    S1.push(head);
    while(!S1.empty())
    {
        TreeNode* node=S1.top();
        S1.pop();
        S2.push(node);
        if(node->left)
        {
            S1.push(node->left);
        }
        if(node->right)
        {
            S1.push(node->right);
        }
    }
    while(!S2.empty())
    {
        TreeNode* node=S2.top();
        S2.pop();
        cout<<node->val<<" ";
    }
    cout<<endl;
}


/*********************************************
*函数功能：二叉树的非递归遍历 morris遍历
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-31-19.58
***********************************************/
void Class5_N1_b::pre_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    TreeNode* curr=head;
    TreeNode* mostRight=NULL;
    while(curr!=NULL)
    {
        mostRight=curr->left;
        if(mostRight)
        {
            while(mostRight->right!=NULL && mostRight->right!=curr)
            {
                mostRight=mostRight->right;
            }
            if(mostRight->right==NULL)
            {
                mostRight->right=curr;
                cout<<curr->val<<" ";
                curr=curr->left;
                continue;
            }else
            {
                mostRight->right=NULL;
            }
        }else
        {
            cout<<curr->val<<" ";
        }
        curr=curr->right;
    }
    cout<<endl;
}
void Class5_N1_b::zhong_Tree(TreeNode* head)
{
    if(head==NULL) return ;
    TreeNode* curr=head;
    TreeNode* mostRight=NULL;
    while(curr!=NULL)
    {
        mostRight=curr->left;
        if(mostRight)
        {
            while(mostRight->right!=NULL && mostRight->right!=curr)
            {
                mostRight=mostRight->right;
            }
            if(mostRight->right==NULL)
            {
                mostRight->right=curr;
                curr=curr->left;
                continue;
            }else
            {
                mostRight->right=NULL;
            }
        }
        cout<<curr->val<<" ";
        curr=curr->right;
    }
    cout<<endl;
}



/*********************************************
*函数功能： 二叉树与整数，找出所有从根节点到叶节点的路径累加和为sum的路径
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-08-31-20.16
***********************************************/
vector<vector<int> > Class5_N1_::pathSum(TreeNode* root,int sum)
{
    vector<vector<int> > result;
    if(root==NULL) return result;
    vector<int> path;
    int target=0;
    pathSum(root,path,result,sum,target);
    return result;
}

void Class5_N1_::pathSum(TreeNode* root,vector<int>& path,vector<vector<int> >& result,int sum,int& target)
{
    if(root==NULL) return ;
    path.push_back(root->val);
    target+=root->val;
    if(root->left==NULL && root->right==NULL && sum==target)
    {
        result.push_back(path);
    }
    pathSum(root->left,path,result,sum,target);

    pathSum(root->right,path,result,sum,target);
    path.pop_back();
    target-=root->val;
}

/*********************************************
*函数功能： 给定两个节点的二叉树的最近公共祖先
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-08-31-20.16
***********************************************/
TreeNode* Class5_N2::lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL || p==NULL || q==NULL) return NULL;
    vector<TreeNode*> vec_p;
    vector<TreeNode*> vec_q;
    vector<TreeNode*> item;
    bool finish=false;
    findNode(root,p,vec_p,item,finish);
    item.clear();
    finish=false;
    findNode(root,q,vec_q,item,finish);
    int len=vec_p.size()>vec_q.size()?vec_q.size():vec_p.size();
    TreeNode* meet=NULL;
    for(int i=0;i<len;i++)
    {
        if(vec_p[i]==vec_q[i])
        {
            meet=vec_p[i];
        }else
        {
            break;
        }
    }
    return meet;
}

void Class5_N2::findNode(TreeNode* root,TreeNode* target,vector<TreeNode*>& path,vector<TreeNode*>& item,bool& finish)
{
    if(root==NULL || finish) return ;
    item.push_back(root);
    if(root==target)
    {
        path=item;
        finish=true;
    }
    findNode(root->left,target,path,item,finish);
    findNode(root->right,target,path,item,finish);
    item.pop_back();
}


/*********************************************
*函数功能： 二叉树转链表
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-31-20.16
***********************************************/
void Class5_N3::flatten(TreeNode* root)
{
    if(root==NULL) return ;
    TreeNode* pre=NULL;
    flatten(root,pre);
}

void Class5_N3::flatten(TreeNode* &root,TreeNode* &pre)
{
    if(root==NULL) return ;
    flatten(root->right,pre);
    flatten(root->left,pre);
    root->right=pre;
    root->left=NULL;
    pre=root;
}

void Class5_N3::flatten1(TreeNode* root)
{
    if(root==NULL) return ;
    vector<TreeNode*> nums;
    flatten1(root,nums);
    for(int i=1;i<nums.size();i++)
    {
        nums[i-1]->left=NULL;
        nums[i-1]->right=nums[i];
    }
}

void Class5_N3::flatten1(TreeNode* root,vector<TreeNode*>& nums)
{
    if(root==NULL) return ;
    nums.push_back(root);
    flatten1(root->left,nums);
    flatten1(root->right,nums);
}



/*********************************************
*函数功能： 从右侧观察二叉树
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-08-31-20.16
***********************************************/
vector<int> Class5_N4::rightSideView(TreeNode* root)
{
    vector<int> result;
    if(root==NULL) return result;
    queue<pair<TreeNode*,int> > Q;
    Q.push(make_pair(root,0));
    while(!Q.empty())
    {
        TreeNode* node=Q.front().first;
        int deep=Q.front().second;
        Q.pop();
        if(result.size()==deep)
        {
            result.push_back(node->val);
        }else
        {
            result[deep]=node->val;
        }
        if(node->left)
        {
            Q.push(make_pair(node->left,deep+1));
        }
        if(node->right)
        {
            Q.push(make_pair(node->right,deep+1));
        }
    }
    return result;
}


/*********************************************
*函数功能：二叉树的宽度遍历
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-09-01-14.47
***********************************************/
void Class5_N5::BFS_graph(GraphNode* node,int visit[])
{
    queue<GraphNode*> Q;
    visit[node->label]=1;
    Q.push(node);
    while(!Q.empty())
    {
        GraphNode* nodes=Q.front();
        Q.pop();
        cout<<nodes->label<<" ";
        for(int i=0;i<nodes->neighbors.size();i++)
        {
            if(visit[nodes->neighbors[i]->label]==0)
            {
                Q.push(nodes->neighbors[i]);
                visit[nodes->neighbors[i]->label]=1;
            }
        }
    }
    cout<<endl;
}
/*********************************************
*函数功能：深度优先遍历
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-09-01-14.54
***********************************************/
void Class5_N5::DFS_graph(GraphNode* node,int visit[])
{
    visit[node->label]=1;
    cout<<node->label<<" ";
    for(int i=0;i<node->neighbors.size();i++)
    {
        if(visit[node->neighbors[i]->label]==0)
        {
            DFS_graph(node->neighbors[i],visit);
        }
    }
}

/*********************************************
*函数功能：判断图是否有环
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-09-01-15.47
***********************************************/
bool Class5_N5_::canFinish(int numCourses,vector<pair<int,int> >& prerequisites)
{
    if(numCourses<1 || prerequisites.size()<1 || numCourses!=prerequisites.size()) return false;
    vector<GraphNode*> graph;
    vector<int> visit;
    for(int i=0;i<numCourses;i++)
    {
        graph.push_back(new GraphNode(i));
        visit.push_back(-1);
    }
    for(int i=0;i<prerequisites.size();i++)
    {
        GraphNode* begins=graph[prerequisites[i].second];
        GraphNode* ends=graph[prerequisites[i].first];
        begins->neighbors.push_back(ends);
    }
    for(int i=0;i<graph.size();i++)
    {
        if(visit[i]==-1 && !DFS_graph(graph[i],visit))
        {
            return false;
        }
    }

    for(int i=0;i<numCourses;i++)
    {
        delete graph[i];
    }
    return true;
}



bool Class5_N5_::DFS_graph(GraphNode* node,vector<int>& visit)
{
    visit[node->label]=0;
    for(int i=0;i<node->neighbors.size();i++)
    {
        if(visit[node->neighbors[i]->label]==-1)
        {
            if(!DFS_graph(node->neighbors[i],visit))
            {
                return false;
            }
        }else if(visit[node->neighbors[i]->label]==0)
        {
            return false;
        }
    }
    visit[node->label]=1;
    return true;
}

bool Class5_N5_::canFinish1(int numCourses,vector<pair<int,int> >& prerequisites)
{
    if(numCourses<1 || prerequisites.size()<1 || numCourses!=prerequisites.size()) return false;
    vector<GraphNode*> graph;
    vector<int> degree;
    for(int i=0;i<numCourses;i++)
    {
        graph.push_back(new GraphNode(i));
        degree.push_back(0);
    }
    for(int i=0;i<prerequisites.size();i++)
    {
        GraphNode* begins=graph[prerequisites[i].second];
        GraphNode* ends=graph[prerequisites[i].first];
        begins->neighbors.push_back(ends);
        degree[prerequisites[i].first]++;
    }
    queue<GraphNode*> Q;
    for(int i=0;i<numCourses;i++)
    {
        if(degree[i]==0)
        {
            Q.push(graph[i]);
        }
    }
    while(!Q.empty())
    {
        GraphNode* nodes=Q.front();
        Q.pop();
        for(int i=0;i<nodes->neighbors.size();i++)
        {
            degree[nodes->neighbors[i]->label]--;
            if(degree[nodes->neighbors[i]->label]==0)
            {
                Q.push(nodes->neighbors[i]);
            }
        }
    }
    for(int i=0;i<graph.size();i++)
    {
        delete graph[i];
    }
    for(int i=0;i<numCourses;i++)
    {
        if(degree[i]!=0)
        {
            return false;
        }
    }
    return true;
}


