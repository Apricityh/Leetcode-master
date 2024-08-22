////
//// Created by bitionam on 2024/5/15.
////
////LRU 最久

/*1、LRU缓存算法
LRU (Least Recently Used)缓存算法是一种常用于管理缓存的策略,其目标是保留最近用过的数据，而淘汰最久未被使用的数据,实现简单的LRU缓存算法，支持直询、插
入、删除操作。
最久未被使用定义:查询、插入和删除操作均为一次访问操作，每个元素均有一个最后一次被访问时间，按照最后一次被访问时间排序，时间最早的即为最久未使用。
插入操作:当缓存中已经存在，则刷新值，不存在，则插入，如果超过上限,则淘汰最久末被使用的元素。
解答要求
时间限制C/C++1000ms,其他语言:2000ms内存限制:C/C++256MB.其他语言:512MB
 输入：
输入缓存大小N(范围[1.100])，及操作列表数量k (范围[1,10000])操作类型操作元素
操作类型:Q表示查询操作，A表示插入操作，D表示删除操作操作元素:正整数，范围[0,100000]
题目保证输入在有效范围，不会超出范围。
输出
返回最后缓存中的整数列表,按照从小到大排列。
样例1
输入:2 5
A 103
A 102
A 102
Q 103
A 101
输出:101 103
 * */
//#include <bits/stdc++.h>
//#include <algorithm>
//
//using namespace std;
//int num;
//int data[10001];
//
//int getIndex(int c) {
//    for (int i = 0; i < num; ++i) {
//        if (c == data[i]) {
//            return i;
//        }
//    }
//    return -1;//无
//}
//
//void remove(int index) {
//    for (int i = index; i < num - 1; ++i) {
//        data[i] = data[i + 1];
//    }
//    num = num - 1;
//}
//
//void insert(int index) {
//    for (int i = num; i >= 1; --i) {
//        //移动
//        data[i] = data[i - 1];
//    }
//    data[0] = index;//移到最前面
//    num += 1;
//}
//
////Q查询  A插入  D删除
//int main() {
//    int n, k, v;
//    char c;
//    cin >> n >> k;//队列输入大小和
//    for (int i = 0; i < k; ++i) {
//        cin >> c >> v;
//        if (c == 'A') {
//            int index = getIndex(v);
//            if (index != -1) {
//                remove(index);
//            } else if (num == n) {
//                remove(num - 1);
//            }
//            insert(v);
//        } else if (c == 'D') {
//            int index = getIndex(v);
//            if (index != -1) {
//                remove(index);
//            }
//        } else {
//            int index = getIndex(v);
//            if (index == -1) {
//                continue;
//            }
//            remove(index);
//            insert(v);
//        }
//    }
//    sort(data, data + num);
//    for (int j = 0; j < num; ++j) {
//        if (j != 0) {
//            cout << " ";
//        }
//        cout << data[j];
//    }
//    return 0;
//}
/*
3、路由器单板配置
框式路由器需要配备接口板才可以工作，接口板用于接入用户业务，且接口板转发能力的和不能大于路由器整机的转发能力。
当前某客户订购了2台设备和num块接口板。请计算是否存在一种安装方法，使用户选购的接口板，刚好能装到两台设备上，且每台设备配置的接口板的转发能力之和，刚好和整机的转发能力相等。
1，设备整机转发能力的单位是Gbps，Gbps是设备单位时间内传输的比特数，代表千兆比特/秒、为了简化问题，规定值为整数，范围为[1,2000] .
2、客户订购的接口板数量num，值的范围[1,200].
3、接口板容量的单位也是Gbps，比如10 10 40 40 100，代表选购了5块接口板，转发能力分别是10Gbps. 10Gbps, 40Gbps, 40Gbps,100Gbps，接口板转发能力的范围一股为特
 定枚举值，为了简化问题，规定值为正整数。
输入
第一行是目标设备的转发能力。
第二行是客户订购的接口板数量num .
第三行是订购的包含num个接口板的转发能力的列表。
输出
如果存在满足要求的安装方法，请分两行输出两台设备配置的接口板的转发能力的列表，且要求每台设备的单板，按转发能力从小到大排列。两台设备的单板，第一个单板
转发能力小的优先输出。如果第一个单板转发能力相同，那单板数多的优先输出。如果不存在对应的安装方案，则返回-1。用例保证在满足前面条件的情况下，不会有多种不
同的结果.
样例1
复制输入:100
        5
40 10 10 40 100
复制输出:10 10 40 40
100

解释、其中一台设备设备安装了能力为40Gbps,10Gbps,10Gbps,40Gbp的接口板，因为要
求单版按容量从小到大输出,所以最终输出10 10 40 40.
另外一台设备安装了100Gbps的接口板，输出100,
结果保证两个设备配的接口板的转发能力的和，都刚好分别等于设备的转发能力大小，且选配的接口板刚好用完。
因为两个设备的单板。第一个单板容量小的优先输出，所以最终为:10 10 40 40
100
输入:100
 3
10 10 20
输出:-1
解释:未找到合适的解，直接返回
-1

 *
 *
 *
 * */
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





/*
 * 2、模式匹配
已知存在一种字符串解析语法，其中的语法元素如下N:用于匹配单个数字(0-9)
A:用于匹配单个字母(a-z,A-Z)
n0:用于表示一个分组，分组中至少有一个N语法元素或者A语法元素，n为一个数值，表示匹配n次，1 <= n <= 200
输入给定的解析语法和字符串，要求从中找到第一个满足解析语法的字符串
 输入
输入两行数据:
第一行是给定的解析语法第二行是目标字符串
解析语法的长度n满足1<= n <= 100000目标字符串长度n满足0<= n <= 100000
输出
输出匹配的字符串内容，如果没有匹配中任何字符串,输出!
样例1
输入:2(AN)
BA3A3ABB
输出:A3A3
解释:匹配模式中AN表示匹配一个字母和一个数字，2(AN)表示该模式连续匹配两次，则第一个匹配中的内容为“A3A3"
样例2
复制输入:2(A2(N))
A3322A33P20BB
输出:A33P20
解释:2(A2(N))该模式要求匹配两组连续的A2(N)模式，A2(N)为一个字母与两个连续的数字，第一个满足条件的则为"A33P20"

样例3
复制输入:A5(N)
A3322A33P20BB
复制输出:!
解释:整个字符串中没有符合条件的子串，输出!
提示
用例保证输入的解析语法是合法的(只有给定的三种语法元素)
*/


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