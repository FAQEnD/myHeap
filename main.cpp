#include <iostream>
#include "chunk.h"

using namespace std;

int main()
{
    Heap heap;
//    heap.info();
    char *p = heap.alloc(3);
    heap.alloc(3);
    heap.alloc(3);
//    heap.info();
    return 0;
}
