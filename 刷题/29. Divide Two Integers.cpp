29. Divide Two Integers
 

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2



class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor  || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        bool flag=(dividend<0 ^ divisor<0)?true:false;
        long long a1=labs(dividend);
        long long b1=labs(divisor);
        long long result=0;
        long long sum=0;
        long long temp=0;
        while(a1>=b1)
        {
            sum=b1;
            temp=1;
            while(a1>=(sum<<1))
            {
                sum <<=1;
                temp <<=1;
            }
            a1-=sum;
            result+=temp;
        }
        return flag?-result:result;
    }
};


class Solution {
    public int divide(int dividend, int divisor) {
        if((divisor==0)  || (dividend==Integer.MIN_VALUE && divisor==-1)) return Integer.MAX_VALUE;
        if(dividend==Integer.MIN_VALUE && divisor==1) return Integer.MIN_VALUE;
        
        boolean flag=(dividend<0 ^ divisor<0)?true:false;
        long a=Math.abs((long)dividend);
        long b=Math.abs((long)divisor);
        long sum=0;
        long temp=0;
        int result=0;
        while(a>=b)
        {
            sum=b;
            temp=1;
            while(a>=(sum<<1))
            {
                sum <<=1;
                temp <<=1;
            }
            a-=sum;
            result+=temp;
        }
        return flag?-result:result;
    }
}



