#include "chunk.h"

using namespace std;

int main()
{
    Heap heap;
//    heap.info();
//    void *p = heap.alloc(3);
//    void *p2 = heap.alloc(3);
//    void *p3 = heap.alloc(3);
//    heap.free(p);
//    heap.info();
//    heap.free(p3);
//    heap.info();
//    heap.free(p2);
//    heap.info();

//    void *p4 = heap.alloc(3);
//    void *p5 = heap.alloc(4);
//    void *p6 = heap.alloc(3);
//    heap.info();
//    heap.free(p5);
//    heap.info();
//    p5 = heap.alloc(2);
//    heap.info();
//    heap.free(p4);
//    heap.info();
//    heap.free(p5);
//    heap.info();
//    heap.free(p6);
//    heap.info();
//    p5 = heap.alloc(4);
//    p6 = heap.alloc(3);
//    heap.free(p5);
//    p5 = heap.alloc(2);
//    p4 = heap.alloc(1);
//    heap.free(p5);
//    heap.info();
//    p5 = heap.alloc(2);
//    heap.info();

//    void *p = malloc(1);
//    heap.free(p);
//    int *p3_1 = (int*)heap.alloc(1);
//    int *p3_2 = (int*)heap.alloc(4);
//    void *p3_3 = heap.alloc(3);
//    *p3_1 = 4000;
//    *p3_2 = 5555;
//    std::cout << "p3_1: " << *p3_1 << " p3_1 adress: " << p3_1 << std::endl;
//    std::cout << "p3_2: " << *p3_2 << " p3_2 adress: " << p3_2 << std::endl;
//    heap.free(p3_3);
//    heap.info();
//    heap.realloc(p3_2, 7);
//    p3_3 = heap.alloc(3);
//    heap.info();
//    heap.free(p3_2);
//    p3_2 = (int*)heap.alloc(4);
//    heap.realloc(p3_3, 5);
//    heap.info();
//    heap.realloc(p3_2, 2);
//    heap.info();
//    heap.info();
    int *i = (int*)heap.alloc(4);
    int k = 1;
    while(i)
    {
        heap.free(i);
        i = (int*)heap.alloc(4*k); heap.alloc(20);
        k++;
        if(i != NULL)
            cout << i << " " << *i << " " << k << endl;
    }
    heap.info();
    return 0;
}
