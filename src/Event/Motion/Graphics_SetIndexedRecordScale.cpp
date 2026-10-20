#include <globaldefs.h>
ARM
struct Record {unsigned kind,a,b;char* object;};
extern "C" void _ZN8Object3D8SetScaleEiii(void*,int,int,int);
// Original: arm9/ov001 @ 0x02164754; symbol: func_ov001_02164754; size: 0xB4.
extern "C" int Graphics_SetIndexedRecordScale(Record* records,int index,int x,int y,int z) {
if(index<0 || index>=32) return 0;
Record* record=&records[index];
switch(record->kind) {
case 0:case 1:case 4:case 5:
if(!record->object) return 0;
_ZN8Object3D8SetScaleEiii(record->object,x,y,z);
return 1;
case 6:
if(!record->object) return 0;
void* nested=*(void**)(record->object+0x18);
if(!nested) return 0;
_ZN8Object3D8SetScaleEiii(nested,x,y,z);
return 1;
}
return 0;
}
