You are visiting a farm that has a single row of fruit trees arranged from left to right.The trees are represented by an integer array fruits of size N, 
where fruits[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible.However,the owner has some strict rules that you must follow :

You only have two baskets , and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice,you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits , return the maximum number of fruits you can pick.


Example 1:

Input:
N = 3
fruits [ ] = { 2, 1, 2 }
Output: 3
Explanation: We can pick from all three tree


'ANS: 
     int totalFruits(int n, vector<int> &fruits) {
       map<int,int>baskets;
       int l=0,r=0,ans=0;
       while(r<n){
           baskets[fruits[r]]++;
           if(baskets.size()<=2) {
               ans=max(ans,r-l+1); //our ans is window size only 
           }
           else {
               baskets[fruits[l]]--; //if we get more fruits in basket on moving right
                            //then we remove left side fruit ans move our window to right
               if(baskets[fruits[l]]==0) baskets.erase(fruits[l]);
               l++;
           }
           r++;
       }
       return ans;
    }
