#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    void Text_ParseDelimitedSignedIntegerSequence(const char *,int *,int);
    void *TextContext_GetSharedInstance();
    void TextWindow_EnqueueControlDelay(void *,int);
// Original: arm9/main @ 0x020698AC; symbol: func_020698ac; size: 0x50.
    int TextStream_AppendRingValueAndWriteMarkerFF1E(void **out,const char *input){
        int id;
        Text_ParseDelimitedSignedIntegerSequence(input,&id,1);
        TextWindow_EnqueueControlDelay(TextContext_GetSharedInstance(),id);
        void *dest=*out;
        unsigned short code=0xff1e;
        memcpy(dest,&code,2);
        return 2;
    }
}
