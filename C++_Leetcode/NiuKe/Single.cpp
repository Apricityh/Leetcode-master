//
// Created by 32894 on 2024-04-22.
//
#include <iostream>
using namespace std;

class Single {
public:
    static Single *Instance() {
        if (single == nullptr) {
            single = new Single();
        }
        return single;
    };

private:
    static Single *single;
    Single() {}
    Single(const Single* &sc){}
};
Single*  Single::single = nullptr;
int main(){
    Single* s1 = Single::Instance();
    Single*s2 = Single::Instance();
    cout<<s1<<endl;
    cout<<s2<<endl;
    return 0;
}
//ถ๖บบ
#include <iostream>
using namespace std;
class Singlex{
    static Singlex* Instance(){
        return singlex;
    }
private:
    static Singlex* singlex;
    Singlex(){};
    Singlex(const Singlex &cx){};

};
Singlex* Singlex::singlex = new Singlex();