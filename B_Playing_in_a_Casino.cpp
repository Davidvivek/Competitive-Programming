#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int no_of_people;
    cin >> no_of_people;
    int count_of_numbers;
    cin >> count_of_numbers;

    vector<vector<int>> matrix(count_of_numbers, vector<int>(no_of_people));
    for (int i = 0; i < no_of_people; i++)
    {
        for (int j = 0; j < count_of_numbers; j++)
        {
            cin >> matrix[j][i];
        }
    }


    long long ans=0;
    for(int i=0; i<count_of_numbers; i++)
    {
        sort(matrix[i].begin(), matrix[i].end());
        long long prefix_sum=0;
        for(int j=0; j<no_of_people; j++)
        {
            ans += (1LL*matrix[i][j]*j-prefix_sum);
            prefix_sum += matrix[i][j];
        }
    }
    cout << ans << endl;
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}