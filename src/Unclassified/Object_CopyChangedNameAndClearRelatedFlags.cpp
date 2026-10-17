#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02023B0C; symbol: func_02023b0c; size: 0x50.
    void Object_CopyChangedNameAndClearRelatedFlags(unsigned char *p,const char *s){
        if(!s)return;
        if(strcmp(s,(char *)p+2)==0)p[18]=0;else p[18]=1;
        if(p[18]){
            p[0x779]=0;
            p[0x9ba]=0;
        }strcpy((char *)p+2,s);
    }
}
