#include <globaldefs.h>
struct Arguments { unsigned char count; unsigned char padding; unsigned short values[8]; short first,second; };
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void Memory_CopyIntoIndexedRecord(void*,unsigned,Arguments*);
// Original: arm9/ov011 @ 0x021882D4; symbol: func_ov011_021882d4; size: 0xB0.
extern "C" unsigned Menu_SetIndexedDescriptorArgumentPacket(void* self,int count) {
 Arguments args;
 VectorizedMemset(&args,0,sizeof(args));
 args.first=-1;
 args.second=-1;
 int i;
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 args.first=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 void* previous=(char*)self+16;
 self=(char*)self+24;
 args.second=Menu_ReadScriptArgumentAsInteger(previous);
 args.count=count-3;
 for(i=0;i<args.count;i++) {
  unsigned value=Menu_ReadScriptArgumentAsInteger(self);
  self=(char*)self+8;
  if(i<8) args.values[i]=value;
 }
 Memory_CopyIntoIndexedRecord(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id,&args);
 return 1;
}
