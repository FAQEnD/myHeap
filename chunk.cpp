#include "chunk.h"

Chunk::Chunk(unsigned int size, unsigned int index, unsigned int id, bool isFree = true)
{
    this->size = size;
    this->mCellIndex = index;
    this->_id = id;
    this->isFree = isFree;
}

void Chunk::info()
{
    qDebug() << "------------------";
    qDebug() << "Chunk id: " << _id;
    qDebug() << "Size: " << size;
    qDebug() << "Memory cell index: " << mCellIndex;
    QString str;
    isFree == true? str = "free" : str = "used";
    qDebug() << "Chunk is: " << str;
    qDebug() << "------------------";
}

Heap::Heap()
{
    _memoryAviable = _MAX_HEAP_MEMORY;
//    heapMemory.resize(_MAX_HEAP_MEMORY);
    createChunk(_MAX_HEAP_MEMORY, 0, true);
//    createChunk(3, 5, false);
//    createChunk(2, 7, false);
//    createChunk(2, 7, false);
    //    createChunk(_MAX_HEAP_MEMORY, 0, true); // shoud return false
}

void Heap::info()
{
    qDebug() << "Maximum heap size: " << _MAX_HEAP_MEMORY;
    qDebug() << "Memory aviable: " << _memoryAviable;
    qDebug() << "Chunks created: " << chunks.size();
    qDebug() << "\n --Chunks list-- ";
    for(auto chunk : chunks)
        chunk.info();
}

bool Heap::createChunk(unsigned int size, unsigned int index, bool isFree)
{
    if(size <= 0)
        return false;
    if(size > _MAX_HEAP_MEMORY || size > _memoryAviable)
    {
        qDebug() << "Not enoght memory";
        return false;
    }
    _memoryAviable -= size;

    unsigned int id = chunks.size();
    Chunk newChank(size, index, id, isFree);
    chunks.push_back(newChank);
    QString isMemoryFree;
    isFree == true? isMemoryFree = "free" : isMemoryFree = "used";
    qDebug() << "New chunk with size: " << size << " and memory cell index: " << index << " created as" << isMemoryFree;
    return true;
}

char* Heap::alloc(unsigned int size)
{
    if(size <= 0)
        return NULL;
    if(size > _MAX_HEAP_MEMORY)
    {
        qDebug() << "Not enoght memory";
        return NULL;
    }
    for(unsigned int i = 0; i < chunks.size(); ++i)
    {
        if(chunks[i].size >= size && chunks[i].isFree == true)
        {
            unsigned int sizeDifference = chunks[i].size - size;
            _memoryAviable += sizeDifference;
            chunks[i].size = size;
            chunks[i].isFree = false;
//            qDebug() << "heapMemory[0]: " << static_cast<void*>(&heapMemory[0]);
            createChunk(sizeDifference, chunks[i].mCellIndex + chunks[i].size, true);
            return &heapMemory[chunks[i].mCellIndex];
        }
    }
    qDebug() << "Not enoght memory";
    return NULL;
}
