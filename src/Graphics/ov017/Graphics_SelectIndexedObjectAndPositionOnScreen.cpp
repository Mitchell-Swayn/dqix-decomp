#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const void*,int*,int*);
extern "C" void SetThreeWordFieldsAtOffsets1C20And24(int,unsigned,unsigned,unsigned);
extern "C" void Object_SelectTimedSequenceAndResetFrame(void*,int);
// ARM9 ov017 0x0219b43c func_ov017_0219b43c
// Original: arm9/ov017 @ 0x0219B43C; symbol: func_ov017_0219b43c; size: 0x13C.
extern "C" void Graphics_SelectIndexedObjectAndPositionOnScreen(char* p,int index,const void* vector,int dx,int dy) {
    int x,y;
    void* state=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
    switch(index) {
    case 2: index=2; break;
    case 5: index=3; break;
    case 6: index=4; break;
    case 14: index=12; break;
    case 15: index=13; break;
    case 16: index=14; break;
    }
    Graphics_ConvertCopiedWorldVectorToScreenCoordinates(state,vector,&x,&y);
    *(char**)(p+0x3630)=p+0x2b90+index*0x88;
    if(index!=12 && index!=13 && index!=14) {
        SetThreeWordFieldsAtOffsets1C20And24(*(int*)(p+0x3630),(x-12+dx)<<12,(y-76+dy)<<12,0);
        Object_SelectTimedSequenceAndResetFrame(*(void**)(p+0x3630),1);
    } else {
        SetThreeWordFieldsAtOffsets1C20And24(*(int*)(p+0x3630),(x-6+dx)<<12,(y-76+dy)<<12,0);
    }
}
