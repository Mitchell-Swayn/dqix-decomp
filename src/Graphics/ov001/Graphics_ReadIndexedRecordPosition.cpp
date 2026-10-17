#include <globaldefs.h>
ARM
struct Vector{int x,y,z;};struct Owner;
struct Record {unsigned kind,a,b;char* object;};
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void ReadFirstAvailablePositionOrZero(Vector*,Owner*);
// Original: arm9/ov001 @ 0x021644C8; symbol: func_ov001_021644c8; size: 0xB0.
extern "C" int Graphics_ReadIndexedRecordPosition(Record* records,int index,Vector* output) {
if(index<0 || index>=32) return 0;
Record* record=&records[index];
switch(record->kind) {
case 0:case 1:case 4:case 5:
if(!record->object) return 0;
_ZN8Vector3iaSERKS_(output,record->object+0x50);
return 1;
case 2:case 6: {
if(!record->object) return 0;
Vector position;
ReadFirstAvailablePositionOrZero(&position,(Owner*)record->object);
_ZN8Vector3iaSERKS_(output,&position);
return 1;
}
}
return 0;
}
