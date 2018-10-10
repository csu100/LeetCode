#include "Class3.h"


/*********************************************
*�������ܣ�//���ǹ�
*����˵��
*    ���룺g={5,10,2,9,15,9};// ������������
           s={6,1,20,3,8};//�ǹ���С
*    �����3
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-22.45
***********************************************/
int Class3_N1::findContentChildren(vector<int>& g,vector<int>& s)
{
    if(g.size()<1 || s.size()<1) return 0;
    int children=0;
    int cookie=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(cookie<s.size() && children<g.size())
    {
        if(s[cookie]>=g[children])
        {
            children++;
        }
        cookie++;
    }
    return children;
}

/*********************************************
*�������ܣ�ҡ�����е�������еĳ���
*����˵��
*    ���룺1,17,5,10,13,15,10,5,16,8
*    �����7
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-22.59
***********************************************/
int Class3_N2::wiggleMaxLength(vector<int>& nums)
{
    if(nums.size()<2) return nums.size();
    int state=0;
    const int Begin=0;
    const int up=1;
    const int down=2;
    int res=1;
    for(int i=1;i<nums.size();i++)
    {
        switch(state)
        {
        case Begin:
            if(nums[i]>nums[i-1])
            {
                res++;
                state=up;
            }else if(nums[i]<nums[i-1])
            {
                res++;
                state=down;
            }
            break;
        case up:
            if(nums[i]<nums[i-1])
            {
                res++;
                state=down;
            }
            break;
        case down:
            if(nums[i]>nums[i-1])
            {
                res++;
                state=up;
            }
            break;
        }
    }
    return res;
}



/*********************************************
*�������ܣ�// �Ƴ�K�����֣������С�Ŀ���������
*����˵��
*    ���룺143219 ,3 ;;100200,1
*    �����1219;;  200
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-23.33
***********************************************/
string Class3_N3::removeKdigits(string num,int k)
{
    if(num.size()<1 || k<1) return num;
    if(num.size()<k) return "0";
    vector<int> S;
    for(int i=0;i<num.size();i++)
    {
        int temp=num[i]-'0';
        while(S.size()>0 && temp<S[S.size()-1] && k>0)
        {
            S.pop_back();
            k--;
        }
        if(S.size()>0 || temp!=0)
        {
            S.push_back(temp);
        }
    }
    while(S.size()>0 && k>0)
    {
        S.pop_back();
        k--;
    }
    if(S.size()==0)
    {
        return "0";
    }
    string res="";
    for(int i=0;i<S.size();i++)
    {
        res+=(char)(S[i]+'0');
    }
    return res;
}

/*********************************************
*�������ܣ���Ծ��Ϸ,�Ƿ���Դ�0λ����Ծ�����һ��Ԫ�ص�λ��
*����˵��
*    ���룺[2,3,1,1,4];[3,2,1,0,4]
*    �����true; false;
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-23.33
***********************************************/
bool Class3_N4::canJump(vector<int>& nums)
{
    if(nums.size()<2) return true;
    int maxR=nums[0];
    for(int i=1;i<nums.size() && i<=maxR;i++)
    {
        if(nums[i]+i>maxR)
        {
            maxR=i+nums[i];
            if(maxR>=nums.size()-1)
            {
                return true;
            }
        }
    }
    if(maxR>=nums.size()-1)
    {
        return true;
    }else
    {
        return false;
    }
}

/*********************************************
*�������ܣ���Ծ��Ϸ,��0λ����Ծ�����һ��Ԫ�ص�λ�� ������Ծ����
*����˵��
*    ���룺[2,3,1,1,4]
*    �����2
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-23.33
***********************************************/
int Class3_N4::jump(vector<int>& nums) //������Ծ����
{
    if(nums.size()<2) return 0;
    int currMaxR=nums[0];
    int preMaxR=nums[0];
    int res=1;
    for(int i=1;i<nums.size() && i<=preMaxR;i++)
    {
        if(i>currMaxR)
        {
            res++;
            currMaxR=preMaxR;
        }
        if(preMaxR<nums[i]+i)
        {
            preMaxR=nums[i]+i;
        }
    }
    if(preMaxR>=nums.size()-1)
    {
        return res;
    }else
    {
        return 0;
    }
}


/*********************************************
*�������ܣ� ����������⣬������Ҫ���ٸ�������
*����˵��
*    ���룺[[10,16], [2,8], [1,6], [7,12]]
*    �����2
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-30-23.33
***********************************************/
bool CMP(const pair<int,int> a,const pair<int,int> b)
{
    return a.first<b.first;// ��С����
}
int Class3_N5::findMinArrowShots(vector<pair<int,int> >&points)
{
    if(points.size()<2) return points.size();
    sort(points.begin(),points.end(),CMP);
    int shoot=1;
    int bigin=points[0].first;
    int ends=points[0].second;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].first<=ends)
        {
            if(points[i].second<ends)
            {
                ends=points[i].second;
            }
        }else
        {
            shoot++;
            ends=points[i].second;
        }
    }
    return shoot;
}

/*********************************************
*�������ܣ����ż��ͷ���������һ����λ������һ����λ�ľ���
*����˵��
*    ���룺L:��㵽�յ�ľ��룬P������ʼ����������pair<����վ���յ�ľ��룬����վ������>
*    ��������ټӼ����ͣ��޷�����򷵻�-1
*ʱ�临�Ӷȣ�O() �ռ临�Ӷ� O()
*���ߣ�guoliang zheng
*���ڣ�2018-08-31-08.41
***********************************************/
bool CMP1(const pair<int,int> a,const pair<int,int> b)
{
    return a.first>b.first;//�Ӵ�С
}
int Class3_N6::get_mininum_step(int L,int P,vector<pair<int,int> >& step)
{
    if(L<1 || P<1 ||step.size()<1) return 0;
    priority_queue<int,vector<int>,less<int> > Q;
    int result=0;
    step.push_back(make_pair(0,0));
    sort(step.begin(),step.end(),CMP1);
    for(int i=0;i<step.size();i++)
    {
        int dis=L-step[i].first;
        while(!Q.empty() && P<dis)
        {
            P+=Q.top();
            Q.pop();
            result++;
        }
        if(Q.empty() && P<dis)
        {
            return -1;
        }
        P=L-dis;
        L=step[i].first;
        Q.push(step[i].second);

    }
    return result;
}
