#include "Class4.h"


/*********************************************
*函数功能：求子集
*参数说明
*    输入：[1,2,3]
*    输出：[[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
*时间复杂度：O(2^n) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-08.41
***********************************************/
vector<vector<int> > Class4_N1::subsets(vector<int>& nums)
{
    vector<vector<int> > result;
    vector<int> item;
    result.push_back(item);
    if(nums.size()<1) return result;
    subsets(nums,result,item,0);
    return result;
}

void Class4_N1::subsets(vector<int>& nums,vector<vector<int> >& result,vector<int>& item,int n)
{
    if(n>=nums.size())
    {
        return ;
    }
    item.push_back(nums[n]);
    result.push_back(item);
    subsets(nums,result,item,n+1);
    item.pop_back();
    subsets(nums,result,item,n+1);
}

vector<vector<int> > Class4_N1::subsets1(vector<int>& nums)
{
    vector<vector<int> > result;
    if(nums.size()<1)
    {
        vector<int> item;
        result.push_back(item);
        return result;
    }
    int all_len=1<<nums.size();
    for(int i=0;i<all_len;i++)
    {
        vector<int> item;
        for(int j=0;j<nums.size();j++)
        {
            if(i&(1<<j))
            {
                item.push_back(nums[j]);
            }
        }
        result.push_back(item);
    }
    return result;
}



/*********************************************
*函数功能：有重复元素，求子集
*参数说明
*    输入：[2,1,2,2]
*    输出：[[],[1],[1,2],[1,2,2],[1,2,2,2],[2],[2,2],[2,2,2]]
*时间复杂度：O(2^n) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-08.41
***********************************************/
vector<vector<int> > Class4_N1_b::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int> > result;
    if(nums.size()<1)
    {
        vector<int> item;
        result.push_back(item);
        return result;
    }
    sort(nums.begin(),nums.end());
    set<vector<int> > has;
    int all_len=1<<nums.size();
    for(int i=0;i<all_len;i++)
    {
        vector<int> item;
        for(int j=0;j<nums.size();j++)
        {
            if(i & (1<<j))
            {
                item.push_back(nums[j]);
            }
        }
        if(has.find(item)==has.end())
        {
            result.push_back(item);
            has.insert(item);
        }
    }
    return result;
}

/*********************************************
*函数功能：有重复元素，求目标和为target 子集
*参数说明
*    输入：10,1,2,7,6,1,5; target=8
*    输出： [1,2,5],[1,1,6],[2,6],[1,7]
*时间复杂度：O(2^n) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-08.41
***********************************************/
vector<vector<int> > Class4_N1_b::combinationSum2(vector<int>& nums,int target)
{
    vector<vector<int> > result;
    if(nums.size()<1) return result;
    int all_len=1<<nums.size();
    set<vector<int> > has;
    sort(nums.begin(),nums.end());
    for(int i=0;i<all_len;i++)
    {
        vector<int> item;
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            if(i & (1<<j))
            {
                item.push_back(nums[j]);
                sum+=nums[j];
                if(sum>target)
                {
                    break;
                }
            }
        }
        if(has.find(item)==has.end() && sum==target)
        {
            has.insert(item);
            result.push_back(item);
        }
    }
    return result;

}


/*********************************************
*函数功能：// 生产合法的括号
*参数说明
*    输入：
*    输出：
*时间复杂度：O(2^n) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-08-31-15.58
***********************************************/
vector<string> Class4_N2::generateParenthesis(int n)
{
    vector<string> result;
    if(n<1) return result;
    generateParenthesis(result,"",n,n);
    return result;
}

void Class4_N2::generateParenthesis(vector<string>& result,string str,int left,int right)
{
    if(left==0 && right==0)
    {
        result.push_back(str);
    }
    if(left>0)
    {
        generateParenthesis(result,str+'(',left-1,right);
    }
    if(left<right)
    {
        generateParenthesis(result,str+')',left,right-1);
    }
}


/*********************************************
*函数功能： N皇后问题
*参数说明
*    输入：
*    输出：
*时间复杂度：O(2^n) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-15.58
***********************************************/
vector<vector<string> > Class4_N3::solveNQueen(int n)
{
    vector<vector<string> > result;
    if(n<1) return result;
    vector<vector<int> > mark(n,vector<int>(n,0));
    vector<string> Queen;
    for(int i=0;i<n;i++)
    {
         Queen.push_back("");
         Queen[i].append(n,'.');
    }

    sloveNQueen(mark,result,Queen,n,0);
    return result;
}

