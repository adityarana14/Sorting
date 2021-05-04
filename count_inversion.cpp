
#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:


    vector<long long > v;
    long long int inversion=0;
    
    
    void merging(vector<long long>& v,long long left, long long mid , long long right)
    {
        cout<<"left mid and right value "<<left<<" "<<mid<<" "<<right<<endl; 
        vector<long long> first;
        vector<long long> second;
        long long equi=left;
        long long p=0,q=0;
        
        for(long long i= left; i<=mid;i++)
        {
            first.push_back(v[i]);
        }
        for(long long i = mid+1 ; i<=right;i++)
        {
            second.push_back(v[i]);
        }
        
        while(p<first.size() && q<second.size())
        {
            if(first[p]<=second[q])
            {
                
                v[equi]=first[p];
                p++;
                equi++;
            }
            else
            {
                v[equi]=second[q];
                q++;
                equi++;
                inversion = inversion + mid - p;
            }
        }
        
        while(p!=first.size())
        {
            v[equi]=first[p];
            p++;
            equi++;
        }
        while(q!=second.size())
        {
            v[equi]=second[q];
            q++;
            equi++;
        }
        
        cout<<"partial output"<<endl;
        
        for(long long i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        
    }
    
    
    
    
    
    void merge(vector<long long>& v,long long left,long long right)
    {
        if(left<right)
        {
            long long mid = (left+ right)/2;
            merge(v,left,mid);
            merge(v,mid+1,right);
            merging(v,left,mid,right);
            
        }
        
    }
        
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        
        for(long long i=0;i<N;i++)
        v.push_back(arr[i]);
    
        merge(v,0,N-1);
        return inversion;
        
    }

};

int main()
{
   
        long long N;
        cin>>N;

        long long A[N];
        for(long long i = 0;i<N;i++)
        {
            cout<<"enter number "<<i+1<<endl;
            cin>>A[i];
        }
        cout<<"done inputting"<<endl;
        Solution obj;
        cout<<obj.inversionCount(A,N)<<endl;
    
    return 0;
    }
