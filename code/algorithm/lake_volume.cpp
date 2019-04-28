#include<iostream>
#include<vector>

using namespace std;

int calcLakeVolume(vector<int>& heights, int start, int end){
  int h = min(heights[start], heights[end]); // 3
  int w = end - start + 1;  // 3
  int volume = h*w; // 9
  
  start++;
  while(start < end){
      volume -= heights[start]; // 7
      start++;
  }
  cout <<  ", volume = " << volume  << endl;
  return volume;
}

// [1, 3, 2, 4, 1, 3, 1, 4, 5, 2, 2, 1, 4, 2, 2]
// size = 15

int calculateVolume(vector<int>& heights){
    int size = heights.size();
    int index = 0;
    int volume = 0;
    
  while(index < size){
    while(index < size-1 && heights[index] < heights[index + 1]){
              index++;
    }
    if(heights[index] < heights[index + 1]){
        return volume;
    }
    int start = index;

    index++;
    while(index < size-1 && heights[index] >= heights[index + 1]){
                index++;
    }
    if(heights[index] > heights[index + 1]){
        return volume;
    }
    index++;
    int end = index;
    if(start < end){
      volume += calcLakeVolume(heights, start, end);
    }
    index++;

  }

  return volume;
}


int main(){
  int heights[] = {1, 3, 2, 4, 1, 3, 1, 4, 5, 2, 2, 1, 4, 2, 2};
  vector<int > h(heights, heights + (sizeof(heights)/sizeof(heights[0])));
  int v = calculateVolume(h);
  cout << v << endl;
  return 0;
}