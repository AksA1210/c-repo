//incomplete

#include <bits/stdc++.h>
using namespace std;

int knapsack_dp(int n, int M, int w[], int p[])
{
    int i, j;
    int c[n + 1][M + 1];
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= M + 1; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (w[i - 1] <= j)
            {
                c[i][j] = max(c[i - 1][j], p[i - 1] + c[i - 1][j - w[i - 1]]);
            }
            else
            {
                c[i][j] = c[i - 1][j];
            }
        }
    }
    cout << "MATRIX OBTAINED =  " << endl
         << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < M + 1; j++)
        {
            cout << setw(4) << c[i][j] << setw(4);
        }
        cout << endl;
    }
    return c[n][M];
}

int main()
{
    int i, j;
    int n; // number of items
    int M; // capacity of knapsack (total weight of bag)
    cout << "-------------------------0/1 KNAPSACK PROBLEM------------------------" << endl;
    cout << "Enter the no. of items  : "
         << " ";
    cin >> n;

    int w[n]; // weight of items
    int p[n]; // profit of items

    cout << "Enter the weight and price of all items in the correct order : " << endl;
    cout << "Weight"
         << "  "
         << "Profit" << endl
         << endl;
    for (i = 0; i < n; i++)
    {
        cin >> w[i] >> p[i];
    }
    cout << endl;
    cout << "Enter the capacity of knapsack  :  ";
    cin >> M; // total weight of the bag
    cout << endl;
    int result = knapsack_dp(n, M, w, p);
    cout << endl;
    cout << "The maximum value of items that can be put into knapsack is :  " << result;
    return 0;
}
