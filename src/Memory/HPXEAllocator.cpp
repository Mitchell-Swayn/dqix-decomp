#include "Memory/HPXEAllocator.h"
#include "std_library_functions.h"

#define BLOCKSIGNATURE_FREE 0x4652 // looks like "RF" in memory
#define BLOCKSIGNATURE_USED 0x5544 // looks like "DU" in memory

// Sets the optimization level to O2,p instead of O2. It performs a small
// optimization in FreeMemoryRange().
// Every other function in this file is unaffected by this.
#pragma optimize_for_size off

#ifdef jpn
#define MIi_CpuClear32 func_020cbeb8
#endif

extern "C"
{
    void MIi_CpuClear32(int val, void* dst, unsigned int len);
}

// USA: func_020af20c
// JPN: func_020b0cd8
// Original: arm9/main @ 0x020AF20C; symbol: _ZN13HPXEAllocator22MemoryRangeDescription17PopulateFromBlockEPNS_5BlockE; size: 0x2C.
void HPXEAllocator::MemoryRangeDescription::PopulateFromBlock(Block* block)
{
    unsigned int dataStart = (unsigned int)block + sizeof(Block);
    unsigned short extraBytesBefore = (block->coalescenceData >> 8) & 0x7f;
    beginAddr = (unsigned int)block - extraBytesBefore;
    endAddr = block->size + dataStart;
}

// USA: func_020af238
// JPN: func_020b0d04
// Original: arm9/main @ 0x020AF238; symbol: _ZN13HPXEAllocator9BlockList20RemoveAndGetPreviousEPNS_5BlockE; size: 0x28.
HPXEAllocator::Block* HPXEAllocator::BlockList::RemoveAndGetPrevious(Block* block)
{
    Block* oldPrev = block->pPrev;
    Block* oldNext = block->pNext;

    if (oldPrev != NULL) 
        oldPrev->pNext = oldNext;
    else
        this->pFirst = oldNext;

    if (oldNext != NULL)
        oldNext->pPrev = oldPrev;
    else
        this->pLast = oldPrev;

    return oldPrev;
}

// USA: func_020af260
// JPN: func_020b0d2c
// Original: arm9/main @ 0x020AF260; symbol: _ZN13HPXEAllocator9BlockList11InsertAfterEPNS_5BlockES2_; size: 0x30.
HPXEAllocator::Block* HPXEAllocator::BlockList::InsertAfter(Block* newBlock, Block* prev)
{
    Block* next;
    newBlock->pPrev = prev;
    if (prev != NULL)
    {
        next = prev->pNext;
        prev->pNext = newBlock;
    }
    else
    {
        next = this->pFirst;
        this->pFirst = newBlock;
    }

    newBlock->pNext = next;
    if (next != NULL)
        next->pPrev = newBlock;
    else
        this->pLast = newBlock;

    return newBlock;
}

// USA: func_020af290
// JPN: func_020b0d5c
// Original: arm9/main @ 0x020AF290; symbol: _ZN13HPXEAllocator22MemoryRangeDescription11CreateBlockEt; size: 0x2C.
HPXEAllocator::Block* HPXEAllocator::MemoryRangeDescription::CreateBlock(unsigned short sig)
{
    Block* block = (Block*)beginAddr;
    block->signature = sig;
    block->coalescenceData = 0;
    unsigned int dataStart = (unsigned int)block + sizeof(Block);
    block->size = endAddr - dataStart;
    block->pPrev = NULL;
    block->pNext = NULL;
    return block;
}

// USA: func_020af2bc
// JPN: func_020b0d88
// Original: arm9/main @ 0x020AF2BC; symbol: _ZN13HPXEAllocator14CreateInRegionEPvS0_t; size: 0x74.
HPXEAllocator* HPXEAllocator::CreateInRegion(void* start, void* end, unsigned short clearFlags)
{
    HPXEAllocator* alloc = (HPXEAllocator*)start;
    AllocatorTree::InsertNewAndPopulateHeader(&alloc->header,
        ALLOCATOR_SIGNATURE_HPXE, (char*)start + sizeof(HPXEAllocator), end, clearFlags);
    alloc->blocks.unknown_34 = 0;
    alloc->blocks.blockSelectFlags = 0;
    
    // no preference for smallest possible block
    alloc->blocks.blockSelectFlags &= ~1;

    MemoryRangeDescription range;
    range.beginAddr = (unsigned int)alloc->header.allocBegin;
    range.endAddr = (unsigned int)alloc->header.allocEnd;
    Block* block = range.CreateBlock(BLOCKSIGNATURE_FREE);
    alloc->blocks.freeBlocks.pFirst = block;
    alloc->blocks.freeBlocks.pLast = block;
    alloc->blocks.usedBlocks.pFirst = 0;
    alloc->blocks.usedBlocks.pLast = 0;
    return alloc;
}

