Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
  
  ANS:
    int longestKSubstr(string s, int k) {
        int i=0,j=0,n=s.size(),ans=-1;
        if (k<=0) return -1; 
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++;// increment the count of the character at the right pointer position
            
     // move the left pointer to the right until the
     //number of unique characters in the substring is less than k
            while(m.size()>k){
                m[s[i]]--;
                // if the count becomes zero, remove the character from the hash table
               if(m[s[i]]==0) m.erase(s[i]);
               i++;
            }
            if(m.size()==k) {ans=max(ans,j-i+1);}
            j++;
        }
        return ans;
    }
