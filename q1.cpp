#include <bits/stdc++.h>
using namespace std;
int n;
multimap<string, string> g;
vector<vector<string>> dp(20, vector<string>(20));
void check(int i, int j, int k)
{
    for (auto a = g.begin(); a != g.end(); a++)
    {
        if (a->second.size() < 2)
            continue;
        if (dp[i][k].find(a->second[0]) != string ::npos && dp[k + 1][j].find(a->second[1]) != string ::npos)
            dp[i][j] += a->first;
    }
}
int main()
{
    string s;
    cin >> s;
    n = s.size();
    g.insert(make_pair("S", "AB"));
    g.insert(make_pair("S", "BC"));
    g.insert(make_pair("A", "BA"));
    g.insert(make_pair("A", "a"));
    g.insert(make_pair("B", "CC"));
    g.insert(make_pair("B", "b"));
    g.insert(make_pair("C", "AB"));
    g.insert(make_pair("C", "a"));
    for (int i = 0; i < n; i++)
    {
        for (auto j = g.begin(); j != g.end(); j++)
        {
            if (j->second.size() == 1 && j->second == s.substr(i, 1))
            {
                dp[i][i] = j->first;
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
    for (auto i : dp)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    if (dp[0][n - 1].find('S') != string ::npos)
    {
        cout << "Accept\n";
    }
    else
        cout << "Reject \n";
}