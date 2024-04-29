//
// Created by 32894 on 2024-04-29.
//
#include <iostream>
using namespace std;
template<typename T>
class Memory_pool{
public:
    void *alloc(size_t size){
        if (pool== nullptr){
            pool = (Node*)new char[(size+4)*10]();
            Node* pCur = pool;
            for (pCur;pCur<pool+10-1;pCur++) {
                pCur->next = pCur+1;
            }
            pCur->next = nullptr;
        }
        Node *node = pool;
        pool = pool->next;
        return node;
    }
    void dealloc(void *ptr){
        if (ptr== nullptr)return;
        Node* node = (Node*)ptr;
        node->next = pool;
        pool = node;
        return;
    }
private:
    class Node{
    public:
        Node(T &val):val(val),next(nullptr){};
    private:
        T val;
        Node * next;
    };
    static Node* pool;
};