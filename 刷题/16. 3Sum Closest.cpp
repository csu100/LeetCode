16. 3Sum Closest
 
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int L=0;
        int len=nums.size();
        int R=len-2;
        int Mingap=0x7fffffff;
        int close_target=0;
        for(int i=0;i<len-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            L=i+1;
            R=len-1;
            int sum3=0;
            while(L<R)
            {
                sum3=nums[i]+nums[L]+nums[R];
                int gap=abs(sum3-target);
                if(gap==0) return sum3;
                if(gap<Mingap)
                {
                    Mingap=gap;
                    close_target=sum3;
                }
                if(sum3<target)
                {
                    L++;
                }else
                {
                    R--;
                }
            }
        }
        return close_target;
        
        
    }
};



class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums==null || nums.length<3) return 0;
        Arrays.sort(nums);
        int L=0;
        int len=nums.length;
        int R=0;
        int Mingap=0x7fffffff;
        int close_target=0;
        for(int i=0;i<len-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            L=i+1;
            R=len-1;
            int sum3=0;
            while(L<R)
            {
                sum3=nums[i]+nums[L]+nums[R];
                int gap=Math.abs(sum3-target);
                if(gap<Mingap)
                {
                    Mingap=gap;
                    close_target=sum3;
                }
                if(sum3<target)
                {
                    L++;
                }else
                {
                    R--;
                }
            }
        }
        return close_target;
    }
}