/*
给定一个数组A[1..n]，求数组B[1..n]，使得B[i] = A[1] * A[2] .. * A[i-1] * A[i+1] .. * A[n]。要求不要使用除法，且在O(n)的时间内完成，使用O(1)的额外空间（不包含B数组所占空间）。
*/

class Solution {
public:
  vector<int> multiplication(vector<int> A) {
    vector<int> B (A.size(), 1);
    if (A.empty()) {
        return B;
    }
    int index = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (i < j) {
                B[j] *= A[i];
            }
        }
    }
    
    
  }

}
