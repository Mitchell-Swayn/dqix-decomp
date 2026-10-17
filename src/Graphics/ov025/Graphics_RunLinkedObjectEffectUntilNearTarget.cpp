#include <globaldefs.h>
ARM
#include <System/Matrix.h>
struct EffectValues { char prefix[0x20]; Vector3fix velocity,position,rotation,scale; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* Object_GetGlobalSixteenEntryDisplayState();
unsigned char* GetPrimaryLinkedRecordByIndex(void*,int);
unsigned char* GetSecondaryLinkedRecordByIndex(void*,int);
unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
void func_ov025_021e3158(void*);
void Object_InitializeRenderValuesAndUnitScales(void*);
void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
Vector3fix _ZNK8Object3D8GetScaleEv(void*);
int _ZNK8Object3D9GetHeightEv(void*);
char* strcpy(char*,const char*);
int InvokeHandlerForKeyedLinkedNode(void*,int,void*);
void GameState_ResetObjectSlotWithinRange208Through223(void*,int);
extern unsigned char data_ov025_021ef9a8[];
extern unsigned data_ov025_021ef988[];
}
// Original: arm9/ov025 @ 0x021E4624; symbol: func_ov025_021e4624; size: 0x244.
extern "C" int Graphics_RunLinkedObjectEffectUntilNearTarget(unsigned char* args,void* links) {
 void* state=_ZN9GameState11GetInstanceEv();
 void* display=Object_GetGlobalSixteenEntryDisplayState();
 unsigned char* primary=GetPrimaryLinkedRecordByIndex(links,0);
 unsigned char* secondary=GetSecondaryLinkedRecordByIndex(links,0);
 unsigned first=*(unsigned short*)(primary+0x20);
 int second=*(short*)(secondary+0xe);
 unsigned char* source=_ZN9GameState20GetGameObjectByIndexEi(state,first);
 unsigned char* target=_ZN9GameState20GetGameObjectByIndexEi(state,second);
 if(!source || !target) { func_ov025_021e3158(data_ov025_021ef9a8); return 1; }
 if(data_ov025_021ef988[8]==0) {
  EffectValues effect;
  Object_InitializeRenderValuesAndUnitScales(&effect);
  Vector3fix origin=*(Vector3fix*)(source+0x44);
  Vector3fix destination=*(Vector3fix*)(target+0x44);
  Vector3fix direction;
  Vector3fix_Subtract(&destination,&origin,&direction);
  direction.y=0;
  Vector3fix_Normalize(&direction,&direction);
  _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&direction,*(short*)(args+0xe),&effect.velocity);
  effect.position=*(Vector3fix*)(source+0x44);
  effect.rotation=*(Vector3fix*)(source+0x50);
  effect.scale=_ZNK8Object3D8GetScaleEv(source);
  effect.position.y+=_ZNK8Object3D9GetHeightEv(source)/2;
  if(*(const char**)(args+8)) strcpy(effect.prefix,*(const char**)(args+8));
  data_ov025_021ef988[9]=InvokeHandlerForKeyedLinkedNode(display,*(unsigned short*)(args+0xc),&effect);
  ++data_ov025_021ef988[8];
  return 0;
 } else if(data_ov025_021ef988[8]==1) {
  unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(state,data_ov025_021ef988[9]);
  if(!object) { func_ov025_021e3158(data_ov025_021ef9a8); return 1; }
  Vector3fix destination=*(Vector3fix*)(target+0x44);
  Vector3fix current=*(Vector3fix*)(object+0x44);
  int distance=Vector3fix_Distance(&destination,&current);
  int sourceHeight=_ZNK8Object3D9GetHeightEv(source);
  int targetHeight=_ZNK8Object3D9GetHeightEv(target);
  int threshold=(sourceHeight+targetHeight)/2;
  int radius=*(short*)(args+0xe)*2;
  if(threshold<radius) threshold=radius;
  if(distance>=threshold) return 0;
  GameState_ResetObjectSlotWithinRange208Through223(display,data_ov025_021ef988[9]);
  func_ov025_021e3158(data_ov025_021ef9a8);
  return 1;
 }
 func_ov025_021e3158(data_ov025_021ef9a8);
 return 1;
}
