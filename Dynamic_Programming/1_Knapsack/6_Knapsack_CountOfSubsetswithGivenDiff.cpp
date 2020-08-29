// Here is the bottom-up approach of dynamic programming
#include <bits/stdc++.h> //Important
using namespace std;

// Returns the value of maximum profit

int knapSack(int wt[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += wt[i];
    int t = (sum + diff) / 2;
    // double pointer to declare the table dynamically
    int dp[n + 1][t + 1]; ///////  "1/2 table is enough for this"
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < t + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < t + 1; j++)
        {

            if (j < wt[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = (dp[i - 1][j - wt[i - 1]] + dp[i - 1][j]);
            }
        }
    return dp[n][t];
}

int main()
{
    int wt[] = {1, 2, 3, 4, 6};
    int diff = 2;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << (knapSack(wt, n, diff)) << "\n";
    cout << endl;
    return 0;
}

//returns: 3        {1,2,6}{3,4}   {1,2,4}{3,6}   {2,3,4}{1,6}