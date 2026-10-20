#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_ResetLoadedLayerResources(unsigned char*);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
extern "C" void Graphics_SetTextBackgroundScreenSize(void*,unsigned);
extern "C" void Graphics_ParseTaggedLayerResource(char*,const void*);
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
extern "C" void Graphics_SetBackgroundColorMode(void*,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" unsigned short ReleaseMainBGVRAMBanks();
extern "C" void System_WaitForInterruptOneAfterShortDelay();
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char*,void**);
extern "C" void SetBackgroundControlFields(unsigned,unsigned,unsigned,unsigned);
extern "C" int Script_ReadParameterString(void*);
extern "C" char Script_LoadEventTextTable_PathDataS[];
struct Canvas { unsigned char raw[28]; unsigned char low:4; unsigned char high:4; unsigned char tail[3]; };
// Original: arm9/ov001 @ 0x021624CC; symbol: func_ov001_021624cc; size: 0x1AC.
extern "C" int Script_LoadResourceFileToMainBackground(void* param) {
 char path[80]; char* blocks[3]; unsigned sizes[3]; Canvas canvas;
 void* file; unsigned size; char* output;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 sprintf(path,Script_LoadEventTextTable_PathDataS,Script_ReadParameterString(param));
 file=0;size=0;
 int locked=0;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path,&file,&size);
 if(!file) {
 _ZN16BackgroundLoader13AddLockGlobalEv();
 locked=1;
 if(!Event_LoadFileIntoSharedScratch(path,&file)) {_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}
 }
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++) blocks[i]=ResourceFile_GetPayloadByIndex((char*)file,i,&output,&sizes[i]);
 ReleaseMainBGVRAMBanks();MapVRAMBanksToMainBG(0x10);
 volatile unsigned* display=(volatile unsigned*)0x4000000;
 *display=(*display&~0x1f00)|0x800;
 SetBackgroundControlFields(0,1,1,1);
 Graphics_InitializeCanvasTransferState((char*)&canvas);
 canvas.low=0;canvas.high=3;
 Graphics_SetBackgroundColorMode(&canvas,0);
 Graphics_SetTextBackgroundScreenSize(&canvas,0);
 Graphics_InvokeTwoIndexTransferCallback(&canvas,0,0);
 System_WaitForInterruptOneAfterShortDelay();
 for(int i=0;i<count;i++) {
 char* block=blocks[i];
 Graphics_ParseTaggedLayerResource((char*)&canvas,block);
 Graphics_DispatchResourceByFourByteMagic((unsigned char*)&canvas,block);
 }
 if(locked) _ZN16BackgroundLoader16RemoveLockGlobalEv();
 Graphics_CleanAndTransferScreenBuffer((char*)&canvas,0);
 Graphics_ResetLoadedLayerResources((unsigned char*)&canvas);
 return 1;
}
