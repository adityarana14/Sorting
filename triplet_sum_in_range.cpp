class Solution {
  public:
  
  int count1(int arr[],int n , int val )
  {
      int count=0;
   for(int start=0;start<n-2;start++)
        {
            int left = start + 1;
            int right = n-1;
            while(left<right)
            {
                if(arr[start]+arr[left]+arr[right]<=val)
                {
                    count=count+right-left;
                    right--;
                }
                else{
                    left++;
                }
                
            }
        }
        
        return count;
    }
      
  
  
    int countTriplets(int arr[], int n, int L, int R) {
        // code here
        sort(arr,arr+n,greater<int>());
        int count =0;
        
        //sum of triplet where sum is less than or equal to upper limit - sum 
        //of triplet where sum is less than or equal to lowerlimit -1 
        //lowerlimit -1 because we want lowerlimit to be inclusive.
        int answer= count1(arr,n,R)-count1(arr,n,L-1);
        
        
        return answer;
    }
       
};