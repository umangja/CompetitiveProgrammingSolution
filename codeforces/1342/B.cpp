#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, T;
string t, ans;
bool c;

int main() {
    cin >> T;
    while(T--)
    {
        ans = "";
        c = 0;
        cin >> t;
        n = t.size();
        for (int i = 0; i < n - 1; i++)
            if (t[i] != t[i + 1]) {
                c = 1;
                break;
            }
        if (c) {
            for (int i = 0; i < 2 * n; i++)
                if(i % 2 == 0)
                    ans += '1';
                else
                    ans += '0';
            cout << ans << endl;
        }
        else
            cout << t << endl;
    }
    return 0;
}