#pragma thumb off
// Field behavior reconstructed from original instructions; broader object semantics remain uncertain.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
extern "C" unsigned Window_IsVisible(void*);
extern "C" int Window_GetConfirmedOptionForActiveInput(void*);
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int TextCanvas_SelectEntryAtPoint(void*,short,short,short,unsigned char*,int);
extern "C" void TextCanvas_CreateAndConfigureDisplayPart(void*,short);
// Original: arm9/ov003 @ 0x021765B4; symbol: func_ov003_021765b4; size: 0x134.
extern "C" int Shop_TestSelectionConfirmation(char* obj) {
    unsigned char changed=0;
    if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401))changed=1;
    if(*(void**)obj && Window_IsVisible(*(void**)obj)) {
        int selection=Window_GetConfirmedOptionForActiveInput(*(void**)obj);
        if(selection>=0) {
            changed=1;
            **(short**)(obj+0xff8)=selection+2;
        }
    } else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] && *(short**)(obj+0xff8)) {
        int x,y;
        char* target=*(char**)(obj+0x89c);
        ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
        *(short*)(obj+0x1000)=**(short**)(obj+0xff8);
        int result=TextCanvas_SelectEntryAtPoint(target,*(short*)(obj+0xffe),(short)x,(short)y,&changed,1);
        if(result<0)return 0;
        **(short**)(obj+0xff8)=result;
        if(*(short*)(obj+0x1000)!=**(short**)(obj+0xff8)) {
            *(short*)(target+0x36)=**(short**)(obj+0xff8);
            TextCanvas_CreateAndConfigureDisplayPart(target,*(short*)(obj+0xffe));
        }
    }
    return changed;
}