// USA: func_020af330
// JPN: func_020b0dfc
// Original: arm9/main @ 0x020AF330; symbol: _ZN13HPXEAllocator12BlockManager21AllocateFromFreeBlockEPNS_5BlockEjjt; size: 0x180.
void* HPXEAllocator::BlockManager::AllocateFromFreeBlock(
    Block* initNode, unsigned int effStart, unsigned int length, unsigned short reversed)
{
    MemoryRangeDescription pieceBefore;
    MemoryRangeDescription pieceAfter;
    pieceBefore.PopulateFromBlock(initNode);
    pieceAfter.endAddr = pieceBefore.endAddr;
    pieceAfter.beginAddr = length + effStart;

    Block* prevFreeBlock;
    unsigned int trueStart = effStart - 0x10;
    pieceBefore.endAddr = trueStart;

    prevFreeBlock = freeBlocks.RemoveAndGetPrevious(initNode);
    if (pieceBefore.endAddr - pieceBefore.beginAddr < 0x14)
        pieceBefore.endAddr = pieceBefore.beginAddr;
    else
    {
        Block* tmp = pieceBefore.CreateBlock(BLOCKSIGNATURE_FREE);
        prevFreeBlock = freeBlocks.InsertAfter(tmp, prevFreeBlock);
    }

    if (pieceAfter.endAddr - pieceAfter.beginAddr < 0x14)
        pieceAfter.beginAddr = pieceAfter.endAddr;
    else
    {
        Block* tmp = pieceAfter.CreateBlock(BLOCKSIGNATURE_FREE);
        freeBlocks.InsertAfter(tmp, prevFreeBlock);
    }

    unsigned char clearFlags = *(unsigned int*)((char*)this - 4);
    unsigned int clearLength = pieceAfter.beginAddr - pieceBefore.endAddr;
    
    if (clearFlags & 1)
        MIi_CpuClear32(0, (void*)pieceBefore.endAddr, clearLength);
    
    MemoryRangeDescription thisPiece;
    thisPiece.beginAddr = trueStart;
    thisPiece.endAddr = pieceAfter.beginAddr;
    Block* usedSubblock = thisPiece.CreateBlock(BLOCKSIGNATURE_USED);

    
    usedSubblock->coalescenceData &= ~0x8000;
    unsigned int reversalBitmask = (unsigned int)reversed << 31;
    usedSubblock->coalescenceData |= reversalBitmask >> 16;


    unsigned short numBytesBefore = ((unsigned int)usedSubblock - pieceBefore.endAddr);
    usedSubblock->coalescenceData &= ~0x7f00;
    usedSubblock->coalescenceData |= (numBytesBefore & 0x7f) << 8;


    unsigned char lowByte = this->unknown_34;
    usedSubblock->coalescenceData &= ~0xff;
    usedSubblock->coalescenceData |= lowByte;
    

    usedBlocks.InsertAfter(usedSubblock, usedBlocks.pLast);
    return (void*)effStart;
}

