14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

struct trieTree
{
    int path;
    trieTree* next[24];
    trieTree()
    {
        path=0;
        for(int i=0;i<24;i++)
        {
            next[i]=0;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1) return "";
        if(strs.size()==1) return strs[0];
        for(int i=0;i<strs.size();i++)
        {
            insert(strs[i]);
        }
        string res=pre_search(strs.size(),strs[0]);
        delete_node();
        return res;
    }
private:
    trieTree root;
    vector<trieTree*> vec_node;
    trieTree* newnode()
    {
        trieTree* node=new trieTree();
        vec_node.push_back(node);
        return node;
    }
    string pre_search(int len,string& str)
    {
        if(len<2) return "";
        trieTree* _root=&root;
        string res="";
        for(int i=0;i<str.size();i++)
        {
            if(_root->next[str[i]-'a']==0)
            {
                break;
            }
            if(_root->next[str[i]-'a']->path!=len)
            {
                break;
            }
            _root=_root->next[str[i]-'a'];
            res+=str[i];
        }
        return res;
    }
    void delete_node()
    {
        int len=vec_node.size();
        for(int i=0;i<len;i++)
        {
            delete vec_node[i];
        }
    }
    void insert(string& str)
    {
        if(str.size()<1) return ;
        trieTree* _root=&root;
        for(int i=0;i<str.size();i++)
        {
            if(_root->next[str[i]-'a']==0)
            {
                _root->next[str[i]-'a']=newnode();
            }
            _root=_root->next[str[i]-'a'];
            _root->path++;
        }
    }
};


class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length<1) return "";
        if(strs.length==1) return strs[0];
         
        int lagest=strs[0].length();
        for(int i=1;i<strs.length;i++)
        {
            lagest=lagest > strs[i].length()?strs[i].length():lagest;
            while(!(strs[i-1].substring(0,lagest)).equals(strs[i].substring(0,lagest)))
            {
                lagest--;
            }
        }
        return strs[0].substring(0,lagest);
         
    }
}

