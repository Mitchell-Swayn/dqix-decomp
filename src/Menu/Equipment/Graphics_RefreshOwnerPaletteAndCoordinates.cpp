#include <globaldefs.h>
ARM
struct Linked {char pad[0x39];unsigned char tag;};
struct RecordOwner {char pad[12];Linked* linked;};
struct GameState;struct State;struct Obj;struct Context;
extern "C" void Window_CreateOptionLayoutAndResetSelection(unsigned char*,int);
extern "C" void Window_SetPaletteColor(unsigned char*,int,unsigned short);
extern "C" void Graphics_UploadSelectedHalfwordToMainOrSubObjectPalette(State*,int,int);
extern "C" void Window_GetTextRowCoordinates(char*,short*,short*,int);
extern "C" void Window_SetSelectedLookupEntryPosition(Context*,unsigned,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" void Window_UpdateOptionSelectionAndEntry(Obj*,int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
inline unsigned char SetTag(unsigned char v,Linked* p) {return p->tag=v;}
// Original: arm9/ov005 @ 0x02159B74; symbol: func_ov005_02159b74; size: 0xB0.
extern "C" void Graphics_RefreshOwnerPaletteAndCoordinates(char* self) {
Window_CreateOptionLayoutAndResetSelection(*(unsigned char**)(self+0xe64),-1);
SetTag(0x4c,(*(RecordOwner**)(self+0xe64))->linked);
char* state=*(char**)(*(char**)(self+0xe64)+16);
Window_SetPaletteColor((unsigned char*)state,0,0x18c6);
Graphics_UploadSelectedHalfwordToMainOrSubObjectPalette((State*)state,1,0);
short x,y;
Window_GetTextRowCoordinates(state,&x,&y,0);
Window_SetSelectedLookupEntryPosition(*(Context**)(self+0xe64),x,(short)(y+4));
unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
if(!ticks) ticks=1;
Window_UpdateOptionSelectionAndEntry(*(Obj**)(self+0xe64),ticks);
SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
}
