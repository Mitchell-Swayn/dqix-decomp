#include <globaldefs.h>
ARM
struct GameState;struct GameObject;struct Sprite;struct Record;struct State;struct SafeAllocator;struct Owner;struct Output;struct Object;struct Position;struct WorldScriptRecordList;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
extern "C" void Graphics_InitializeSpriteTransformDefaults(State*);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void Script_ExecuteCodeWithGlobalContextValues(void*,void*,const void*,unsigned,void*,unsigned short,unsigned char);
extern "C" void InitializeLinkedListHeadAndCount(WorldScriptRecordList*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" unsigned char Vocation_GetSkillLineId(unsigned,unsigned);
extern "C" void Script_ExecuteWithArgumentsAndOutputRecord(Output*,void*,const void*,unsigned,void*,unsigned);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_SetBackgroundColorMode(Owner*,unsigned);
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
extern "C" void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,SafeAllocator*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void DrawSortedSelectorEntries(char*,Sprite*);
extern "C" int Graphics_LoadTaggedLayerResource(Owner*,const void*,unsigned);
extern "C" char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);
extern "C" void Tilemap_SetWholeMapPalette(Position*,int);
extern "C" void Graphics_UpdateBoundedSixteenByteEntry(Object*,unsigned,unsigned,unsigned,unsigned short);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
extern "C" void Graphics_LoadPartyPalettePreset(int,int);
extern "C" char SkillDetails_AdvanceResourceInitialization_PathDataAniObjSklupIPac[];
extern "C" char SkillDetails_AdvanceResourceInitialization_PathDataBinStrSklcGp2[];
extern "C" char SkillDetails_AdvanceResourceInitialization_MarkupStrSklcLGBin[];
extern "C" char SkillDetails_AdvanceResourceInitialization_PathDataPrmSklnameGp2[];
extern "C" char SkillDetails_AdvanceResourceInitialization_MarkupSklnameLGBin[];
// Original data: arm9/ov013 @ 0x2187db8; symbol: data_ov013_02187db8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000000c0000000f0000002e000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" unsigned char SkillDetailsAdvanceResourceInitialization_UnknownRoleInitializedBytes[];
extern "C" char AdvanceTenEntryResourceLoading_PathDataAniBgSknPac[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Vector {int x,y,z;};
// Original: arm9/ov013 @ 0x021870F0; symbol: func_ov013_021870f0; size: 0x694.
// Allocates thirteen UI records and sequences resource, script and canvas loading over nine phases.
extern "C" bool SkillDetails_AdvanceResourceInitialization(char* self){
 if(B(self,0x65))return true;bool complete=true;int auxiliary;void* loader=_ZN16BackgroundLoader11GetInstanceEv();int phase=B(self,0x66);
 if(phase==0){char* owner=P(self,0);_ZN13SafeAllocator5ResetEv(owner+0x50);
 P(self,0x48)=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+0x50),84);P(self,0x4c)=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+0x50),520);P(self,0x50)=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+0x50),26);P(self,0x54)=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+0x50),26);P(self,0x58)=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+0x50),13);
 Graphics_InitializeSpriteResourceBuffers((unsigned char*)P(self,0x48));B(P(self,0x48),0x50)=B(self,0x64);char* header=P(self,0x48);P(header,0x40)=P(self,0x4c);H(header,0x4c)=13;
 auxiliary=40;for(int i=0;i<13;++i)Graphics_InitializeSpriteTransformDefaults((State*)(P(self,0x4c)+auxiliary*i));
 for(int i=0;i<10;++i){((short*)P(self,0x50))[i]=-1;((short*)P(self,0x54))[i]=-1;P(self,0x58)[i]=2;}
 W(self,0x5c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,SkillDetails_AdvanceResourceInitialization_PathDataAniObjSklupIPac,0);++B(self,0x66);complete=0;
 }else if(phase==1){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x5c))){char* out;void* data;unsigned size;char* owner=P(self,0);_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x5c),&data,&size);int count=ResourceFile_CountActiveStrideRecords((Record*)data);unsigned length;
 for(int i=0;i<count;++i){char* block=ResourceFile_GetPayloadByIndex((char*)data,i,&out,&length);Graphics_DispatchDataByResourceMagic((int)P(self,0x48),block,length,(int)(owner+0x50));}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x5c));W(self,0x5c)=-1;++B(self,0x66);}complete=0;
 }else if(phase==2){_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);W(self,0x5c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,SkillDetails_AdvanceResourceInitialization_PathDataBinStrSklcGp2,SkillDetails_AdvanceResourceInitialization_MarkupStrSklcLGBin,0);++B(self,0x66);complete=0;
 }else if(phase==3){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x5c))){void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x5c),&data,&size);char* owner=P(self,0);_ZN13SafeAllocator5ResetEv(owner+0x3c);Script_ExecuteCodeWithGlobalContextValues(self+4,owner+0x3c,data,size,0,0,0);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x5c));W(self,0x5c)=-1;++B(self,0x66);}complete=0;
 }else if(phase==4){InitializeLinkedListHeadAndCount((WorldScriptRecordList*)(self+12));_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);W(self,0x5c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,SkillDetails_AdvanceResourceInitialization_PathDataPrmSklnameGp2,SkillDetails_AdvanceResourceInitialization_MarkupSklnameLGBin,0);++B(self,0x66);complete=0;
 }else if(phase==5){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x5c))){void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x5c),&data,&size);char* owner=P(self,0);_ZN13SafeAllocator5ResetEv(owner+0x28);void* passed=0;short arguments[5]={0};
 char* object=(char*)GameState_GetObjectWithFlag100((GameState*)_ZN9GameState11GetInstanceEv(),*(signed char*)(self+0x67));if(object){auxiliary=(int)GameObject_GetLinkedIndexedState(object);if(auxiliary){for(unsigned char i=0;i<5;++i)arguments[i]=Vocation_GetSkillLineId(U((void*)auxiliary,0x950)&255,i);passed=arguments;}}
 Script_ExecuteWithArgumentsAndOutputRecord((Output*)(self+12),owner+0x28,data,size,passed,5);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x5c));W(self,0x5c)=-1;++B(self,0x66);}complete=0;
 }else if(phase==6){char* owner=P(self,0);_ZN13SafeAllocator5ResetEv(owner);unsigned char choices[2]={SkillDetailsAdvanceResourceInitialization_UnknownRoleInitializedBytes[0],SkillDetailsAdvanceResourceInitialization_UnknownRoleInitializedBytes[1]};Graphics_InitializeCanvasTransferState(self+0x28);
 B(self,0x44)=(B(self,0x44)&~15)|(B(self,0x64)&15);B(self,0x44)=(B(self,0x44)&~0xf0)|((choices[B(self,0x64)]&15)<<4);
 Graphics_SetBackgroundColorMode((Owner*)(self+0x28),0);Graphics_SetTextBackgroundScreenSize((int)(self+0x28),0);Graphics_InvokeTwoIndexTransferCallback((State*)(self+0x28),0,0);Graphics_AllocateAndClearConfiguredBuffer(self+0x28,(SafeAllocator*)owner);Graphics_AllocateScreenDescriptors((unsigned char*)self+0x28,1,(SafeAllocator*)owner);
 if(B(self,0x64)==0){*(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x1200;*(volatile unsigned short*)0x4000050=0;}else{*(volatile unsigned short*)0x4001008=(*(volatile unsigned short*)0x4001008&0x43)|0xf00;*(volatile unsigned short*)0x4001050=0;}++B(self,0x66);complete=0;
 }else if(phase==7){_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);W(self,0x5c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceTenEntryResourceLoading_PathDataAniBgSknPac,0);++B(self,0x66);complete=0;
 }else if(phase==8){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x5c))){char* out;void* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x5c),&data,&size);char* block;int count=ResourceFile_CountActiveStrideRecords((Record*)data);auxiliary=(int)P(self,0);_ZN13SafeAllocator5ResetEv((char*)auxiliary+20);unsigned length;
 for(int i=0;i<count;++i){block=ResourceFile_GetPayloadByIndex((char*)data,i,&out,&length);if(!block)continue;if(i==0){unsigned canvas[56];TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)canvas);H(canvas,0xb4)=10;H(canvas,0xb6)=11;H(canvas,0xa8)=32;H(canvas,0xaa)=24;P(canvas,8)=block+16;DrawSortedSelectorEntries(self,(Sprite*)canvas);}((int(*)(Owner*,const void*,unsigned,unsigned))Graphics_LoadTaggedLayerResource)((Owner*)(self+0x28),block,(unsigned)((char*)auxiliary+20),length);}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x5c));W(self,0x5c)=-1;char* entry=Graphics_GetLoadedScreenDescriptor(self+0x28,0);if(entry)Tilemap_SetWholeMapPalette((Position*)entry,*(signed char*)(self+0x67));Graphics_UpdateBoundedSixteenByteEntry((Object*)(self+0x28),0,0,0,0xffff);Graphics_CleanAndTransferScreenBuffer(self+0x28,0);B(self,0x65)=1;B(self,0x66)=0;if(B(self,0x64)==0)Graphics_LoadPartyPalettePreset(4,-1);else Graphics_LoadPartyPalettePreset(3,-1);}complete=0;
 }return complete;
}
