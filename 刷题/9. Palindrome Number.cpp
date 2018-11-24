9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x>0))
        {
            return false;
        }
        int res=0;
        int origel=x;
        while(x!=0)
        {
            res=res*10+x%10;
            x=x/10;
        }
        return res==origel;
        
        /*
        if(x<0) return false;
        deque<int> S;
        int temp=0;
        while(x!=0)
        {
            temp=x%10;
            x=x/10;
            S.push_back(temp);
        }
        int L=0;
        int R=0;
        while(S.size()>1)
        {
            L=S.front();
            R=S.back();
            S.pop_front();
            S.pop_back();
            if(L!=R) return false;
        }
        return true;
        */
    }
};



class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0 or (x>0 and x%10==0):
            return False;
        res=0
        origel=x
        while x>0:
            res=res*10+x%10
            x=x//10;
        return res==origel
        
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0 or (x>0 and x%10==0):
            return False
        S=str(x)
        for i in range(len(S)//2):
            if S[i]!=S[-(i+1)]:
                return False
        return True



