#ifndef CHUNK_H
#define CHUNK_H
#include <QtDebug>
#include <vector>
#include <QString>
class Chunk
{
public:
    // methods
    Chunk(unsigned int, unsigned int, unsigned int, bool);
    void info();

    // members
    unsigned int size;
    unsigned int mCellIndex;
    bool isFree;
    unsigned int id;
};

class Heap
{
public:
    //methods
    Heap();
    void info();
    bool createChunk(unsigned int, unsigned int, bool, unsigned int);
    void *alloc(unsigned int);
    void free(void *);
    void *realloc(void*, unsigned int);

    void splitFreeChunks();

    //members
private:
    const unsigned int _MAX_HEAP_MEMORY = 10;
    unsigned int _memoryAviable;
    unsigned int getAviableMemory();
public:
    std::vector<Chunk> chunks;
    char heapMemory[10];
};

#endif // CHUNK_H
