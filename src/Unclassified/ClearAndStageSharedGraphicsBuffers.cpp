#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>
#include <System/BGBases.h>
extern "C" void* data_02107800;
extern "C" void ClearLinkedByteFlagBitZeroAndSetBitOne(unsigned);
// Original: arm9/main @ 0x02043124; symbol: func_02043124; size: 0xE0.
extern "C" void ClearAndStageSharedGraphicsBuffers(char* p){
    *(unsigned*)(p+0x9a0)=0;*(unsigned*)(p+0x998)=0;
    if(*(unsigned char*)(p+0x19cc)){
        p[0x19cc]=0;void* buffer=data_02107800;
        memset(buffer,0,0x1000);
        StageMemoryToVRAM((VRAMSubregion)7,buffer,0,0x800,true,false);
        StageMemoryToVRAM((VRAMSubregion)9,buffer,0,0x800,true,false);
        void* screen=(void*)GetMainBG1ScreenBase();
        if(screen)memset(screen,0,0x800);
        *(volatile unsigned*)0x04000018=0;
        volatile unsigned* display=(volatile unsigned*)0x04000000;
        *display=(*display&~0x1f00)|0x1300;
    }
    if(*(unsigned*)(p+0x38))ClearLinkedByteFlagBitZeroAndSetBitOne(*(unsigned*)(p+0x38));
    *(unsigned*)(p+0x38)=0;
}
