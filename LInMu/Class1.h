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

class N1_a  //���������
{
public:
    ListNode* reverseList(ListNode* head); //���������
};

class N1_b  //���������
{
public:
    ListNode* reverseBetween(ListNode* head,int m,int n); //����M��Nλ�õ�����
};

class N2  //�����󽻵���������
{
public:
    ListNode* getIntersectionNode(ListNode* headA,ListNode *headB);// �����޻�����Ľ���
    ListNode* getSectionNode(ListNode* headA,ListNode *headB);// ���������л�����Ľ���
private:
    ListNode* Is_Huan(ListNode* head); // �ж��Ƿ��л�������������㷵��

};

class N4  // ������
{
public:
    ListNode* Partition(ListNode* head,int x);//����ĳֵ��������л���
};

struct RandomListNode
{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(NULL),random(NULL){}
};
class copyRandomList_N5  // // ��������ĸ���
{
public:
    RandomListNode* copyRandomList(RandomListNode* head); // ��������ĸ���
};

class N6_a  // ������������ĺϲ�
{
public:
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2); //// ������������ĺϲ�
};

class N6_b  //�����������ĺϲ�
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);//�����������ĺϲ�
private:
    ListNode* mergeKLists(vector<ListNode*>& lists,int L,int R);
    ListNode* mergeTwoLists(ListNode* headA,ListNode* headB);
};


#endif // CLASS1_H_INCLUDED
