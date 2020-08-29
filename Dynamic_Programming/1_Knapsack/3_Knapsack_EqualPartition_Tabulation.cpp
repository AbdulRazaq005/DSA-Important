// Here is the bottom-up approach of dynamic programming
#include <bits/stdc++.h> //Important
using namespace std;

// Returns the value of maximum profit

bool knapSack(int wt[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += wt[i];
    if (sum % 2 != 0)
        return false;

    sum = sum / 2;
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (j < wt[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = (dp[i - 1][j - wt[i - 1]] || dp[i - 1][j]);
            }
        }
    return dp[n][sum];
}

int main()
{
    int wt[] = {1, 3, 3, 6, 1};
    int n = sizeof(wt) / sizeof(wt[0]);
    (knapSack(wt, n)) ? cout << "True" : cout << "False";
    cout << endl;
    return 0;
}
