#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    extern char data_020ef6b5[],data_020ef6c5[];
    const char *LookupGlobalResourceByKey(int);
    unsigned int TextLayout_ComputeWidthWithGlyphSpacing(const char *,int);
// Original: arm9/main @ 0x02026470; symbol: func_02026470; size: 0x74.
    void FormatIdentifierTextAndAccumulateWidth(unsigned char *p,int id){
        if(!id)strcpy((char *)p+1524,data_020ef6b5);
        else sprintf((char *)p+1524,data_020ef6c5,LookupGlobalResourceByKey(1011),id);
        unsigned int len=TextLayout_ComputeWidthWithGlyphSpacing((char *)p+1524,0);
        *(unsigned int *)(p+3044)+=len+4;
    }
}
