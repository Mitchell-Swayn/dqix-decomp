#include <globaldefs.h>
#include <System/ColorEffects.h>
ARM
struct SafeAllocator; struct Owner; struct State; struct Record;
struct Nibbles {unsigned char low:4, high:4; inline void SetLow(unsigned v){low=v;} inline void SetHigh(unsigned v){high=v;} };
struct Canvas {char pad[28];Nibbles flags;char tail[3];};
struct CanvasBase {char pad[28];unsigned char flags;};
struct Frame {char* out;unsigned length;Canvas canvas;unsigned sizes[3];void* blocks[3];};
extern "C" {
void _ZN13SafeAllocator5ResetEv(void*);
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
void MapVRAMBanksToMainBG(int);void MapVRAMBanksToSubBG(int);void MapVRAMBanksToSubObj(int);
unsigned DisableSubObjVRAMBanks();unsigned DisableSubBGVRAMBanks();
void Graphics_WriteSubDisplayModeLowBits(unsigned);
void ConfigureBackgroundLayerOneControlBits(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetDisplayControlBits(int,int,int,int,int);
void Graphics_InitializeCanvasTransferState(char*);
void Graphics_SetTextBackgroundScreenSize(int,unsigned);
void Graphics_SetBackgroundColorMode(Owner*,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,SafeAllocator*);
int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void _ZN16BackgroundLoader13AddLockGlobalEv();void _ZN16BackgroundLoader16RemoveLockGlobalEv();
void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
int ResourceFile_CountActiveStrideRecords(Record*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
void Graphics_ParseTaggedLayerResource(char*,const void*);
void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void Graphics_ResetLoadedLayerResources(unsigned char*);
void ColorEffect_ConfigureAlphaBlend(intptr_t,unsigned,unsigned,unsigned,unsigned);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Graphics_InitializeCanvasAndLoadSelectedArchive_PathDataMenuBgSqenPac[],Graphics_InitializeCanvasAndLoadSelectedArchive_PathDataMenuBgLv5Pac[],Main_UnknownRoleZeroInitializedStorage_Variant6[];
}
// Original: arm9/ov020 @ 0x0218D32C; symbol: func_ov020_0218d32c; size: 0x318.
// Initializes the main canvas and sub display, then loads one of two resource archives.
extern "C" void Graphics_InitializeCanvasAndLoadSelectedArchive(char* p,int selection){
 _ZN13SafeAllocator5ResetEv(p+0x470);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 MapVRAMBanksToMainBG(8);
 ConfigureBackgroundLayerOneControlBits(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(p+0x49c);
 Graphics_SetTextBackgroundScreenSize((int)(p+0x49c),0);
 CanvasBase* canvas=(CanvasBase*)(p+0x49c);
 canvas->flags &= ~0xf;
 canvas->flags = (canvas->flags & ~0xf0)|0x10;
 Graphics_SetBackgroundColorMode((Owner*)(p+0x49c),1);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x49c,(SafeAllocator*)(p+0x470));
 Graphics_AllocateScreenDescriptors((unsigned char*)p+0x49c,1,(SafeAllocator*)(p+0x470));
 Graphics_InvokeTwoIndexTransferCallback((State*)(p+0x49c),0,0);
 DisableSubObjVRAMBanks();DisableSubBGVRAMBanks();Graphics_WriteSubDisplayModeLowBits(0);
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 MapVRAMBanksToSubObj(0x100);
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&0xffcfffef)|0x10;
 MapVRAMBanksToSubBG(0x80);
 Graphics_SetDisplayControlBits(0,0,14,0,0);Graphics_SetDisplayControlBits(0,0,15,0,0);
 *(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|1;
 *(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|2;
 *(volatile unsigned short*)0x0400100c=(*(volatile unsigned short*)0x0400100c&~3);
 *(volatile unsigned short*)0x0400100e=(*(volatile unsigned short*)0x0400100e&~3)|3;
 _ZN16BackgroundLoader13AddLockGlobalEv();
 Frame f;
 if(selection==1)_Z18LoadFileIntoMemoryPKcPvPj(Graphics_InitializeCanvasAndLoadSelectedArchive_PathDataMenuBgSqenPac,Main_UnknownRoleZeroInitializedStorage_Variant6,&f.length);
 else _Z18LoadFileIntoMemoryPKcPvPj(Graphics_InitializeCanvasAndLoadSelectedArchive_PathDataMenuBgLv5Pac,Main_UnknownRoleZeroInitializedStorage_Variant6,&f.length);
 int count=ResourceFile_CountActiveStrideRecords((Record*)Main_UnknownRoleZeroInitializedStorage_Variant6);
 for(int i=0;i<count;i++)f.blocks[i]=ResourceFile_GetPayloadByIndex(Main_UnknownRoleZeroInitializedStorage_Variant6,i,&f.out,&f.sizes[i]);
 Graphics_InitializeCanvasTransferState((char*)&f.canvas);
 f.canvas.flags.low=1;f.canvas.flags.high=0;
 Graphics_SetBackgroundColorMode((Owner*)&f.canvas,3);
 Graphics_SetTextBackgroundScreenSize((int)&f.canvas,0);
 Graphics_InvokeTwoIndexTransferCallback((State*)&f.canvas,0,0);
 for(int i=0;i<3;i++){Graphics_ParseTaggedLayerResource((char*)&f.canvas,f.blocks[i]);Graphics_DispatchResourceByFourByteMagic((unsigned char*)&f.canvas,f.blocks[i]);}
 Graphics_CleanAndTransferScreenBuffer((char*)&f.canvas,0);Graphics_ResetLoadedLayerResources((unsigned char*)&f.canvas);
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 *(volatile unsigned short*)0x04000050=0;*(volatile unsigned short*)0x04001050=0;
 ColorEffect_ConfigureAlphaBlend(0x04000050,1,2,15,31);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1300;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
}
