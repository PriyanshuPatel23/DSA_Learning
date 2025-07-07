#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void reverseVector(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        
    }
    

void rotateImage(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < mat[i].size(); j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<n; i++) {
            reverseVector(mat[i]);
        }
} 

int main() {
    vector<vector<int>> mat;
    vector<int> in = {1,2,3};
    vector<int> v = {4,5,6};
    vector<int> o = {7,8,9};
    
    mat.push_back(in);
    mat.push_back(v);
    mat.push_back(o);
    
    rotateImage(mat);
    
    cout << "Rotated Matrix:\n";
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}