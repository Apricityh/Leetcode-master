//
// Created by 32894 on 2024-04-15.
//

//
//int main(){
//    int a = 0;
//    int* b =&a;
//    int* c = b+1;
//    std::cout<<reinterpret_cast<char*>(c)-reinterpret_cast<char*>(b);
//    return 0;
//}
#include <iostream>
#include <vector>

using namespace std;

string convert_to_hex(int number) {
    vector<char *> res;

}

int main() {
    int i = 1;
    int count = 0;
    while (i) {
        i = i << 1; // ÿ������һλ
        count++;
    }
    std::cout << count / 8 << std::endl; // һ���ֽ�8λ
    return 0;
}
