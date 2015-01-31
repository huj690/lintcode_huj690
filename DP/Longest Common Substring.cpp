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
        vector<vector<int> > dp(A.length() + 1, vector<int> (B.length() + 1, 0));
        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
				i_index = i - 1;
				j_index = j - 1;
				if (A[i_index] == B[j_index]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
                maxCnt = max(maxCnt, dp[i][j]);
            }
        }
        return maxCnt;
    }
};

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

