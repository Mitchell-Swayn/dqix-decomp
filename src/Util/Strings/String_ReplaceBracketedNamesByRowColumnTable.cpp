#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {
// Original data: arm9/main @ 0x20ee9d8; symbol: data_020ee9d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000270000656e006573007300006e0000720000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20eeab0; symbol: data_020eeab0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000101000000000000020200000000000003030000000000000404000000000000050505050505000002020202020200000404020202020006050505050505 ...; full span in module reference.
// Observed span: 104 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2d2c; symbol: data_020f2d2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 67275d000000000000000067656e5d000000000000006765735d0000000000000067735d000000000000000073676c5f696e665f315d0073676c5f696e665f32 ...; full span in module reference.
// Observed span: 156 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern signed char StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes_Variant3[][11];extern signed char StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes_Variant2[];extern signed char StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes[][3];
unsigned String_CountBytesUntilTerminator(const char *);int RuntimeMemory_CompareByteRanges(const void *,const void *,unsigned);
// Original: arm9/main @ 0x020E4864; symbol: func_020e4864; size: 0xF4.
void String_ReplaceBracketedNamesByRowColumnTable(const signed char *input,signed char *output,int row,unsigned unused,unsigned unused2,int column) {
    signed char current;
    for(;;) {
        current=*input;
        if(current==0)break;
        if(*input=='[') {
            bool found=false;
            const signed char *names=&StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes_Variant3[0][0];
            for(int i=0;;i++) {
                int offset=i*11;
                if(names[offset]==0)break;
                unsigned length=String_CountBytesUntilTerminator((const char *)(names+offset));
                if(RuntimeMemory_CompareByteRanges(input+1,names+offset,length)==0) {
                    if(row>=0&&column>=0) {
                        int index=*(StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes_Variant2+i*8+(row+column*2));
                        const signed char *replacements=&StringReplaceBracketedNamesByRowColumnTable_UnknownRoleInitializedBytes[0][0];
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
