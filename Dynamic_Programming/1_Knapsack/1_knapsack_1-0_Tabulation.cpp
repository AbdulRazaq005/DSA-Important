// Here is the bottom-up approach of dynamic programming
#include <bits/stdc++.h> //Important
using namespace std;

// Returns the value of maximum profit

int knapSack(int W, int wt[], int val[], int n)
{
    // double pointer to declare the table dynamically
    int dp[n + 1][W + 1];

    // loop to initially filled the table with -1
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < W + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < W + 1; j++)
        {
            if (W < wt[i - 1])
                return dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
            }
        }
    return dp[n][W];
}

int main()
{
    int val[] = {10, 20, 30};
    int wt[] = {3, 3, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n) << endl;
    return 0;
}

//Output : 50