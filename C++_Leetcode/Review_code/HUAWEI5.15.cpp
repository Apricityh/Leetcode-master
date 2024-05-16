////
//// Created by bitionam on 2024/5/15.
////
////LRU
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int num;
int data[10001];

int getIndex(int c) {
    for (int i = 0; i < num; ++i) {
        if (c == data[i]) {
            return i;
        }
    }
    return -1;//无
}

void remove(int index) {
    for (int i = index; i < num - 1; ++i) {
        data[i] = data[i + 1];
    }
    num = num - 1;
}

void insert(int index) {
    for (int i = num; i >= 1; --i) {
        //移动
        data[i] = data[i - 1];
    }
    data[0] = index;//移到最前面
    num += 1;
}

//Q查询  A插入  D删除
int main() {
    int n, k, v;
    char c;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> c >> v;
        if (c == 'A') {
            int index = getIndex(v);
            if (index != -1) {
                remove(index);
            } else if (num == n) {
                remove(num - 1);
            }
            insert(v);
        } else if (c == 'D') {
            int index = getIndex(v);
            if (index != -1) {
                remove(index);
            }
        } else {
            int index = getIndex(v);
            if (index == -1) {
                continue;
            }
            remove(index);
            insert(v);
        }
    }
    sort(data, data + num);
    for (int j = 0; j < num; ++j) {
        if (j != 0) {
            cout << " ";
        }
        cout << data[j];
    }
    return 0;
}

//三题 动态规划
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int a[210];
int dp[2100];
int flag[210];

int main() {

    int n, num, sum = 0;
    cin >> n >> num;

    for (int i = 0; i < num; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + num);
    if (sum != n * 2) {
        cout << -1 << endl;
        return 0;
    }

    dp[0] = 1;
    for (int i = 0; i < num; ++i) {
        for (int j = n; j >= a[i]; --j) {
            if (dp[j - a[i]] == 1) {
                dp[j] = 1;
            }
        }
    }
    if (dp[n] == 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> result;
    int now = n;
    int index = 0;
    while (now != 0 && index < num) {
        if (now >= a[index] && dp[now - a[index]] == 1) {
            now -= a[index];
            result.push_back(a[index]);
            flag[index] = 1;
        }
        index += 1;
    }
    for (int i = 0; i < result.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;
    bool temp = true;
    for (int i = 0; i < num; ++i) {
        if (!flag[i]) {
            if (!temp) {
                cout << " ";
            }
            temp = false;
            cout << a[i];
        }
    }
    cout << endl;
    return 0;
}
//第二题：
//#include <bits/stdc++.h>
//#include <algorithm>
//using namespace std;
//int main(){
//    string s1,s2;
//    cin>>s1,s2;
//    for (int i = 0; i < s2.size(); ++i) {
//        if (s2[i]>='0'&&s2[i]<='9'){
//            s2[i] = 'N';
//        }else{
//            s2[i] = 'A';
//        }
//    }
//   cout<<"!"<<endl;
//}