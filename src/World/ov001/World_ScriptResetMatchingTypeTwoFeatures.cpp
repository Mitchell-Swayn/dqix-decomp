#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void* ReadGlobalValueAt020FB3F0();
struct Entry {unsigned char pad[0x2c];unsigned char a,b;unsigned short low:4;unsigned short flags:12;unsigned char pad2[0x40];Entry* next;};
extern "C" Entry* _ZN12ZoneFeatures14GetTypeEntriesEi(void*,int);
extern "C" void _ZN6Zone3D25ResetType2FeaturePositionEPN12ZoneFeatures13Opcode6aEntryE(void*,Entry*);
// Original: arm9/ov001 @ 0x02160BC0; symbol: func_ov001_02160bc0; size: 0xB8.
extern "C" int World_ScriptResetMatchingTypeTwoFeatures(unsigned char* p,int count){
 int a=ReadScriptParameterAsInteger((IntegerParameterView*)p);
 int b=ReadScriptParameterAsInteger((IntegerParameterView*)(p+8));
 if(count>2)ReadScriptParameterAsInteger((IntegerParameterView*)(p+16));
 unsigned char* zone=(unsigned char*)ReadGlobalValueAt020FB3F0();
 Entry* entry=_ZN12ZoneFeatures14GetTypeEntriesEi(zone+0x6c,2);
 while(entry){
 if((entry->flags&1) && entry->a==a && entry->b==b){
 unsigned short flags=entry->flags&~0x200;
 entry->flags=flags;
 _ZN6Zone3D25ResetType2FeaturePositionEPN12ZoneFeatures13Opcode6aEntryE(zone,entry);
 }
 entry=entry->next;
 }
 return 1;
}
