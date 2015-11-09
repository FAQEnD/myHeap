#include "chunk.h"

Chunk::Chunk(unsigned int size, unsigned int index, unsigned int id, bool isFree = true)
{
    this->size = size;
    this->mCellIndex = index;
    this->id = id;
    this->isFree = isFree;
}

void Chunk::info(void)
{
    std::cout << "------------------" << std::endl;
    std::cout << "Chunk id: " << id << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Memory cell index: " << mCellIndex << std::endl;
    std::string str;
    isFree == true? str = "free" : str = "used";
    std::cout << "Chunk is: " << str << std::endl;
    std::cout << "------------------" << std::endl;
}

Heap::Heap(void)
{
    _memoryAviable = _MAX_HEAP_MEMORY;
    createChunk(_MAX_HEAP_MEMORY, 0, true, 0);
}

void Heap::info(void)
{
    std::cout << "Maximum heap size: " << _MAX_HEAP_MEMORY << std::endl;
    std::cout << "Memory aviable: " << getAviableMemory() << std::endl;
    std::cout << "Chunks created: " << chunks.size() << std::endl;
    std::cout << "\n --Chunks list-- " << std::endl;
    for(auto chunk : chunks)
        chunk.info();
}

bool Heap::createChunk(unsigned int size, unsigned int index, bool isFree, unsigned int id)
{
    if(size <= 0)
        return false;
    if(size > _MAX_HEAP_MEMORY || size > _memoryAviable)
        return false;

    _memoryAviable -= size;
    if((size == _MAX_HEAP_MEMORY && id == 0) || (_memoryAviable == _MAX_HEAP_MEMORY))
    {
        Chunk newChunk(size, index, id, isFree);
        chunks.push_back(newChunk);
        return true;
    }

    Chunk newChunk(size, index, id + 1, isFree);
    chunks.insert(chunks.begin() + id, newChunk);
    std::swap(chunks[id], chunks[id + 1]);

    for(unsigned int i = id; i < chunks.size(); ++ i)
        chunks[i].id = i;

    return true;
}

void *Heap::alloc(unsigned int size)
{
    if(size <= 0) // wtf? Idiots defence
        return NULL;
    if(size > _MAX_HEAP_MEMORY || size > getAviableMemory()) // not enoght memory
        return NULL;
    for(unsigned int i = 0; i < chunks.size(); ++ i)
    {
        if(chunks[i].size >= size && chunks[i].isFree == true)
        {
            unsigned int sizeDifference = chunks[i].size - size;
            _memoryAviable += sizeDifference;
            chunks[i].size = size; // resize chunk to needed size
            chunks[i].isFree = false; // switch flag to 'used'
            createChunk(sizeDifference, chunks[i].mCellIndex + chunks[i].size, true, i);
            return &heapMemory[chunks[i].mCellIndex];
        }
    }
    return NULL;
}

void Heap::free(void *beginPtr)
{
    if(beginPtr < &heapMemory[0] || beginPtr > &heapMemory[_MAX_HEAP_MEMORY])
        return;
    for(unsigned int i = 0; i < chunks.size(); ++ i)
        if(beginPtr == &heapMemory[chunks[i].mCellIndex])
            chunks[i].isFree = true;
    splitFreeChunks();
}

void *Heap::realloc(void *beginPtr, unsigned int size)
{
    if(size <= 0)
        return NULL;
    if(size > _MAX_HEAP_MEMORY) // not enoght memory
        return NULL;

    for(unsigned int i = 0; i < chunks.size(); ++ i)
    {
        if(beginPtr == &heapMemory[chunks[i].mCellIndex]) // find our chunk
        {
            if(size == chunks[i].size) // if same size, return p
                return beginPtr;

            if(size > chunks[i].size && i < chunks.size() - 1) // if we wanna more memory
            {
                unsigned int newSize = size - chunks[i].size;
                if(chunks[i + 1].isFree == true && chunks[i + 1].size >= newSize) // if we have free chunk near
                {
                    if(chunks[i + 1].size == newSize)
                    {
                        chunks[i].size += newSize;
                        chunks.erase(chunks.begin() + i + 1);
                    }
                    else
                        if(chunks[i + 1].size > newSize)
                        {
                            chunks[i].size += newSize;
                            chunks[i + 1].mCellIndex += newSize;
                            chunks[i + 1].size -= newSize;
                        }
                }
                return beginPtr;
            }
            if(size < chunks[i].size)
            {
                unsigned int sizeDifference = chunks[i].size - size;
                _memoryAviable += sizeDifference;
                chunks[i].size = size;
                createChunk(sizeDifference, chunks[i].mCellIndex + chunks[i].size, true, i);
                splitFreeChunks();
                return beginPtr;
            }
        }
    }
    return NULL;
}

void Heap::splitFreeChunks(void)
{
    for(unsigned int i = 0; i < chunks.size() - 1; ++ i)
        if(chunks[i].isFree == true && chunks[i + 1].isFree == true)
        {
            chunks[i].size += chunks[i + 1].size;
            chunks.erase(chunks.begin() + i + 1);
            -- i;
        }
}

unsigned int Heap::getAviableMemory()
{
    unsigned int aviableMemoryInChunks = 0;
    for(unsigned int i = 0; i < chunks.size(); ++ i)
    {
        if(chunks[i].isFree == true)
            aviableMemoryInChunks += chunks[i].size;
    }
    return aviableMemoryInChunks;
}
