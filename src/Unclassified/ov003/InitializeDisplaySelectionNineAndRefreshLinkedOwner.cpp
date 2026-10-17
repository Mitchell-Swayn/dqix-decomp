#include <globaldefs.h>
ARM
extern "C" {
    void Object_CreateAndConfigureSelectedDisplayPart(void*,int);
    void ResetPointedHalfwordAndSynchronizeSignedByteState(void*);
    void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int);
    void Object_SetSelectedTextureFlag20(void*,int);
    void ResetOwnerSetLinkedValueAndRefresh(void*,int);
    extern char data_02108760[];
}
// Original: arm9/ov003 @ 0x021612C0; symbol: func_ov003_021612c0; size: 0x84.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" void InitializeDisplaySelectionNineAndRefreshLinkedOwner(char* p) {
    *(short*)(p+0x488)=9;
    *(short*)(p+0x474)=*(short*)(p+0x49c)=44;
    *(short*)(*(char**)(p+0x324)+0x36)=*(short*)(p+0x49c);
    Object_CreateAndConfigureSelectedDisplayPart(*(void**)(p+0x324),*(short*)(p+0x488));
    ResetPointedHalfwordAndSynchronizeSignedByteState(p+0x308);
    *(int*)(p+0x470)=0;
    DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,5,0);
    if(*(void**)(p+0x390)) {
        Object_SetSelectedTextureFlag20(*(void**)(p+0x324),*(short*)(p+0x488));
        ResetOwnerSetLinkedValueAndRefresh(*(void**)(p+0x390),-1);
    }
}
