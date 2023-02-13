#include <bits/stdc++.h>
using namespace std;
int n;
map<string, string> g;
vector<vector<string>> dp(n, vector<string>(n));
void check(int i, int j, int k)
{
    for (auto a : g)
    {
        if (a.second.size() == 1)
            continue;
        if (dp[i][k].find(a.second[0]) != string ::npos && dp[k + 1][j].find(a.second[1]) != string ::npos)
            dp[i][j] += a.first;
    }
}
int main()
{
    string s;
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++)
    {
        for (auto j : g)
        {
            if (j.second.size() == 1 && j.second == s.substr(i, 1))
            {
                dp[i][i] = j.first;
            }
        }
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            for (int k = i; k < j; k++)
            {
                check(i, j, k);
            }
        }
    }

    if (dp[0][n - 1].find('S') != string ::npos)
    {
        cout << "Accept\n";
    }
    else
        cout << "Reject \n";
}