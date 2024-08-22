//
// Created by 32894 on 2024-05-21.
//
/*1、LRU缓存算法
LRU (Least Recently Used)缓存算法是一种常用于管理缓存的策略,其目标是保留最近用过的数据，而淘汰最久未被使用的数据,实现简单的LRU缓存算法，支持直询、插
入、删除操作。
最久未被使用定义:查询、插入和删除操作均为一次访问操作，每个元素均有一个最后一次被访问时间，按照最后一次被访问时间排序，时间最早的即为最久未使用。
插入操作:当缓存中已经存在，则刷新值，不存在，则插入，如果超过上限,则淘汰最久末被使用的元素。
解答要求
时间限制C/C++1000ms,其他语言:2000ms内存限制:C/C++256MB.其他语言:512MB
 输入：
输入缓存大小N(范围[1,100])，及操作列表数量k (范围[1,10000])操作类型操作元素
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
//using namespace std;
//int num;//存在数据的数量
//int data[11001];
//int search(int val){
//    for (int i = 0; i < num; ++i) {
//        if (data[i]==val)return i;
//    }
//    return -1;
//}
//void remove(int index){
//    for (int i = index; i <num-1 ; ++i) {
//        data[i] = data[i+1];
//    }
//    num-=1;
//}
//void insert(int val){
//    for (int i = 1; i <num+1 ; ++i) {
//        data[i]=data[i-1];
//    }
//    data[0] = val;
//    num++;
//}
//int main(){
//    int n;//缓存大小
//    int k;//列表数量
//    char c;
//    int value;
//    for (int i = 0; i < k; ++i) {
//        cin>>c>>value;//传入数据
//        if (c=='A'){
//            //插入逻辑，首先查询是否data里面有当前数据没，有则将其删除，再置顶。
//            int index = search(value);
//            if (index!=-1){
//                remove(index);
//            }else if(num==n){
//                remove(n-1);//如果当前满了，则直接去掉最后一个。
//            }
//            insert(value);
//        }else if(c=='Q'){
//            int index = search(value);
//            if (index==-1)continue;
//            remove(index);
//            insert(value);
//        }else{
//            int index = search(value);
//            remove(index);
//        }
//    }
//    sort(data,data+num);
//    for (int i = 0; i < num; ++i) {
//        if (i!=0){
//            cout<<" ";
//        }
//        cout<<data[i];
//    }
//    return 0
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
 * */
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

