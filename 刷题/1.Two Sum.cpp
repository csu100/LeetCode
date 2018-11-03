1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()<2) return result;
        unordered_map<int,int> M;
        for(int i=0;i<nums.size();i++)
        {
            M[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            auto f1=M.find(target-nums[i]);
            if(f1!=M.end() && f1->second >i)
            {
                result.push_back(i);
                result.push_back(f1->second);
            }
        }
        return result;
    }
};

####################################

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)<2:
            return []
        MAP={}
        for i in range(len(nums)):
            MAP[nums[i]]=i
        result=[]
        for i in range(len(nums)):
            tmp=MAP.get(target-nums[i],-1)
            if tmp!=-1 and tmp>i:
                result.append(i)
                result.append(tmp)    
        return result
        
#########################################

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)<2:
            return []
        MAP={}
        for i in range(len(nums)):
            if target-nums[i] in MAP:
                return [MAP[target-nums[i]],i]
            if nums[i] not in MAP.keys():
                MAP[nums[i]]=i
        return []
        