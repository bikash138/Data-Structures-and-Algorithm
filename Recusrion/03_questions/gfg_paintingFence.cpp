class Solution {
  public:
    int countWays(int n, int k) {
        // Base Case
        if(n == 1) return k;
        if(n == 2) return k + k*(k-1);
        
        /* 
        Total ways will be (same last two posts + different last two posts) 
        same last two posts: 
        - If we fix the last to fence colors then we will have f(n-2)*(k-1) ways
        different last two posts
        - If we want different colors for the last two fence the we can paint the
          first (n-1) fences.
        - Now paint the nth fence but it must be different from (n-1)th post so 
          for this we have (k-1) ways
        - THerefore for for the different fence case we have total
          f(n-1) * (k-1) ways

        Now our answer will contain both the case hecne on adding we have:
            f(n) = different + same
            f(n) = f(n - 1)(k - 1) + f(n - 2)(k - 1)
            f(n) = (k - 1) [ ways(n - 1) + ways(n - 2) ]
        */
        int ans = (k-1) * (countWays(n-1, k) + countWays(n-2, k));
        
        return ans;
    }
};