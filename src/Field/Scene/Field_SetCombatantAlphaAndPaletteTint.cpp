#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void _ZN8Object3D10SetField9eEh(void*, unsigned char);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" void Graphics_ModifyObjectTexturePalette(void*, int, unsigned short);
extern "C" void Graphics_ApplyMemberModelPaletteColor(void*, int, unsigned short);
extern "C" void Graphics_SetPartyRelatedObjectAlpha(void*, int, unsigned short);
extern "C" void Graphics_ApplyMemberModelPaletteColor(void*, int, unsigned short);
extern "C" void Graphics_ModifyObjectTexturePalette(void*, int, unsigned short);
// Original: arm9/ov017 @ 0x02191e5c; Graphics_SetMemberPaletteAndField; 240 bytes
extern "C" void Field_SetCombatantAlphaAndPaletteTint(void* self, int index, unsigned short palette, unsigned char field, unsigned short color) {
 void* state = _ZN9GameState11GetInstanceEv();
 int validIndex;
 if (index < 0) goto invalidFirst;
 if (index <= 3) validIndex = 1;
 else goto invalidFirst;
 goto checkedFirst;
 invalidFirst: validIndex = 0;
 checkedFirst:;
 if (validIndex && !_ZN9GameState21GetPartyMemberByIndexEi(state, index)) return;
 void* combatant = _ZN9GameState19GetCombatantByIndexEi(state, index);
 if (!combatant) return;
 Graphics_SetPartyRelatedObjectAlpha(self, index, palette);
 *(unsigned short*)((char*)combatant + 0x9c) = color;
 _ZN8Object3D10SetField9eEh(combatant, field);
 int validIndexAgain;
 if (index < 0) goto invalidSecond;
 if (index <= 3) validIndexAgain = 1;
 else goto invalidSecond;
 goto checkedSecond;
 invalidSecond: validIndexAgain = 0;
 checkedSecond:;
 if (validIndexAgain) {
  void* obj = GameState_GetObjectWithFlag100(state, index);
  if (!obj) return;
  if (!GameObject_HasLinkedStatusNibble((char*)obj)) {
   Graphics_ApplyMemberModelPaletteColor(self, index, color);
   return;
  }
 }
 Graphics_ModifyObjectTexturePalette(self, index, color);
}
