#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(void*,void*,int);
extern "C" unsigned Text_EncodeGlyphIndices(void*,void*,int);
// Original data: arm9/main @ 0x20ef078; symbol: data_020ef078.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];
// Original: arm9/main @ 0x02052958; symbol: func_02052958; size: 0xB8.
extern "C" ARM void Text_ConvertAndStoreBoundedText(char* p,void* source,int format)
{
    char first[48],second[48];
    __clear(first,48);
    __clear(second,48);
    Text_MapInputBytesToVariableLengthOutputSequences(source,first,1);
    unsigned size=Text_EncodeGlyphIndices(first,second,1);
    memset(p+0x141,0,12);
    memcpy(p+0x141,source,size);
    if(format)
    {
        char third[48];
        __clear(third,48);
        Text_MapInputBytesToVariableLengthOutputSequences(source,third,1);
        sprintf(*(char**)(p+0x134),UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,third);
    }
}
