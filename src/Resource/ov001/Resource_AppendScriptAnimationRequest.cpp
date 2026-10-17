#include <globaldefs.h>
ARM
struct Request {unsigned char kind:4,group:4;unsigned char parameter;short id;unsigned char field4,pad[3];char path[36];int index;unsigned char option,other;unsigned short padding;Request* next;};
struct Context {char pad[0xd0];Request* head;char more[0x24];unsigned low:27,counter:5;char rest[0x1a];signed char active;};
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* GameResources_GetInstance();
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void* memset(void*,int,unsigned);int ReadScriptParameterAsInteger(void*);char* OV017_ReadWordField04(void*);
int GameState_ReadFirstObjectIndex(void*);void* GameState_GetObjectWithFlag100(void*,int);void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
char* GameState_FindIndexedObjectWithFlag1000(void*,int);int TestIndirectField150FlagsNonzero(char*);unsigned func_ov001_021612ac(void*);
char* strstr(const char*,const char*);char* strrchr(const char*,int);char* strcpy(char*,const char*);int sprintf(char*,const char*,...);
extern unsigned data_ov001_021658b8[];extern char data_ov001_02165728[],data_ov001_02165745[],data_ov001_02165775[],data_ov001_021657b2[];
}
// Original: arm9/ov001 @ 0x02160DA8; symbol: func_ov001_02160da8; size: 0x504.
extern "C" int Resource_AppendScriptAnimationRequest(char* parameters,int count){
 void* state=_ZN9GameState11GetInstanceEv();
 Request* request;
 Context* context=*(Context**)((char*)GameResources_GetInstance()+0x3734);
 unsigned allocator=data_ov001_021658b8[0];
 unsigned id=context->counter+0xa0;if(id>0xbf)return 0;
 request=(Request*)_ZN13SafeAllocator8AllocateEj(allocator,0x38);
 request->kind=0;request->group=0;request->parameter=0;request->id=0;request->field4=0;
 memset(request->path,0,36);request->index=-1;request->next=0;request->option=0;request->other=0;
 request->kind=(unsigned char)ReadScriptParameterAsInteger(parameters);
 switch(request->kind){
 case 0:case 1:case 9:
 if(count<2)return 0;
 request->parameter=ReadScriptParameterAsInteger(parameters+8);
 if(request->kind==1)request->id=GameState_ReadFirstObjectIndex(state);
 else if(request->kind==9){request->id=context->active;if(!GameState_GetObjectWithFlag100(state,request->id))request->id=GameState_ReadFirstObjectIndex(state);}
 if(request->id==0)request->group=1;else request->group=2;
 break;
 case 11:case 12:case 13:
 if(count<2)return 0;
 request->parameter=ReadScriptParameterAsInteger(parameters+8);request->group=2;GameState_ReadFirstObjectIndex(state);
 if(request->kind==11)request->id=3;else if(request->kind==12)request->id=2;else if(request->kind==13)request->id=1;
 if(!_ZN9GameState20GetGameObjectByIndexEi(state,request->id)){request->kind=15;return 0;}
 break;
 case 10:{
 if(count<2)return 0;
 request->parameter=ReadScriptParameterAsInteger(parameters+8);
 unsigned value=0;char* object=GameState_FindIndexedObjectWithFlag1000(state,0xce);
 if(object){request->id=0xce;value=func_ov001_021612ac(object);}
 else{
 int i;
 for(i=0;i<4;i++){object=GameState_FindIndexedObjectWithFlag1000(state,i);if(object&&TestIndirectField150FlagsNonzero(object)){request->id=i;value=func_ov001_021612ac(object);break;}}
 if(i==4)return 0;
 }
 request->group=(unsigned char)(value+2);break;
 }
 case 2:case 6:case 7:{
 if(count<3)return 0;
 char* path=OV017_ReadWordField04(parameters+8);
 if(request->kind==6){
 if(!strstr(path,data_ov001_02165728))return 0;
 char* end=strrchr(path,'/');if(end)path=end+1;strcpy(request->path,path);
 }else sprintf(request->path,data_ov001_02165745,path);
 request->parameter=ReadScriptParameterAsInteger(parameters+16);
 request->id=context->counter+0xa0;context->counter++;
 if(count>3)request->option=ReadScriptParameterAsInteger(parameters+24);
 break;
 }
 case 8:
 if(count<2)return 0;
 sprintf(request->path,data_ov001_02165775);
 request->parameter=ReadScriptParameterAsInteger(parameters+8);
 request->id=context->counter+0xa0;context->counter++;
 if(count>2)request->option=ReadScriptParameterAsInteger(parameters+16);
 break;
 case 3:{
 if(count<3)return 0;
 char* path=OV017_ReadWordField04(parameters+8);sprintf(request->path,data_ov001_021657b2,path);
 request->parameter=ReadScriptParameterAsInteger(parameters+16);
 if(count>3)request->option=ReadScriptParameterAsInteger(parameters+24);
 break;
 }
 case 4:case 5:
 if(count<3)return 0;
 *(int*)request->path=ReadScriptParameterAsInteger(parameters+8);
 request->parameter=ReadScriptParameterAsInteger(parameters+16);
 if(request->kind==4){request->id=context->counter+0xa0;context->counter++;}
 break;
 default:return 0;
 }
 Request* tail=context->head;
 if(!tail)context->head=request;
 else{while(tail->next)tail=tail->next;tail->next=request;}
 return 1;
}
