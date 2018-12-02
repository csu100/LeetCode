19. Remove Nth Node From End of List
 

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || n<1) return head;
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            len++;
            temp=temp->next;
        }
        if(len<n) return head;
        if(len==n) return head->next;
        temp=head;
        len=len-n;
        while(--len>0 && temp!=nullptr)
        {
            temp=temp->next;
        }
        if(temp->next!=nullptr)
        {
           temp->next=temp->next->next; 
        }else
        {
            temp->next=nullptr;
        }
        return head;
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null || n<1) return head;
        ListNode first=head;
        ListNode second=head;
        while(n>0 && first!=null)
        {
            first=first.next;
            n--;
        }
        if(n>0) return head;
        if(n==0 && first==null) return head.next;
        while(first.next!=null)
        {
            first=first.next;
            second=second.next;
        }
        if(second.next!=null)
        {
            second.next=second.next.next;
        }
        return head;
    }
}


