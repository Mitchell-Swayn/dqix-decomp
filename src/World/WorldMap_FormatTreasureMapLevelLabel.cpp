#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20ef6b5; symbol: data_020ef6b5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char WorldMapFormatTreasureMapLevelLabel_UnknownRoleInitializedBytes[],WorldMap_FormatTreasureMapLevelLabel_FormatSD[];
    const char *Text_LookupStandardString(int);
    unsigned int TextLayout_ComputeWidthWithGlyphSpacing(const char *,int);
// Original: arm9/main @ 0x02026470; symbol: func_02026470; size: 0x74.
    void WorldMap_FormatTreasureMapLevelLabel(unsigned char *p,int id){
        if(!id)strcpy((char *)p+1524,WorldMapFormatTreasureMapLevelLabel_UnknownRoleInitializedBytes);
        else sprintf((char *)p+1524,WorldMap_FormatTreasureMapLevelLabel_FormatSD,Text_LookupStandardString(1011),id);
        unsigned int len=TextLayout_ComputeWidthWithGlyphSpacing((char *)p+1524,0);
        *(unsigned int *)(p+3044)+=len+4;
    }
}
