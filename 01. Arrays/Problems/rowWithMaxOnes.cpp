#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat){
    int n = mat.size();
    vector<int>ans;
    int row = -101;
    int oneCount = INT_MIN;
    
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < mat[i].size(); j++){
            if(mat[i][j] == 1){
                count++;
            }
        }
        
        if(count > oneCount){
            oneCount = count;
            row = i;
        }
    }
    ans.push_back(row);
    ans.push_back(oneCount);
    return ans;
} 

int main() {
    vector<vector<int>> mat;
    vector<int> in = {0, 1};
    vector<int> v = {1, 0};
    
    mat.push_back(v);
    mat.push_back(in);
    
    vector<int> result = rowAndMaximumOnes(mat);
    
    cout << "Row with maximum ones: " << result[0] << endl;
    cout << "Number of ones: " << result[1] << endl;
    
    return 0;
}