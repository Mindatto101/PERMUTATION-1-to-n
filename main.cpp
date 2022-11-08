///Coding or to be Coded !
#include <bits/stdc++.h>

using namespace std;
int a[1001];
void out(int k, int a[])   // Output function
{
   cout << "{";
    for (int i = 1; i <= k; i++)
    {
        if (i == k)
        {
            cout << a[k];
            break;
        }
        cout << a[i] << ",";
    }
    cout << "}" << endl;
}
int main()
{
    int n, x, y, amin, ad, lim = 1, counti = 1;
    cin >> n;
    for (int k = 2; k <= n; k++)
    {
        lim *= k;
    }
    for (int i = 1; i <= n; i++)     // 1 to n has n! permutations
    {
        a[i] = i;
    }
    out(n,a);
    while (counti != lim)
    {
        for (int i = n-1; i >= 1; i--)
        {
            if (a[i] < a[i+1])
            {
                amin = 10;                       // digits of permutations always < 10
                for (int j = i+1; j <= n; j++)
                {
                    if (a[j] > a[i] && amin > a[j])
                    {
                        amin = a[j];
                        ad = j;
                    }
                }
                swap(a[ad],a[i]);
                x = i+1, y = n;
                while (x < y)
                {
                    swap(a[x],a[y]);
                    x++;
                    y--;
                }
                counti++;
                out(n,a);
                break;
            }
        }
    }

}
