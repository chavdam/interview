#include<iostream>
#include<vector>

using namespace std;

pair<int, int> find(vector<vector<int> >& matrix, int target, int start, bool isRow){
        pair<int, int> element = make_pair(-1, -1);
        int rn = matrix.size();
        int cn = matrix[0].size();
        
        if(isRow){
            int low = 0, high = cn-1;

            while(low <= high){
                int mid = (low + high)/2;
                if(target < matrix[start][mid] ){
                    high = mid-1;
                }
                else if(target > matrix[start][mid] ){
                    low = mid+1;
                }
                else{
                    element = make_pair(start, mid);
                    break;
                }
            }
        }
        else{
            int low = 0, high = rn-1;

            while(low <= high){
                int mid = (low + high)/2;
                
                if(target < matrix[mid][start] ){
                    high = mid-1;
                }
                else if(target > matrix[mid][start] ){
                    low = mid+1;
                }
                else{
                    element = make_pair(mid, start);
                    break;
                }
            }
        }
        
        return element;
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int numOfR = matrix.size();
        if(numOfR == 0)
            return false;
        int numOfC = matrix[0].size();
        
        if(numOfR == 1 && numOfC == 1)
            return matrix[0][0] == target;
        
        pair<int, int> r;
        
        if(numOfR < numOfC){
            for(int i=0;i<numOfR; i++){
                r = find(matrix, target, i, true);
                if(r.first > -1){
                    return true;
                }
            }
        }
        else{
            for(int i=0;i<numOfC; i++){
                r = find(matrix, target, i, false);
                if(r.first > -1){
                    return true;
                }
            }
        }
        
        return false;
        
    }

    int main(){
      vector<vector<int> > test;
      vector<int> ele;
      ele.push_back(-1);
      test.push_back(ele);
      test.push_back(ele);
      searchMatrix(test, 0);
    }
