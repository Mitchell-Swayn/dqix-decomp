#include <globaldefs.h>
ARM
struct Object;struct GameResources;
extern "C" char* strcpy(char*,const char*);
extern "C" void __clear(void*,unsigned);
extern "C" void* ReadGlobalAt02100044();
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*,const void*,short);
extern "C" GameResources* GameResources_GetInstance();
struct Fields {short category,index;char text[12];};
struct Record {unsigned char type;unsigned char pad[3];Fields fields;};
// Original: arm9/ov017 @ 0x021D0B30; symbol: func_ov017_021d0b30; size: 0xA4.
extern "C" void Resource_QueueNamedRecordAndUpdateText(int category,int index,const char* text){
 Object* queue;
 Record record;unsigned char mapped[48];
 queue=(Object*)ReadGlobalAt02100044();
 Fields* fields=&record.fields;
 record.type=42;fields->category=category;fields->index=index;
 if(text)strcpy(fields->text,text);
 MoveQueuedRecordAndApplySourceValue(queue,&record,0);
 if(category==0){
 char* dest=(char*)GameResources_GetInstance()+0x435c+index*48;
 if(dest){
 __clear(mapped,48);
 Text_MapInputBytesToVariableLengthOutputSequences((const unsigned char*)text,mapped,1);
 strcpy(dest,(const char*)mapped);
 }
 }
}
