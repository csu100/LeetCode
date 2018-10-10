#ifndef CLASS1_H_INCLUDED
#define CLASS1_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class N1_a  //链表的逆序
{
public:
    ListNode* reverseList(ListNode* head); //链表的逆序
};

class N1_b  //链表的逆序
{
public:
    ListNode* reverseBetween(ListNode* head,int m,int n); //链表M到N位置的逆序
};

class N2  //链表求交点与求环问题
{
public:
    ListNode* getIntersectionNode(ListNode* headA,ListNode *headB);// 两个无环链表的交点
    ListNode* getSectionNode(ListNode* headA,ListNode *headB);// 两个可能有环链表的交点
private:
    ListNode* Is_Huan(ListNode* head); // 判断是否有环，并将环的起点返回

};

class N4  // 链表划分
{
public:
    ListNode* Partition(ListNode* head,int x);//根据某值将链表进行划分
};

struct RandomListNode
{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};
class copyRandomList_N5  // // 复杂链表的复制
{
public:
    RandomListNode* copyRandomList(RandomListNode* head); // 复杂链表的复制
};

class N6_a  // 两个有序链表的合并
{
public:
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2); //// 两个有序链表的合并
};

class N6_b  //多个有序链表的合并
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);//多个有序链表的合并
private:
    ListNode* mergeKLists(vector<ListNode*>& lists,int L,int R);
    ListNode* mergeTwoLists(ListNode* headA,ListNode* headB);
};


#endif // CLASS1_H_INCLUDED
