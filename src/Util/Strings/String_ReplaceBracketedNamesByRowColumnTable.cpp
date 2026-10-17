#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {
extern signed char data_020f2d2c[][11];extern signed char data_020eeab0[];extern signed char data_020ee9d8[][3];
unsigned String_CountBytesUntilTerminator(const char *);int RuntimeMemory_CompareByteRanges(const void *,const void *,unsigned);
// Original: arm9/main @ 0x020E4864; symbol: func_020e4864; size: 0xF4.
void String_ReplaceBracketedNamesByRowColumnTable(const signed char *input,signed char *output,int row,unsigned unused,unsigned unused2,int column) {
    signed char current;
    for(;;) {
        current=*input;
        if(current==0)break;
        if(*input=='[') {
            bool found=false;
            const signed char *names=&data_020f2d2c[0][0];
            for(int i=0;;i++) {
                int offset=i*11;
                if(names[offset]==0)break;
                unsigned length=String_CountBytesUntilTerminator((const char *)(names+offset));
                if(RuntimeMemory_CompareByteRanges(input+1,names+offset,length)==0) {
                    if(row>=0&&column>=0) {
                        int index=*(data_020eeab0+i*8+(row+column*2));
                        const signed char *replacements=&data_020ee9d8[0][0];
                        i=index*3;
                        const signed char *replacement=replacements+i;
                        unsigned size=String_CountBytesUntilTerminator((const char *)replacement);
                        memcpy(output,replacement,size);output+=size;
                    }
                    input+=length+1;found=true;break;
                }
            }
            if(found)continue;
        }
        *output++=*input++;
    }
    *output=current;
}
}
