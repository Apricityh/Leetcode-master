#include <iostream>
using  namespace std;
class Ref_count{
private:
    int* ptr;         // ���ݶ���ָ��
    int* count;     // ���ü�����ָ��
public:
    // ��ָͨ�빹�칲��ָ��
    Ref_count(int* t) : ptr(t), count(new int(1)){}

    ~Ref_count(){
        decrease();
    }

    // ��������
    Ref_count(const Ref_count& tmp){
        count = tmp.count;
        ptr = tmp.ptr;
        increase();
    }

    // ע��=��ָ��������ָ�����˼�����˵��=��ߵĹ���ָ��ָ����=�ұߵ�
    // ���=��ߵĹ���ָ��-1��=�ұߵĹ���ָ��+1
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
                // ���ü���Ϊ0��ʱ���ɾ�����ݶ���ָ������ö���ָ��
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

    // ����һ�� int ���͵�ָ�룬�������ڴ�
    int* intValue = new int(42);

    // ʹ����ָͨ�빹�칲��ָ��
    Ref_count re(intValue);

    // ʹ�ù���ָ���������
    std::cout << "Value: " << *re << std::endl;

    // ʹ�ù���ָ��ļ�ͷ�������������
    *re = 100;
    std::cout << "New Value: " << *re << std::endl;
    cout<<re.get_count()<<endl;
    Ref_count res(re);
    cout<<re.get_count();
    return 0;
}