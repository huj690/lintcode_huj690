class Solution {
public:
  void qsort(vector<int> &num, int begin, int end) {
	  if (begin < end) {
	  	int index = partition(num, begin, end);
	  	qsort(num, begin, index - 1);
	  	qsort(num, index + 1, end);
	  }
  }
  
private:
  int partition(vector<int> &num, int begin, int end) {
    int key = num[begin];
    int i = begin, j = end;
    while (i < j) {
      while (i < j && num[j] > key) {
        j--;
      }
      if (i < j) {
        num[i] = num[j];
        i++;
      }
      while (i < j && num[i] <= key) {
        i++;
      }
      if (i < j) {
        num[j] = num[i];
        j--;
      }
    }
    num[i] = key;
    return i;
  }

};
