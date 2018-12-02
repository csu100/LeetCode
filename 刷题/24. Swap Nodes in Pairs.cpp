24. Swap Nodes in Pairs
Medium
789
65


Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list s nodes, only nodes itself may be changed.



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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode result(0);
        ListNode* temp=&result;
       
        while(head!=nullptr && head->next!=nullptr)
        {
            ListNode* node3=head->next->next;
            temp->next=head->next;
            temp=temp->next;
            temp->next=head;
            temp=temp->next;
            head=node3;
        }
        if(head!=nullptr)
        {
            temp->next=head;
        }else
        {
        	temp->next=nullptr;
        }
        return result.next;
        
    }
};



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode result=new ListNode(0);
        ListNode temp=result;
        while(head!=null && head.next!=null)
        {
            ListNode node3=head.next.next;
            temp.next=head.next;
            temp=temp.next;
            temp.next=head;
            temp=temp.next;
            head=node3;
        }
        if(head!=null)
        {
            temp.next=head;
        }else
        {
            temp.next=null;
        }
        return result.next;
    }
}
