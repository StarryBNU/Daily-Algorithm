#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<cstdio> 
using namespace std;
const int MOD = 10000;
int main() {
    string s;
    getline(cin, s);
    vector<int> stk;
    long long num = 0;
    char op = '+';
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = (num * 10 + (c - '0')) % MOD;
        } else {
            if (op == '+') {
                stk.push_back(static_cast<int>(num));
            } else {
                int top = stk.back();
                stk.pop_back();
                stk.push_back(static_cast<int>((top * num) % MOD));
            }
            op = c;
            num = 0;
        }
    }
    if (op == '+') {
        stk.push_back(static_cast<int>(num));
    } else {
        int top = stk.back();
        stk.pop_back();
        stk.push_back(static_cast<int>((top * num) % MOD));
    }
    int ans = 0;
    for (size_t i = 0; i < stk.size(); ++i) {
        ans = (ans + stk[i]) % MOD;
    }
    printf("%d",ans);
    return 0;
}
