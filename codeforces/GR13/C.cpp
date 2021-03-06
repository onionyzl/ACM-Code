#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
using LL = long long;
using pii = pair<int, int>;

inline int lowbit(int x) { return x & (-x); }
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd) {
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

int T, n;
vector<int> s, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> T;
    while(T --){
        cin >> n;
        s.clear(), c.clear();
        s.resize(n + 1);
        c.resize(n + 1);
        for(int i = 1; i <= n; i ++){
            cin >> s[i];
        }
        LL res = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = min(i + s[i], n); j >= i + 2; j --){
                c[j] += 1;
            }
            if(s[i] <= c[i] + 1){
                if(i + 1 <= n) c[i + 1] += c[i] - s[i] + 1;
            }
            else{
                res += s[i] - c[i] - 1;
            }
        }

        cout << res << endl;
    }

    return 0;
}
