#include <Resource/Script.h>
struct Date {int year,month,day,weekday;};
struct PackedDate {unsigned int year:12; unsigned int month:4; unsigned int day:5; unsigned int rest:10; unsigned int valid:1;};
struct Request { PackedDate date; unsigned int identity; signed char enabled; };
struct Context {unsigned char flags; unsigned char padding[3];void* buffer;Request* request;};
// Original data: arm9/main @ 0x21098e8; symbol: data_021098e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20f1504; symbol: data_020f1504.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000f48f090265000000fc8f090266000000049009020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry BuildRequestBufferAndExecuteScript_UnknownRoleProcedureReferenceRecords[];
extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(void*);
extern "C" int RTC_GetDate(Date*);
extern "C" char* TextContext_GetSharedInstance();extern "C" void TextLayout_ResetFormattingWorkspace(char*);
extern "C" void TextContext_SetNumericArgument(char*,int,unsigned int);extern "C" void TextContext_SetStringArgument(char*,int,unsigned int);
extern "C" int Calendar_ComputeAgeFromBirthDate(int,int,int);
// Original: arm9/main @ 0x02099304; symbol: func_02099304; size: 0x238.
extern "C" int BuildRequestBufferAndExecuteScript(Request* request,int kind,const void* code,unsigned int codeLength,void* buffer,unsigned int bufferLength,unsigned char options,unsigned int parameter1,unsigned int parameter2) {
 Date now; Script script;
 void* state=Network_GetConnectionManager();
 if(!request || !kind) return 0;
 if((int)bufferLength<400)return 0;
 memset(buffer,0,bufferLength);
 *(Request**)(BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage+8)=request;*(void**)(BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage+4)=buffer;BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]=0;
 if(!options)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=16;
 else {
  if((options&2) && Network_IsParentOrOffline(state)) {
   RTC_GetDate(&now);
   if(now.month==request->date.month && now.day==request->date.day)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=1;
   if(now.month==1 && now.day==1)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=2;
   else if(now.month==12 && now.day==25)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=8;
   else if(now.month==2 && now.day==14)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=4;
  }
  if((options&1) && request->enabled)BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage[0]|=32;
 }
 char* environment=TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace(environment);
 unsigned int month=request->date.month,day=request->date.day;
 TextContext_SetNumericArgument(environment,1,month);TextContext_SetNumericArgument(environment,2,day);
 if(request->date.valid) {
  int age;
  if(((int)(request->identity<<23)>>23)<0)age=0;
  else {age=Calendar_ComputeAgeFromBirthDate(request->date.year,request->date.month,request->date.day);if(age<0)age=0;}
  TextContext_SetNumericArgument(environment,0,age);
 }
 TextContext_SetStringArgument(environment,0,kind);TextContext_SetStringArgument(environment,1,parameter1);TextContext_SetStringArgument(environment,2,parameter2);
 script.Initialize();script.SetOpcodeLookup(BuildRequestBufferAndExecuteScript_UnknownRoleProcedureReferenceRecords);script.Load(code,codeLength);script.Execute();return 1;
}
