#ifndef CLASS7_H_INCLUDED
#define CLASS7_H_INCLUDED

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

class Class7_N1  // 给定字符串中能够生成的最长回文串长度
{
public:
    int longestPalindrome(string s);
};


class Class7_N2  // 词语模式匹配
{
    bool wordPattern(string pattern,string str);
};

class Class7_N3  // 同字符词语分组
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& str);
};

class Class7_N4 // 无重复字符的最长子串
{
public:
    int lengthOfLongestSubstring(string s);
};

class Class7_N5  // 重复DNA序列
{
public:
    vector<string> findRepeatedDnaSequences(string s);
private:
    int char_to_int(char C);
};


class Class7_N6 // 最小窗口子串
{
public:
    string minWindow(string n,string t);
private:
    bool is_Include(int mn[],int mt[],vector<char> vec_t);
};








#endif // CLASS7_H_INCLUDED
