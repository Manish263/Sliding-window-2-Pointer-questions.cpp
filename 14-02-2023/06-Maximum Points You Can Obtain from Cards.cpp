There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score.
  The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
  
  ANS:

     int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int res=0,i;
        for(i=0;i<k;i++){
            res+=a[i]; //First k elements in our window
        }
        int cur=res;
        for(i=k-1;i>=0;i--){
            //We remove the last visited element and add the non-visited element from the last
            cur-=a[i];
            cur+=a[n-k+i];
            res=max(res,cur); 
            //We check the maximum value any possible combination can give
        }
        return res;

    }
