#include "Class2.h"


/*********************************************
*�������ܣ����ö���ʵ��ջ�Ĺ���
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(1) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-08-27-21.58
***********************************************/
void My_stack::push(int x)
{
    queue<int> temp;
    temp.push(x);
    while(!data.empty())
    {
        temp.push(data.front());
        data.pop();
    }
    while(!temp.empty())
    {
        data.push(temp.front());
        temp.pop();
    }
}
int My_stack::top()
{
    if(data.empty())
    {
        throw "stack is empty!";
    }
    return data.front();
}
int My_stack::pop()
{
    if(data.empty())
    {
        throw "stack is empty!";
    }
    int x=data.front();
    data.pop();
    return x;
}
bool My_stack::empty()
{
    return data.empty();
}

/*********************************************
*�������ܣ�����ջʵ�ֶ���
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(1) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-27-22.17
***********************************************/
void My_queue::push(int x)
{
    data.push(x);
}
int My_queue::peek()
{
    if(output.empty())
    {
        adjust();
    }
    if(output.empty())
    {
        throw "queue is empty!";
    }
    return output.top();
}
void My_queue::adjust()
{
    if(output.empty())
    {
        while(!data.empty())
        {
            output.push(data.top());
            data.pop();
        }
    }
}
int My_queue::pop()
{
    if(output.empty())
    {
        adjust();
    }
    if(output.empty())
    {
        throw "queue is empty!";
    }
    int x=output.top();
    output.pop();
    return x;
}
bool My_queue::empty()
{
    return (data.empty() && output.empty());
}


/*********************************************
*�������ܣ���Сջ������ʵ��
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(1) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-08-28-23.04
***********************************************/
void MinStack::push(int x)
{
    if(MinD.empty())
    {
        MinD.push(x);
    }else
    {
        if(MinD.top()>=x)
        {
            MinD.push(x);
        }
    }
    data.push(x);
}
int MinStack::pop()
{
    if(data.empty())
    {
        throw "stack is empty!";
    }
    int x=data.top();
    data.pop();
    if(x==MinD.top())
    {
        MinD.pop();
    }
    return x;
}
int MinStack::top()
{
    if(data.empty())
    {
        throw "stack is empty!";
    }
    return data.top();
}
int MinStack::getMin()
{
    if(MinD.empty())
    {
        throw "stack is empty!";
    }
    return MinD.top();
}

/*********************************************
*�������ܣ�//�ж��Ƿ�Ϊ�Ϸ�����
*����˵��
*    ���룺1��2��3��4��5;5,4,1,2,3
*    �����Yes;No
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-08-28-23.12
***********************************************/
bool valid_order::check_is_valid_order(queue<int>& order)
{
    if(order.empty()) return true;
    stack<int> S;
    int len=order.size();
    for(int i=1;i<=len;i++)
    {
        S.push(i);
        while(!S.empty() && S.top()==order.front())
        {
            S.pop();
            order.pop();
        }
    }
    if(S.empty())
    {
        return true;
    }else
    {
        return false;
    }
}

/*********************************************
*�������ܣ����׵ļ�����
*����˵��
*    ���룺" 48*((70- 65 ) -43 )+8*1"
*    ����� -1816
*ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-08-29-23.30
***********************************************/
int Calculate_N5::calculate(string str)
{
    if(str.size()<1) return 0;
    vector<int> res(2,0);
    res=calculates(str,0);
    return res[0];
}

vector<int> Calculate_N5::calculates(string str,int i)
{
    deque<string> data;
    string number="";
    vector<int> bra(2,0);
    while(i<str.size() && str[i]!=')')
    {
        if(str[i]==' ')
        {
            i++;continue;
        }
        if(str[i]>='0' && str[i]<='9')
        {
            number+=str[i++];
        }else if(str[i]!='(') // + - * /
        {
           add_num(data,number);
           string temp="";
           switch(str[i++])
           {
               case '+':temp="+";break;
               case '-':temp="-";break;
               case '*':temp="*";break;
               case '/':temp="/";break;
           }
           data.push_back(temp);
           number="";
        }else  // (
        {
            bra=calculates(str,i+1);
            number=to_string(bra[0]);
            i=bra[1]+1;
        }
    }
    add_num(data,number);
    vector<int> res(2,0);
    res[0]=get_num(data);
    res[1]=i;
    return res;
}
void Calculate_N5::add_num(deque<string>& data,string num)
{
    int number=string_to_int(num);
    if(!data.empty())
    {
        string cur="";
        cur=data.back();
        data.pop_back();
        if(cur=="+" || cur=="-")
        {
            data.push_back(cur);
        }else
        {
            int first=string_to_int(data.back());
            data.pop_back();
            number=cur=="*"?first*number:first/number;
        }
    }
    data.push_back(to_string(number));

}
int Calculate_N5::get_num(deque<string>& data)
{
    int number=0;
    bool flag=true;

    while(!data.empty())
    {
        string cur=data.front();
        data.pop_front();
        if(cur=="+")
        {
            flag=true;
        }else if(cur=="-")
        {
            flag=false;
        }else
        {
            number+=flag?string_to_int(cur):0-string_to_int(cur);
        }
    }
    return number;
}
int Calculate_N5::string_to_int(string str)
{
    int i=0;
    bool flag=true;
    if(str[i]=='-')
    {
        i++;flag=false;
    }
    int number=0;
    for(;i<str.size();i++)
    {
        number=number*10+str[i]-'0';
    }
    return flag?number:0-number;
}

/*********************************************
*�������ܣ������е�K�����
*����˵��
*    ���룺3,2,3,1,2,4,5,5,6;k=4
*    �����4
*ʱ�临�Ӷȣ�O(nlgk) �ռ临�Ӷ� O(k)
*���ߣ�guoliang zheng
*���ڣ�2018-08-29-23.45
***********************************************/
int FindKth_N6::findKthLargest(vector<int>& nums,int k)
{
    if(nums.size()<1 || k<1 || nums.size()<k) return 0;
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i=0;i<nums.size();i++)
    {
        if(Q.size()<k)
        {
            Q.push(nums[i]);
        }else
        {
            if(Q.top()<nums[i])
            {
                Q.pop();
                Q.push(nums[i]);
            }
        }
    }
    return Q.top();
}



/*********************************************
*�������ܣ�Ѱ����λ��
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(lgN) �ռ临�Ӷ� O(N)
*���ߣ�guoliang zheng
*���ڣ�2018-08-29-23.45
***********************************************/
void FindMedian_N6::addNum(int num)
{
    if(Qmax.empty())
    {
        Qmax.push(num);return ;
    }
    if(Qmax.size()==Qmin.size())
    {
        if(Qmax.top()>num)
        {
            Qmax.push(num);
        }else
        {
            Qmin.push(num);
        }
    }else if(Qmax.size()>Qmin.size())
    {
         if(Qmax.top()>num)
         {
             Qmin.push(Qmax.top());
             Qmax.pop();
             Qmax.push(num);
         }else
         {
             Qmin.push(num);
         }
    }else if(Qmax.size()<Qmin.size())
    {
        if(Qmin.top()<num)
        {
            Qmax.push(Qmin.top());
            Qmin.pop();
            Qmin.push(num);
        }else
        {
           Qmax.push(num);
        }
    }
}
double FindMedian_N6::findMedian()
{
    if(Qmax.empty() && Qmin.empty()) return 0.0;
    if(Qmax.size()==Qmin.size())
    {
        return (Qmin.top()+Qmax.top())/2.0;
    }else if(Qmax.size()>Qmin.size())
    {
        return Qmax.top();
    }else
    {
        return Qmin.top();
    }
}











