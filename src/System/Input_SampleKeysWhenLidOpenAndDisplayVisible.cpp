#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" int Graphics_DecodeSignedBrightness(unsigned);
extern "C" unsigned short Input_ReadCombinedKeyState();
extern "C" char* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);
struct State
{
    unsigned short current,previous;
    unsigned char pad[24];
    unsigned char enabled;
};
// Original: arm9/main @ 0x0201229C; symbol: func_0201229c; size: 0xB8.
extern "C" ARM void Input_SampleKeysWhenLidOpenAndDisplayVisible(State* p)
{
    bool clear=false;
    if(p->enabled&&((*(volatile unsigned short*)0x027fffa8&0x8000)>>15)==0)
    {
        int x=Graphics_DecodeSignedBrightness(0x0400106c);
        int y=Graphics_DecodeSignedBrightness(0x0400006c);
        y=abs(y);
        x=abs(x);
        if(y+x<32)goto done;
    }clear=true;
    done:if(clear)
    {
        p->previous=0;
        p->current=0;
        return;
    }p->previous=p->current;
    p->current=Input_ReadCombinedKeyState();
    if(p->current)
    {
        char* owner=GameState_GetSerializedProgressState();
        BitArray_SetIndexedBoolean(owner,owner+0x8c,0x113e,1);
    }
}
