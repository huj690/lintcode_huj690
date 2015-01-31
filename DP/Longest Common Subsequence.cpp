class Solution {
public:    
    int longestCommonSubstring(string &A, string &B) {
        if (A.empty() || B.empty()) {
            return 0;
        }
        
		int i_index, j_index;
        vector<vector<int> > dp(A.length() + 1, vector<int> (B.length() + 1, 0));
        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
				i_index = i - 1;
				j_index = j - 1;
                dp[i][j] = max(dp[i - 1][j], 
                           max (dp[i][j - 1], 
                           A[i_index] == B[j_index] ? dp[i - 1][j - 1] + 1 : dp[i - 1][j - 1]));
            }
        }
        
        return dp[A.length()][B.length()];
    }
};


//优化为只有2 * n行而不是m * n
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if (A.empty() || B.empty()) {
            return 0;
        }
        
		int i_index, j_index, maxCnt = 0;
        vector<int> dp_prev(B.length() + 1, 0);
        vector<int> dp(B.length() + 1, 0);
        
        for (int i = 1; i <= A.length(); i++) { 
            for (int j = 1; j <= B.length(); j++) {
                i_index = i - 1;
                j_index = j - 1;
                if (A[i_index] == B[j_index]) {
                    dp[j] = dp_prev[j - 1] + 1;
                    maxCnt = max(dp[j], maxCnt);
                }
            }
            dp_prev = dp;
            dp.assign(B.length() + 1, 0);
        }
        return maxCnt;
    }
};
