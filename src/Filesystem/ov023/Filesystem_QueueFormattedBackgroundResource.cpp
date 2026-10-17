#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int OV023_ReadWordField04(void*);
extern "C" void OV023_WriteWordField04(void*,int);
extern "C" char data_ov023_021feb30[];
struct VariantFlags { unsigned char variant:1, other:7; };
// Original: arm9/ov023 @ 0x021FA370; symbol: func_ov023_021fa370; size: 0x158.
extern "C" int Filesystem_QueueFormattedBackgroundResource(char* p,void* state) {
 void* entry=func_ov011_021849c8(state);
 if(OV023_ReadWordField04(entry)<0) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int variant=0;
 if(*(unsigned char*)(p+0x2c)==1) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* obj=_ZN9GameState21GetPartyMemberByIndexEi(game,GameState_ReadProtagonistObjectIndex(game));
 if(obj) variant=((VariantFlags*)(*(char**)(obj+0x150)+0x49c))->variant;
 } else if(*(unsigned char*)(p+0x2c)==2) {} else if(*(unsigned char*)(p+0x2c)==3) variant=1;
 char name[32];
 if(*(char**)(p+0x28)) sprintf(name,*(char**)(p+0x28),variant);
 else sprintf(name,*(char**)(p+0x10),variant);
 char path[64]={0};
 if(strncmp(path,data_ov023_021feb30,5)) strcpy(path,data_ov023_021feb30);
 strcat(path,name);
 unsigned handle;
 if(*(char**)(p+0x28)) {
 memset(name,0,32);
 sprintf(name,*(char**)(p+0x10),variant);
 handle=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,path,name,0);
 } else handle=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
 OV023_WriteWordField04(entry,handle);
 return 1;
 }
 return *(int*)(p+0x1c);
}
