#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" int Object_ReadIndexedBitAtOffset8EC(unsigned char*,int);
struct Entry { unsigned short value,pad; };
extern "C" Entry data_020ee710[];
extern "C" Entry data_020ee712[];
// Original: arm9/main @ 0x020DD200; symbol: func_020dd200; size: 0x90.
extern "C" int GameState_TestMappedObjectBit(int index,int key) {
int result=0;
unsigned char* object=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
if(!object)return result;
for(unsigned char i=0;data_020ee710[i].value!=65535;++i){
int mapped=data_020ee712[i].value&255;
if(mapped==key){if(Object_ReadIndexedBitAtOffset8EC(*(unsigned char**)(object+0x150),data_020ee710[i].value))result=1;break;}
}
return result;
}
