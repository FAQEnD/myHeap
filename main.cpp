#include <iostream>
#include "chunk.h"

using namespace std;

int main()
{
    Heap heap;
//    heap.info();
    char *p = heap.alloc(3);
    char *p2 = heap.alloc(3);
    char *p3 = heap.alloc(3);
    qDebug() << "Free p";
    heap.free(p);
    heap.info();
    heap.free(p3);
    heap.info();
    heap.free(p2);
    heap.info();
    char *p4 = heap.alloc(3);
    char *p5 = heap.alloc(4);
    char *p6 = heap.alloc(3);
    heap.info();
    heap.free(p5);
    heap.info();
    p5 = heap.alloc(2);
    heap.info();
    heap.free(p4);
    heap.info();
    heap.free(p5);
    heap.info();
//    heap.info();
    return 0;
}
