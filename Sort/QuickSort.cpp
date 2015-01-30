class Solution {
public:
  void qsort(vector<int> &num) {
    int index = partition(num, 0, num.size() - 1);
    partition(num, 0, index - 1);
    partition(num, index + 1, num.size() - 1);
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
