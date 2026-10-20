#include <globaldefs.h>
ARM
struct GameState;struct Owner;struct Entry {char pad[8];unsigned kind:4;unsigned rest:28;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" Entry* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(Owner*,int);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" void TextCanvas_HideDisplayPart(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
inline int IsLowerRecordKind(unsigned kind) {return kind<=7;}
// Original: arm9/ov003 @ 0x02176ED4; symbol: func_ov003_02176ed4; size: 0xC0.
extern "C" void Graphics_ConfigureDisplayPartFromPartySum(char* self) {
char* object=*(char**)(self+0x89c);
Owner* list=(Owner*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
TextCanvas_ShowDisplayPart((unsigned char*)object,8);
TextCanvas_SetGroupPalette(object,8,0);
bool show=false;
Entry* entry=ZoneState2754_FindPrimaryRecordByKey(self+0x874,*(short*)(self+0x103a));
if(entry) show=IsLowerRecordKind(entry->kind);
if(show) {
int value=SumIndexedValuesAcrossPresentPartyIds(list,*(short*)(self+0x103a));
TextCanvas_SetEntryNumericValue(object,0x54,value);
} else TextCanvas_HideDisplayPart((unsigned char*)object,8);
TextCanvas_CreateAndConfigureDisplayPart(object,8);
}
