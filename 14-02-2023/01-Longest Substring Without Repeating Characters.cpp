Given a string s, find the length of the longest 
substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

ANS: 
   int lengthOfLongestSubstring(string s) {
        int n=s.size(),i,ans=INT_MIN;
        int l=0;
        unordered_set<int>st;
        for (i=0;i<n;i++) {
           if(st.find(s[i])!=st.end()){ 
               while(l<i && st.find(s[i])!=st.end()){ //if duplicate element is found remove it's previous version from set and move left pointer ahead.
                   st.erase(s[l]);
                   l++;
               }
           }
           st.insert(s[i]); //keep inserting right pointer 
           ans=max(ans,i-l+1); // tracking max substring.
        } 
        if(s.size()==0) return 0;
        return ans;
    }
