23. Merge k Sorted Lists
 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6



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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1) return nullptr;
        if(lists.size()==1) return lists[0];
        return patitions(lists,0,lists.size()-1);
    }
private:
    ListNode* patitions(vector<ListNode*>& lists,int L,int R)
    {
        if(L>=R)
        {
            return lists[L];
        }
        int mid=L+((R-L)>>1);
        ListNode* left=patitions(lists,L,mid);
        ListNode* right=patitions(lists,mid+1,R);
        return merge(left,right);
    }
    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode result(0);
        ListNode* head=&result;
        while(left!=nullptr && right!=nullptr)
        {
            if(left->val < right->val)
            {
                head->next=left;
                left=left->next;
            }else
            {
                head->next=right;
                right=right->next;
            }
            head=head->next;
        }
        if(left!=nullptr)
        {
            head->next=left;
        }
        if(right!=nullptr)
        {
            head->next=right;
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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists==null || lists.length<1) return null;
        if(lists.length==1) return lists[0];
        return patitions(lists,0,lists.length-1);
    }
    
    private ListNode patitions(ListNode[] lists,int L,int R)
    {
        if(L>=R) return lists[L];
        int mid=L+((R-L)>>1);
        ListNode left=patitions(lists,L,mid);
        ListNode right=patitions(lists,mid+1,R);
        return merge(left,right);
    }
    private ListNode merge(ListNode left,ListNode right)
    {
        ListNode result=new ListNode(0);
        ListNode head=result;
        while(left!=null && right!=null)
        {
            if(left.val < right.val)
            {
                head.next=left;
                left=left.next;
            }else
            {
                head.next=right;
                right=right.next;
            }
            head=head.next;
        }
        if(left!=null)
        {
            head.next=left;
        }
        if(right!=null)
        {
            head.next=right;
        }
        return result.next;
    }
}



