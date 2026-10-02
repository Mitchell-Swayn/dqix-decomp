#include "TitleDisplayResources.h"

// Load the mobile-service background and distribute alternating archive entries.
extern "C" void func_ov020_0218cf8c(TitleTransitionController* state) {
    state->primaryAllocator.Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0,0,31,2,0);
    func_0204af64(&state->mainBackground);
    func_0204b11c(&state->mainBackground,0);
    state->mainBackground.engine=0;
    state->mainBackground.layer=1;
    func_0204b5b4(&state->mainBackground,0);
    func_0204b12c(&state->mainBackground,&state->primaryAllocator);
    func_0204af38(&state->mainBackground,1,&state->primaryAllocator);
    func_0204b5e8(&state->mainBackground,0,0);
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0,0,1,1,0);
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
    task=loader->QueueLoadFile(data_ov020_0218dcca,0);
    for (;;) {
        if (loader->GetTaskStatus(task)) {
            int type;
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(task,&file,&length);
            int count=func_02046900(file);
            void* entries[6];
            unsigned int sizes[6];
            for(int i=0;i<count;i++) entries[i]=func_020467f0(file,i,&type,&sizes[i]);
            TitleBackgroundSelection mainSelection=data_ov020_0218d950;
            TitleBackgroundSelection subSelection=data_ov020_0218d944;
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
    *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000 & ~0x1f00)|0x200;
    *(volatile unsigned int*)0x04001000=(*(volatile unsigned int*)0x04001000 & ~0x1f00)|0x100;
    func_020c39a0((volatile unsigned short*)0x0400006c,-16);
    func_020c39a0((volatile unsigned short*)0x0400106c,-16);
}

extern "C" {
void DisableSubObjVRAMBanks();
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubObj(int);
void func_020c3984(int);
void func_0204b2e0(void*,void*);
void func_0204b3a0(void*,void*);
void func_0204afb4(TitleBackgroundDescriptor*);
extern char data_ov020_0218dce2[], data_ov020_0218dcf8[];
extern unsigned char data_0211e33c[];
}
// Select the Square Enix or Level-5 archive and upload its three sub-BG entries.
extern "C" void func_ov020_0218d32c(TitleTransitionController* state, int publisher) {
    state->primaryAllocator.Reset();
    func_020c39a0((volatile unsigned short*)0x0400006c,-16);
    func_020c39a0((volatile unsigned short*)0x0400106c,-16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0,1,1,1,0);
    func_0204af64(&state->mainBackground);
    func_0204b11c(&state->mainBackground,0);
    TitleBackgroundDescriptor* main = &state->mainBackground;
    main->engine=0;
    main->layer=1;
    func_0204b5b4(main,1);
    func_0204b12c(&state->mainBackground,&state->primaryAllocator);
    func_0204af38(&state->mainBackground,1,&state->primaryAllocator);
    func_0204b5e8(&state->mainBackground,0,0);
    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    func_020c3984(0);
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00)|0x100;
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef)|0x10;
    MapVRAMBanksToSubBG(0x80);
    func_ov020_0218cd64(0,0,14,0,0);
    func_ov020_0218cd64(0,0,15,0,0);
    volatile unsigned short* controls=(volatile unsigned short*)0x04001008;
    controls[0]=(controls[0]&~3)|1;
    controls[1]=(controls[1]&~3)|2;
    controls[2]=controls[2]&~3;
    controls[3]=(controls[3]&~3)|3;
    BackgroundLoader::AddLockGlobal();
    unsigned int length;
    int type;
    if (publisher==1) LoadFileIntoMemory(data_ov020_0218dce2,data_0211e33c,&length);
    else LoadFileIntoMemory(data_ov020_0218dcf8,data_0211e33c,&length);
    int count=func_02046900(data_0211e33c);
    // Keep the descriptor and parser output together: upload calls can alias
    // this record, so each entry pointer is read again between the two calls.
    struct Upload {
        TitleBackgroundDescriptor background;
        unsigned int sizes[3];
        void* entries[3];
    } upload;
    for(int i=0;i<count;i++) upload.entries[i]=func_020467f0(data_0211e33c,i,&type,&upload.sizes[i]);
    func_0204af64(&upload.background);
    upload.background.engine=1;
    upload.background.layer=0;
    func_0204b5b4(&upload.background,3);
    func_0204b11c(&upload.background,0);
    func_0204b5e8(&upload.background,0,0);
    for(int i=0;i<3;i++) {
        func_0204b2e0(&upload.background,upload.entries[i]);
        func_0204b3a0(&upload.background,upload.entries[i]);
    }
    func_0204b0e8(&upload.background,0);
    func_0204afb4(&upload.background);
    BackgroundLoader::RemoveLockGlobal();
    *(volatile unsigned short*)0x04000050=0;
    *(volatile unsigned short*)0x04001050=0;
    ColorEffect_ConfigureAlphaBlend(0x04000050,1,2,15,31);
    *(volatile unsigned int*)0x04000000=(*(volatile unsigned int*)0x04000000 & ~0x1f00)|0x1300;
    func_020c39a0((volatile unsigned short*)0x0400006c,-16);
    func_020c39a0((volatile unsigned short*)0x0400106c,-16);
}
