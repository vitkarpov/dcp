#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

int merge(vector<int> & arr, vector<int> & tmp, int left, int mid, int right) {
  int i, j, k;
  int result = 0;

  i = left;
  j = mid;
  k = left;

  while (i <= mid - 1 && j <= right) {
    if (arr[i] <= arr[j]) {
      tmp[k] = arr[i];
      i++;
    } else {
      tmp[k] = arr[j];
      j++;
      result += (mid - i);
    };
    k++;
  }

  while (i <= mid - 1) {
    tmp[k++] = arr[i++];
  }
  while (j <= right) {
    tmp[k++] = arr[j++];
  }

  for (int i = left; i <= right; i++) {
    arr[i] = tmp[i];
  }

  return result;
}

int mergeSortHelper(vector<int> & arr, vector<int> & tmp, int left, int right) {
  if (right <= left) {
    return 0;
  }

  int mid = (left + right) / 2;
  int result = 0;

  result += mergeSortHelper(arr, tmp, left, mid);
  result += mergeSortHelper(arr, tmp, mid + 1, right);
  result += merge(arr, tmp, left, mid + 1, right);

  return result;
}

int mergeSort(vector<int> & arr, int n) {
  vector<int> tmp(n);

  return mergeSortHelper(arr, tmp, 0, n - 1); 
}

void read(vector<int> & arr, int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  read(arr, n);

  cout << mergeSort(arr, n) << endl;
} 
