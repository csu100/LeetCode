11. 盛最多水的容器
11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49


class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2) return 0;
        int M_area=0;
        int L=0;
        int R=height.size()-1;
        int temp=0;
        int H=0;
        while(L<R)
        {
            H=height[L]<height[R]?height[L++]:height[R--];
            temp=H*(R-L+1);
            M_area=max(M_area,temp);
        }
        return M_area;
    }
};


class Solution {
    public int maxArea(int[] height) {
        if(height.length<2) return 0;
        int L=0;
        int R=height.length-1;
        int Area=0;
        int H=0;
        while(L<R)
        {
            H=height[L]<height[R]?height[L++]:height[R--];
            Area=Math.max(Area,H*(R-L+1));
        }
        return Area;
    }
}

