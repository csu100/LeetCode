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

class Class7_N1  // �����ַ������ܹ����ɵ�����Ĵ�����
{
public:
    int longestPalindrome(string s);
};


class Class7_N2  // ����ģʽƥ��
{
    bool wordPattern(string pattern,string str);
};

class Class7_N3  // ͬ�ַ��������
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& str);
};

class Class7_N4 // ���ظ��ַ�����Ӵ�
{
public:
    int lengthOfLongestSubstring(string s);
};

class Class7_N5  // �ظ�DNA����
{
public:
    vector<string> findRepeatedDnaSequences(string s);
private:
    int char_to_int(char C);
};


class Class7_N6 // ��С�����Ӵ�
{
public:
    string minWindow(string n,string t);
private:
    bool is_Include(int mn[],int mt[],vector<char> vec_t);
};








#endif // CLASS7_H_INCLUDED
