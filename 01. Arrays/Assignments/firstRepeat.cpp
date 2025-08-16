class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
      
      int n = arr.size();
       unordered_map<int, int>seen; 
       
       for(int i : arr){ 
           seen[i]++; 
       } 
       
       for (int i = 0; i < n; i++) { 
        if (seen[arr[i]] > 1) 
        { return i + 1; } 
       }
       
       return -1;
    }
};