#include "Filesystem/BackgroundLoader.h"
struct GameResources; struct GameState { static GameState* GetInstance(); };
void SetBrightness(GameResources*,int,int); int IsBrightnessTransitionActive(GameResources*);
extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Entry { unsigned char pre[0xc]; short value; unsigned char pad[5]; unsigned char flags; unsigned char gap[6]; short index; unsigned char tail[4]; };
struct Owner { unsigned char pre[0x48]; void* current; void* previous; unsigned* descriptor; unsigned* previousDescriptor; unsigned char gap[0x18]; int load; unsigned char gap2[0xa]; unsigned char count, reserved, selected, flags; unsigned char gap3[0x22]; unsigned char list[0x10]; unsigned word; Node* head; Node* node; void* service; unsigned char gap4[0xae]; short index; short extra; unsigned char gap5[4]; unsigned char state, phase, other[2], options; unsigned char gap6[1]; unsigned short extra2; short values[8]; };
void* BestiaryList_GetEntries(void*); unsigned short BestiaryList_GetEntryCount(void*);
void TextCanvas_SetEntryMessageKey(void*,int,int);void TextCanvas_SetEntryTextAlignmentMode(void*,int,int);void TextCanvas_SetGroupInteriorFillSuppressed(void*,int,int);void TextCanvas_SetGroupPalette(void*,int,int);void TextCanvas_CreateAndConfigureDisplayPart(void*,int);void TextCanvas_EnableEntryHorizontalCentering(void*,int);
GameResources* GameState_ReadPResources(GameState*);
// Original: arm9/ov014 @ 0x021882D4; symbol: func_ov014_021882d4; size: 0x5C.
 void BestiaryScreen_AdvanceCloseFade(Owner* p) { GameResources* r=GameState_ReadPResources(GameState::GetInstance());if(p->phase==0) {SetBrightness(r,-16,8);++p->phase;}else if(p->phase==1) {if(!IsBrightnessTransitionActive(r)) {p->state=6;p->phase=0;} } }
}
