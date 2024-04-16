#include <iostream>
#include <string>
std::string convertToBase3(int num) {
    std::string result = "";
    int base = 1;
    int sum = 0;
    while(num){
        int temp = num%10;
        sum +=temp*base;
        base = base*7;
        num = num/10;
    }
    std::cout<<sum<<std::endl;
    while(sum){
        int temp = sum%3;
        result += std::to_string(temp)+result;
        sum = sum/3;
    }
    return result;
}
int main() {
    int num = 234; // Æß½øÖÆÊı
    std::string result = convertToBase3(num);
    std::cout << "The base-3 representation of " << num << " is: " << result << std::endl;
    return 0;
}
