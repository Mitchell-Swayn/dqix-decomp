#include <Resource/Script.h>
struct Date {int year,month,day,weekday;};
struct PackedDate {unsigned int year:12; unsigned int month:4; unsigned int day:5; unsigned int rest:10; unsigned int valid:1;};
struct Request { PackedDate date; unsigned int identity; signed char enabled; };
struct Context {unsigned char flags; unsigned char padding[3];void* buffer;Request* request;};
extern "C" unsigned char data_021098e8[];
extern "C" Script::OpcodeLookupEntry data_020f1504[];
extern "C" void* Object_GetGlobalConnectionState();extern "C" bool TestInactiveOrPrimaryIndexState(void*);
extern "C" int Calendar_ReadCurrentDateThroughSynchronousReply(Date*);
extern "C" char* ReadWordFieldAtOffset1C();extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(char*);
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(char*,int,unsigned int);extern "C" void CopyBoundedNameToIndexedSlot(char*,int,unsigned int);
extern "C" int Calendar_ComputeAgeFromBirthDate(int,int,int);
// Original: arm9/main @ 0x02099304; symbol: func_02099304; size: 0x238.
extern "C" int BuildRequestBufferAndExecuteScript(Request* request,int kind,const void* code,unsigned int codeLength,void* buffer,unsigned int bufferLength,unsigned char options,unsigned int parameter1,unsigned int parameter2) {
 Date now; Script script;
 void* state=Object_GetGlobalConnectionState();
 if(!request || !kind) return 0;
 if((int)bufferLength<400)return 0;
 memset(buffer,0,bufferLength);
 *(Request**)(data_021098e8+8)=request;*(void**)(data_021098e8+4)=buffer;data_021098e8[0]=0;
 if(!options)data_021098e8[0]|=16;
 else {
  if((options&2) && TestInactiveOrPrimaryIndexState(state)) {
   Calendar_ReadCurrentDateThroughSynchronousReply(&now);
   if(now.month==request->date.month && now.day==request->date.day)data_021098e8[0]|=1;
   if(now.month==1 && now.day==1)data_021098e8[0]|=2;
   else if(now.month==12 && now.day==25)data_021098e8[0]|=8;
   else if(now.month==2 && now.day==14)data_021098e8[0]|=4;
  }
  if((options&1) && request->enabled)data_021098e8[0]|=32;
 }
 char* environment=ReadWordFieldAtOffset1C();ClearOwnerBuffersAndResetSignedByteSentinels(environment);
 unsigned int month=request->date.month,day=request->date.day;
 SetOneOfSixteenWordFieldsAtOffset8B0(environment,1,month);SetOneOfSixteenWordFieldsAtOffset8B0(environment,2,day);
 if(request->date.valid) {
  int age;
  if(((int)(request->identity<<23)>>23)<0)age=0;
  else {age=Calendar_ComputeAgeFromBirthDate(request->date.year,request->date.month,request->date.day);if(age<0)age=0;}
  SetOneOfSixteenWordFieldsAtOffset8B0(environment,0,age);
 }
 CopyBoundedNameToIndexedSlot(environment,0,kind);CopyBoundedNameToIndexedSlot(environment,1,parameter1);CopyBoundedNameToIndexedSlot(environment,2,parameter2);
 script.Initialize();script.SetOpcodeLookup(data_020f1504);script.Load(code,codeLength);script.Execute();return 1;
}
