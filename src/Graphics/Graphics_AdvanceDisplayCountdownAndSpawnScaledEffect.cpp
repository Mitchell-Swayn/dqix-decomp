#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma always_inline on
struct Vector {int x,y,z;};
struct Effect {
 unsigned char first,pad[15],enabled;
 unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;
 short unused,v1,v2,v3,v4,palette,pad2;
 unsigned values[12];
 inline void Initialize() {
 first=0;enabled=1;unused=0;v1=-1;v2=-1;v3=-1;v4=-1;palette=-0x1000;
 values[0]=0;values[1]=0;values[2]=0;values[3]=0;values[4]=0;values[5]=0;values[6]=0;values[7]=0;values[8]=0;
 values[9]=0x1000;values[10]=0x1000;values[11]=0x1000;
 a=0;b=0;c=1;d=0;e=0;f=0;g=0;h=0;
 }
};
extern "C" void GameObject_AdvanceBattleMotionAlphaAndAnimation(unsigned char*);
extern "C" void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*,unsigned char);
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(void*,int,int);
extern "C" void _ZNK8Object3D23GetShadowSourcePositionEv(Vector*,const void*);
extern "C" int ObjectPool_SpawnFromTemplateKey(void*,int,void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02048690; symbol: func_02048690; size: 0x1C0.
// Updates the countdown, then consumes the effect flag with a scaled shadow-source effect.
extern "C" void Graphics_AdvanceDisplayCountdownAndSpawnScaledEffect(unsigned char* object) {
 GameObject_AdvanceBattleMotionAlphaAndAnimation(object);
 if(object[0x183] && --object[0x183]==0) GameObject_SetMotionStateAndRefreshAnimation(object,5);
 if(((unsigned)object[0xe0]<<28)>>31) {
  void* display=Object_GetGlobalSixteenEntryDisplayState();
  _ZN8Object3D24TransitionInheritedAlphaEii(object,0,500);
  int delta=*(short*)(object+0x18e)-0x1000;
  int scale=(int)(((long long)delta*0x800+0x800)>>12);
  scale+=0x1000;
  scale=(int)(((long long)scale*266+0x800)>>12);
  Effect effect;
  effect.Initialize();
  Vector position;
  _ZNK8Object3D23GetShadowSourcePositionEv(&position,object);
  effect.values[3]=position.x;effect.values[4]=position.y;effect.values[5]=position.z;
  effect.values[9]=scale;effect.values[10]=scale;effect.values[11]=scale;
  ObjectPool_SpawnFromTemplateKey(display,2,&effect);
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,50,0);
  object[0xe0]&=~8;
 }
}
