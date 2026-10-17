#include <globaldefs.h>
ARM
struct EightBytes { unsigned char item[8]; };
struct RecordBits { unsigned type:4; unsigned rest:28; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
void ClearResolvedEntryByteC5Bit20(unsigned char*,int);
void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
void* ReadKeyedValueThroughOwnerFirstPointer(void**,int);
void SetKeyedRecordHalfwordField28(unsigned char*,int,int);
void WriteResolvedEntryByte13HighNibble(char*,int,unsigned);
void SetKeyedRecordFirstWord(char*,int,int);
void SetKeyedRecordFlagMask40(unsigned char*,int);
int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern EightBytes data_ov003_0217faa4;
}
// Original: arm9/ov003 @ 0x02177410; symbol: func_ov003_02177410; size: 0x140.
extern "C" void Graphics_ConfigureEightIndexedDisplayRecords(unsigned char* p) {
void* state=_ZN9GameState11GetInstanceEv();
unsigned char* owner=*(unsigned char**)(p+0x89c);
ClearResolvedEntryByteC5Bit20(owner,14);
Object_SetGroupNibbleAndTextureLowFourBits((char*)owner,14,0);
unsigned char* object=(unsigned char*)GameState_GetObjectWithFlag100(state,*(signed char*)(p+0x1043));
if(!object)return;
EightBytes indices=data_ov003_0217faa4;
int fallback=(int)ReadKeyedValueThroughOwnerFirstPointer((void**)owner,20);
for(short i=0;i<8;i++) {
unsigned index=indices.item[i];
short key=i+0x68;
int value=fallback; unsigned nibble=3;
if(index!=255) {
unsigned char* record=*(unsigned char**)(object+0x150)+0x194+index*32;
if(!record)continue;
if(*(short*)(record+0x18)>0 && ((RecordBits*)(record+8))->type!=11){value=*(int*)(record+4);nibble=15;}
}
SetKeyedRecordHalfwordField28(owner,key,13);
WriteResolvedEntryByte13HighNibble((char*)owner,key,nibble);
SetKeyedRecordFirstWord((char*)owner,key,value);
SetKeyedRecordFlagMask40(owner,key);
}
Object_CreateAndConfigureSelectedDisplayPart((char*)owner,14);
}