//// 全局变量定义
//int a[210];    // 存储接口板的转发能力
//int dp[2100];  // 动态规划数组，表示某个转发能力是否可达
//int flag[210]; // 标记数组，用于标记接口板是否被分配给第一台设备
//
//int main() {
//
//    int need;
//    int num;
//    int sum=0;
//    cin >> need >> num; // 读取设备的转发能力 n 和接口板数量 num
//    cout<<need<<num<<sum;
//    // 读取每个接口板的转发能力并计算总和
//    for (int i = 0; i < num; ++i) {
//        cin >> a[i];
//        sum += a[i];
//    }
//    sort(a, a + num); // 对接口板的转发能力进行排序
//
//    // 检查接口板的总转发能力是否等于两台设备的总转发能力
//    if (sum != need * 2) {
//        cout << -1 << endl; // 如果不等于，输出 -1 并结束程序
//        return 0;
//    }
//
//    dp[0] = 1; // 初始化动态规划数组，容量为 0 时可达
//
//    // 动态规划填充 dp 数组  10 10 20 40 100   ///100
//    for (int i = 0; i < num; ++i) {
//        for (int j = need; j >= a[i]; --j) {
//            if (dp[j - a[i]] == 1) { // 如果 j-a[i] 容量可达，则 j 容量也可达
//                dp[j] = 1;
//            }
//        }
//    }
//    //dp[0]可达   dp[10] dp[10] dp[20] dp[40] dp[100]
//
//    // 检查是否存在一种组合使得转发能力正好为 n,如果没有则就不存在这个组合满足need
//    if (dp[need] == 0) {
//        cout << -1 << endl; // 如果不存在，输出 -1 并结束程序
//        return 0;
//    }
//
//    vector<int> result; // 存储第一台设备的接口板组合
//    int now = need;        // 当前剩余需要达到的转发能力
//    int index = 0;      // 当前处理的接口板索引
//
//    // 构建第一台设备的接口板组合
//    while (now != 0 && index < num) {//最后跳出肯定是now==0
//        if (now >= a[index] && dp[now - a[index]] == 1) { // 检查当前接口板是否可以加入组合
//            now -= a[index];    // 减去当前接口板的转发能力
//            result.push_back(a[index]); // 将接口板加入结果组合
//            flag[index] = 1;    // 标记该接口板已被使用
//        }
//        index += 1; // 移动到下一个接口板
//    }
//
//    // 输出第一台设备的接口板组合
//    for (int i = 0; i < result.size(); ++i) {
//        if (i != 0) {
//            cout << " ";
//        }
//        cout << result[i];
//    }
//    cout << endl;
//
//    // 输出第二台设备的接口板组合
//    vector<int> result2;
//    for (int i = 0; i < num; ++i) {
//        if (flag[i]==true){
//            continue;
//        }
//        result2.push_back(a[i]);
//    }
//    bool temp = true;
//    for (int i = 0; i < num; ++i) {
//        if (!flag[i]) { // 如果该接口板没有被使用
//            if (!temp) {
//                cout << " ";
//            }
//            temp = false;
//            cout << a[i];
//        }
//    }
//    for (int i = 0; i < result2.size(); ++i) {
//        if (i != 0) {
//            cout << " ";
//        }
//        cout << result[i];
//    }
//    cout << endl;
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
bool flag[210];
int main(){
    int need;//设备转发总和
    int num;//接口数量
    vector<int> data(210,0);
    int sum =0;
    vector<int> dp(2100,0);
    cin>>need>>num;
    for (int i = 0; i < num; ++i) {
        cin>>data[i];
    }

    sort(data.begin(),data.begin()+num);
    for (int i :data) {
       sum+=i;
    }
    cout<<"num"<<sum<<endl;
    if (need*2!=sum){
        cout<<-1<<endl;
        return 0;
    }
    dp[0] = 1;
    //dp[10]=1 dp[20] dp[30]     dp[40] dp[100]     dp[]
    for (int i = 0; i < num; ++i) {
        for (int j = need; j >=data[i] ; --j) {
            if (dp[j-data[i]]==1){
                dp[j]=1;
            }
        }
    }
    if (dp[need]==0){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> result;
//回溯
    int index =0;
    int needs = need;
    while(needs!=0&&index<num){
        if (needs>=data[index]&&dp[needs-data[index]]==1){  //选择当前接口板后，剩余的转发能力是可达的。如果不可达就不可以选择
            needs = needs -data[index];
            result.push_back(data[index]);
            flag[index]=true;
        }
        index +=1;
    }
    for (int i = 0; i < result.size(); ++i) {
        if (i!=0){
            cout<< " ";
        }
        cout<<result[i];
    }
    cout<<endl;
    for (int i = 0; i < num; ++i) {
        if (flag[i]){
            continue;
        }
        cout<<data[i];
    }
    cout<<endl;
    return 0;
}
/*我的解决方案使用动态规划来确定是否存在一种分配方式可以使每台设备的总转发能力等于目标值。具体步骤如下：
1. 计算接口板的总转发能力，并检查它是否等于两台设备的总转发能力的两倍。如果不等，直接输出-1。
2. 使用动态规划来确定是否存在一种组合使得接口板的总转发能力等于目标值。
3. 如果存在这样的组合，使用回溯法找到具体的组合方案。
4. 输出两个组合，并确保它们按要求排序。

 * */