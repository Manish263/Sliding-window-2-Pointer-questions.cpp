Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
  
  ANS:
     int helper(vector<int>&a,int k){
         int n=a.size();
        int i=0,j=0,c=0,ans=0;
//same we did find presum and if presum exceeds k then we reduce sum by subtracting start pointer and then we move our window.        
        while(j<n){
            c+=a[j];
            while(c>k){
                c-=a[i];i++;
            }
            //ans will contain all possible no of subarrays.
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& a, int k) {
        for(int i=0;i<a.size();i++){
            if(a[i]%2==1) a[i]=1;
            else a[i]=0; //we reduce our problem to Binary subarray with sum k
        }
        return helper(a,k)-helper(a,k-1); // sum of subarray of k - sum of subarrays of k-1 = exact no of subarrays.
    } 
