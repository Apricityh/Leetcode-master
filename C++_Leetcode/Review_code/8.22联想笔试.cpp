//
// Created by 32894 on 2024-08-22.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> monster(n);
    int xst, yst, xed, yed;
    cin >> xst >> yst >> xed >> yed;
    //����������
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> monster[i].first >> monster[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int x = monster[i].first;
        int y = monster[i].second;
        //��������������������һ����Ҫ���㣬���ڼ������������Ĵ�ֱ�������ڶ�ά�ռ��У���������������ж��������Ƿ��ߡ�
        if ((x - xst) * (yed - yst) == (y - yst) * (xed - xst)) {
            //�������Ƿ������߷���  ��ֹ������
            if ((x - xst) * (xed - xst) >= 0 && (y - yst) * (yed - yst) >= 0) {
                count++;
            }
        }
    }
    cout << count;
}
//#include "iostream"
//#include "vector"
//#include "unordered_set"
//#include "unordered_map"
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    long long n = s.size();
//    vector<long long > dp(n + 1, 0);
//    dp[0] = 1;
//    unordered_map<string,int> strings;
//    for (long long i = 1; i <= n; ++i) {
//        for (long long j = 0; j <i; ++j) {
//            string temp = s.substr(j, i - j);
//            int num = stoi(temp);
//            if ((strings.find(temp) == strings.end()||strings[temp]<j)&&num%4==0) {
//                dp[i] += dp[j];
//                strings[temp] = i;
//            }
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}