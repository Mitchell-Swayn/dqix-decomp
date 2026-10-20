typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef int intptr_t;
#define NULL 0
typedef struct SearchTreeEntry { unsigned char bitIndex_; unsigned char children_[2]; unsigned char resourceIndex_; } SearchTreeEntry;
typedef struct NSBXXNameList { unsigned char unknown_0_, numEntries_; unsigned short totalSize_, subheaderSize_, offsetToDataStart_; SearchTreeEntry treeRoot_8_; } NSBXXNameList;

#pragma optimize_for_size off

// Original: arm9/main @ 0x020B752C; symbol: NSBXXNameList_SearchIndex; size: 0x168.
extern "C" int NNS_G3dGetResDictIdxByName(NSBXXNameList* nameList, const char* name)
{
    unsigned int numEntries;
    volatile NSBXXNameList* volList = nameList;
    const uint32_t* targetIntArray = (const uint32_t*)name;
    if (name == NULL)
        return -1;

    numEntries = nameList->numEntries_;
    if (numEntries < 16) // list is short, do linear search
    {
        unsigned int searchIndex = 0;
        uint32_t target0 = targetIntArray[0];
        uint32_t target1 = targetIntArray[1];
        uint32_t target2 = targetIntArray[2];
        uint32_t target3 = targetIntArray[3];
        unsigned int zero = 0;
        if (numEntries > zero)
        {
            int offsetWithinNameData = 0;
            do
            {
                const uint32_t* source;
                intptr_t sourcePtr;
                    if (nameList != NULL && searchIndex < volList->numEntries_)
                {
                    intptr_t dataStart = (intptr_t)nameList + nameList->offsetToDataStart_;
                    // dataStart + 2 holds the distance between dataStart and the start
                    // of the name data
                    sourcePtr = dataStart + *(uint16_t*)(dataStart + 2);
                    sourcePtr += offsetWithinNameData;
                }
                else
                    sourcePtr = 0;

                // Compare 16-byte strings by comparing ints
                source = (const uint32_t*)sourcePtr;
                if (source[0] == target0 && source[1] == target1 &&
                    source[2] == target2 && source[3] == target3)
                    return searchIndex;

                searchIndex++;
                offsetWithinNameData += 16;
            } while (searchIndex < volList->numEntries_);
        }
    }
    else // list is long, use the binary search tree
    {
        SearchTreeEntry* entryArray = (SearchTreeEntry*)&nameList->treeRoot_8_;
        unsigned int candidateIndex;
        intptr_t sourcePtr;
        const uint32_t* sourceIntArray;
        int firstChild = entryArray[0].children_[0];
        if (firstChild != 0)
        {
            SearchTreeEntry* searchCursor = &entryArray[firstChild];
            int bitIndex = entryArray[firstChild].bitIndex_;
            unsigned int prevBitIndex = entryArray[0].bitIndex_;
            if (prevBitIndex > bitIndex)
            {
                do
                {
                    int integerToQuery = bitIndex >> 5;
                    int bitToQuery = bitIndex & 0x1f;
                    int bitValue = (targetIntArray[integerToQuery] >> bitToQuery) & 1;
                    int childID = searchCursor->children_[bitValue];
                    prevBitIndex = searchCursor->bitIndex_;
                    searchCursor = &entryArray[childID];
                    bitIndex = entryArray[childID].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            candidateIndex = searchCursor->resourceIndex_;
            if (nameList != NULL && candidateIndex < nameList->numEntries_)
            {
                intptr_t dataStart = (intptr_t)nameList + nameList->offsetToDataStart_;
                // dataStart + 2 holds the distance between dataStart and the start
                // of the name data
                sourcePtr = dataStart + *(uint16_t*)(dataStart + 2) + (candidateIndex * 16);
            }
            else
                sourcePtr = 0;

            sourceIntArray = (const uint32_t*)sourcePtr;
            if (sourceIntArray[0] == targetIntArray[0] && sourceIntArray[1] == targetIntArray[1] &&
                sourceIntArray[2] == targetIntArray[2] && sourceIntArray[3] == targetIntArray[3])
                return searchCursor->resourceIndex_;

        }
    }

    return -1;
}