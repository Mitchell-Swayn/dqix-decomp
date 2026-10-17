#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <System/ColorEffects.h>
extern "C" int GameResources_GetInstance();
extern "C" void Graphics_InitializeCanvasTransferState(void*);
extern "C" void DispatchResourceLoadByFourByteTag(void*,unsigned,int,int);

extern "C" unsigned char* data_02107800[2];

extern "C" void func_020c4cc8(void*);


extern "C" void* GetMainBG1ScreenBase();
// Original: arm9/main @ 0x02044D0C; symbol: func_02044d0c; size: 0x230.
extern "C" void ARM Graphics_ConfigureMainDisplayAndBackgroundControls(void) {
    volatile unsigned* disp=(volatile unsigned*)0x04000000;
    volatile unsigned short* cnt=(volatile unsigned short*)0x0400000a;
    disp[0]= (disp[0]&0xffffe0ff)|0x1100;
    disp[6]=0; disp[7]=0;
    cnt[0]=(cnt[0]&0x43)|0x1d00;
    cnt[1]=(cnt[1]&0x43)|0x1e00;
    cnt[2]=(cnt[2]&0x43)|0x1f08;
    unsigned char* buf=data_02107800[0];
    int context=GameResources_GetInstance();
    unsigned size=*(unsigned*)((char*)context+0x2c);
    struct Descriptor { unsigned char prefix[0x1c]; unsigned char low:4; unsigned char high:4; unsigned char tail[3]; } descriptor;

    Graphics_InitializeCanvasTransferState(&descriptor);
    descriptor.low=0;
    descriptor.high=3;
    DispatchResourceLoadByFourByteTag(&descriptor,size,0,0);
    if(buf) {
        memset(buf,0,0x1000);
        unsigned char i=0;
        while(i<6) { StageMemoryToVRAM((VRAMSubregion)10,buf,(unsigned)i<<12,0x1000,1,0); i=(unsigned char)(i+1); }
        unsigned char* volatile* banks=(unsigned char* volatile*)data_02107800;
        unsigned char* p=banks[1];
        if(p+0x280) StageMemoryToVRAM((VRAMSubregion)8,p+0x280,0x20,0x900,1,0);
    }
    if(buf) {
        memset(buf,0,0x1000);
        StageMemoryToVRAM((VRAMSubregion)7,buf,0,0x800,1,0);
        unsigned short* p=(unsigned short*)(buf+0x800);
        unsigned short i=0;
        while(i<0x300) { *p=i; i=(unsigned short)(i+1); ++p; }
        StageMemoryToVRAM((VRAMSubregion)9,buf,0,0x800,1,0);
        void* screen=GetMainBG1ScreenBase();
        if(screen)memset(screen,0,0x800);
    }
    ColorEffect_ConfigureAlphaBlend(0x04000050,4,1,10,6);
    volatile unsigned short* blend=(volatile unsigned short*)0x04000008;
    blend[0]=(blend[0]&~3)|3;
    blend[1]=(blend[1]&~3)|2;
    blend[2]=(blend[2]&~3)|1;
    blend[3]&=~3;
}
