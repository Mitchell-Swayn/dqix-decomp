#include <globaldefs.h>
ARM
struct Table { int entries[9]; };
struct Flags { unsigned index:4; unsigned rest:28; };
extern "C" { void* _ZN9GameState11GetInstanceEv(); char* GameState_GetObjectWithFlag100(void*,int); int ReadLinkedHalfwordArrayElementOrMinusOne(char*,int); void* FindSerializedPrimaryRecordByKey(void*,int); extern Table data_ov003_0217fb68; }
// Original: arm9/ov003 @ 0x02179CFC; symbol: func_ov003_02179cfc; size: 0xAC.
extern "C" void* Resource_FindLinkedSerializedRecordOrFallback(unsigned char* owner,int id,unsigned char* fallback) {
 char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(!object) return fallback;
 Table table=data_ov003_0217fb68;
 int key=ReadLinkedHalfwordArrayElementOrMinusOne(object,table.entries[((Flags*)(fallback+8))->index]);
 if(key==-1) return fallback;
 void* result=FindSerializedPrimaryRecordByKey(owner+0x874,key);
 if(!result) result=fallback;
 else *(short*)(owner+0x1048)=key;
 return result;
}