// USA: func_020af4b0
// JPN: func_020b0f7c
// Original: arm9/main @ 0x020AF4B0; symbol: _ZN13HPXEAllocator17AllocateFromFrontEjj; size: 0xB4.
void* HPXEAllocator::AllocateFromFront(unsigned int len, unsigned int align)
{
    bool acceptAnyBlock = (unsigned short)(blocks.blockSelectFlags & 1) == 0;
    
    Block* loopBlock = blocks.freeBlocks.pFirst;
    Block* bestBlock = NULL;
    
    unsigned int smallestBlockSize = 0xffffffff;
    unsigned int addrWithinBestBlock = 0;
    
    if (loopBlock != NULL)
    {
        unsigned int bitmask = ~(align - 1);
        do
        {
            unsigned int minStartAddr = (unsigned int)loopBlock + 0x10;
            // Want to start as close to beginning of block as possible, but have
            // to respect header size (0x10) and alignment
            unsigned int desiredStartAddr = (align - 1 + minStartAddr) & bitmask;
            unsigned int wastedBytes = desiredStartAddr - minStartAddr;

            if (loopBlock->size >= len + wastedBytes && smallestBlockSize > loopBlock->size)
            {
                bestBlock = loopBlock;
                smallestBlockSize = loopBlock->size;
                addrWithinBestBlock = desiredStartAddr;
                
                if (acceptAnyBlock || loopBlock->size == len)
                    break;
            }
            loopBlock = loopBlock->pNext;
        } while (loopBlock != NULL);
    }

    if (bestBlock == NULL)
        return NULL;

    return blocks.AllocateFromFreeBlock(bestBlock, addrWithinBestBlock, len, 0);
}

// USA: func_020af564
// JPN: func_020b1030
// Original: arm9/main @ 0x020AF564; symbol: _ZN13HPXEAllocator15AllocateFromEndEjj; size: 0xB0.
void* HPXEAllocator::AllocateFromEnd(unsigned int len, unsigned int align)
{
    bool acceptAnyBlock = (unsigned short)(blocks.blockSelectFlags & 1) == 0;
    
    Block* loopBlock = blocks.freeBlocks.pLast;
    Block* bestBlock = NULL;
    
    unsigned int smallestBlockSize = 0xffffffff;
    unsigned int addrWithinBestBlock = 0;
    
    if (loopBlock != NULL)
    {
        unsigned int bitmask = ~(align - 1);
        do
        {
            unsigned int minStartAddr = (unsigned int)loopBlock + 0x10;
            // go as close to end of block as possible, respecting alignment
            unsigned int desiredStartAddr = (loopBlock->size + minStartAddr - len) & bitmask;
            int remainingBytes = desiredStartAddr - minStartAddr;

            if (remainingBytes >= 0 && smallestBlockSize > loopBlock->size)
            {
                bestBlock = loopBlock;
                smallestBlockSize = loopBlock->size;
                addrWithinBestBlock = desiredStartAddr;
                
                if (acceptAnyBlock || loopBlock->size == len)
                    break;
            }
            loopBlock = loopBlock->pPrev;
        } while (loopBlock != NULL);
    }

    if (bestBlock == NULL)
        return NULL;

    return blocks.AllocateFromFreeBlock(bestBlock, addrWithinBestBlock, len, 1);
}

// https://decomp.me/scratch/BJC0E
// USA: func_020af614
// JPN: func_020b10e0
// Original: arm9/main @ 0x020AF614; symbol: _ZN13HPXEAllocator12BlockManager15FreeMemoryRangeERKNS_22MemoryRangeDescriptionE; size: 0xF0.
bool HPXEAllocator::BlockManager::FreeMemoryRange(const MemoryRangeDescription& range)
{
    MemoryRangeDescription updatedRange = range;
    Block* prevBlock = NULL;

    if (freeBlocks.pFirst != NULL)
    {
        //Block* u1 = freeBlocks.pFirst;
        unsigned int minAddress = range.beginAddr;
        Block* loopBlock = freeBlocks.pFirst;
        do {
            if ((unsigned int)loopBlock < minAddress)
            {
                prevBlock = loopBlock;
            }
            else
            {
                if ((unsigned int)loopBlock == range.endAddr)
                {
                    unsigned int dataStart = (unsigned int)loopBlock + 0x10;
                    updatedRange.endAddr = loopBlock->size + dataStart;
                    freeBlocks.RemoveAndGetPrevious(loopBlock);
                }
                break;
            }
            loopBlock = loopBlock->pNext;
        } while (loopBlock != NULL);
    }

    if (prevBlock != 0)
    {
        unsigned int prevBlockEnd = prevBlock->size + ((unsigned int)prevBlock + sizeof(Block));
        if (prevBlockEnd == range.beginAddr)
        {
            updatedRange.beginAddr = (unsigned int)prevBlock;
            prevBlock = freeBlocks.RemoveAndGetPrevious(prevBlock);
        }
    }

    unsigned int len = updatedRange.endAddr - updatedRange.beginAddr;
    
    if (len < sizeof(Block))
        return false;

    Block* freeBlock = updatedRange.CreateBlock(BLOCKSIGNATURE_FREE);
    freeBlocks.InsertAfter(freeBlock, prevBlock);
    return true;
}

