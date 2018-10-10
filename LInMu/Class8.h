#ifndef CLASS8_H_INCLUDED
#define CLASS8_H_INCLUDED

#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>


using namespace std;

class Class8_N1  // 岛屿数量
{
public:
    int numIslands(vector<vector<char> >& grid);
private:
    void numIslands(vector<vector<char> >& grid,int x,int y);
};


class Class8_N2 // 词语阶梯
{
public:
    int ladderLength(string beginWord,string endWord,vector<string>& wordList); // 从起始单词到结束单词的最短转换步数
private:
    void construct_graph(string beginWord,vector<string>& wordList,map<string,vector<string> >& graph);
    int BFS_graph(string beginWord,string endWord,map<string,vector<string> >& graph);
    bool connect(const string word1,const string word2);
};

class Class8_N4
{
public:
    bool makesquare(vector<int>& nums);
private:
    bool makesquare(vector<int>& nums,vector<int>& single,int target,int n);
};



#endif // CLASS8_H_INCLUDED
