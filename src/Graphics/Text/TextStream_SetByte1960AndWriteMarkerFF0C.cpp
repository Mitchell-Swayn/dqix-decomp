#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    void Text_ParseDelimitedSignedIntegerSequence(const char *,int *,int);
    unsigned char *ReadWordFieldAtOffset1C();
// Original: arm9/main @ 0x0206973C; symbol: func_0206973c; size: 0x54.
    int TextStream_SetByte1960AndWriteMarkerFF0C(void **out,const char *input){
        int id;
        Text_ParseDelimitedSignedIntegerSequence(input,&id,1);
        unsigned char *p=ReadWordFieldAtOffset1C();
        p[6496]=id;
        void *dest=*out;
        unsigned short code=0xff0c;
        memcpy(dest,&code,2);
        return 2;
    }
}
