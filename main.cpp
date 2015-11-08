#include <iostream>
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


    void *p3_1 = heap.alloc(3);
    void *p3_2 = heap.alloc(4);
    void *p3_3 = heap.alloc(3);
    heap.free(p3_3);
    heap.info();
    heap.realloc(p3_2, 7);
    p3_3 = heap.alloc(3);
    heap.info();
    heap.free(p3_2);
    p3_2 = heap.alloc(4);
    heap.realloc(p3_2, 5);
    heap.info();
    heap.realloc(p3_2, 2);
    heap.info();
//    heap.info();
    return 0;
}
