//
// Created by 32894 on 2024-04-29.
//
#include <iostream>
using namespace std;
template<typename T>
class Memory_Pool  //内存池
{
public:
    void* alloc(size_t size)   //即申请内存
    {
        if (pool == NULL)   //pool指针为空，说明第一次申请，则申请一个内存池
        {
            pool = (Node*)new char[(size + 4) * 10]();//申请10倍所需资源；+4：数据域后面要加指针域
            Node* pCur = pool;
            for (pCur; pCur < pool + 10 - 1; pCur = pCur + 1)//循环，让每个node的指针域指向下一个node
            {
                pCur->pnext = pCur + 1;
            }
            pCur->pnext = NULL;//最后一个node的next域为NULL
        }
        Node* prt = pool;
        pool = pool->pnext;
        return prt;
    }

    void dealloc(void* mptr) //释放内存
    {
        if (mptr == NULL)
            return;
        Node* ptr = (Node*)mptr;
        ptr->pnext = pool;
        pool = ptr;
    }
private:
    class Node    //结点：数据域和指针域
    {
    public:
        Node(T &val) :mData(val), pNext(NULL){}
    public:
        T mData;    //数据域是一个T类型的数据   设计成模板：多态的体现
        Node* pNext;  //指针域
    };
    static Node* pool;   //设计成static
    //静态数据成员被当作是类的成员。无论这个类的对象定义了多少个，
    //静态数据成员在程序中也只有一份拷贝，由该类型的所有对象共享访问
};

