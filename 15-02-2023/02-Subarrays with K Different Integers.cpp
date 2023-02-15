Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

ANS:
   int helper(vector<int>& a, int k){
    int n=a.size();
        int i,j,ans=0,c=0;
        i=j=0;
        unordered_map<int,int>m; // keeps track of the count of each element in the current window
        while(j<n){
            m[a[j]]++;
            while(m.size()>k){
                // shrink the window until we have k distinct elements
                m[a[i]]--;
                if(m[a[i]]==0) m.erase(a[i]);
                i++;
            }
// count the number of subarrays that end at the right endpoint of the window            
            ans+=j-i+1;
            j++;
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& a, int k) {
 // The number of good subarrays is the difference between the number of subarrays with at most k distinct elements
// and the number of subarrays with at most k-1 distinct elements.
        return helper(a,k)-helper(a,k-1);
    }
