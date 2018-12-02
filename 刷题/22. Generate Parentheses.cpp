22. Generate Parentheses
 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n<1) return result;
        generateParent(n,n,result,"");
        return result;
    }
private:
    void generateParent(int left,int right,vector<string>& result,string str)
    {
        if(left==0 && right==0)
        {
            result.push_back(str);
            return ;
        }
        if(left>0)
        {
            generateParent(left-1,right,result,str+'(');
        }
        if(right>0 && right>left)
        {
            generateParent(left,right-1,result,str+')');
        }
    }
};


class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result=new ArrayList<String>();
        if(n<1) return result;
        String temp=new String();
        generateParent(n,n,result,temp);
        return result;
    }
    
    private void generateParent(int left,int right,List<String> result,String temp)
    {
        if(left==0 && right==0)
        {
            result.add(temp);
            return ;
        }
        if(left>0)
        {
            
            generateParent(left-1,right,result,temp+'(');
        }
        if(right>0 && right>left)
        {
            generateParent(left,right-1,result,temp+')');
        }
    }
}

