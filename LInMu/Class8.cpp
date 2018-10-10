#include "Class8.h"





/*********************************************
*函数功能：求岛屿数量
*参数说明
*    输入：
            11000
            11000
            00100
            00011
*    输出：3
*时间复杂度：O(N*M) 空间复杂度 O(1)
*作者：guoliang zheng
*日期：2018-09-02-22.35
***********************************************/
int Class8_N1::numIslands(vector<vector<char> >& grid)
{
    if(grid.size()<1) return 0;
    int land=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]=='1')
            {
                land++;
                numIslands(grid,i,j);
            }
        }
    }
    return land;
}


void Class8_N1::numIslands(vector<vector<char> >& grid,int x,int y)
{
    const int dx[]={-1,0,1,0};
    const int dy[]={0,1,0,-1};
    grid[x][y]='2';
    for(int i=0;i<4;i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(new_x<0 || new_x>=grid.size() || new_y<0 || new_y>=grid[0].size())
        {
            continue;
        }
        if(grid[new_x][new_y]=='1')
        {
            numIslands(grid,new_x,new_y);
            grid[new_x][new_y]='2';
        }
    }
}

/*********************************************
*函数功能：词语阶梯 转换
*参数说明
*    输入：
*    输出：
*时间复杂度：O() 空间复杂度 O()
*作者：guoliang zheng
*日期：2018-09-09-21.32
***********************************************/
int Class8_N2::ladderLength(string beginWord,string endWord,vector<string>& wordList)
{
    if(wordList.size()<1) return 0;
    map<string,vector<string> > graph;
    construct_graph(beginWord,wordList,graph);
    return BFS_graph(beginWord,endWord,graph);
}

void  Class8_N2::construct_graph(string beginWord,vector<string>& wordList,map<string,vector<string> >& graph)
{
    wordList.push_back(beginWord);
    for(int i=0;i<wordList.size();i++)
    {
        graph[wordList[i]]=vector<string>();
    }
    for(int i=0;i<wordList.size();i++)
    {
        for(int j=i+1;j<wordList.size();j++)
        {
            if(connect(wordList[i],wordList[j]))
            {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }

}
bool Class8_N2::connect(const string word1,const string word2)
{
    if(word1.size()<1 || word1.size()!=word2.size()) return false;
    int cnt=0;
    for(int i=0;i<word1.size();i++)
    {
        if(word1[i]!=word2[i])
        {
            cnt++;
            if(cnt>1)
            {
                return false;
            }
        }
    }
    return cnt==1;
}


int  Class8_N2::BFS_graph(string beginWord,string endWord,map<string,vector<string> >& graph)
{
    int step=1;
    queue<pair<string,int> > Q;
    Q.push(make_pair(beginWord,1));
    set<string> visit;
    visit.insert(beginWord);
    while(!Q.empty())
    {
        string temp=Q.front().first;
        int step=Q.front().second;
        Q.pop();
        if(temp==endWord)
        {
            return step;
        }
        vector<string> vec_t=graph[temp];
        for(int i=0;i<vec_t.size();i++)
        {
            if(visit.find(vec_t[i])==visit.end())
            {
               Q.push(make_pair(vec_t[i],step+1));
               visit.insert(vec_t[i]);
            }

        }
    }
    return 0;
}


/*********************************************
*函数功能：火柴棍摆正方形
*参数说明
*    输入：[3,3,3,3,4]    [1,1,2,2,2]
*    输出：false          true
*时间复杂度：O(2^n) 空间复杂度 O(lgn)
*作者：guoliang zheng
*日期：2018-09-09-21.32
***********************************************/
bool Class8_N4::makesquare(vector<int>& nums)
{
    if(nums.size()<4) return false;
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    if(sum%4!=0)
    {
        return false;
    }
    int single_target=sum/4;

    sort(nums.rbegin(),nums.rend());
    vector<int> bian(4,0);
    return makesquare(nums,bian,single_target,0);
}

bool Class8_N4::makesquare(vector<int>& nums,vector<int>& single,int target,int n)
{
    if(n>=nums.size())
    {
        for(int i=0;i<single.size();i++)
        {
            if(single[i]!=target)
            {
                return false;
            }
        }
        return true;
    }
    for(int i=0;i<single.size();i++)
    {
        if(single[i]+nums[n]>target)
        {
            continue;
        }
        single[i]+=nums[n];
        if(makesquare(nums,single,target,n+1))
        {
            return true;
        }
        single[i]-=nums[n];
    }
    return false;
}











