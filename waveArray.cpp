class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int arr[], int n){
        
        // Your code here
     
            for(int i=0;i<n;i=i+2)
            {
                if(i+1>=n)
                break;
                
                int temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }

    }
};