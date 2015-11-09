#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <string>
#include <iostream>
struct Chunk
{
    Chunk(unsigned int, unsigned int, unsigned int, bool);
    void info(void);
    // @brief This function output information about Chunk

    unsigned int size;
    unsigned int mCellIndex;
    bool isFree;
    unsigned int id;
};

struct Heap
{
    Heap(void);
    void info(void);
    // @brief This function output information about Heap

    bool createChunk(unsigned int size, unsigned int index, bool isFree, unsigned int id);
    /*
    **  @brief This function create new chunk.
    **  @param [size]   size of new chunk;
    **  @param [index]  index of chunk begin point
    **  @param [isFree] bool flag of memory using. True - memory free, False - memory used
    **  @param [id]     id of memory in vector<Chunk>;
    **
    **  @return bool true if created or false if not created
    */

    void *alloc(unsigned int size);
    /*
    **  @brief This function create ptr to new allocated memory in heap
    **  @param [size]   size of new allocated memory
    **
    **  @return - void or NULL if error
    */

    void free(void *beginPtr);
    /*
    **  @brief This function free memory by ptr chunk begin
    **  @param [p]      prt on begin of chunk
    */

    void *realloc(void *beginPtr, unsigned int size);
    /*
    **  @brief This function change size of memory chunk by ptr on chunk begin
    **  @param [p]      ptr on chunk begin
    **  @param [size]   new size of chunk
    **
    **  @return void or NULL if error
    */

    void splitFreeChunks(void);
    // @brief This function split near free chunks

    //members
private:
    const unsigned int _MAX_HEAP_MEMORY = 10;
    unsigned int _memoryAviable;
    unsigned int getAviableMemory();
public:
    std::vector<Chunk> chunks;
    char heapMemory[10]; // My Heap aviable physical memory
};

#endif // CHUNK_H
