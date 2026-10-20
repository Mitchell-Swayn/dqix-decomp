#include "Memory/SignedAllocator.h"

namespace AllocatorTree
{
    // Yes, this is an int and not a bool. It's handled like a bool though.
    // This makes me think this part might have been written in C, since it
    // already seems likely to be from an external library (and we know
    // parts/all of it use different compiler settings)
    static int initializedTopLevel;
    // At the root of the tree we don't have an allocator, so we just store a 
    // global list of 'top-level' allocators. Can also view this as a forest.
    static SignedAllocatorList topLevel;
}

// USA: func_020aeec8
// JPN: func_020b0994
// Original: arm9/main @ 0x020AEEC8; symbol: _ZN19SignedAllocatorList10InitializeEt; size: 0x18.
void SignedAllocatorList::Initialize(unsigned short sigLength)
{
    pFirst = NULL;
    pLast = NULL;
    numElements = 0;
    signatureLength = sigLength;
}

// USA: func_020aeee0
// JPN: func_020b09ac
// Original: arm9/main @ 0x020AEEE0; symbol: _ZN19SignedAllocatorList18DoInitialInsertionEP21SignedAllocatorHeader; size: 0x2C.
void SignedAllocatorList::DoInitialInsertion(SignedAllocatorHeader* what)
{
    SignedAllocatorHeader** whatPtrs = (SignedAllocatorHeader**)((char*)what + signatureLength);
    whatPtrs[1] = NULL;
    whatPtrs[0] = NULL;

    pFirst = what;
    pLast = what;

    numElements++;
}

// USA: func_020aef0c
// JPN: func_020b09d8
// Original: arm9/main @ 0x020AEF0C; symbol: _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader; size: 0x54.
void SignedAllocatorList::InsertAtEnd(SignedAllocatorHeader* what)
{
    if (pFirst == NULL)
        return DoInitialInsertion(what);

    SignedAllocatorHeader** whatPtrs = (SignedAllocatorHeader**)((char*)what + signatureLength);
    whatPtrs[0] = pLast;
    whatPtrs[1] = NULL;

    ((SignedAllocatorHeader**)((char*)pLast + signatureLength))[1] = what;
    pLast = what;

    numElements++;
}

// USA: func_020aef60
// JPN: func_020b0a2c
// Original: arm9/main @ 0x020AEF60; symbol: _ZN19SignedAllocatorList13InsertAtStartEP21SignedAllocatorHeader; size: 0x50.
void SignedAllocatorList::InsertAtStart(SignedAllocatorHeader* what)
{
    if (pFirst == NULL)
        return DoInitialInsertion(what);

    SignedAllocatorHeader** whatPtrs = (SignedAllocatorHeader**)((char*)what + signatureLength);

    whatPtrs[0] = NULL;
    whatPtrs[1] = pFirst;

    *(SignedAllocatorHeader**)((char*)pFirst + signatureLength) = what;
    pFirst = what;

    numElements++;
}

// USA: func_020aefb0
// JPN: func_020b0a7c
// Original: arm9/main @ 0x020AEFB0; symbol: _ZN19SignedAllocatorList12InsertBeforeEP21SignedAllocatorHeaderS1_; size: 0x64.
void SignedAllocatorList::InsertBefore(SignedAllocatorHeader* where, SignedAllocatorHeader* what)
{
    if (where == NULL)
        return InsertAtEnd(what);

    if (where == pFirst)
        return InsertAtStart(what);
    
    SignedAllocatorHeader** whatPtrs = (SignedAllocatorHeader**)((char*)what + signatureLength);
    SignedAllocatorHeader* wherePrev = *(SignedAllocatorHeader**)((char*)where + signatureLength);
    SignedAllocatorHeader** wherePrevPtrs = (SignedAllocatorHeader**)((char*)wherePrev + signatureLength);

    whatPtrs[0] = wherePrev;
    whatPtrs[1] = where;
    wherePrevPtrs[1] = what;
    *(SignedAllocatorHeader**)((char*)where + signatureLength) = what;

    numElements++;
}

// USA: func_020af014
// JPN: func_020b0ae0
// Original: arm9/main @ 0x020AF014; symbol: _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader; size: 0x60.
void SignedAllocatorList::Remove(SignedAllocatorHeader* what)
{
    SignedAllocatorHeader** prevAndNext = (SignedAllocatorHeader**)((char*)what + signatureLength);
    
    if (prevAndNext[0] == NULL)
        pFirst = prevAndNext[1];
    else
        *(SignedAllocatorHeader**)((char*)prevAndNext[0] + signatureLength + 4) = prevAndNext[1];

    if (prevAndNext[1] == NULL)
        pLast = prevAndNext[0];
    else
        *(SignedAllocatorHeader**)((char*)prevAndNext[1] + signatureLength) = prevAndNext[0];

    prevAndNext[0] = NULL;
    prevAndNext[1] = NULL;
    numElements--;
}

