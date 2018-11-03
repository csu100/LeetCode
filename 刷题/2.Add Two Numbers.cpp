You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        int flag=0;
        
        ListNode res(0);
        ListNode* curr=&res;
        int a=0;
        while(l1!=NULL || l2!=NULL || flag==1)
        {
            a=0;
            a+=flag;
            if(l1!=NULL)
            {
                a+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                a+=l2->val;
                l2=l2->next;
            }
            if(a>9)
            {
                a-=10;
                flag=1;
            }else
            {
                flag=0;
            }
            curr->next=new ListNode(a);
            curr=curr->next;
            if((l1==NULL || l2==NULL) && (flag==0))
            {
                if(l1==NULL && l2)
                {
                    curr->next=l2;
                }else if(l2==NULL && l1)
                {
                    curr->next=l1;
                }
                break;
            }
        } 
        return res.next;
    }
};

##############################################

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1==None:
            return l2
        if l2==None:
            return l1
        res=[]
        a=0
        flag=0
        while l1!=None or l2!=None or flag==1:
            a=0
            a+=flag
            if l1!=None:
                a+=l1.val
                l1=l1.next
            if l2!=None:
                a+=l2.val
                l2=l2.next
            if a>9:
                a-=10
                flag=1
            else:
                flag=0
            res.append(a)
        return res
        