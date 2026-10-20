#include <globaldefs.h>
ARM
struct Request {unsigned char kind:4,group:4;unsigned char parameter;short id;unsigned char field4,pad[3];char path[36];int index;unsigned char option,other;unsigned short padding;Request* next;};
struct Context {char pad[0xd0];Request* head;char more[0x24];unsigned low:27,counter:5;char rest[0x1a];signed char active;};
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameResources_GetInstance();
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void* memset(void*,int,unsigned);int Script_ReadParameterAsInteger(void*);char* Script_ReadParameterString(void*);
int GameState_ReadFirstObjectIndex(void*);void* GameState_GetObjectWithFlag100(void*,int);void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
char* GameState_FindIndexedObjectWithFlag1000(void*,int);int GameObject_HasLinkedStatusNibble(char*);unsigned GameObject_ReadLinkedStatusLowNibble(void*);
char* strstr(const char*,const char*);char* strrchr(const char*,int);char* strcpy(char*,const char*);int sprintf(char*,const char*,...);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];extern char Event_ResolveCharacterArchiveMember_TextMon[],Script_LoadEventTextTable_PathDataS[],Script_LoadHiddenCHRObject_PathDataEffectEv999991500Chr[],Resource_AppendScriptAnimationRequest_PathDataAniS[];
}
// Original: arm9/ov001 @ 0x02160DA8; symbol: func_ov001_02160da8; size: 0x504.
extern "C" int Resource_AppendScriptAnimationRequest(char* parameters,int count){
 void* state=_ZN9GameState11GetInstanceEv();
 Request* request;
 Context* context=*(Context**)((char*)GameResources_GetInstance()+0x3734);
 unsigned allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0];
 unsigned id=context->counter+0xa0;if(id>0xbf)return 0;
 request=(Request*)_ZN13SafeAllocator8AllocateEj(allocator,0x38);
 request->kind=0;request->group=0;request->parameter=0;request->id=0;request->field4=0;
 memset(request->path,0,36);request->index=-1;request->next=0;request->option=0;request->other=0;
 request->kind=(unsigned char)Script_ReadParameterAsInteger(parameters);
 switch(request->kind){
 case 0:case 1:case 9:
 if(count<2)return 0;
 request->parameter=Script_ReadParameterAsInteger(parameters+8);
 if(request->kind==1)request->id=GameState_ReadFirstObjectIndex(state);
 else if(request->kind==9){request->id=context->active;if(!GameState_GetObjectWithFlag100(state,request->id))request->id=GameState_ReadFirstObjectIndex(state);}
 if(request->id==0)request->group=1;else request->group=2;
 break;
 case 11:case 12:case 13:
 if(count<2)return 0;
 request->parameter=Script_ReadParameterAsInteger(parameters+8);request->group=2;GameState_ReadFirstObjectIndex(state);
 if(request->kind==11)request->id=3;else if(request->kind==12)request->id=2;else if(request->kind==13)request->id=1;
 if(!_ZN9GameState20GetGameObjectByIndexEi(state,request->id)){request->kind=15;return 0;}
 break;
 case 10:{
 if(count<2)return 0;
 request->parameter=Script_ReadParameterAsInteger(parameters+8);
 unsigned value=0;char* object=GameState_FindIndexedObjectWithFlag1000(state,0xce);
 if(object){request->id=0xce;value=GameObject_ReadLinkedStatusLowNibble(object);}
 else{
 int i;
 for(i=0;i<4;i++){object=GameState_FindIndexedObjectWithFlag1000(state,i);if(object&&GameObject_HasLinkedStatusNibble(object)){request->id=i;value=GameObject_ReadLinkedStatusLowNibble(object);break;}}
 if(i==4)return 0;
 }
 request->group=(unsigned char)(value+2);break;
 }
 case 2:case 6:case 7:{
 if(count<3)return 0;
 char* path=Script_ReadParameterString(parameters+8);
 if(request->kind==6){
 if(!strstr(path,Event_ResolveCharacterArchiveMember_TextMon))return 0;
 char* end=strrchr(path,'/');if(end)path=end+1;strcpy(request->path,path);
 }else sprintf(request->path,Script_LoadEventTextTable_PathDataS,path);
 request->parameter=Script_ReadParameterAsInteger(parameters+16);
 request->id=context->counter+0xa0;context->counter++;
 if(count>3)request->option=Script_ReadParameterAsInteger(parameters+24);
 break;
 }
 case 8:
 if(count<2)return 0;
 sprintf(request->path,Script_LoadHiddenCHRObject_PathDataEffectEv999991500Chr);
 request->parameter=Script_ReadParameterAsInteger(parameters+8);
 request->id=context->counter+0xa0;context->counter++;
 if(count>2)request->option=Script_ReadParameterAsInteger(parameters+16);
 break;
 case 3:{
 if(count<3)return 0;
 char* path=Script_ReadParameterString(parameters+8);sprintf(request->path,Resource_AppendScriptAnimationRequest_PathDataAniS,path);
 request->parameter=Script_ReadParameterAsInteger(parameters+16);
 if(count>3)request->option=Script_ReadParameterAsInteger(parameters+24);
 break;
 }
 case 4:case 5:
 if(count<3)return 0;
 *(int*)request->path=Script_ReadParameterAsInteger(parameters+8);
 request->parameter=Script_ReadParameterAsInteger(parameters+16);
 if(request->kind==4){request->id=context->counter+0xa0;context->counter++;}
 break;
 default:return 0;
 }
 Request* tail=context->head;
 if(!tail)context->head=request;
 else{while(tail->next)tail=tail->next;tail->next=request;}
 return 1;
}
