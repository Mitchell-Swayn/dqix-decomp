#include <globaldefs.h>
ARM
struct Entry;
extern "C" Entry* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" void Graphics_SetBackgroundStateAndClearTilemap(char*,int);
// Original: arm9/ov023 @ 0x021DCAE0; symbol: func_ov023_021dcae0; size: 0x90.
extern "C" void Graphics_SelectBackgroundStateRecord(char* self,int value) {
if(!*(unsigned char*)(self+0x776) || !(*(unsigned short*)(self+0x774)&4)) {
*(short*)(self+0x772)=value;
if(*(int*)(self+0x754)<=0 || !*(unsigned char*)(self+0x776)) {
*(short*)(self+0x770)=value;return;
}
}
int current=*(short*)(self+0x770);
if(current==value) {
void* table=*(void**)(self+0x48);
if(!table) return;
Entry* record=FindSerializedPrimaryRecordByKey(table,current);
if(*(Entry**)(self+0x4c)!=record) *(Entry**)(self+0x4c)=record;
} else Graphics_SetBackgroundStateAndClearTilemap(self,value);
}
