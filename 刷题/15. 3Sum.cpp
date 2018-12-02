15. 3Sum
 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size()<3) return result;
        int L=0;
        int R=0;
        sort(nums.begin(),nums.end());
        
        vector<int> temp;
        int len=nums.size();
        int target=0;
        for(int i=0;i<len-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            L=i+1;
            R=len-1;
            int sum3=0;
            while(L<R)
            {
                sum3=nums[L]+nums[R]+nums[i];
                if(sum3<0)
                {
                    L++;
                }else if(sum3>0)
                {
                    R--;
                }else
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[L]);
                    temp.push_back(nums[R]);
                    result.push_back(temp);
                    temp.clear();   
                    while(L<len-2 && nums[L]==nums[L+1]) L++;
                    while(R>0 && nums[R]==nums[R-1]) R--;
                    L++;
                    R--;
                }
            }
        }
        return result;
        
    }
};




class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer> > result=new ArrayList<>();
        if(nums==null || nums.length<3) return result;
        Arrays.sort(nums);
        int L=0;
        int R=0;
        int len=nums.length;
        int target=0;
        for(int i=0;i<len-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            L=i+1;
            R=len-1;
            int sum3=0;
            while(L<R)
            {
                sum3=nums[i]+nums[L]+nums[R];
                if(sum3<0)
                {
                    L++;
                }else if(sum3>0)
                {
                    R--;
                }else
                {
                    result.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while(L<len-2 && nums[L]==nums[L+1]) L++;
                    while(R>0 && nums[R]==nums[R-1]) R--;
                    L++;
                    R--;
                }
                    
            }
           
        }
         return result;
    }
}