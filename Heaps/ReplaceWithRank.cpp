#include <bits/stdc++.h>
using namespace std;
// TC -> O(N log N)
// SC -> O(N)
class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }

        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 5, 8, 15, 8, 25, 9};

    vector<int> res = obj.replaceWithRank(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
