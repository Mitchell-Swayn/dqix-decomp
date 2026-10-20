#include <globaldefs.h>
ARM
extern "C" {
void* GameResources_GetInstance();
void* _ZN16BackgroundLoader11GetInstanceEv();
int DispatchModeIndexedMemberFunctionIfPresent(void*);
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int ResourceFile_CountActiveStrideRecords(void*);
bool SubBackground_IsLoadComplete(unsigned char*);
void* GetSubBG0ScreenBase();
void* memset(void*,int,unsigned);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
void LoadToSubBGStandardPalette(const void*,unsigned,unsigned);
extern char TagMode_LoadAndScrollArrivalNotice_PathDataAniComNamePac[];
}
// Original: arm9/ov003 @ 0x021735C4; symbol: func_ov003_021735c4; size: 0x1C4.
extern "C" void Graphics_UpdateSubBackgroundPaletteLoad(unsigned char* p){
void* resources=GameResources_GetInstance();
void* loader=_ZN16BackgroundLoader11GetInstanceEv();
DispatchModeIndexedMemberFunctionIfPresent(p+0xd8);
if(p[0xef]==0){
*(int*)(p+0xf4)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,TagMode_LoadAndScrollArrivalNotice_PathDataAniComNamePac,0);
p[0xef]=1;
}else if(p[0xef]==1){
if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0xf4)))return;
char* out;char* file;unsigned size;char* blocks[3];unsigned sizes[3];
_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0xf4),(void**)&file,&size);
int count=ResourceFile_CountActiveStrideRecords(file);
for(int i=0;i<count;i++)blocks[i]=ResourceFile_GetPayloadByIndex(file,i,&out,&sizes[i]);
memset(GetSubBG0ScreenBase(),0,0x800);
char* palette=blocks[2];
_Z25CleanInvalidateCacheRangePKvj(palette+0x4c,0x40);
LoadToSubBGStandardPalette(palette+0x4c,0x40,0x40);
*(short*)(p+0xc6)=-192;
*(volatile unsigned*)0x04001010=(*(short*)(p+0xc6)<<16)&0x01ff0000;
_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0xf4));
*(int*)(p+0xf4)=-1;
if(!SubBackground_IsLoadComplete(p+0xd8))p[0xef]=2;
else{_Z16SetSubBrightnessP13GameResourcesii(resources,0,24);p[0xef]=3;}
}else if(p[0xef]==2){
if(SubBackground_IsLoadComplete(p+0xd8)){_Z16SetSubBrightnessP13GameResourcesii(resources,0,24);p[0xef]=3;}
}else if(p[0xef]==3){
if(!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)){p[0xed]=2;p[0xef]=0;}
}
}