// USA: func_020af704
// JPN: func_020b11d0
// Original: arm9/main @ 0x020AF704; symbol: _ZN13HPXEAllocator16CreateAtLocationEPvjt; size: 0x38.
HPXEAllocator* HPXEAllocator::CreateAtLocation(void* where, unsigned int size, unsigned short clearFlags)
{
    unsigned int end = (size + (unsigned int)where) & ~3;
    unsigned int begin = ((unsigned int)where + 3) & ~3;
    
    // 0x4c = sizeof(HPXEAllocator) + sizeof(Block) + 4
    // (any less and we have no useful space)
    if (begin > end || end - begin < 0x4c)
        return NULL;
    
    return HPXEAllocator::CreateInRegion((void*)begin, (void*)end, clearFlags);
}

// USA: func_020af73c
// JPN: func_020b1208
// Original: arm9/main @ 0x020AF73C; symbol: _ZN13HPXEAllocator14RemoveFromTreeEv; size: 0xC.
void HPXEAllocator::RemoveFromTree()
{
    AllocatorTree::Remove(&header);
}

// USA: func_020af748
// JPN: func_020b1214
// Original: arm9/main @ 0x020AF748; symbol: _ZN13HPXEAllocator8AllocateEji; size: 0x30.
void* HPXEAllocator::Allocate(unsigned int len, int alignAndDir)
{
    if (len == 0)
        len = 1;
    
    unsigned int fourByteAlignedLength = (len + 3) & ~3;
    if (alignAndDir >= 0)
        return AllocateFromFront(fourByteAlignedLength, alignAndDir);
    else
        return AllocateFromEnd(fourByteAlignedLength, -alignAndDir);
}

// USA: func_020af778
// JPN: func_020b1244
// Original: arm9/main @ 0x020AF778; symbol: _ZN13HPXEAllocator4FreeEPv; size: 0x3C.
void HPXEAllocator::Free(void* data)
{
    Block* pBlock = (Block*)((char*)data - sizeof(Block));
    MemoryRangeDescription range;

    range.PopulateFromBlock(pBlock);
    blocks.usedBlocks.RemoveAndGetPrevious(pBlock);
    blocks.FreeMemoryRange(range);
}

// USA: func_020af7b4
// JPN: func_020b1280
// Original: arm9/main @ 0x020AF7B4; symbol: _ZN13HPXEAllocator24GetMaxPossibleAllocationEi; size: 0x84.
unsigned int HPXEAllocator::GetMaxPossibleAllocation(int alignAndDir)
{
    unsigned int align = abs(alignAndDir);

    unsigned int maxUsableSpace = 0;
    unsigned int minWastedSpace = 0xFFFFFFFF;
    
    Block* loopBlock = blocks.freeBlocks.pFirst;
    
    if (loopBlock != NULL)
    {    
        unsigned int alignRounding = align - 1;
        unsigned int bitmask = ~(align - 1);
        do
        {
            unsigned int blockHeaderEnd = (unsigned int)loopBlock + sizeof(Block);
            unsigned int blockUsableStart = (alignRounding + blockHeaderEnd) & bitmask;
            unsigned int blockUsableEnd = loopBlock->size + blockHeaderEnd;

            if (blockUsableStart < blockUsableEnd)
            {
                unsigned int thisUsableSpace = blockUsableEnd - blockUsableStart;
                unsigned int thisWastedSpace = blockUsableStart - blockHeaderEnd;
                if (maxUsableSpace < thisUsableSpace ||
                   (maxUsableSpace == thisUsableSpace && minWastedSpace > thisWastedSpace))
                {
                    maxUsableSpace = thisUsableSpace;
                    minWastedSpace = thisWastedSpace;
                }
            }
            
            loopBlock = loopBlock->pNext;
        } while (loopBlock != NULL);
    }
    
    return maxUsableSpace;
}