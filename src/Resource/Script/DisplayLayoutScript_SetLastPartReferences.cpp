#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2108ee0; symbol: data_02108ee0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char *DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[];
    unsigned char *DisplayLayout_GetPartByIndex(void *,int);
// Original: arm9/main @ 0x0207F4A8; symbol: func_0207f4a8; size: 0x68.
    bool DisplayLayoutScript_SetLastPartReferences(Script::Parameter *p){
        unsigned char *owner=DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[1];
        short index=*(short *)(owner+4)-1;
        unsigned char *q=DisplayLayout_GetPartByIndex(owner,index);
        if(q){
            *(short *)(q+24)=p[0].ToInt();
            *(short *)(q+28)=p[1].ToInt();
            *(short *)(q+32)=p[2].ToInt();
            *(short *)(q+36)=p[3].ToInt();
        }return true;
    }
}
