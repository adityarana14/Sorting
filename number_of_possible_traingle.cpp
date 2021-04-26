int findNumberOfTriangles(int arr[], int n){
        // code here
        //(arr,arr+n,greater<int> ());
        
        for(int i=0;i<n;i++)
	    {		
	    	for(int j=i+1;j<n;j++)
		        {
			        if(arr[i]<arr[j])
			            {
				            int temp  =arr[i];
				            arr[i]=arr[j];
				            arr[j]=temp;
		    	        }
		         }
	    }

        
        int count = 0;
        for(int start=0;start<n-2;start++)
        {
            int first = start+ 1;
            int last = n-1;
            while(first<last)
            {
            
                if(arr[first]+arr[last]>arr[start])
                {
                    count = count + last - first;
                    first++;
                }
                else
                {
                    last--;
                }
            }
            
        }
        
        return count;
    }
