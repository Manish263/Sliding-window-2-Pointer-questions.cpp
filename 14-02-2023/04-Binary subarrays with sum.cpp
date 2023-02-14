
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

ANS: 
    int helper(vector<int>& a, int g){
        int n=a.size();
        int i=0,j=0,c=0,s=0;
        if(g<0) return 0;
        while(i<n){
            s+=a[i]; //keep calculating sum until it exceds goal. as soon as we exceds
            while(s>g){
                s-=a[j];j++;//if s exceds goal we remove from start poitner and shift our window to right and make sum ==goal.
            }
            c+=(i-j+1); // gives us no of subarrays.
            i++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& a, int g) {
      return  helper(a,g)-helper(a,g-1); //number of subarrays with atMost goal - number of subarrays with atMost goal-1 = number of subarray with sum exactly goal
    }
