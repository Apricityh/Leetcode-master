#include <exception>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n, m;
    vector<int> dp(m,0);
    vector<bool> flag(n, false);
    vector<int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        data[i]*=n-i;
    }
    dp[0] = 1;
    int res = 0;
    for (int i=0;i<n; i++) {
        for (int j=m; j>=data[i]; j--) {
            if (dp[j-data[i]]==1){
                dp[j]=1;
                flag[i] = true;
            }
        }
    }

    for (bool i:flag) {
        if (i)  {
            res++;
        }
    }
    cout<<res;
}

// 64 Î»Êä³öÇëÓÃ printf("%lld")