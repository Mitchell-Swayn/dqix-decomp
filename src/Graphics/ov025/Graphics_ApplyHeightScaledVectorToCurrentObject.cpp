#include <globaldefs.h>
ARM
struct Triple{int x,y,z;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadUnknownB0(void*);
extern "C" char* GetSecondaryLinkedRecordByIndex(void*,int);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int _ZNK8Object3D9GetHeightEv(void*);
extern "C" void Object_SetVectorComponentsThroughPositionSetter(void*,const Triple*);
extern "C" char* ReadOverlayControlSecondWord();
// Original: arm9/ov025 @ 0x021E5C68; symbol: func_ov025_021e5c68; size: 0x1B4.
extern "C" int Graphics_ApplyHeightScaledVectorToCurrentObject(char* self,void* owner){
 void* state=_ZN9GameState11GetInstanceEv();
 char* object=GameState_ReadUnknownB0(state);
 unsigned mode=*(unsigned char*)(self+0x14);
 if(mode==0){if(object)Object_SetVectorComponentsThroughPositionSetter(object,(Triple*)(self+8));}
 else if(mode==2){
  int height=1;
  char* record=GetSecondaryLinkedRecordByIndex(owner,0);
  if(record){void* target=_ZN9GameState19GetCombatantByIndexEi(state,*(short*)(record+14));if(target)height=_ZNK8Object3D9GetHeightEv(target);}
  float scale=1.0f;
  if(height>=0x24cc){scale=1.0f+0.6f*((float)height/4096.0f-2.3f)/1.7f;if(scale>=1.6f)scale=1.6f;}
  *(int*)(self+16)=(int)(4096.0f*((float)*(int*)(self+16)/4096.0f*scale));
  if(object)Object_SetVectorComponentsThroughPositionSetter(object,(Triple*)(self+8));
 }else if(object){
  Triple value=*(Triple*)(object+0x70);
  Triple delta=*(Triple*)(self+8);
  value.x+=delta.x;value.y+=delta.y;value.z+=delta.z;
  Object_SetVectorComponentsThroughPositionSetter(object,&value);
 }
 char* control=ReadOverlayControlSecondWord();if(control)*(unsigned char*)(control+0x6fd5)=1;
 return 1;
}
