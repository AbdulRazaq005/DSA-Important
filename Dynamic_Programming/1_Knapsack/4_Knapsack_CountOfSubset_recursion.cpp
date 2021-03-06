// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int sum, int wt[], int n, vector<vector<int>> dp)
{
    // base condition
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (wt[n - 1] > sum)
    {
        dp[n][sum] = knapSackRec(sum, wt, n - 1, dp);
        return dp[n][sum];
    }
    else
    {
        dp[n][sum] = (knapSackRec(sum - wt[n - 1], wt, n - 1, dp) + knapSackRec(sum, wt, n - 1, dp));
        return dp[n][sum];
    }
}

int knapSack(int sum, int wt[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1)); //Very Important

    return knapSackRec(sum, wt, n, dp);
}

int main()
{
    int wt[] = {1, 3, 4, 1, 2};
    int sum = 5;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << knapSack(sum, wt, n) << "\n";
    cout << endl;
    return 0;
}

//Output : True

//    for(int i=0; i<n+1;i++)        //Important
//    fill(dp[i], dp[i]+(W+1), -1);  //Important