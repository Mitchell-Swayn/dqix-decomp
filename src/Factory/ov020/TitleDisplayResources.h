#pragma once

#include "TitleController.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "System/ColorEffects.h"

struct TitleBackgroundSelection { int indices[3]; };

extern "C" {
void func_020c39a0(volatile unsigned short*, int);
void MapVRAMBanksToSubBG(int);
void MapVRAMBanksToMainBG(int);
void func_ov020_0218cd64(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
void func_ov020_0218c7bc(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
void func_0204af64(TitleBackgroundDescriptor*);
void func_0204b11c(TitleBackgroundDescriptor*, int);
void func_0204b5b4(TitleBackgroundDescriptor*, int);
void func_0204b12c(TitleBackgroundDescriptor*, SafeAllocator*);
void func_0204af38(TitleBackgroundDescriptor*, int, SafeAllocator*);
void func_0204b5e8(TitleBackgroundDescriptor*, int, int);
int func_02046900(void*);
void* func_020467f0(void*, int, int*, unsigned int*);
void func_0204b174(TitleBackgroundDescriptor*, void*, SafeAllocator*, unsigned int);
void func_0204b8d0(TitleBackgroundDescriptor*, int,int,int,int,int,int,int,int);
void func_0204b0e8(TitleBackgroundDescriptor*, int);
extern char data_ov020_0218dc9d[], data_ov020_0218dcca[];
extern const TitleBackgroundSelection data_ov020_0218d944, data_ov020_0218d950, data_ov020_0218d95c, data_ov020_0218d968;
}
