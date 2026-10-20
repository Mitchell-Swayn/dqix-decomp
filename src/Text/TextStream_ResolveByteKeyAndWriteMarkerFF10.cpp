#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    void Text_ParseDelimitedSignedIntegerSequence(const char *,int *,int);
    void *Quest_GetGlobalOrderState();
    int FindByteKeyAmong204EntriesOrReturnFF(void *,unsigned char);
    unsigned char *TextContext_GetSharedInstance();
// Original: arm9/main @ 0x02069D08; symbol: func_02069d08; size: 0x64.
    int TextStream_ResolveByteKeyAndWriteMarkerFF10(void **out,const char *input){
        int id;
        Text_ParseDelimitedSignedIntegerSequence(input,&id,1);
        void *state=Quest_GetGlobalOrderState();
        int value=FindByteKeyAmong204EntriesOrReturnFF(state,id);
        unsigned char *p=TextContext_GetSharedInstance();
        *(short *)(p+0x1948)=value;
        void *dest=*out;
        unsigned short code=0xff10;
        memcpy(dest,&code,2);
        return 2;
    }
}
