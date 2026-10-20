#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadUnknownCb8(void*);
// Original data: arm9/ov017 @ 0x21d8438; symbol: data_ov017_021d8438.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov017 @ 0x021B9BCC; symbol: func_ov017_021b9bcc; size: 0x134.
extern "C" bool GameState_TrySelectIndexedEntry(int index,int selection)
{
 void* game=_ZN9GameState11GetInstanceEv();
 int group=(index%80)/16;
 int entry=(index%80)%16;
 int current=ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[2];
 if(index/80 != current/80) return false;
 if(group==0) {
 if(entry<=ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[6]) ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[5]=selection;
 else return false;
 } else if(group==1) {
 if(entry<=ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[8]) ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[5]=selection;
 else return false;
 } else if(group==2) {
 if(index==current) ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[5]=selection;
 else return false;
 } else if(group==3) {
 if(index==current) ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[5]=selection;
 else return false;
 } else if(group==4) {
 if(entry<=GameState_ReadUnknownCb8(game) && entry>=ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[3]) {
 ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[5]=selection;ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[3]=entry;
 } else return false;
 }
 return true;
}
