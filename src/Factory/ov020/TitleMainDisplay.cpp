#include "TitleDisplayResources.h"

// Load the title archive, distributing its entries to the main and sub BGs.
// Local declaration order preserves the original compiler's stack layout.
extern "C" void func_ov020_0218c98c(TitleTransitionController* state) {
    state->primaryAllocator.Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0,1,1,1,0);
    func_0204af64(&state->mainBackground);
    func_0204b11c(&state->mainBackground,0);
    state->mainBackground.engine=0;
    state->mainBackground.layer=1;
    func_0204b5b4(&state->mainBackground,1);
    func_0204b12c(&state->mainBackground,&state->primaryAllocator);
    func_0204af38(&state->mainBackground,1,&state->primaryAllocator);
    func_0204b5e8(&state->mainBackground,0,0);
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0,1,1,1,0);
    func_0204af64(&state->subBackground);
    func_0204b11c(&state->subBackground,0);
    state->subBackground.engine=1;
    state->subBackground.layer=0;
    func_0204b5b4(&state->subBackground,0);
    func_0204b12c(&state->subBackground,&state->primaryAllocator);
    func_0204af38(&state->subBackground,1,&state->primaryAllocator);
    func_0204b5e8(&state->subBackground,0,0);
    int task;
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    loader->MaybeReset();
    task=loader->QueueLoadFile(data_ov020_0218dc9d,0);
    for (;;) {
        if (loader->GetTaskStatus(task)) {
            int type;
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(task,&file,&length);
            int count=func_02046900(file);
            void* entries[5];
            unsigned int sizes[5];
            for(int i=0;i<count;i++) entries[i]=func_020467f0(file,i,&type,&sizes[i]);
            TitleBackgroundSelection mainSelection=data_ov020_0218d95c;
            TitleBackgroundSelection subSelection=data_ov020_0218d968;
            int mainIndex=0;
            int subIndex=0;
            for(int i=0;i<count;i++) {
                if (i==mainSelection.indices[mainIndex]) {
                    func_0204b174(&state->mainBackground,entries[i],&state->primaryAllocator,sizes[i]);
                    mainIndex++;
                }
                if (i==subSelection.indices[subIndex]) {
                    func_0204b174(&state->subBackground,entries[i],&state->primaryAllocator,sizes[i]);
                    subIndex++;
                }
            }
            loader->RemoveTask(task);
            func_0204b8d0(&state->mainBackground,0,0,0,0,0,32,25,0);
            func_0204b8d0(&state->subBackground,0,0,0,0,0,32,25,0);
            func_0204b0e8(&state->mainBackground,0);
            func_0204b0e8(&state->subBackground,0);
            break;
        }
        loader->RemoveAllLocks();
    }
    *(volatile unsigned short*)0x04000050=0;
    *(volatile unsigned short*)0x04001050=0;
    ColorEffect_ConfigureAlphaBlend(0x04000050,1,2,15,31);
    ColorEffect_ConfigureAlphaBlend(0x04001050,1,2,31,0);
    *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000 & ~0x1f00)|0x300;
    *(volatile unsigned int*)0x04001000=(*(volatile unsigned int*)0x04001000 & ~0x1f00)|0x100;
    func_020c39a0((volatile unsigned short*)0x0400006c,0);
    func_020c39a0((volatile unsigned short*)0x0400106c,0);
}
