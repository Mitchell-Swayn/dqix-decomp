#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    int TextLayout_ComputeWidthWithGlyphSpacing(const char *,int);
    unsigned int String_CountBytesUntilTerminator(const signed char *);
    extern char data_020efe91[];
// Original: arm9/main @ 0x02042084; symbol: func_02042084; size: 0x64.
    unsigned int Text_AppendCenteredTextUsingComputedWidth(char *out,const char *text,int width,int mode){
        int len=TextLayout_ComputeWidthWithGlyphSpacing(text,mode);
        sprintf(out+String_CountBytesUntilTerminator((const signed char *)out),data_020efe91,((width-len)>>1)+1);
        sprintf(out+String_CountBytesUntilTerminator((const signed char *)out),text);
        return String_CountBytesUntilTerminator((const signed char *)out);
    }
}
