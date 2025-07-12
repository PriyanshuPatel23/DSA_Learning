#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>v){
    int n = v.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    
    while(s <= e){
        if(s == e){
            return s;
        }
        
        if(v[mid] > v[mid+1]){
            return mid;
        }
        else if(v[mid] < v[mid-1]){
            return mid - 1;
        }
        else if(v[s] > v[mid]){
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main() {
    vector<int>v;
    
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    
    int pivotIndex = findPivot(v);
    cout << pivotIndex << endl;
    return 0;
}