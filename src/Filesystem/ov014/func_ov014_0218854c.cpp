#include "Filesystem/BackgroundLoader.h"
struct GameResources; struct GameState { static GameState* GetInstance(); };
void SetBrightness(GameResources*,int,int); int IsBrightnessTransitionActive(GameResources*);
extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Entry { unsigned char pre[0xc]; short value; unsigned char pad[5]; unsigned char flags; unsigned char gap[6]; short index; unsigned char tail[4]; };
struct Owner { unsigned char pre[0x48]; void* current; void* previous; unsigned* descriptor; unsigned* previousDescriptor; unsigned char gap[0x18]; int load; unsigned char gap2[0xa]; unsigned char count, reserved, selected, flags; unsigned char gap3[0x22]; unsigned char list[0x10]; unsigned word; Node* head; Node* node; void* service; unsigned char gap4[0xae]; short index; short extra; unsigned char gap5[4]; unsigned char state, phase, other[2], options; unsigned char gap6[1]; unsigned short extra2; short values[8]; };
void* ReadWordAtOffset8_Main02097418(void*); unsigned short ReadWord4Low12Bits(void*);
void WriteResolvedEntryHalfword0E(void*,int,int);void Object_SetSelectedPartLowTwoBitMode(void*,int,int);void WriteResolvedEntryByte15Flag2(void*,int,int);void Object_SetGroupNibbleAndTextureLowFourBits(void*,int,int);void Object_CreateAndConfigureSelectedDisplayPart(void*,int);void Object_ApplyModeEightToSelectedPart(void*,int);
// Original: arm9/ov014 @ 0x0218854C; symbol: func_ov014_0218854c; size: 0x70.
void func_ov014_0218854c(Owner* p){short index=((p->options&8)!=0)+0x1b;WriteResolvedEntryHalfword0E(p->service,0x1a,index);Object_SetSelectedPartLowTwoBitMode(p->service,0x1a,1);WriteResolvedEntryByte15Flag2(p->service,4,1);Object_SetGroupNibbleAndTextureLowFourBits(p->service,4,1);Object_CreateAndConfigureSelectedDisplayPart(p->service,4);}
}
