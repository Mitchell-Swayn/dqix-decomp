#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" int _fflt(int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadUnknownB0(void*);
extern "C" char* ResourceTracks_GetDrawSettings(void*);
extern "C" void EffectEmitter_SortDrawRecordsByDistance(void*,void*,int,int);
extern "C" bool EffectEmitter_TestCompletionIncludingChildren(void*);
extern "C" void UpdateAndDrawMovingEffect(void*);
extern "C" int Vector3fix_Distance(const void*,const void*);
struct Vec { int x,y,z; };
struct Pair { char* effect; unsigned distance; };
// Original: arm9/main @ 0x0205765C; symbol: func_0205765c; size: 0x170.
extern "C" void DrawActiveEffectsInOptionalDistanceOrder(char* self) {
 if(EffectEmitter_TestCompletionIncludingChildren(self) && *(unsigned char*)(self+0x38)) return;
 char* record=ResourceTracks_GetDrawSettings(*(void**)(self+0x30));
 if(!*(unsigned char*)(record+5)) {
 Pair pairs[64];
 memset(pairs,0,sizeof(pairs));
 Vec reference=*(Vec*)(GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv())+4);
 reference.y=0;
 int count=0;
 char* effect=*(char**)(self+0x34);
 while(effect) {
 if(!*(unsigned char*)(effect+0x2c)) {effect=*(char**)(effect+0x148); continue;}
 int alpha=_ffix(*(unsigned*)(effect+0x138));
 if(alpha<=0) {effect=*(char**)(effect+0x148);continue;}
 if(alpha>31) alpha=31;
 alpha+=31;
 if(alpha>47) alpha-=17;
 *(int*)(effect+0x128)=alpha;
 Vec position=*(Vec*)(effect+0x10);
 position.y=0;
 pairs[count].effect=effect;
 pairs[count].distance=_fdiv(_fflt(Vector3fix_Distance(&position,&reference)),0x45800000);
 effect=*(char**)(effect+0x148);
 count++;
 }
 if(count>0) {
 EffectEmitter_SortDrawRecordsByDistance(self,pairs,0,count-1);
 for(int i=0;i<count;i++) UpdateAndDrawMovingEffect(pairs[i].effect);
 }
 } else {
 char* effect=*(char**)(self+0x34);
 while(effect) {
 if(!*(unsigned char*)(effect+0x2c)) {effect=*(char**)(effect+0x148);continue;}
 UpdateAndDrawMovingEffect(effect);
 effect=*(char**)(effect+0x148);
 }
 }
}
