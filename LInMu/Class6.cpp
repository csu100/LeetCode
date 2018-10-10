#include "Class6.h"


/*********************************************
*�������ܣ�����λ��(���ظ�Ԫ�أ�
*����˵��
*    ���룺[1,3,5,6], 7
*    �����4
*ʱ�临�Ӷȣ�O(nlgn) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-01-16.14
***********************************************/
int Class6_N1::searchInsert(vector<int>& nums,int target)
{
    if(nums.size()<1) return 0;
    int L=0;
    int R=nums.size()-1;
    while(L<=R)
    {
        int mid=L+((R-L)>>1);
        if(nums[mid]==target)
        {
            return mid;
        }else if(nums[mid]<target)
        {
            if(mid==nums.size()-1 || nums[mid+1]>target)
            {
                return mid+1;
            }
            L=mid+1;
        }else if(nums[mid]>target)
        {
            if(mid==0 || nums[mid-1]<target)
            {
                return mid;
            }
            R=mid-1;
        }
    }
    return 0;
}

/*********************************************
*�������ܣ�������� ������һ����������(���ظ�Ԫ��)����targetĿ��ֵ��δ�ҵ��򷵻�[-1,-1];
*����˵��
*    ���룺nums = [5,7,7,8,8,10], target = 8
*    �����[3,4]
*ʱ�临�Ӷȣ�O(NlogN) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-01-16.14
***********************************************/
vector<int> Class6_N2::searchRange(vector<int>& nums,int target)
{
    vector<int> res(2,-1);
    if(nums.size()<1) return res;
    res[0]=searchLeft(nums,target,0,nums.size()-1);
    if(res[0]==-1)
    {
        return res;
    }
    res[1]=searchRight(nums,target,res[0],nums.size()-1);
    return res;
}


int Class6_N2::searchLeft(vector<int>& nums,int target,int L,int R)
{
    if(L>R || nums.size()<1) return -1;
    while(L<=R)
    {
        int mid=L+((R-L)>>1);
        if(nums[mid]==target)
        {
            if(mid==0 || nums[mid-1]<target)
            {
                return mid;
            }
            R=mid-1;
        }else if(nums[mid]<target)
        {
            L=mid+1;
        }else if(nums[mid]>target)
        {
            R=mid-1;
        }
    }
    return -1;
}
int Class6_N2::searchRight(vector<int>& nums,int target,int L,int R)
{
    if(L>R || nums.size()<1) return -1;
    while(L<=R)
    {
        int mid=L+((R-L)>>1);
        if(nums[mid]==target)
        {
            if(mid==nums.size()-1 || nums[mid+1]>target)
            {
                return mid;
            }
            L=mid+1;
        }else if(nums[mid]>target)
        {
            R=mid-1;
        }else if(nums[mid]<target)
        {
            L=mid+1;
        }
    }
    return -1;
}


/*********************************************
*�������ܣ���ת����Ĳ���
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O(NlgN) �ռ临�Ӷ� O(1)
*���ߣ�guoliang zheng
*���ڣ�2018-09-01-22.54
***********************************************/
int Class6_N3::Search(vector<int>& nums,int target)
{
    if(nums.size()<1) return -1;
    int L=0;
    int R=nums.size()-1;
    while(L<=R)
    {
        int mid=L+((R-L)>>1);
        if(nums[mid]==target)
        {
            return mid;
        }else if(target<nums[mid])
        {
            if(nums[L]<nums[mid]) //L:mid-1 ��; mid+1:R -��ת
            {
                if(target>nums[L])
                {
                    R=mid-1;
                }else if(target<nums[L])
                {
                    L=mid+1;
                }else if(target==nums[L])
                {
                    return L;
                }
            }else if(nums[L]>nums[mid]) //L:mid-1 ��ת;mid+1:R ��
            {
                R=mid-1;
            }else if(nums[L]==nums[mid])
            {
                L=mid+1;
            }
        }else if(target>nums[mid])
        {
            if(nums[L]<nums[mid]) //L:mid-1 ��; mid+1:R ��ת
            {
                L=mid+1;
            }else if(nums[L]>nums[mid]) // L:mid-1 ��ת; mid+1:R ��
            {
                if(target>nums[L])
                {
                    R=mid-1;
                }else if(target<nums[L])
                {
                    L=mid+1;
                }else if(target==nums[L])
                {
                    return L;
                }
            }else if(nums[L]==nums[mid])
            {
                L=mid+1;
            }

        }
    }
    return -1;
}



void Class6_N4_::BST_insert(TreeNode* root,TreeNode* target)
{
     if(root->val > target->val)
     {
         if(root->left)
         {
             BST_insert(root->left,target);
         }else
         {
             root->left=target;
         }
     }else if(root->val < target->val)
     {
         if(root->right)
         {
             BST_insert(root->right,target);
         }else
         {
             root->right=target;
         }
     }else if(root->val == target->val)
     {
         return ;
     }
}
bool Class6_N4_::BST_search(TreeNode* root,int value)
{
    if(root==NULL) return false;
    if(root->val > value)
    {
        if(root->left)
        {
            BST_search(root->left,value);
        }else
        {
            return false;
        }
    }else if(root->val < value)
    {
        if(root->right)
        {
            BST_search(root->right,value);
        }else
        {
            return false;
        }
    }else if(root->val == value)
    {
        return true;
    }
}

void Class6_N4_::pre_Tree(TreeNode* root)
{
    if(root==NULL) return ;
    pre_Tree(root,0);
}

void Class6_N4_::pre_Tree(TreeNode* root,int layer)
{
    if(root==NULL) return ;
    for(int i=0;i<layer;i++)
    {
        cout<<"--";
    }
    cout<<root->val<<endl;
    pre_Tree(root->left,layer+1);
    pre_Tree(root->right,layer+1);
}

/*********************************************
*�������ܣ��������ı��������
*����˵��
*    ���룺
*    �����
*ʱ�临�Ӷȣ�O() �ռ临�Ӷ� O()
*���ߣ�guoliang zheng
*���ڣ�2018-09-01-23.47
***********************************************/
string Class6_N4::serialize(TreeNode* root)
{
    if(root==NULL) return "#!";
    string str="";
    serialize(root,str);
    return str;
}

void Class6_N4::serialize(TreeNode* root,string& str)
{
    if(root==NULL)
    {
        str+="#!";
        return ;
    }
    str+=to_string(root->val)+'!';
    serialize(root->left,str);
    serialize(root->right,str);
}

TreeNode* Class6_N4::deserialize(string data)
{
    if(data.size()<1) return NULL;
    string word="";
    queue<string> Q;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]=='!')
        {
            Q.push(word);
            word="";
        }else
        {
            word+=data[i];
        }
    }
    return deserialize(Q);
}


TreeNode* Class6_N4::deserialize(queue<string>& Q)
{
    string temp=Q.front();
    Q.pop();
    if(temp=="#")
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(string_to_int(temp));
    root->left=deserialize(Q);
    root->right=deserialize(Q);
    return root;
}


int Class6_N4::string_to_int(string str)
{
    int number=0;
    for(int i=0;i<str.size();i++)
    {
        number=number*10+str[i]-'0';
    }
    return number;
}










