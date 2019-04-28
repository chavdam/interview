#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void swap(vector<int>& arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapify(vector<int>& arr, int n, int i){
  int iMax = i, l = 2*i + 1, r = 2*i + 2;

  if(l < n && arr[l] > arr[iMax])
    iMax = l;
  if(r < n && arr[r] > arr[iMax])
    iMax = r;

  if(iMax != i){
    swap(arr, iMax, i);
    heapify(arr, n, iMax);
  }
}

void sort(vector<int>& arr){
  int size = arr.size();
  for(int i=size/2 - 1; i>=0; i--){
    heapify(arr, size, i);
  }

  for(int i=size-1; i>=0; i--){
    swap(arr, 0, i);
    heapify(arr, i, 0);
  }
}

int main(){
  int a[] = {67, 3, 99, 12, 33, 17, 28, 4, 6, 19, 25};
  vector<int> input(a, a + sizeof(a)/sizeof(a[0]));
  sort(input);

  for(int i=0;i<input.size();i++){
    cout << input[i] << "    " ;
  }
  cout << endl;

  return 0;
}