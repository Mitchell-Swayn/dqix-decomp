#pragma thumb off
// Field behavior reconstructed from original instructions; broader object semantics remain uncertain.
extern "C" unsigned char data_02114e30[],data_02114e54[];
extern "C" int Object_TestNewlySetHalfwordMask(void*,unsigned);
extern "C" unsigned ReadBit(void*);
extern "C" int ReadSelectionWhenInputActiveOrMinusOne(void*);
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int SelectHitEntryAndWriteFlagOutput(void*,short,short,short,unsigned char*,int);
extern "C" void Object_CreateAndConfigureSelectedDisplayPart(void*,short);
// Original: arm9/ov003 @ 0x021765B4; symbol: func_ov003_021765b4; size: 0x134.
extern "C" int UpdateSelectionFromActiveInputOrHitTest(char* obj) {
    unsigned char changed=0;
    if(Object_TestNewlySetHalfwordMask(data_02114e30,0x401))changed=1;
    if(*(void**)obj && ReadBit(*(void**)obj)) {
        int selection=ReadSelectionWhenInputActiveOrMinusOne(*(void**)obj);
        if(selection>=0) {
            changed=1;
            **(short**)(obj+0xff8)=selection+2;
        }
    } else if(data_02114e54[0x55] && *(short**)(obj+0xff8)) {
        int x,y;
        char* target=*(char**)(obj+0x89c);
        ReadSelectedCoordinatePair(data_02114e54,&x,&y);
        *(short*)(obj+0x1000)=**(short**)(obj+0xff8);
        int result=SelectHitEntryAndWriteFlagOutput(target,*(short*)(obj+0xffe),(short)x,(short)y,&changed,1);
        if(result<0)return 0;
        **(short**)(obj+0xff8)=result;
        if(*(short*)(obj+0x1000)!=**(short**)(obj+0xff8)) {
            *(short*)(target+0x36)=**(short**)(obj+0xff8);
            Object_CreateAndConfigureSelectedDisplayPart(target,*(short*)(obj+0xffe));
        }
    }
    return changed;
}
