#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define full(a, b) memset(a, b, sizeof a)
#define __fastIn ios::sync_with_stdio(false), cin.tie(0)
#define pb push_back
using namespace std;
using LL = long long;
inline int lowbit(int x){ return x & (-x); }
inline int read(){
    int ret = 0, w = 0; char ch = 0;
    while(!isdigit(ch)){
        w |= ch == '-', ch = getchar();
    }
    while(isdigit(ch)){
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -ret : ret;
}
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd){
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}
 
int main(){
 
    int _;
    string s;
 
    for(cin >> _; _; _ --){
        cin >> s;
        int p = -1, ans = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '1'){
                int val = 0;
                for(int j = i; j < min(i + 20, (int)s.size()); j ++){
                    val = val * 2 + (s[j] - '0');
                    if(val > j - p) break;
                    ans ++;
                }
                p = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}