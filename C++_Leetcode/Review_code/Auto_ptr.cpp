#include <iostream>
using  namespace std;
class Ref_count{
private:
    int* ptr;         // 数据对象指针
    int* count;     // 引用计数器指针
public:
    // 普通指针构造共享指针
    Ref_count(int* t) : ptr(t), count(new int(1)){}

    ~Ref_count(){
        decrease();
    }

    // 拷贝构造
    Ref_count(const Ref_count& tmp){
        count = tmp.count;
        ptr = tmp.ptr;
        increase();
    }

    // 注意=在指针里面是指向的意思，因此说明=左边的共享指针指向了=右边的
    // 因此=左边的共享指针-1，=右边的共享指针+1
    Ref_count& operator=(const Ref_count& tmp){
        if(&tmp != this){
            tmp.increase();
            decrease();
            ptr = tmp.ptr;
            count = tmp.count;

        }
        return *this;
    }

    int* operator ->() const{
        return ptr;
    }

    int& operator *() const{
        return *ptr;
    }

    void increase()const{
        if(count){
            (*count)++;
        }
    }

    void decrease(){
        if(count){
            (*count)--;
            if(*count == 0){
                // 引用计数为0的时候就删除数据对象指针和引用对象指针
                delete ptr;
                ptr = nullptr;
                delete count;
                count = nullptr;
            }
        }
    }

    int* get() const{
        return ptr;
    }

    int get_count() const{
        if(!count){
            return 0;
        }
        return *count;
    }
};
int main(){

    // 创建一个 int 类型的指针，并分配内存
    int* intValue = new int(42);

    // 使用普通指针构造共享指针
    Ref_count re(intValue);

    // 使用共享指针访问数据
    std::cout << "Value: " << *re << std::endl;

    // 使用共享指针的箭头运算符访问数据
    *re = 100;
    std::cout << "New Value: " << *re << std::endl;
    cout<<re.get_count()<<endl;
    Ref_count res(re);
    cout<<re.get_count();
    return 0;
}