// USA: func_020af074
// JPN: func_020b0b40
// Original: arm9/main @ 0x020AF074; symbol: _ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader; size: 0x18.
SignedAllocatorHeader* SignedAllocatorList::ElementAfter(SignedAllocatorHeader* what)
{
    if (what == NULL)
        return pFirst;
    
    return *(SignedAllocatorHeader**)((char*)what + signatureLength + 4);
}

// USA: func_020af08c
// JPN: func_020b0b58
// Original: arm9/main @ 0x020AF08C; symbol: _ZN19SignedAllocatorList13ElementBeforeEP21SignedAllocatorHeader; size: 0x14.
SignedAllocatorHeader* SignedAllocatorList::ElementBefore(SignedAllocatorHeader* what)
{
    if (what == NULL)
        return pLast;

    return *(SignedAllocatorHeader**)((char*)what + signatureLength);
}

// USA: func_020af0a0
// JPN: func_020b0b6c
// Original: arm9/main @ 0x020AF0A0; symbol: _ZN19SignedAllocatorList13GetNthElementEj; size: 0x48.
SignedAllocatorHeader* SignedAllocatorList::GetNthElement(unsigned int n)
{
    unsigned int loopIdx = 0;
    SignedAllocatorHeader* loopNode = this->ElementAfter(NULL);
    if (loopNode != NULL)
    {
        do
        {
            if (loopIdx == n)
                return loopNode;

            loopIdx++;
            loopNode = this->ElementAfter(loopNode);
        } while (loopNode != NULL);
    }

    return NULL;
}

// USA: func_020af0e8
// JPN: func_020b0bb4
// Original: arm9/main @ 0x020AF0E8; symbol: _ZN13AllocatorTree9GetParentEP19SignedAllocatorListP21SignedAllocatorHeader; size: 0x68.
SignedAllocatorHeader* AllocatorTree::GetParent(SignedAllocatorList* searchList, SignedAllocatorHeader* alloc)
{
    // Loop through the list to find which element is an ancestor
    SignedAllocatorHeader* ancestor = searchList->ElementAfter(NULL);
    if (ancestor != NULL)
    {
        do
        {
            // Allocators manage a contiguous block, and siblings in the list
            // don't share any space, so this range condition is satisfied by
            // at most one ancestor.
            if (ancestor->allocBegin <= alloc && alloc < ancestor->allocEnd)
            {
                // Having found the ancestor, look among its children & descendants
                SignedAllocatorHeader* answer = GetParent(&ancestor->children, alloc);
                if (answer != NULL)
                    return answer;
                // If we couldn't find it among the descendants, then it must be that 
                // ancestor is actually the node we're looking for
                return ancestor;
            }
    
            ancestor = searchList->ElementAfter(ancestor);
        } while (ancestor != NULL);
    }

    return NULL;
}

// USA: func_020af150
// JPN: func_020b0c1c
// Original: arm9/main @ 0x020AF150; symbol: _ZN13AllocatorTree26GetListContainingAllocatorEP21SignedAllocatorHeader; size: 0x28.
SignedAllocatorList* AllocatorTree::GetListContainingAllocator(SignedAllocatorHeader* alloc)
{
    SignedAllocatorList* list = &topLevel;
    SignedAllocatorHeader* parent = GetParent(list, alloc);
    if (parent != NULL)
        list = &parent->children;
    return list;
}

// USA: func_020af178
// JPN: func_020b0c44
// Original: arm9/main @ 0x020AF178; symbol: _ZN13AllocatorTree26InsertNewAndPopulateHeaderEP21SignedAllocatorHeaderjPvS2_t; size: 0x7C.
void AllocatorTree::InsertNewAndPopulateHeader(SignedAllocatorHeader* allocator,
    unsigned int sig, void* allocBegin, void* allocEnd, unsigned short clearFlags)
{
    SignedAllocatorHeader* header = (SignedAllocatorHeader*)allocator;
    header->signature = sig;
    header->allocBegin = allocBegin;
    header->allocEnd = allocEnd;
    // wtf?!
    header->clearFlags = 0;
    header->clearFlags &= ~0xFF;
    header->clearFlags |= clearFlags & 0xFF;
    
    header->children.Initialize(4);
    if (!initializedTopLevel)
    {
        topLevel.Initialize(4);
        initializedTopLevel = 1;
    }

    SignedAllocatorList* containList = GetListContainingAllocator(header);
    containList->InsertAtEnd(header);
}

// USA: func_020af1f4
// JPN: func_020b0cc0
// Original: arm9/main @ 0x020AF1F4; symbol: _ZN13AllocatorTree6RemoveEP21SignedAllocatorHeader; size: 0x18.
void AllocatorTree::Remove(SignedAllocatorHeader* alloc)
{
    SignedAllocatorList* containList = GetListContainingAllocator(alloc);
    containList->Remove(alloc);
}