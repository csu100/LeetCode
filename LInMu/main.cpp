#include <iostream>
#include "Class1.h"
#include <vector>
#include "Class2.h"
#include <stack>
#include <queue>
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"
#include "Class7.h"
#include <limits.h>
#include "Class8.h"
#include "Class9.h"


using namespace std;

vector<int> generateNumber(int A[],int len)
{
    vector<int> res(len,0);
    for(int i=0;i<len;i++)
    {
        res[i]=A[i];
    }
    return res;
}
//Class4_N4 zgl;
//int A[]={};
//int len=sizeof(A)/sizeof(*A);
//vector<int> nums=generateNumber(A,len);


int main()
{
//    int A[]={1,1,2,2,2};
//    int len=sizeof(A)/sizeof(*A);
//    vector<int> nums=generateNumber(A,len);
//    Class8_N4 zgl;
//    cout<<zgl.makesquare(nums)<<endl;;

    int A[][3]={{1,3,1},{1,5,1},{4,2,1}};
    int len=3;
    vector<vector<int> > grid;
    for(int i=0;i<len;i++)
    {
        grid.push_back(vector<int>());
        for(int j=0;j<len;j++)
        {
            grid[i].push_back(A[i][j]);
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    Class9_N7 zgl;
    cout<<zgl.minPathSum(grid)<<endl;

    return 0;
}

//int main()
//{
////    Class7_N6 zgl;
////    string s="ADOBECODEBANC";
////    string t = "ABC";
////    cout<<zgl.minWindow(s,t)<<endl;
//
//
//    Class8_N2 zgl;
//    string beginWord="hit";
//    string endWord="cog";
//    vector<string>  wordList;
//    wordList.push_back("hot");
//    wordList.push_back("dot");
//    wordList.push_back("dog");
//    wordList.push_back("lot");
//    wordList.push_back("log");
//    //wordList.push_back("cog");
//
//    cout<<zgl.ladderLength(beginWord,endWord,wordList)<<endl;;
//    return 0;
//}

//int main()
//{
//    Class7_N6 zgl;
//    string s="ABCD";
//    string t="ABC";
//    string result="";
//    cout<<zgl.minWindow(s,t)<<endl;;
//
//    int aa=INT_MAX;
//    cout<<aa<<endl;
//    return 0;
//}



//int main()
//{
//    Class6_N4_ zgl;
//    int A[]={8,3,10,1,6,15};
//    int len=sizeof(A)/sizeof(*A);
//    vector<TreeNode*> vec;
//    for(int i=0;i<len;i++)
//    {
//        vec.push_back(new TreeNode(A[i]));
//    }
//    for(int i=1;i<len;i++)
//    {
//        zgl.BST_insert(vec[0],vec[i]);
//    }
//    zgl.pre_Tree(vec[0]);
//
//    cout<<zgl.BST_search(vec[0],6);
//
//    for(int i=0;i<len;i++)
//    {
//        delete vec[i];
//    }
//
//
////    Class5_N5_ zgl;
////    vector<pair<int,int> > nums;
////    nums.push_back(make_pair(1,0));
////    nums.push_back(make_pair(0,2));
////    nums.push_back(make_pair(2,0));
////    int numCourses=3;
////
////    cout<<zgl.canFinish1(numCourses,nums)<<endl;
//
////    const int MAX_N=5;
////    GraphNode* graph[MAX_N];
////    for(int i=0;i<MAX_N;i++)
////    {
////        graph[i]=new GraphNode(i);
////    }
////    graph[0]->neighbors.push_back(graph[4]);
////    graph[0]->neighbors.push_back(graph[2]);
////    graph[4]->neighbors.push_back(graph[3]);
////    graph[2]->neighbors.push_back(graph[3]);
////    graph[3]->neighbors.push_back(graph[4]);
////    graph[1]->neighbors.push_back(graph[0]);
////    graph[1]->neighbors.push_back(graph[2]);
////
////    int visit[MAX_N]={0};
////
////    Class5_N5 zgl;
////
////
////    for(int i=0;i<MAX_N;i++)
////    {
////        if(visit[i]==0)
////        {
////            zgl.DFS_graph(graph[i],visit);
////            cout<<endl;
////        }
////    }
////
////    for(int i=0;i<MAX_N;i++)
////    {
////        delete graph[i];
////    }
////
//
//    return 0;
//}

/*********************************************
*函数功能：二叉树的测试
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-09-01-14.37
***********************************************/
//int main()
//{
//    TreeNode a(5);
//    TreeNode b1(4);
//    TreeNode b2(8);
//    TreeNode c1(11);
//    TreeNode c3(13);
//    TreeNode c4(4);
//    TreeNode d1(7);
//    TreeNode d2(2);
//    TreeNode d3(5);
//    TreeNode d4(1);
//    a.left=&b1;
//    a.right=&b2;
//    b1.left=&c1;
//    b2.left=&c3;
//    b2.right=&c4;
//    c1.left=&d1;
//    c1.right=&d2;
//    c4.left=&d3;
//    c4.right=&d4;
//
//    TreeNode* result=NULL;
//    Class5_N2 zgl;
//    Class5_N1 zgl1;
//     zgl1.pre_Tree(&a);
//
//     Class5_N4 zgl4;
//     vector<int> result1;
//     result1=zgl4.rightSideView(&a);
//     for(int i=0;i<result1.size();i++)
//     {
//         cout<<result1[i]<<" ";
//     }
//     cout<<endl;
//
////     Class5_N3 zgl3;
////     zgl3.flatten1(&a);
////     zgl1.pre_Tree(&a);
//
////    result=zgl.lowestCommonAncestor(&a,&d3,&c4);
////    if(result)
////    {
////        cout<<result->val<<endl;
////    }else
////    {
////        cout<<"NULL"<<endl;
////    }
//
////    Class5_N1 zgl1;
////    zgl1.pre_Tree(&a);
////    vector<vector<int> > result;
////    int sum=22;
////    Class5_N1_ zgl;
////    result=zgl.pathSum(&a,sum);
////    for(int i=0;i<result.size();i++)
////    {
////        for(int j=0;j<result[i].size();j++)
////        {
////            cout<<result[i][j]<<" ";
////        }
////        cout<<endl;
////    }
////    cout<<endl;
//    return 0;
//}

/*********************************************
*函数功能：二叉树的遍历 测试
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-08-31-20.08
***********************************************/
//int main()
//{
//    TreeNode a(1);
//    TreeNode b1(2);
//    TreeNode b2(3);
//    TreeNode c1(4);
//    TreeNode c2(5);
//    TreeNode c3(6);
//    TreeNode c4(7);
//    a.left=&b1;
//    a.right=&b2;
//    b1.left=&c1;
//    b1.right=&c2;
//    b2.left=&c3;
//    b2.right=&c4;
//
//    Class5_N1 zgl1;
//    zgl1.pre_Tree(&a);
//    cout<<"**************************"<<endl;
//    zgl1.zhong_Tree(&a);
//    cout<<"**************************"<<endl;
//    zgl1.hou_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    Class5_N1_a zgl2;
//    zgl2.pre_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    zgl2.zhong_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    zgl2.hou_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    Class5_N1_b zgl3;
//    zgl3.pre_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    zgl3.zhong_Tree(&a);
//    cout<<"**************************"<<endl;
//
//    //zgl3.hou_Tree(&a);
//    //cout<<"**************************"<<endl;
//
//    return 0;
//}



//int main()
//{
//    Class4_N4 zgl;
//    int A[]={6,6,6,1,1,1};
//    int len=sizeof(A)/sizeof(*A);
//    vector<int> nums=generateNumber(A,len);
//
//    //cout<<zgl.countSmaller(nums);
//    vector<int> result=zgl.countSmaller(nums);
//    for(int i=0;i<result.size();i++)
//    {
//        cout<<result[i]<<" ";
//    }
//    cout<<endl;
//
//    return 0;
//}

//int main()
//{
//    Class4_N3 zgl;
//    int n=4;
//    vector<vector<string> > result=zgl.solveNQueen(n);
//    for(int i=0;i<result.size();i++)
//    {
//        for(int j=0;j<result[i].size();j++)
//        {
//            cout<<result[i][j]<<endl;
//        }
//        cout<<endl<<"------------------------"<<endl;
//    }
//
//    return 0;
//}




//int main()
//{
//    Class4_N2 zgl;
//    vector<string> result;
//
//    result=zgl.generateParenthesis(10);
//    for(int i=0;i<result.size();i++)
//    {
//        cout<<result[i]<<endl;
//    }
//    return 0;
//}

//int main()
//{
//
//    int A[]={10,1,2,7,6,1,5};
//    int len=sizeof(A)/sizeof(*A);
//
//    vector<int> nums=generateNumber(A,len);
//    vector<vector<int> > result;
//
////    Class4_N1_b zgl;
////    result=zgl.subsetsWithDup(nums);
////
//    Class4_N1_b zgl;
//    int target=8;
//    result=zgl.combinationSum2(nums,target);
//
//
////    Class4_N1 zgl;
////    result=zgl.subsets1(nums);
//    for(int i=0;i<result.size();i++)
//    {
//        for(int j=0;j<result[i].size();j++)
//        {
//            cout<<result[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}


//int main()
//{
////    Class3_N3 zgl;
////    string num="";
////    int k=0;
////    cin>>num;
////    cin>>k;
////    cout<<num<<"  "<<k<<endl;
////    cout<<zgl.removeKdigits(num,k)<<endl;
//
//
////    Class3_N2 zgl;
////    int A[]={1,17,5,10,13,15,10,5,16,8};
////    int lenA=sizeof(A)/sizeof(*A);
////
////    vector<int> nums=generateNumber(A,lenA);
////    cout<<zgl.wiggleMaxLength(nums)<<endl;
//
//
////    Class3_N1 zgl;
////    int A[]={5,10,2,9,15,9};
////    int B[]={6,1,20,3,8};
////    int lenA=sizeof(A)/sizeof(*A);
////    int lenB=sizeof(B)/sizeof(*B);
////    vector<int> numsA=generateNumber(A,lenA);
////    vector<int> numsB=generateNumber(B,lenB);
////
////    cout<<zgl.findContentChildren(numsA,numsB);
//
//    return 0;
//}

/*********************************************
*函数功能：测试计算器是否正确
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-08-29-23.41
***********************************************/
//int main()
//{
//    Calculate_N5 zgl;
//    string str="( 3+1*4) ";
//    cout<<str<<endl;
//    cout<<zgl.calculate(str)<<endl;;
//
//    return 0;
//}


//int main()
//{
//    valid_order zgl;
//    int A[]={5,4,1,2,3};
//    queue<int> Q;
//    int len=sizeof(A)/sizeof(*A);
//    for(int i=0;i<len;i++)
//    {
//        Q.push(A[i]);
//    }
//    cout<<zgl.check_is_valid_order(Q)<<endl;
//
//    return 0;
//}


//int main()
//{
//    MinStack s;
//    s.push(-2);
//    cout<<"top:"<<s.top()<<" min top:"<<s.getMin()<<endl;
//    s.push(0);
//    cout<<"top:"<<s.top()<<" min top:"<<s.getMin()<<endl;
//    s.push(-5);
//    cout<<"top:"<<s.top()<<" min top:"<<s.getMin()<<endl;
//    s.pop();
//    cout<<"top:"<<s.top()<<" min top:"<<s.getMin()<<endl;
//
////    My_queue s;
////    cout<<s.empty()<<endl;
////    s.push(1);
////    s.push(2);
////    s.push(3);
////    s.push(4);
////    cout<<s.peek()<<endl;
////    s.pop();
////    cout<<s.peek()<<endl;
////    s.push(5);
////    cout<<s.peek()<<endl;
////    cout<<s.empty()<<endl;
//
////    My_stack s;
////    cout<<s.empty()<<endl;
////    s.push(1);
////    s.push(2);
////    s.push(3);
////    s.push(4);
////    cout<<s.top()<<endl;
////    s.pop();
////    cout<<s.top()<<endl;
////    s.push(5);
////    cout<<s.top()<<endl;
////    cout<<s.empty()<<endl;
//
//    return 0;
//}

/*********************************************
*函数功能：class1测试程序
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-08-27-22.11
***********************************************/
//int main()
//{
//    N6_b zgl;
//    ListNode a1(1);
//    ListNode a2(4);
//    ListNode a3(6);
//    a1.next=&a2;
//    a2.next=&a3;
//
//    ListNode b1(0);
//    ListNode b2(5);
//    ListNode b3(7);
//    b1.next=&b2;
//    b2.next=&b3;
//
//    ListNode c1(1);
//    ListNode c2(3);
//    c1.next=&c2;
//
//    vector<ListNode*> lists;
//    lists.push_back(&a1);
//    lists.push_back(&b1);
//    lists.push_back(&c1);
//    for(int i=0;i<lists.size();i++)
//    {
//        ListNode* head=lists[i];
//        while(head!=NULL)
//        {
//            cout<<head->val<<" ";
//            head=head->next;
//        }
//        cout<<endl;
//    }
//    ListNode* result=NULL;
//
//    result=zgl.mergeKLists(lists);
//    while(result!=NULL)
//    {
//        cout<<result->val<<" ";
//        result=result->next;
//    }
//
//    return 0;
//}

/*
int main()
{
//    N1_a aa;
//    ListNode a(1);
//    ListNode a1(2);
//    ListNode a2(3);
//    ListNode a3(4);
//    ListNode a4(5);
//    a.next=&a1;
//    a1.next=&a2;
//    a2.next=&a3;
//    a3.next=&a4;
//
//    ListNode b(12);
//    ListNode b1(13);
//    ListNode b2(15);
//    ListNode b3(16);
//    ListNode b4(17);
//    b.next=&b1;
//    b1.next=&b2;
//    b2.next=&b3;
//    b3.next=&b4;
//    b4.next=&a3;
//
//    ListNode* result=NULL;
//    N2 cc;
//    result=cc.getIntersectionNode(&a,&b);
//

    ListNode a(1);
    ListNode a1(4);
    ListNode a2(3);
    ListNode a3(2);
    ListNode a4(5);
    ListNode a5(2);
    a.next=&a1;
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    a4.next=&a5;
    N4 dd;
    ListNode* result1=NULL;
    result1=dd.Partition(&a,3);

//    N1_b bb;
//    int m=2,n=8;
//    result=bb.reverseBetween(&a,m,n);
    //result=aa.reverseList(&a);
    while(result1)
    {
        cout<<result1->val<<" ";
        result1=result1->next;
    }

    return 0;
}
*/