void Class4_N3::putQueen(vector<vector<int> >& mark,int x,int y)
{
    const int dx[]={-1,-1,0,1,1,1,0,-1};
    const int dy[]={0,1,1,1,0,-1,-1,-1};
    mark[x][y]=1;
    for(int i=1;i<mark.size();i++)
    {
        for(int j=0;j<8;j++)
        {
            int new_x=x+i*dx[j];
            int new_y=y+i*dy[j];
            if(new_x<0 || new_x>=mark.size() || new_y<0 || new_y>=mark[0].size())
            {
                continue;
            }
            mark[new_x][new_y]=1;
        }
    }

}
void Class4_N3::sloveNQueen(vector<vector<int> >& mark,vector<vector<string> >& result,vector<string>& Queen,int n,int m)
{
    if(n==m)
    {
        result.push_back(Queen);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(mark[m][i]==0)
        {
            vector<vector<int> > temp=mark;
            putQueen(mark,m,i);
            Queen[m][i]='Q';
            sloveNQueen(mark,result,Queen,n,m+1);
            mark=temp;
            Queen[m][i]='.';
        }

    }
}

/*********************************************
*函数功能：逆序对问题
*参数说明
*    输入：6,6,6,1,1,1
*    输出：3,3,3,0,0,0
*时间复杂度：O(nlgn) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-18.18
***********************************************/
vector<int> Class4_N4::countSmaller(vector<int>& nums)
{
    vector<int> result;
    if(nums.size()<2) return result;
    vector<pair<int,int> > vec_p;
    for(int i=0;i<nums.size();i++)
    {
        vec_p.push_back(make_pair(nums[i],i));
        result.push_back(0);
    }
    countSmaller(vec_p,result,0,nums.size()-1);
    return result;
}

void Class4_N4::countSmaller(vector<pair<int,int> >& vec_p,vector<int>& result,int L,int R)
{
    if(L>=R) return ;
    int mid=L+((R-L)>>1);
    countSmaller(vec_p,result,L,mid);
    countSmaller(vec_p,result,mid+1,R);
    mergers(vec_p,result,L,mid,R);
}
void Class4_N4::mergers(vector<pair<int,int> >& vec_p,vector<int>& result,int L,int mid,int R)
{
    int i=L;
    int j=mid+1;
    vector<pair<int,int> > help;
    while(i<=mid && j<=R)
    {
        if(vec_p[i].first<=vec_p[j].first)
        {
            help.push_back(vec_p[i]);
            result[vec_p[i].second]+=(j-mid-1);
            i++;
        }else
        {
            help.push_back(vec_p[j++]);
        }
    }
    for(;i<=mid;i++)
    {
        help.push_back(vec_p[i]);
        result[vec_p[i].second]+=(j-mid-1);
    }
    for(;j<=R;j++)
    {
        help.push_back(vec_p[j++]);
    }
    for(int k=0;k<help.size();k++)
    {
        vec_p[L+k]=help[k];
    }
}

/*********************************************
*函数功能：逆序对问题
*参数说明
*    输入：6,6,6,1,1,1
*    输出：9
*时间复杂度：O(nlgn) 空间复杂度 O(n)
*作者：guoliang zheng
*日期：2018-08-31-18.18
***********************************************/
int Class4_N4_a::countSmaller(vector<int>& nums)
{
    if(nums.size()<2) return 0;
    return countSmaller(nums,0,nums.size()-1);
}


int Class4_N4_a::countSmaller(vector<int>& nums,int L,int R)
{
    if(L>=R) return 0;
    int mid=L+((R-L)>>1);
    int left=countSmaller(nums,L,mid);
    int right=countSmaller(nums,mid+1,R);
    return left+right+mergers(nums,L,mid,R);
}
int Class4_N4_a::mergers(vector<int>& nums,int L,int mid,int R)
{
    int i=L;
    int j=mid+1;
    vector<int> help;
    int res=0;
    while(i<=mid && j<=R)
    {
        if(nums[i]>nums[j])
        {
            help.push_back(nums[j]);
            res+=(mid-i+1);
            j++;
        }else
        {
            help.push_back(nums[i++]);
        }
    }
    while(i<=mid)
    {
        help.push_back(nums[i++]);
    }
    while(j<=R)
    {
        help.push_back(nums[j++]);
    }
    for(int k=0;k<help.size();k++)
    {
        nums[k+L]=help[k];
    }
    return res;
}

