25. Reverse Nodes in k-Group
 


Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list s nodes, only nodes itself may be changed.


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k<2) return head;
        int n=k;
        ListNode result(0);
        ListNode* root=&result;
        ListNode* tnode=head;
        while(head!=nullptr)
        {
            ListNode* saveNode=head;
            n=k;
            ListNode* prenode=nullptr;
            while(head!=nullptr && n>0)
            {
                ListNode* temp=head->next;
                head->next=prenode;
                prenode=head;
                head=temp;
                n--;
            }
            if(n==0)
            {
                root->next=prenode;
                root=saveNode;
            }else
            {
                ListNode* new_node=nullptr;
                while(prenode!=nullptr)
                {
                    ListNode* temp=prenode->next;
                    prenode->next=new_node;
                    new_node=prenode;
                    prenode=temp;
                }
                root->next=new_node;
                
                break;
            } 
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null || head.next==null || k<2) return head;
        ListNode result=new ListNode(0);
        ListNode new_head=result;
        int n=k;
        while(head!=null)
        {
            ListNode node=head;
            ListNode prenode=null;
            n=k;
            while(head!=null && n>0)
            {
                ListNode temp=head.next;
                head.next=prenode;
                prenode=head;
                head=temp;
                n--;
            }
            if(n==0)
            {
                 new_head.next=prenode;
                new_head=node;
            }else
            {
                ListNode temp=null;
                while(prenode!=null)
                {
                    ListNode node1=prenode.next;
                    prenode.next=temp;
                    temp=prenode;
                    prenode=node1;
                }
                new_head.next=temp;
                break;
            }
        }
        
        return result.next;
        
    }
}

 
