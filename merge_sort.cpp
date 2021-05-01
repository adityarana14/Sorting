#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& v,int start, int end, int mid)
{
    //cout<<"start mid and end values are "<<start<<" "<<mid<<" "<<end<<endl;
    vector<int> left;
    vector<int> right;
    
    
    for(int i=start;i<=mid;i++)
    {
        left.push_back(v[i]);
    }
    for(int i=mid+1;i<=end;i++)
    {
        right.push_back(v[i]);
    }
    int i=0;
    int j =0 ;
    vector<int> answer;
    while(i!=left.size()&&j!=right.size())
    {
            if(left[i]>right[j])
            {
                answer.push_back(right[j]);
                j++;
            }
            else{
               answer.push_back(left[i]);
               i++;
            }
    }

    while(i!=left.size())
    {
        answer.push_back(left[i]);
        i++;

    }

    while(j!=right.size())
    {
        answer.push_back(right[j]);
        j++;
    }
int m=0;
    for(int k=start;k<=end;k++)
    {
            v[k]=answer[m];
            m++;
    }
   
cout<<"intermediate sorted array : "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
// for(int i=0;i<answer.size();i++)
// {
//     cout<<answer[i]<<" ";
// }
// cout<<endl;

}

void merge_sort(vector<int>& v,int start,int end)
{
   
    if(start<end)
    {
        int mid = (start+end)/2;
        merge_sort(v,start,mid);
        merge_sort(v,mid+1,end);
        merge(v,start,end,mid);
    }


}

int main()
{
    vector<int> v={9,8,7,6,5,4,3};
    merge_sort(v,0,v.size()-1);

    cout<<"final sorted array : "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
   
  
    return 0;
}