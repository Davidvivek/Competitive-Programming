#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int a, b;
    cin >> a >> b;
    int c; cin >> c;

    if(a==b)
    {
        cout << c << endl;
        return;
    }

    if(abs(a-b)>= abs(c+a-b))
    {
        cout << abs(a-b) << endl;
        return;
    }

    cout << abs(c+a-b) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}