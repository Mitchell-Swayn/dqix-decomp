#include <globaldefs.h>
ARM
struct GameResources;
extern "C" void* Zone3D_GetMainInstance();
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" bool _Z32IsMainBrightnessTransitionActiveP13GameResources(void*);
extern "C" void _ZN13ZoneState08408AddEntryEPKNS_5EntryEbb(void*,const void*,bool,bool);
extern "C" void ResetThreeSentinelWordsAndTrailingValue(char*);
extern "C" GameResources* GameResources_GetInstance();
// Original: arm9/ov003 @ 0x021733D0; symbol: func_ov003_021733d0; size: 0xC0.
extern "C" void World_FadeOutAndRepopulateZoneEntries(unsigned char* p) {
GameResources* resources=GameResources_GetInstance();
if(p[0xee]==0){_Z17SetMainBrightnessP13GameResourcesii(resources,-16,24);p[0xee]=1;return;}
if(p[0xee]!=1)return;
if(_Z32IsMainBrightnessTransitionActiveP13GameResources(resources))return;
unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance();
if(!p[0xcc]){
ResetThreeSentinelWordsAndTrailingValue((char*)zone+0x840);
for(int i=0;i<p[0xd5];++i)_ZN13ZoneState08408AddEntryEPKNS_5EntryEbb(zone+0x840,*(unsigned char**)(p+0xd0)+0x460+(unsigned char)i*0xe8,true,false);
ResetThreeSentinelWordsAndTrailingValue((char*)zone+0x840);
}
p[0xec]=6;p[0xee]=0;
}
