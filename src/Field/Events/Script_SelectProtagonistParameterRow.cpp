#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
struct Header {unsigned short mode;unsigned short id:15,flag:1;};
struct Config {Header* current;unsigned short id,mode,entry,pad;int x,y,z;short value;};
// Original data: arm9/ov017 @ 0x21d83b0; symbol: data_ov017_021d83b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Config ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021AB6B0; symbol: func_ov017_021ab6b0; size: 0x1B0.
extern "C" int Script_SelectProtagonistParameterRow(unsigned char* args,int count) {
 unsigned char* p;
 unsigned short id=_ZNK6Script9Parameter5ToIntEv(args);
 if(ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.current->id!=id) return 0;
 if(id==ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.id && ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.mode) return 0;
 unsigned char* next=args+8; args+=16;
 unsigned short mode=_ZNK6Script9Parameter5ToIntEv(next);
 if(mode && mode!=ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.current->mode) return 0;
 int rows=(count-2)/5;
 if(rows==0) {
  if(ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.current->mode==mode) ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.entry=0;
  return 0;
 }
 p=GameObject_GetLinkedIndexedState(_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv()));
 unsigned short entry;
 float value,x,y,z;
 int i=0;
 p+=0x500;
 for(;i<rows;++i) {
  entry=_ZNK6Script9Parameter5ToIntEv(args);
  value=_ZNK6Script9Parameter7ToFloatEv(args+8);
  x=_ZNK6Script9Parameter7ToFloatEv(args+16);
  y=_ZNK6Script9Parameter7ToFloatEv(args+24);
  next=args+32; args+=40;
  z=_ZNK6Script9Parameter7ToFloatEv(next);
  if(entry==*(unsigned short*)(p+0x66)) break;
 }
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.id=id;
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.mode=mode;
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.entry=entry;
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.value=(int)(4096.0f*value);
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.x=(int)(4096.0f*x);
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.y=(int)(4096.0f*y);
 ScriptSelectProtagonistParameterRow_UnknownRoleZeroInitializedStorage.z=(int)(4096.0f*z);
 return 1;
}
