12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one s added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


class Solution {
public:
    string intToRoman(int num) {
        if(num<1) return "";
        int keys[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string values[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int length=sizeof(keys)/sizeof(*keys); 
        string res="";
        while(num>0)
        {
            for(int i=0;i<length;i++)
            {
                if(num>=keys[i])
                {
                    res+=values[i];
                    num-=keys[i];
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
    static int[] keys={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    static String[] vaules={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    public String intToRoman(int num) {
        if(num<1) return "";   
        StringBuilder res=new StringBuilder(); 
        while(num>0)
        {
            for(int i=0;i<keys.length;i++)
            {
                if(num>=keys[i])
                {
                    res.append(vaules[i]);
                    num-=keys[i];
                    break;
                }
            }
        }
        return res.toString();    
    }
}