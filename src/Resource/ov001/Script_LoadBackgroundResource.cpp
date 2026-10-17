#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
int OV017_ReadWordField04(void*);
int ReadScriptParameterAsInteger(void*);
int sprintf(char*,const char*,...);
void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
void _ZN16BackgroundLoader13AddLockGlobalEv();
void _ZN16BackgroundLoader16RemoveLockGlobalEv();
unsigned LoadFileToGlobalScratchAndReturnLength(const char*,void**);
int ResourceFile_CountActiveStrideRecords(void*);
char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
void SetBackgroundControlFields(unsigned,unsigned,unsigned,unsigned);
unsigned DisableSubBGVRAMBanks();
void Graphics_WriteSubDisplayModeLowBits(unsigned);
void MapVRAMBanksToSubBG(int);
void WriteDisplayCaptureControl(int,int,int,int);
void Graphics_InitializeCanvasTransferState(void*);
void DispatchModeThroughTwoDimensionalFlagTable(void*,unsigned);
void SetWordField18AndClearFormatByte1F(void*,unsigned);
void Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
void System_WaitForInterruptOneAfterShortDelay();
void DispatchResourceParserByFourByteMagic(void*,const void*);
void Graphics_DispatchResourceByFourByteMagic(void*,void*);
void UpdateProvidedOrStoredChildResource(void*,void*);
void ResetRecordAndIndexedEntries(void*);
extern char data_ov001_02165745[];
}
struct Canvas {char pad[28];unsigned char screen:4,kind:4;char tail[3];};
// Original: arm9/ov001 @ 0x021626E4; symbol: func_ov001_021626e4; size: 0x1F0.
extern "C" int Script_LoadBackgroundResource(char* args){
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
int id=OV017_ReadWordField04(args);
args=(char*)ReadScriptParameterAsInteger(args+8);
char filename[80];char* blocks[3];unsigned sizes[3];Canvas canvas;
char* file;unsigned size;char* out;
sprintf(filename,data_ov001_02165745,id);
int locked=0;file=0;size=0;
_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,filename,(void**)&file,&size);
if(!file){
_ZN16BackgroundLoader13AddLockGlobalEv();locked=1;
if(!LoadFileToGlobalScratchAndReturnLength(filename,(void**)&file)){_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}
}
int count=ResourceFile_CountActiveStrideRecords(file);
for(int i=0;i<count;i++)blocks[i]=FindVariableLengthBlockByIndex(file,i,&out,&sizes[i]);
*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x800;
if(!args)SetBackgroundControlFields(0,0,1,1);
else{DisableSubBGVRAMBanks();Graphics_WriteSubDisplayModeLowBits(0);MapVRAMBanksToSubBG(0x80);WriteDisplayCaptureControl(0,0,14,0);}
Graphics_InitializeCanvasTransferState(&canvas);
canvas.screen=(unsigned char)(int)args;canvas.kind=3;
DispatchModeThroughTwoDimensionalFlagTable(&canvas,0);
SetWordField18AndClearFormatByte1F(&canvas,0);
Graphics_InvokeTwoIndexTransferCallback(&canvas,0,0);
System_WaitForInterruptOneAfterShortDelay();
for(int i=0;i<count;i++){
char* block=blocks[i];DispatchResourceParserByFourByteMagic(&canvas,block);Graphics_DispatchResourceByFourByteMagic(&canvas,block);
}
UpdateProvidedOrStoredChildResource(&canvas,0);
ResetRecordAndIndexedEntries(&canvas);
if(locked)_ZN16BackgroundLoader16RemoveLockGlobalEv();
return 1;
}
