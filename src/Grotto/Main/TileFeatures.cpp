#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"

#ifdef jpn
#define ChooseTileFeaturePosition_UnknownRoleInitializedBytes data_020e78b4
#define Zone3D_GetMainInstance func_02012dac
#define ChooseTileFeatureOrientation_UnknownRoleInitializedBytes data_020e78b0
#endif

// Original data: arm9/main @ 0x20e7010; symbol: data_020e7010.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff0000000000000000000000000a000040000000000800002f0000004000000000080000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char const ChooseTileFeaturePosition_UnknownRoleInitializedBytes[];
extern "C" int Zone3D_GetMainInstance(void);
// Original data: arm9/main @ 0x20e700c; symbol: data_020e700c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char const ChooseTileFeatureOrientation_UnknownRoleInitializedBytes[];

// USA: func_0201ea54
// JPN: func_0201e7e0
// Original: arm9/main @ 0x0201EA54; symbol: _Z25ChooseTileFeaturePositionPK24TileFeaturePlacementData; size: 0x7C.
int ChooseTileFeaturePosition(const TileFeaturePlacementData* data)
{
    unsigned char validArray[12];
 
    // This function doesn't seem to do anything besides put a value in r0.
    // We never use the value, but it gets called so yeah   
    Zone3D_GetMainInstance();

    int validCount = 0;

    int j = 9;
    unsigned char* copyDst = validArray;
    const unsigned char* copySrc = ChooseTileFeaturePosition_UnknownRoleInitializedBytes;
    do
    {
        j--;
        *copyDst = *copySrc;
        copyDst++;
        copySrc++;
    } while (j != 0);

    for (int i = 0; i < 9; i++)
    {
        if (data->directionBitmasks[i] != 0)
        {
            validArray[validCount++] = i;
        }
    }
    
    return (int)(char)validArray[rand() % validCount];
}

// USA: func_0201ead0
// JPN: func_0201e85c
// Original: arm9/main @ 0x0201EAD0; symbol: _Z28ChooseTileFeatureOrientationPK24TileFeaturePlacementDataib; size: 0xF4.
int ChooseTileFeatureOrientation(const TileFeaturePlacementData* data,
    int direction, bool preferFaceDown)
{
    char validDirections[4];

    Zone3D_GetMainInstance();
    int numValidDirections = 0;    
    int j = 4;
    unsigned char* dstPtr = (unsigned char*)validDirections;
    const unsigned char* srcPtr = ChooseTileFeatureOrientation_UnknownRoleInitializedBytes;
    do {
        j--;
        *dstPtr = *srcPtr;
        dstPtr++;
        srcPtr++;
    } while (j != 0);

    for (unsigned int i = 0; (int)i < 4; i++)
    {
        if (((int)data->directionBitmasks[direction] >> i & 1u) != 0)
        {
            validDirections[numValidDirections++] = i;
        }
    }

    if (preferFaceDown)
    {
        // 2 = facing down, 1 = facing right, 3 = facing left
        for (int i = 0; i < numValidDirections; i++)
        {
            if (validDirections[i] == 2)
                return validDirections[i];
        }

        for (int i = 0; i < numValidDirections; i++)
        {
            if (validDirections[i] == 1)
                return validDirections[i];
        }

        for (int i = 0; i < numValidDirections; i++)
        {
            if (validDirections[i] == 3)
                return validDirections[i];
        }
    }

    return (int)validDirections[rand() % numValidDirections];
}
