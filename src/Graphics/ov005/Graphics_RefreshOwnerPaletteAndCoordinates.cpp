#include <globaldefs.h>
ARM
struct Linked {char pad[0x39];unsigned char tag;};
struct RecordOwner {char pad[12];Linked* linked;};
struct GameState;struct State;struct Obj;struct Context;
extern "C" void ResetOwnerSetLinkedValueAndRefresh(unsigned char*,int);
extern "C" void Object_SetBoundedHalfwordAtOffset22(unsigned char*,int,unsigned short);
extern "C" void Graphics_UploadSelectedHalfwordToMainOrSubObjectPalette(State*,int,int);
extern "C" void ReadIndirectIndexedTextCoordinates(char*,short*,short*,int);
extern "C" void DispatchLookupCoordinatesThroughOwnerID(Context*,unsigned,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" void ApplyEntryFlagsAndFinalizeUpdate(Obj*,int);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" char data_02108760[];
inline unsigned char SetTag(unsigned char v,Linked* p) {return p->tag=v;}
// Original: arm9/ov005 @ 0x02159B74; symbol: func_ov005_02159b74; size: 0xB0.
extern "C" void Graphics_RefreshOwnerPaletteAndCoordinates(char* self) {
ResetOwnerSetLinkedValueAndRefresh(*(unsigned char**)(self+0xe64),-1);
SetTag(0x4c,(*(RecordOwner**)(self+0xe64))->linked);
char* state=*(char**)(*(char**)(self+0xe64)+16);
Object_SetBoundedHalfwordAtOffset22((unsigned char*)state,0,0x18c6);
Graphics_UploadSelectedHalfwordToMainOrSubObjectPalette((State*)state,1,0);
short x,y;
ReadIndirectIndexedTextCoordinates(state,&x,&y,0);
DispatchLookupCoordinatesThroughOwnerID(*(Context**)(self+0xe64),x,(short)(y+4));
unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
if(!ticks) ticks=1;
ApplyEntryFlagsAndFinalizeUpdate(*(Obj**)(self+0xe64),ticks);
DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,5,0);
}
