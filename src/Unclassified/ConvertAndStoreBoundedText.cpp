#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(void*,void*,int);
extern "C" unsigned EncodeTextAsGlyphIds(void*,void*,int);
extern "C" char data_020ef078[];
// Original: arm9/main @ 0x02052958; symbol: func_02052958; size: 0xB8.
extern "C" ARM void ConvertAndStoreBoundedText(char* p,void* source,int format)
{
    char first[48],second[48];
    __clear(first,48);
    __clear(second,48);
    Text_MapInputBytesToVariableLengthOutputSequences(source,first,1);
    unsigned size=EncodeTextAsGlyphIds(first,second,1);
    memset(p+0x141,0,12);
    memcpy(p+0x141,source,size);
    if(format)
    {
        char third[48];
        __clear(third,48);
        Text_MapInputBytesToVariableLengthOutputSequences(source,third,1);
        sprintf(*(char**)(p+0x134),data_020ef078,third);
    }
}
