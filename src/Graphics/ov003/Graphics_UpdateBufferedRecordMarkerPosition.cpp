#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" int AreBothWordFieldsD4And9CNonzero(char*);
extern "C" void ApplyValueToAllHalfwordCountedEntries(char*,unsigned);
extern "C" void Object_ResetSelectedEntryCoordinatesAndFlags(char*,int);
extern "C" char* FindRecordPointerByKey(char*,unsigned);
extern "C" void Object_WriteSelectedEntryByte14(void*,int,unsigned char);
extern "C" void Object_UpdateAllCountedResourceEntries(unsigned char*);
extern "C" unsigned Object_GetSelectedRecordWhenBuffersEnabled(char*);
// Original: arm9/ov003 @ 0x0215E2A8; symbol: func_ov003_0215e2a8; size: 0x154.
extern "C" void Graphics_UpdateBufferedRecordMarkerPosition(char* self) {
 if(!*(unsigned char*)(self+0x3c2)) return;
 char* record=(char*)Object_GetSelectedRecordWhenBuffersEnabled(self+0x98);
 if(!record)return;
 if(*(unsigned char*)(record+0xc4)!=1)return;
 if(!AreBothWordFieldsD4And9CNonzero(record))return;
 if(*(unsigned char*)(record+0xc5)&0x20)return;
 short x=(short)(*(short*)(record+0xbc)+(short)(*(short*)(record+0xac)*8));
 short y=(short)(*(short*)(record+0xbe)+(short)(*(short*)(record+0xae)*8));
 x-=8;y-=2;
 if(*(unsigned char*)(self+0x3f2)) {
  char* data=(char*)ReadWordFieldAtOffset1C();
  x-=2;y+=(short)(*(short*)(data+0x916)%8);
 }
 void* state=_ZN9GameState11GetInstanceEv();
 char* marker=*(char**)(self+0x394);
 if(!marker)return;
 Object_ResetSelectedEntryCoordinatesAndFlags(marker,0);
 char* entry=FindRecordPointerByKey(marker,0);
 if(entry) *(unsigned char*)(entry+0x15)|=8;
 ApplyValueToAllHalfwordCountedEntries(marker,_ZNK9GameState12GetTickCountEv(state));
 entry=FindRecordPointerByKey(marker,0);
 if(entry){*(short*)(entry+4)=x;*(short*)(entry+6)=y;}
 Object_WriteSelectedEntryByte14(marker,0,0x3f);
 Object_UpdateAllCountedResourceEntries((unsigned char*)self+0x358);
}
