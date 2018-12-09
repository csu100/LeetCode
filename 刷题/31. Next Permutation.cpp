31. Next Permutation
 

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        if(nums.size()==2)
        {
            if(nums[0]>nums[1])
            {
                swap(nums[0],nums[1]);
            }else
            {
                swap(nums[0],nums[1]);
            }
            return ;
        }
        int len=nums.size();
        int i=0;
        int j=0;
        for(i=len-2;i>=0;i--)
        {
           if(nums[i+1]>nums[i])
            {
                for(j=len-1;j>i;j--)  // 寻找比nums[i]大的第一个数
                {
                    if(nums[j]>nums[i])
                    {
                        break;     
                    }
                }
                swap(nums[i],nums[j]);
                sort(nums.begin()+i+1,nums.end());
                return ;
            }   
        }
        sort(nums.begin(),nums.end());
    }
};




class Solution {
    public void nextPermutation(int[] nums) {
        if(nums==null || nums.length<2) return ;
        int i=0;
        int j=0;
        for(i=nums.length-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                for(j=nums.length-1;j>i;j--)
                {
                    if(nums[j]>nums[i])
                        break;
                }
                SWAP(nums,i,j);
                my_Sort(nums,i+1,nums.length);
                return ;
            }
        }
        my_Sort(nums,0,nums.length);
    }
    private void my_Sort(int[] nums,int L,int R)
    {
        if(nums==null || nums.length<2 || L<0 || L>=R) return;
        for(int i=L;i<R;i++)
        {
            heayInsert(nums,i,L);
        }
        int len=nums.length;
        SWAP(nums,--len,L);
        while(len>L)
        {
            heayFeay(nums,0,len,L);
            SWAP(nums,--len,L);
        }
        
    }
    private void heayInsert(int[] nums,int index,int L)
    {
        while(L<=(index-1)/2 && nums[(index-1)/2]<nums[index])
        {
            SWAP(nums,(index-1)/2,index);
            index=(index-1)/2;
        }
    }
    private void heayFeay(int[] nums,int index,int Size,int Start)
    {
        int L=2*index+1;
        while(L+Start<Size)
        {
            int lagest=L+1+Start<Size && nums[L+1+Start]>nums[L+Start]?L+1:L;
            lagest=nums[index+Start]<nums[lagest+Start]?lagest:index;
            if(lagest==index)
            {
                return;
            }
            SWAP(nums,index+Start,lagest+Start);
            index=lagest;
            L=2*index+1;
        }
    }
    private void SWAP(int[] nums,int l,int r)
    {
        int temp=nums[l];
        nums[l]=nums[r];
        nums[r]=temp;
    }
}


class Solution {
    public void nextPermutation(int[] nums) {
        if(nums==null || nums.length<2) return ;
        int i=nums.length-2;
        while(i>=0 && nums[i]>=nums[i+1]) --i;
        if(i>=0)
        {
           int j=nums.length-1; 
           while(j>=0 && nums[j]<=nums[i]) j--;
           SWAP(nums,i,j);
        }
        reverse(nums,i+1); 
        
    }
    private void reverse(int[] nums,int start)
    {
        int L=start;
        int R=nums.length-1;
        while(L<R)
        {
            SWAP(nums,L++,R--);
        }
    }
     
    private void SWAP(int[] nums,int l,int r)
    {
        int temp=nums[l];
        nums[l]=nums[r];
        nums[r]=temp;
    }
}

// pre Permutation
bool cmp(int a,int b)
{
    return a>b;
}
 void prePermutation(vector<int>& nums)
 {
     if(nums.size()<2) return ;
     int i=nums.size()-2;
     int j=0;
     while(i>0 &&  nums[i]<=nums[i+1]) i--;
     for(j=nums.size()-1;j>i;j--)
     {
         if(nums[j]<nums[i])
         {
             swap(nums[i],nums[j]);
             break;
         }
     }
     sort(nums.begin()+i+1,nums.end(),cmp);
 }


// 方法二  
 void  prePermutation(vector<int>& nums)
 {
     if(nums.size()<2) return ;
     int i=nums.size()-2;
     int j=0;
     while(i>0 &&  nums[i]<=nums[i+1]) i--;
     for(j=nums.size()-1;j>i;j--)
     {
         if(nums[j]<nums[i])
         {
             swap(nums[i],nums[j]);
             break;
         }
     }
     reverses(nums,i+1);
     //sort(nums.begin()+i+1,nums.end(),cmp);
 }


 void  reverses(vector<int>& nums,int index)
 {
     if(index<0 || index>=nums.size()) return ;
     int L=index;
     int R=nums.size()-1;
     while(L<R)
     {
         swap(nums[L++],nums[R--]);
     }
 }

