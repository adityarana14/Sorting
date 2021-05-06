class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	pair<int,char> p;
    	vector<pair<int,char>> v;//need to use vector of pair in this question 
    	for(int i=0;i<n;i++)
    	{
    	    p=(make_pair(arr[i],'a'));
    	    v.push_back(p);
    	}
    	for(int i=0;i<n;i++)
    	{
    	    p=make_pair(dep[i],'d');
    	    v.push_back(p);
    	}
    	
    	sort(v.begin(),v.end());
    	int min =1;
    	int count = 0;
    	for(auto itr=v.begin();itr!=v.end();itr++)
    	{
    	    if((*itr).second=='a')
    	    count++;
    	    else
    	    count--;
    	    
    	    if(count > min)
    	    min= count;
    	}
    	    
    	
    	return min ;
    }
};
