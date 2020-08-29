// Here is the bottom-up approach of dynamic programming
#include <bits/stdc++.h> //Important
using namespace std;

// Returns the value of maximum profit

int knapSack(int wt[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += wt[i];
    // double pointer to declare the table dynamically
    bool dp[n + 1][(sum / 2) + 1]; ///////  "1/2 table is enough for this"
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
    int pos, range = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i] == true)
        {
            pos = i;
            break;
        }
    }

    return sum - 2 * pos;
}

int main()
{
    int wt[] = {1, 2, 3, 7};
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << (knapSack(wt, n)) << "\n";
    cout << endl;
    return 0;
}

//returns: 1