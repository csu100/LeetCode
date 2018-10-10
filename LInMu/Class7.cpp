#include "Class7.h"


/*********************************************
*�������ܣ������ַ������ܹ����ɵ�����Ĵ�����
*����˵��
*    ���룺"abccccdd"
*    �����7
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-00.08
***********************************************/
int Class7_N1::longestPalindrome(string s)
{
    if(s.size()<2) return s.size();
    map<char,int> M;
    for(int i=0;i<s.size();i++)
    {
        M[s[i]]++;
    }
    int res=0;
    int flag=0;
    for(auto it=M.begin();it!=M.end();it++)
    {
        if(it->second %2 ==0)
        {
            res+=it->second;
        }else
        {
            res+=it->second-1;
            flag=1;
        }
    }
    return res+flag;
}


/*********************************************
*�������ܣ�����ģʽƥ��
*����˵��
*    ���룺pattern = "abba", str = "dog cat cat dog"
*    �����true
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-14.33
***********************************************/
bool Class7_N2::wordPattern(string pattern,string str)
{
    if(pattern.size()<1 || str.size()<1) return false;
    int pos=0;
    str+=' ';
    string word="";
    map<char,string> MP;
    map<string,char> MS;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            if(pos==pattern.size())
            {
                return false;
            }
            if(MS.find(word)==MS.end() && MP.find(pattern[pos])==MP.end())
            {
                MS[word]=pattern[pos];
                MP[pattern[pos]]=word;
            }else if(MS.find(word)!=MS.end() && MP.find(pattern[pos])!=MP.end())
            {
                if(MS[word]!=pattern[pos] || MP[pattern[pos]]!=word)
                {
                    return false;
                }
            }else
            {
                return false;
            }
            pos++;
            word="";
        }else
        {
            word+=str[i];
        }
    }
    if(pos==pattern.size())
    {
        return true;
    }else
    {
        return false;
    }
}


/*********************************************
*�������ܣ� ͬ�ַ��������
*����˵��
*    ���룺 ["eat", "tea", "tan", "ate", "nat", "bat"]
*    ����� [["ate","eat","tea"],["nat","tan"],["bat"]]
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-14.33
***********************************************/
vector<vector<string> > Class7_N3::groupAnagrams(vector<string>& strs)
{
    vector<vector<string> > result;
    if(strs.size()<1) return result;
    map<string,vector<string> > M;
    for(int i=0;i<strs.size();i++)
    {
        string temp=strs[i];
        sort(temp.begin(),temp.end());
        if(M.find(temp)==M.end())
        {
            vector<string> item;
            M[temp]=item;
        }
        M[temp].push_back(strs[i]);
    }
    for(auto it=M.begin();it!=M.end();it++)
    {
        result.push_back(it->second);
    }
    return result;
}

/*********************************************
*�������ܣ�  ���ظ��ַ�����Ӵ�
*����˵��
*    ���룺 "abcabcbb"
*    ����� 3
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-14.33
***********************************************/
int Class7_N4::lengthOfLongestSubstring(string s)
{
    if(s.size()<2) return s.size();
    char M[128]={0};
    int L=0;
    string word="";
    int result=0;
    for(int i=0;i<s.size();i++)
    {
        M[s[i]]++;
        if(M[s[i]]==1)
        {
            int temp=i-L+1;
            result=max(result,temp);
        }else
        {
            while(L<i && M[s[i]]>1)
            {
                M[s[L]]--;
                L++;
            }
        }
    }
    return result;
}

/*********************************************
*�������ܣ�  �ظ�DNA����
*����˵��
*    ���룺 s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
*    ����� ["AAAAACCCCC", "CCCCCAAAAA"]
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-14.33
***********************************************/
vector<string> Class7_N5::findRepeatedDnaSequences(string s)
{
    vector<string> result;
    if(s.size()<11) return result;
    bitset<1<<20> S1;
    bitset<1<<20> S2;
    int key=0;
    for(int i=0;i<10;i++)
    {
        key=key<<2 | char_to_int(s[i]);
    }
    S2.set(key);
    int mask=(1<<20)-1;
    for(int i=10;i<s.size();i++)
    {
        key=(key<<2)&mask | char_to_int(s[i]);
        if(S1[key])
        {
            continue;
        }
        if(S2[key])
        {
            result.push_back(s.substr(i-9,10));
            S1.set(key);
        }else
        {
            S2.set(key);
        }
    }
    return result;

}


int Class7_N5::char_to_int(char C)
{
    int number=0;
    switch(C)
    {
        case 'A':number=0;break;
        case 'C':number=1;break;
        case 'G':number=2;break;
        case 'T':number=3;break;
    }
    return number;
}


/*********************************************
*�������ܣ�  ��С�����Ӵ�
*����˵��
*    ���룺 S = "ADOBECODEBANC", T = "ABC"
*    ����� "BANC"
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-02-14.33
***********************************************/
string Class7_N6::minWindow(string s,string t)
{
    if(s.size()<1 || t.size()<1 || s.size()<t.size()) return "";
    int MS[128]={0};
    int MT[128]={0};
    vector<char> vec_t;
    for(int i=0;i<t.size();i++)
    {
        MT[t[i]]++;
        if(MT[t[i]]==1)
        {
            vec_t.push_back(t[i]);
        }
    }
    int L=0;
    string res="";
    int R=0;
    while(R<s.size())
    {
        MS[s[R]]++;
        while(L<R)
        {
            char temp=s[L];
            if(MT[temp]==0)
            {
                L++;
            }else if(MT[temp]<MS[temp])
            {
                MS[temp]--;
                L++;
            }else
            {
                break;
            }
        }
        if(is_Include(MS,MT,vec_t))
        {
            int len=R-L+1;
            if(res=="" || len<res.size())
            {
                res=s.substr(L,len);
            }
        }
        R++;
    }
    return res;

}

bool Class7_N6::is_Include(int mn[],int mt[],vector<char> vec_t)
{
    for(int i=0;i<vec_t.size();i++)
    {
        if(mn[vec_t[i]]<mt[vec_t[i]])
        {
            return false;
        }
    }
    return true;
}
