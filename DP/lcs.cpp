#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonSubsequence(const string& s, const string& t) {
        int n = (int)s.size(), m = (int)t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans.push_back(s[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] == dp[i][j]) i--;
            else j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s = "abcde";
    string t = "bace";

    Solution sol;
    cout << sol.longestCommonSubsequence(s, t);
    return 0;
}
