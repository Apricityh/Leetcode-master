//
// Created by 32894 on 2024-04-29.
//
#include <iostream>
using namespace std;
template<typename T>
class Memory_Pool  //�ڴ��
{
public:
    void* alloc(size_t size)   //�������ڴ�
    {
        if (pool == NULL)   //poolָ��Ϊ�գ�˵����һ�����룬������һ���ڴ��
        {
            pool = (Node*)new char[(size + 4) * 10]();//����10��������Դ��+4�����������Ҫ��ָ����
            Node* pCur = pool;
            for (pCur; pCur < pool + 10 - 1; pCur = pCur + 1)//ѭ������ÿ��node��ָ����ָ����һ��node
            {
                pCur->pnext = pCur + 1;
            }
            pCur->pnext = NULL;//���һ��node��next��ΪNULL
        }
        Node* prt = pool;
        pool = pool->pnext;
        return prt;
    }

    void dealloc(void* mptr) //�ͷ��ڴ�
    {
        if (mptr == NULL)
            return;
        Node* ptr = (Node*)mptr;
        ptr->pnext = pool;
        pool = ptr;
    }
private:
    class Node    //��㣺�������ָ����
    {
    public:
        Node(T &val) :mData(val), pNext(NULL){}
    public:
        T mData;    //��������һ��T���͵�����   ��Ƴ�ģ�壺��̬������
        Node* pNext;  //ָ����
    };
    static Node* pool;   //��Ƴ�static
    //��̬���ݳ�Ա����������ĳ�Ա�����������Ķ������˶��ٸ���
    //��̬���ݳ�Ա�ڳ�����Ҳֻ��һ�ݿ������ɸ����͵����ж��������
};

