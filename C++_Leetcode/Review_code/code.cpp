//
// Created by 32894 on 2024-05-29.
//
/*1��LRU�����㷨
LRU (Least Recently Used)�����㷨��һ�ֳ����ڹ�����Ĳ���,��Ŀ���Ǳ�������ù������ݣ�����̭���δ��ʹ�õ�����,ʵ�ּ򵥵�LRU�����㷨��֧��ֱѯ����
�롢ɾ��������
���δ��ʹ�ö���:��ѯ�������ɾ��������Ϊһ�η��ʲ�����ÿ��Ԫ�ؾ���һ�����һ�α�����ʱ�䣬�������һ�α�����ʱ������ʱ������ļ�Ϊ���δʹ�á�
�������:���������Ѿ����ڣ���ˢ��ֵ�������ڣ�����룬�����������,����̭���ĩ��ʹ�õ�Ԫ�ء�
���Ҫ��
ʱ������C/C++1000ms,��������:2000ms�ڴ�����:C/C++256MB.��������:512MB
 ���룺
���뻺���СN(��Χ[1,100])���������б�����k (��Χ[1,10000])�������Ͳ���Ԫ��
��������:Q��ʾ��ѯ������A��ʾ���������D��ʾɾ����������Ԫ��:����������Χ[0,100000]
��Ŀ��֤��������Ч��Χ�����ᳬ����Χ��
���
������󻺴��е������б�,���մ�С�������С�
����1
����:2 5
A 103
A 102
A 102
Q 103
A 101
���:101 103
 * */
//#include <iostream>
//using namespace std;
//#include <algorithm>
//int nums[11000];
//int counts;//���е�����
//int search(int value){
//    for (int i = 0; i < counts; ++i) {
//        if (nums[i]==value)return i;
//    }
//    return -1;//δ�ҵ�
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
//        if (input=='A'){//����
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
//        }else{//ɾ��
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
3��·������������
��ʽ·������Ҫ�䱸�ӿڰ�ſ��Թ������ӿڰ����ڽ����û�ҵ���ҽӿڰ�ת�������ĺͲ��ܴ���·����������ת��������
��ǰĳ�ͻ�������2̨�豸��num��ӿڰ塣������Ƿ����һ�ְ�װ������ʹ�û�ѡ���Ľӿڰ壬�պ���װ����̨�豸�ϣ���ÿ̨�豸���õĽӿڰ��ת������֮�ͣ��պú�������ת��������ȡ�
1���豸����ת�������ĵ�λ��Gbps��Gbps���豸��λʱ���ڴ���ı�����������ǧ�ױ���/�롢Ϊ�˼����⣬�涨ֵΪ��������ΧΪ[1,2000] .
2���ͻ������Ľӿڰ�����num��ֵ�ķ�Χ[1,200].
3���ӿڰ������ĵ�λҲ��Gbps������10 10 40 40 100������ѡ����5��ӿڰ壬ת�������ֱ���10Gbps. 10Gbps, 40Gbps, 40Gbps,100Gbps���ӿڰ�ת�������ķ�Χһ��Ϊ��
 ��ö��ֵ��Ϊ�˼����⣬�涨ֵΪ��������
����
��һ����Ŀ���豸��ת��������
�ڶ����ǿͻ������Ľӿڰ�����num .
�������Ƕ����İ���num���ӿڰ��ת���������б�
���
�����������Ҫ��İ�װ������������������̨�豸���õĽӿڰ��ת���������б���Ҫ��ÿ̨�豸�ĵ��壬��ת��������С�������С���̨�豸�ĵ��壬��һ������
ת������С����������������һ������ת��������ͬ���ǵ�������������������������ڶ�Ӧ�İ�װ�������򷵻�-1��������֤������ǰ������������£������ж��ֲ�
ͬ�Ľ��.
����1
��������:100
        5
40 10 10 40 100
�������:10 10 40 40
100

���͡�����һ̨�豸�豸��װ������Ϊ40Gbps,10Gbps,10Gbps,40Gbp�Ľӿڰ壬��ΪҪ
�󵥰水������С�������,�����������10 10 40 40.
����һ̨�豸��װ��100Gbps�Ľӿڰ壬���100,
�����֤�����豸��Ľӿڰ��ת�������ĺͣ����պ÷ֱ�����豸��ת��������С����ѡ��Ľӿڰ�պ����ꡣ
��Ϊ�����豸�ĵ��塣��һ����������С�������������������Ϊ:10 10 40 40
100
����:100
 3
10 10 20
���:-1
����:δ�ҵ����ʵĽ⣬ֱ�ӷ���
-1
 * */
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#include <vector>
int main(){
    int N;//ת������,һ̨���ӵĺ�
    int num;//�ӿڰ��
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
    int target = sum/2;//��������
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
        return -1;//���ɴ�
    }
    //�����
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