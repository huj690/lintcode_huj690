class Solution {
public:
  void mergeSort(vector<int> &num, int begin, int end) {
  	if (begin < end) {
  		int mid = begin + (end - begin) / 2;
  		mergeSort(num, begin, mid);
  		mergeSort(num, mid + 1, end);
  		merge(num, begin, mid, end);
  	}
  }
  
private:
	void merge(vector<int> &num, int begin, int mid, int end) {
		vector<int> left(num.begin() + begin, num.begin() + mid + 1);
		vector<int> right(num.begin() + mid + 1,  num.begin() + end + 1);
		left.push_back(INT_MAX);
		right.push_back(INT_MAX);
		
		int i = 0, j = 0;
		for (int k = begin; k <= end; k++) {
			if (left[i] <= right[j]) {
				num[k] = left[i++];
			} else {
				num[k] = right[j++];
			}
		}
	}
};
