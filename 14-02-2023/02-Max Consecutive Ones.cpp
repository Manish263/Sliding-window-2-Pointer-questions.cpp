Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
  
  
  'ANS:
     int longestOnes(vector<int>& a, int k) {
        int i=0,j=0,ans=INT_MIN,c=0;
        int n=a.size();
        while(j<n){
            if(a[j]==0 ) c++; //if 1 find keep continue otherwise count no of 0's
            while(c>k) {
                if(a[i]==0) {
                    c--; //whenever 0's cnt exceeds then k need to shift window so when find a[i]=0 reduce 0 count. until its <k
                }
                i++;
            }
            ans=max(ans,j-i+1); //keep calculating max length.
            j++;
        }
        return ans;
    }
      
