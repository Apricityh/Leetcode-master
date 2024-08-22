//
// Created by 32894 on 2024-05-29.
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
//#include <iostream>
//using namespace std;
//#include <algorithm>
//int nums[11000];
//int counts;//已有的数量
//int search(int value){
//    for (int i = 0; i < counts; ++i) {
//        if (nums[i]==value)return i;
//    }
//    return -1;//未找到
//}
//void remove(int index){
//    for (int i = index; i < counts-1; ++i) {
//        nums[i] = nums[i+1];
//    }
//    counts--;
//}
//void insert(int value){
//    for (int i = 1; i < counts+1 ; ++i) {
//        nums[i] = nums[i-1];
//    }
//    nums[0] = value;
//    counts++;
//}
//int main(){
//    int N,K;
//    cin>>N>>K;
//    for(int i=0;i<K;i++){
//        char input;
//        int value;
//        cin>>input>>value;
//        if (input=='A'){//插入
//            int index = search(value);
//            if (index!=-1){
//                remove(index);
//            }else if(counts == N){
//                remove(counts-1);
//            }
//            insert(value);
//        }else if(input=='Q') {
//            int index = search(value);
//            if (index == -1)continue;
//            else {
//                remove(index);
//                insert(value);
//            }
//        }else{//删除
//            int index = search(value);
//            if (index==-1)continue;
//            else{
//                remove(index);
//            }
//        }
//
//    }
//    sort(nums,nums+counts);
//    for (int j = 0; j < counts; ++j) {
//        cout<<nums[j];
//        cout<<" "<<endl;
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
 * */
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#include <vector>
int main(){
    int N;//转发能力,一台机子的和
    int num;//接口板和
    cin>>N>>num;
    vector<int> data(num,0);
    int sum=0;
    for (int i = 0; i < num; ++i) {
        cin>>data[i];
        sum+=data[i];
    }
    if (sum%2!=0){
        cout<<"-1";
    }
    sort(data.begin(),data.end());
    int target = sum/2;//背包容量
    vector<int> dp(target,0);
    dp[0] = 1;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = N; j >=data[i] ;--j) {
            if (dp[j-data[i]]==1){
                dp[j] = 1;
            }
        }
    }
    if (dp[N]!=1){
        cout<<"-1";
        return -1;//不可达
    }
    //找组合
    int temp = N;
    vector<bool> flag(data.size(),false);
    vector<int> result;
    int index = 0;
    while(temp!=0&&index<data.size()){
            if (temp>data[index]&&dp[temp-data[index]]){
                temp-=data[index];
                result.push_back(data[index]);
                flag[index] = true;
            }
            index++;
    }

}