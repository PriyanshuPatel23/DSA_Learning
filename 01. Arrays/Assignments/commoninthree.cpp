class Solution {
  public:
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        vector<int> ans;

        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();

        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2 && k < n3) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.push_back(arr1[i]);
                int val = arr1[i];
                // skip duplicates
                while (i < n1 && arr1[i] == val) i++;
                while (j < n2 && arr2[j] == val) j++;
                while (k < n3 && arr3[k] == val) k++;
            }
            else {
                int mn = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == mn) {
                    int val = arr1[i];
                    while (i < n1 && arr1[i] == val) i++;
                }
                else if (arr2[j] == mn) {
                    int val = arr2[j];
                    while (j < n2 && arr2[j] == val) j++;
                }
                else {
                    int val = arr3[k];
                    while (k < n3 && arr3[k] == val) k++;
                }
            }
        }

        if (ans.empty()) ans.push_back(-1);
        return ans;
    }
};
