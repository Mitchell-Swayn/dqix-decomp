#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* ZoneState_GetTrackedZoneCache();
struct E {unsigned short key;unsigned short type:2;unsigned short rest:14;};
extern "C" E* ZoneState_FindTrackedZoneByIdentifier(E*,int);
struct Source {unsigned short key;unsigned char pad;unsigned char index:4;unsigned char rest:4;};
struct Output {int index;E* record;char* monster;};
// Original: arm9/ov017 @ 0x021D446C; symbol: func_ov017_021d446c; size: 0xB0.
extern "C" int Field_ResolveSynchronizedMonster(Source* source,Output* out,int mode){
 void* gs=_ZN9GameState11GetInstanceEv();
 unsigned short* zone=(unsigned short*)Zone3D_GetMainInstance();
 E* records=(E*)ZoneState_GetTrackedZoneCache();
 if(source->key!=*zone && mode!=1)return 0;
 out->record=ZoneState_FindTrackedZoneByIdentifier(records,source->key);
 if(!out->record)return 0;
 out->index=out->record->type*12+112+source->index;
 out->monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(gs,out->index);
 if(!out->monster)return 0;
 int state=*(int*)(out->monster+0x130);
 if(state==8)return 0;
 return state!=9;
}
