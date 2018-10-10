#include  "Class1.h"


/*********************************************
*函数功能：链表的逆序
*参数说明
*    输入：1，2，3，4，5
*    输出：5，4，3，2，1
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-19.39
***********************************************/
ListNode* N1_a::reverseList(ListNode* head)
{
    if(head==NULL) return NULL;
    ListNode* new_head=NULL;
    while(head)
    {
        ListNode* node=head->next;
        head->next=new_head;
        new_head=head;
        head=node;
    }
    return new_head;
}

/*********************************************
*函数功能：链表M到N位置的逆序
*参数说明
*    输入：1,2,3,4,5;m=2,n=4;
*    输出：1,4,3,2,5
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-19.39
***********************************************/
ListNode* N1_b::reverseBetween(ListNode* head,int m,int n)
{
    if(head==NULL || m<1 || n<1 || m>n) return NULL;
    ListNode *result=head;
    ListNode *pre=NULL;
    int len=n-m+1;
    while(--m && head)
    {
        pre=head;
        head=head->next;
    }
    ListNode *modify=head;
    ListNode *new_head=NULL;
    while(len>0 && head)
    {
        ListNode* node=head->next;
        head->next=new_head;
        new_head=head;
        head=node;
        len--;
    }
    modify->next=head;
    if(pre!=NULL)
    {
        pre->next=new_head;
    }else
    {
        result=new_head;
    }
    return result;
}

/*********************************************
*函数功能：两个无环链表的交点
*参数说明
*    输入：无环链表A，B
*    输出：最近的一个开始交点
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-20.05
***********************************************/
ListNode* N2::getIntersectionNode(ListNode* headA,ListNode *headB)
{
    if(headA==NULL || headB==NULL) return NULL;
    int len=0;
    ListNode* currA=headA;
    while(currA->next!=NULL)
    {
        len++;
        currA=currA->next;
    }
    ListNode* currB=headB;
    while(currB->next!=NULL)
    {
        len--;
        currB=currB->next;
    }
    if(currA!=currB)
    {
        return NULL;
    }
    currA=len>0?headA:headB; // 长链表
    currB=len>0?headB:headA; // 短链表
    len=len>0?len:0-len;
    while(currA!=NULL &&len>0)
    {
        currA=currA->next;
        len--;
    }
    ListNode* meet=NULL;
    while(currA!=NULL && currB!=NULL)
    {
        if(currA==currB)
        {
            meet=currA;
            break;
        }
        currA=currA->next;
        currB=currB->next;
    }
    return meet;
}

/*********************************************
*函数功能：判断输入链表是否有环
*参数说明
*    输入：链表
*    输出：有环则返回起点，否则返回NULL
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-20.05
***********************************************/
ListNode* N2::Is_Huan(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* meet=NULL;
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==NULL)
        {
            return NULL;
        }
        fast=fast->next;
        if(fast==slow)
        {
            meet=fast;
            break;
        }
    }
    if(meet==NULL)
    {
        return NULL;
    }
    fast=head;
    while(fast!=NULL && meet!=NULL)
    {
        if(fast==meet)
        {
            return fast;
        }
        fast=fast->next;
        meet=meet->next;
    }
    return NULL;
}
/*********************************************
*函数功能：判断输入的两个链表的第一个交点
*参数说明
*    输入：链表A,B
*    输出：两个链表的第一个交点，若不存在，则返回NULL
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-20.05
***********************************************/
ListNode* N2::getSectionNode(ListNode* headA,ListNode *headB)
{
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* A1=Is_Huan(headA);
    ListNode* B1=Is_Huan(headB);
    if(A1==NULL && B1==NULL) // 无环
    {
        return getIntersectionNode(headA,headB);
    }else
    {
        if(A1==B1)  //Y型
        {
            int len=0;
            ListNode* currA=headA;
            while(currA->next!=A1)
            {
                len++;
                currA=currA->next;
            }
            ListNode* currB=headB;
            while(currB->next!=B1)
            {
                len--;
                currB=currB->next;
            }
            if(currA!=currB)
            {
                return A1;
            }
            currA=len>0?headA:headB;
            currB=len>0?headB:headA;
            len=len>0?len:0-len;
            while(len>0 && currA!=NULL)
            {
                currA=currA->next;
                len--;
            }
            while(currA!=NULL && currB!=NULL)
            {
                if(currA==currB)
                {
                    return currA;
                }
                currA=currA->next;
                currB=currB->next;
            }

        }else  // 66型 或者猫型
        {
             ListNode *node=A1->next;
             while(node!=B1)
             {
                 if(node==A1) //66型
                 {
                     return NULL;
                 }
                 node=node->next;
             }
             return A1; //猫型
        }
    }

}

