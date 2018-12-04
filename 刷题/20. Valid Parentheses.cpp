20. Valid Parentheses
 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true


class Solution {
public:
    bool isValid(string s) {
        if(s.size()<1) return true;
        if(s.size()%2!=0) return false;
        stack<char> S;
        S.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
           if(!S.empty() && S.top()=='(' && s[i]==')')
           {
               S.pop();
           }else if(!S.empty() && S.top()=='[' && s[i]==']')
           {
               S.pop();
           }else if(!S.empty() && S.top()=='{' && s[i]=='}')
           {
               S.pop();
           }else
           {
               S.push(s[i]);
           }
        }
        return S.empty()?true:false;
    }
};


class Solution {
    public boolean isValid(String s) {
        if(s.length()==0) return true;
        if(s.length()%2!=0) return false;
        Stack<Character> st=new Stack<Character>();
        
        char[] ss=s.toCharArray();
        st.push(ss[0]);
        for(int i=1;i<ss.length;i++)
        {
            if(!st.empty() && st.peek()=='(' && ss[i]==')')
            {
                st.pop();
            }else if(!st.empty() && st.peek()=='{' && ss[i]=='}')
            {
                st.pop();
            }else if(!st.empty() && st.peek()=='[' && ss[i]==']')
            {
                st.pop();
            }else  
            {
                st.push(ss[i]);
            }
        }
        return st.empty()?true:false;
   
    }
}


