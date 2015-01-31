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