/*********************************************
*函数功能：根据输入链表和划分值进行划分，小于X放前面，大于等于的放后面
*参数说明
*    输入：1,4,3,2,5,2;x=3
*    输出：1,2,2,4,3,5
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-20.05
***********************************************/
ListNode* N4::Partition(ListNode* head,int x)
{
    if(head==NULL) return NULL;
    ListNode Less(0);
    ListNode* less_ptr=&Less;
    ListNode More(0);
    ListNode* more_ptr=&More;
    while(head!=NULL)
    {
        if(head->val < x)
        {
            less_ptr->next=head;
            less_ptr=less_ptr->next;
        }else
        {
            more_ptr->next=head;
            more_ptr=more_ptr->next;
        }
        head=head->next;
    }
    more_ptr->next=NULL;
    less_ptr->next=More.next;
    return Less.next;
}

/*********************************************
*函数功能：复杂链表的深度拷贝
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(N)
*作者：guoliang zheng
*日期：2018-08-27-20.58
***********************************************/
RandomListNode* copyRandomList_N5::copyRandomList(RandomListNode* head)
{
    if(head==NULL) return NULL;
    map<RandomListNode*,RandomListNode*> M;
    RandomListNode* curr=head;
    while(curr!=NULL)
    {
        M[curr]=new RandomListNode(curr->label);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        M[curr]->next=M[curr->next];
        M[curr]->random=M[curr->random];
        curr=curr->next;
    }
    return M[head];
}


/*********************************************
*函数功能：两个有序链表的合并
*参数说明
*    输入：
*    输出：
*时间复杂度：O(N) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-20.58
***********************************************/
ListNode* N6_a::mergeTwoList(ListNode* l1,ListNode* l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode result(0);
    ListNode* head=&result;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val < l2->val)
        {
            head->next=l1;
            l1=l1->next;
        }else
        {
            head->next=l2;
            l2=l2->next;
        }
        head=head->next;
    }
    if(l1!=NULL)
    {
        head->next=l1;
    }
    if(l2!=NULL)
    {
        head->next=l2;
    }
    return result.next;
}

/*********************************************
*函数功能：多个有序链表的合并
*参数说明
*    输入：
*    输出：
*时间复杂度：O(NlgN) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-27-21.40
***********************************************/
ListNode* N6_b::mergeKLists(vector<ListNode*>& lists)
{
    if(lists.size()<1) return NULL;
    if(lists.size()==1) return lists[0];
    return mergeKLists(lists,0,lists.size()-1);
}


ListNode* N6_b::mergeKLists(vector<ListNode*>& lists,int L,int R)
{
    if(L>=R)
    {
        return lists[L];
    }
    int mid=L+((R-L)>>1);
    ListNode* headA=mergeKLists(lists,L,mid);
    ListNode* headB=mergeKLists(lists,mid+1,R);

    return mergeTwoLists(headA,headB);
}
ListNode* N6_b::mergeTwoLists(ListNode* headA,ListNode* headB)
{
    ListNode result(0);
    ListNode *head=&result;
    while(headA!=NULL && headB!=NULL)
    {
        if(headA->val < headB->val)
        {
            head->next=headA;
            headA=headA->next;
        }else
        {
            head->next=headB;
            headB=headB->next;
        }
        head=head->next;
    }
    if(headA!=NULL)
    {
        head->next=headA;
    }
    if(headB!=NULL)
    {
        head->next=headB;
    }
    return result.next;
}

