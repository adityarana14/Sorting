class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        
        unordered_map<int,int> m;
        vector<int> answer;
        auto itr=unique(A2.begin(),A2.end());
    
        sort(A1.begin(),A1.end());
        for(int i=0;i<A1.size();i++)
        {
            m[A1[i]]++;
        }
        for(auto it=A2.begin();it!=itr;it++)
        {
            auto itr1 = m.find(*it);
            if(itr1!=m.end())
            {
                  int count = m[(*it)];
                  m[(*it)]=0;
                  for(int j=0;j<count;j++)
                  {
                      answer.push_back((*it));
                  }
            
            }
            
        }
        vector<int> second;
        
        for(auto itr= m.begin();itr!=m.end();itr++)
        {
            if((*itr).second==0)
            {}
            else
            {
                int len= (*itr).second;
                while(len)
                {
                    second.push_back((*itr).first);
                    len--;
                }
                
            }
        }
        sort(second.begin(),second.end());
        int len = answer.size();
        for(int i=0;i<second.size();i++)
        {
            answer.push_back(second[i]);
        }
        
        return answer;
    } 
};