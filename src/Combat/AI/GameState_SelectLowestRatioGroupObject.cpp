#include <globaldefs.h>
ARM
extern "C" int GameObject_GetCombatTrackingRecord(int);
extern "C" unsigned char* Combat_FindIndexedMonsterObject(void*,int);
extern "C" bool GameObject_IsDead(void*);
extern "C" float Combat_GetCurrentHealthFraction(unsigned char*);
struct Group { unsigned char a; unsigned char b0:4; unsigned char count:2; unsigned char b1:2; unsigned char pad[4]; unsigned char ids[8]; unsigned char n:4; unsigned char n1:4; unsigned char tail[9]; };
// Original: arm9/ov024 @ 0x021F8628; symbol: func_ov024_021f8628; size: 0x134.
extern "C" int GameState_SelectLowestRatioGroupObject(unsigned char** self,int unused,int obj,short* result) {
 unsigned char* out=(unsigned char*)GameObject_GetCombatTrackingRecord(obj);
 if(!out) return 0;
 int id=0;
 float best=1.1f;
 int group=0, found=0;
 Group* groups=(Group*)(*self+0x81b0);
 for(int i=0;i<groups->count;i++) {
 for(int j=0;j<groups[i].n;j++) {
 unsigned char* o=Combat_FindIndexedMonsterObject(*self,(short)(groups[i].ids[j]+0xc0));
 if(o && !GameObject_IsDead(o) && Combat_GetCurrentHealthFraction(o)<best) {
 best=Combat_GetCurrentHealthFraction(o); group=i; id=groups[i].ids[j]+0xc0; found=1;
 }
 }
 }
 if(!found) return 0;
 *(short*)out=1; out[2]=id; out[3]=group; *result=1;
 return 1;
}
