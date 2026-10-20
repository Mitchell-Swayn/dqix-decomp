#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x2171048; symbol: data_ov004_02171048.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" { void* memcpy(void*,const void*,unsigned); unsigned char* _ZN9GameState11GetInstanceEv(); unsigned TextContext_GetSharedInstance(); void Menu_QueueScriptEntry(void*,unsigned); extern unsigned char* GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[]; }
struct Nested { unsigned unknown; char data[64]; };
// Original: arm9/ov004 @ 0x0216F788; symbol: func_ov004_0216f788; size: 0x9C.
extern "C" int System_SelectStateFromTwoStatusBytes(void* self) {
 unsigned char saved[64];
 unsigned char* state=_ZN9GameState11GetInstanceEv();
 Nested* nested=(Nested*)(state+0x6380);
 memcpy(saved,nested->data,64);
 if(!GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x32]) {
  Menu_QueueScriptEntry(self,101);
  GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x31]=1;
 } else if(!GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x33]) {
  Menu_QueueScriptEntry(self,102);
  *(int*)(TextContext_GetSharedInstance()+0x2c8)=1;
 } else Menu_QueueScriptEntry(self,200);
 return 0;
}
