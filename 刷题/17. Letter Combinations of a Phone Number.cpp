17. Letter Combinations of a Phone Number
 

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()<1) return result;
        map<char,vector<string> > M;
        vector<string> s2{"a","b","c"};
        vector<string> s3{"d","e","f"};
        vector<string> s4{"g","h","i"};
        vector<string> s5{"j","k","l"};
        vector<string> s6{"m","n","o"};
        vector<string> s7{"p","q","r","s"};
        vector<string> s8{"t","u","v"};
        vector<string> s9{"w","x","y","z"};
        M['2']=s2;
        M['3']=s3;
        M['4']=s4;
        M['5']=s5;
        M['6']=s6;
        M['7']=s7;
        M['8']=s8;
        M['9']=s9;

        return Combinations(digits,M,0,digits.size()-1);

    }

private:
    vector<string> Combinations(string digits,map<char,vector<string> >& M,int L,int R)
    {
        if(L>=R)
        {
            return M[digits[L]];
        }
        int mid=(R+L)>>1;
        vector<string> left_str=Combinations(digits,M,L,mid);
        vector<string> right_str=Combinations(digits,M,mid+1,R);
        return CombinString(left_str,right_str);
    }

    vector<string> CombinString(vector<string>& str1,vector<string>& str2)
    {
        if(str1.size()<1) return str2;
        if(str2.size()<1) return str1;
        vector<string> result;

        for(int i=0;i<str1.size();i++)
        {
            for(int j=0;j<str2.size();j++)
            {
                result.push_back(str1[i]+str2[j]);
            }
        }
        return result;
    }
};



class Solution {
    public  List<String> letterCombinations(String digits) {
        List<String> result=new ArrayList<String>();
        if(digits.length()<1) return result;
        Map<Character,List<String>> M=new HashMap<Character,List<String>>();
     
        List<String> s2= Arrays.asList("a","b","c");
        List<String> s3=Arrays.asList("d","e","f");
        List<String> s4=Arrays.asList("g","h","i");
        List<String> s5=Arrays.asList("j","k","l");
        List<String> s6=Arrays.asList("m","n","o");
        List<String> s7=Arrays.asList("p","q","r","s");
        List<String> s8=Arrays.asList("t","u","v");
        List<String> s9=Arrays.asList("w","x","y","z");
        M.put('2',s2);
        M.put('3',s3);
        M.put('4',s4);
        M.put('5',s5);
        M.put('6',s6);
        M.put('7',s7);
        M.put('8',s8);
        M.put('9',s9);
        
        return combinations(digits,M,0,digits.length()-1);
        
    }
    
     

	private  List<String> combinations(String digits,Map<Character,List<String>> M,int L,int R)
    {
        if(L>=R)
        {
            return M.get(digits.charAt(L));
        }
        int mid=L+((R-L)>>1);
        List<String> leftstr=combinations(digits,M,L,mid);
        List<String> rightstr=combinations(digits,M,mid+1,R);
        return mergers(leftstr,rightstr);
    }
    
   private  List<String> mergers(List<String> str1,List<String> str2)
    {
        if(str1==null || str1.isEmpty()) return str2;
        if(str2==null || str2.isEmpty()) return str1;
        List<String> result=new ArrayList<String>();
        for(int i=0;i<str1.size();i++)
        {
            for(int j=0;j<str2.size();j++)
            {
                result.add(str1.get(i)+str2.get(j));
            }
        }
        return result;
    }
	
}



