18. 4Sum
 


Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        if(4*nums[0]>target || 4*nums[nums.size()-1]<target) return {};
        int L=0;
        int R=0;
        int len=nums.size();
        set<vector<int> > S;
        for(int i=0;i<len-3 && 4*nums[i]<=target;i++)
        {
            for(int j=i+1;j<len-2 && nums[i]+3*nums[j]<=target;j++)
            {
                L=j+1;
                R=len-1;
                int sum4=0;
                while(L<R)
                {
                    sum4=nums[i]+nums[j]+nums[L]+nums[R];
                    if(sum4<target)
                    {
                        L++;
                    }else if(sum4>target)
                    {
                        R--;
                    }else
                    {
                        vector<int> temp={nums[i],nums[j],nums[L],nums[R]};
                        if(S.find(temp)==S.end())
                        {
                            result.push_back(temp);
                            S.insert(temp);
                        }
                        L++;
                        R--;
                    }
                        
                }
            }
        }
        return result;
        
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        if(nums.size()<4 || 4*nums[0]>target || 4*nums[nums.size()-1]<target) return result;
        int L=0;
        int R=0;
        int len=nums.size();
        for(int i=0;i<len-2 && 4*nums[i]<=target;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len-1 && nums[i]+3*nums[j]<=target;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                L=j+1;
                R=len-1;
                int new_target=target-nums[i]-nums[j];
                int sum4=0;
                while(L<R)
                {
                    sum4=nums[L]+nums[R];
                    if(sum4==new_target)
                    {
                        result.push_back(vector<int>{nums[i],nums[j],nums[L],nums[R]});
                        while(++L<R && nums[L]==nums[L-1]);
                        while(L<--R && nums[R]==nums[R+1]);
                    }else if(sum4<new_target)
                    {
                        while(++L<R && nums[L]==nums[L-1]);
                    }else
                    {
                        while(L<--R && nums[R]==nums[R+1]);
                    }
                }
            }
        }
        return result;
        
        
    }
};


class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result=new ArrayList<>();
        if(nums==null || nums.length<4) return result;
        
        Arrays.sort(nums);
        int len=nums.length;
        if(4*nums[0]>target || 4*nums[len-1]<target) return result;
         
        int L=0;
        int R=0;
         
        for(int i=0;i<len-2 && 4*nums[i]<=target;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<len-1 && nums[i]+3*nums[j]<=target;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                L=j+1;
                R=len-1;
                int new_target=target-nums[i]-nums[j];
                int sum4=0;
                while(L<R)
                {
                    sum4=nums[L]+nums[R];
                    if(sum4==new_target)
                    {
                        result.add(Arrays.asList(nums[i],nums[j],nums[L],nums[R]));
                        while(++L<R && nums[L]==nums[L-1]);
                        while(L<--R  && nums[R]==nums[R+1]);
                    }else if(sum4<new_target)
                    {
                        while(++L<R && nums[L]==nums[L-1]);
                       
                    }else
                    {
                        while(L<--R && nums[R]==nums[R+1]);
                    }
                }
                
            }
        }
        return result; 
    }
}