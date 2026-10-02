#include "TitleDisplayResources.h"

extern "C" {
extern char data_ov020_0218dcb3[];
extern unsigned char data_0211e33c[];
}

// Load the Nintendo background synchronously while the background loader is locked.
extern "C" void func_ov020_0218cd98(TitleTransitionController* state) {
    func_020c39a0((volatile unsigned short*)0x0400106c, -16);
    state->primaryAllocator.Reset();
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0,1,1,1,0);
    func_0204af64(&state->subBackground);
    func_0204b11c(&state->subBackground,0);
    TitleBackgroundDescriptor* region = &state->subBackground;
    region->engine = 1;
    region->layer = 0;
    func_0204b5b4(region,0);
    func_0204b12c(&state->subBackground,&state->primaryAllocator);
    func_0204af38(&state->subBackground,1,&state->primaryAllocator);
    func_0204b5e8(&state->subBackground,0,0);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    LoadFileIntoMemory(data_ov020_0218dcb3,data_0211e33c,&length);
    int count = func_02046900(data_0211e33c);
    unsigned int size;
    int type;
    for (int i=0;i<count;i++) {
        void* entry = func_020467f0(data_0211e33c,i,&type,&size);
        if (entry) func_0204b174(&state->subBackground,entry,&state->primaryAllocator,size);
    }
    func_0204b8d0(&state->subBackground,0,0,0,0,0,32,24,65535);
    func_0204b0e8(&state->subBackground,0);
    BackgroundLoader::RemoveLockGlobal();
    *(volatile unsigned short*)0x04000050 = 0;
    *(volatile unsigned short*)0x04001050 = 0;
    *(volatile unsigned int*)0x04000000 = (*(volatile unsigned int*)0x04000000 & ~0x1f00) | 0x1300;
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x100;
    func_020c39a0((volatile unsigned short*)0x0400006c,-16);
    func_020c39a0((volatile unsigned short*)0x0400106c,-16);
}
