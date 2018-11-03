4. median of Two sorted arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<1 && nums2.size()<1) return 0.0;
        if(nums1.size()<1)
        {
            return Search(nums2);
        }
        if(nums2.size()<1)
        {
            return Search(nums1);
        }
        vector<int> result;
        int index1_i=0;
        int index2_i=0;
        while(index1_i<nums1.size() && index2_i<nums2.size())
        {
            int tmp=nums1[index1_i]<nums2[index2_i]?nums1[index1_i++]:nums2[index2_i++];
            result.push_back(tmp);
        }
        while(index1_i<nums1.size())
        {
            result.push_back(nums1[index1_i++]);
        }
        while(index2_i<nums2.size())
        {
            result.push_back(nums2[index2_i++]);
        }
        return Search(result);  
    }
    
private:
    double Search(vector<int>& nums)
    {
        int len_i=nums.size()-1;
        int mid_i=len_i>>1;
        if(len_i%2!=0)
        {
            return (double)(nums[mid_i]+nums[mid_i+1])/2.0;
        }else
        {
            return (double)nums[mid_i];
        }
    }
};

############################################

auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    struct Median {
        int left;
        int right;
        double val;
        
        Median(int l, int r, double v) : left(l), right(r), val(v) {}
    };
    
    Median med( vector<int>& nums, int i, int j ){
        int l = i + (j - i - 1) / 2;
        int r = i + (j - i) / 2;
        return Median(nums[l], nums[r], (nums[l] + nums[r]) / 2.0 );
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const bool is_first_larger = nums1.size() > nums2.size();
        vector<int>& n1 = is_first_larger ? nums1 : nums2;
        vector<int>& n2 = is_first_larger ? nums2 : nums1;
        
        int i1 = 0;
        int j1 = n1.size();
        int i2 = 0;
        int j2 = n2.size();
        
        while( i2 + 1 < j2 ) {         
            Median m1 = med(n1, i1, j1);
            Median m2 = med(n2, i2, j2);
            
            if(m1.left >= m2.left && m1.right <= m2.right) {
                return m1.val;
            } else if(m2.left >= m1.left && m2.right <= m1.right) {
                return m2.val;
            }
            
            // reduce problem
            const int drop_len = ( j2 - i2 ) / 2;
            if( m1.val < m2.val ) {
                j2 -=drop_len;
                i1 += drop_len;
            } else {
                i2 += drop_len;
                j1 -= drop_len;
            }            
        }
        
        if( i1 == j1 ) {
            return 0;
        } else if( i2 == j2 ) {
            return med(n1, i1, j1).val;
        } else if( ( j1 - i1 ) % 2 == 0 ) {
            assert( j2 - i2 == 1 );
            int l = i1 + (j1 - i1 - 1) / 2;
            int r = i1 + (j1 - i1) / 2;
            int m2 = n2[i2];
            if( m2 > n1[r] ) {
                return n1[r];
            } else if( m2 < n1[l] ) {
                return n1[l];
            } else {
                return m2;
            }
        } else {
            assert( j2 - i2 == 1 );
            int m1_i = i1 + (j1 - i1 - 1) / 2;
            int m1 = n1[m1_i];
            int m2 = n2[i2];
            if( j1 - i1 == 1 ) {
                return (m1 + m2) / 2.0;
            }
            
            if( m2 >= m1 ) {
                return (m1 + min(m2, n1[m1_i+1])) / 2.0;
            } else {
                return (m1 + max(m2, n1[m1_i-1])) / 2.0;
            }
        }
        
    }
};







