#include <iostream>

#include "MinHead.h"
#include "HuffmanTree.h"
using namespace std;

struct PID
{
    int k;
    int i;
    int d;
    PID* next;
    PID():k(0),i(0),d(0),next(nullptr){}
    PID(int kp,int ki,int kd,PID* n):k(ki),i(ki),d(kd),next(n){}

};

void test2(PID& pid)
{
    PID* p = new PID();
    p->k = 2;
    p->i = 2;
    p->d = 2;
    p->next = &pid;
    pid = *p;
    cout << "p的地址" << p << endl;
}

std::ostream& operator<<(ostream& out,PID& p)
{
    return out << p.k << " " << p.i << " " << p.d << " " << p.next << endl;
}

void test(int& a)
{
    a = 90;
}

int main()
{
    int arr[] = {1,2,3,8,7,5,4,6};
    int len = sizeof(arr)/sizeof(arr[0]);

    float w[] = {10.0f,2.0f,6.0f,2.5f,6.5f,0.1f,3.8f};
    int length = sizeof(w)/sizeof(w[0]);

    //MinHeap<int> mHeap(arr,len);
   // mHeap.print();
   // mHeap.Insert(100);
   // mHeap.print();

   /*
   PID t;
   PID p(3,3,3,&t);
   cout << "调用前的地址:" << &p << endl;
   PID* tmp = &p;
   cout << p << endl;
   test2(p);
   cout << p << endl;
   cout << *tmp << endl;
   cout << "调用后的地址:" << &p << endl;
   cout << "tmp的地址:" << tmp << endl;
*/


    HuffmanTree<int> ht(arr,len);

   //ht.PreOrder();
    return 0;
}
