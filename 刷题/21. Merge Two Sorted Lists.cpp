21. Merge Two Sorted Lists
 

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode result(0);
        ListNode* head=&result;
        while(l1!=nullptr && l2!=nullptr)
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
        if(l1!=nullptr)
        {
            head->next=l1;
        }
        if(l2!=nullptr)
        {
            head->next=l2;
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null) return l2;
        if(l2==null) return l1;
        ListNode result=new ListNode(0);
        ListNode head=result;
        while(l1!=null && l2!=null)
        {
            if(l1.val < l2.val)
            {
                head.next=l1;
                l1=l1.next;
            }else 
            {
                head.next=l2;
                l2=l2.next;
            }
            head=head.next;
        }
        if(l1!=null) 
        {
            head.next=l1;
        }
        if(l2!=null)
        {
            head.next=l2;
        }
        return result.next;
    }
}


