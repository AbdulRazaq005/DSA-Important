// Here is the bottom-up approach of dynamic programming
#include <bits/stdc++.h> //Important
using namespace std;

// Returns the value of maximum profit

int knapSack(int sum, int wt[], int n)
{
    // double pointer to declare the table dynamically
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (j < wt[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = (dp[i - 1][j - wt[i - 1]] + dp[i - 1][j]);
            }
        }
    return dp[n][sum];
}

int main()
{
    int wt[] = {1, 2, 3, 4, 1};
    int sum = 5;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << (knapSack(sum, wt, n)) << "\n";
    cout << endl;
    return 0;
}
