#include "Class9.h"

/*********************************************
*�������ܣ���¥��
*����˵��
*    ���룺3
*    �����3
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*���ߣ�guoliang zheng
*���ڣ�2018-09-11-21.59
***********************************************/
int Class9_N1::climbStairs(int n)
{
    if(n<1) return 0;
    vector<int> dp(n+3,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

/*********************************************
*�������ܣ���ҽ�������
*����˵��
*    ���룺3
*    �����3
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*���ߣ�guoliang zheng
*���ڣ�2018-09-11-21.59
***********************************************/
int Class9_N2::rob(vector<int>& nums)
{
    if(nums.size()<1) return 0;
    int len=nums.size();
    vector<int> dp(len+2,0);
    dp[0]=nums[0];
    dp[1]=max(nums[1],nums[0]);
    for(int i=2;i<len;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[len-1];
}

/*********************************************
*�������ܣ���������������
*����˵��
*    ���룺[-2,1,-3,4,-1,2,1,-5,4]
*    �����6
*ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ� O(n)
*���ߣ�guoliang zheng
*���ڣ�2018-09-11-21.59
***********************************************/

int Class9_N3::maxSubArray(vector<int>& nums)
{
    if(nums.size()<1) return 0;
    if(nums.size()==1) return nums[0];
    int len=nums.size();
    vector<int> dp(len,0);
    dp[0]=nums[0];
    int maxSum=dp[0];
    for(int i=1;i<len;i++)
    {
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        if(dp[i]>maxSum)
        {
            maxSum=dp[i];
        }
    }
    return maxSum;
}


/*********************************************
*�������ܣ� ���ٻ���Ǯ��
*����˵��
*    ���룺1,2,5 ;11
*    �����3(5+5+1)
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(NM)
*���ߣ�guoliang zheng
*���ڣ�2018-09-12-08.41
***********************************************/
int Class9_N4::coinChange(vector<int>& coins,int amount)
{
    if(coins.size()<1 || amount<1) return 0;
    vector<int> dp(amount+1,-1);
    dp[0]=0;
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(i-coins[j]>=0 && dp[i-coins[j]]!=-1)
            {
                if(dp[i]==-1 || dp[i]>dp[i-coins[j]]+1)
                {
                    dp[i]=dp[i-coins[j]]+1;
                }
            }
        }
    }
    return dp[amount];
}

/*********************************************
*�������ܣ����˵��Ͷ˸����ֺ���С��·����
*����˵��
*    ���룺
            [
                 [2],
                [3,4],
               [6,5,7],
              [4,1,8,3]
            ]
*    �����11
*ʱ�临�Ӷȣ�O(N*N) �ռ临�Ӷ� O(N*N)
*���ߣ�guoliang zheng
*���ڣ�2018-09-12-08.41
***********************************************/
int Class9_N5::minimunTotal(vector<vector<int> >& triangle)
{
    if(triangle.size()<1) return 0;
    if(triangle.size()==1) return triangle[0][0];
    int row=triangle.size();
    vector<vector<int> > dp(row,vector<int>(row,0));
    for(int i=0;i<triangle[row-1].size();i++)
    {
        dp[row-1][i]=triangle[row-1][i];
    }
    for(int i=row-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
    }
    return dp[0][0];
}


/*********************************************
*�������ܣ������������ ����
*����˵��
*    ���룺[10,9,2,5,3,7,101,18]
*    �����4
*ʱ�临�Ӷȣ�O(NlogN) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-09-12-08.41
***********************************************/
int Class9_N6::lengthOfLIS(vector<int>& nums)
{
    if(nums.size()<2) return nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>dp.back())
        {
            dp.push_back(nums[i]);
        }else
        {
            int pos=find_binary(dp,nums[i]);
            if(pos!=-1 || pos<dp.size())
            {
                dp[pos]=nums[i];
            }
        }
    }
    return dp.size();
}

int Class9_N6::find_binary(vector<int> dp,int target)
{
    int L=0;
    int R=dp.size()-1;
    while(L<=R)
    {
        int mid=L+((R-L)>>1);
        if(dp[mid]==target)
        {
            return mid;
        }else if(target<dp[mid])
        {
            if(mid==0 || target>dp[mid-1])
            {
                return mid;
            }
            R=mid-1;
        }else if(target>dp[mid])
        {
            if(mid==dp.size()-1 || target<dp[mid+1])
            {
                return mid+1;
            }
            L=mid+1;
        }
    }
    return -1;
}


/*********************************************
*�������ܣ���С·����
*����˵��
*    ���룺
            [
              [1,3,1],
              [1,5,1],
              [4,2,1]
            ]
*    �����7
*ʱ�临�Ӷȣ�O(NM) �ռ临�Ӷ� O(NM)
*���ߣ�guoliang zheng
*���ڣ�2018-09-12-08.41
***********************************************/
int Class9_N7::minPathSum(vector<vector<int> >& grid)
{
    if(grid.size()<1) return 0;
    int row=grid.size();
    int colum=grid[0].size();
    vector<vector<int> > dp(row,vector<int>(colum,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<colum;i++)
    {
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1;i<row;i++)
    {
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<colum;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[row-1][colum-1];
}



int Class9_N8::calculateMinimunHP(vector<vector<int> >& dungeon)
{
    if(dungeon.size()<1) return 1;
    int row=dungeon.size();
    int column=dungeon[0].size();
    vector<vector<int> > dp(row,vector<int>(column,0));
    dp[row-1][column-1]=max(1,1-dungeon[row-1][column-1]);
    for(int i=row-2;i>=0;i--)
    {
        dp[i][column-1]=max(1,dp[i+1][column-1]-dungeon[i][column-1]);
    }
    for(int i=column-2;i>=0;i--)
    {
        dp[row-1][i]=max(1,dp[row-1][i+1]-dungeon[row-1][i]);
    }
    for(int i=row-2;i>=0;i--)
    {
        for(int j=column-2;j>=0;j--)
        {
            int temp=min(dp[i][j+1],dp[i+1][j]);
            dp[i][j]=max(1,temp-dungeon[i][j]);
        }
    }
    return dp[0][0];
}







