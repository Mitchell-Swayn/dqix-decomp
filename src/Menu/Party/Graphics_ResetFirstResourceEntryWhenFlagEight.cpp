#include <globaldefs.h>
ARM
struct List; struct Entry; struct Lookup;
extern "C" void SpriteAnimation_AdvanceAllTracks(char* p,unsigned value);
extern "C" void SpriteAnimation_StartTrack(void*, int);
extern "C" Entry* SpriteAnimation_FindTrackByKey(List* list, unsigned int key);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void* owner, int index, unsigned char value);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char* p);
extern "C" void Window_SetLookupEntryPosition(Lookup* lookup,unsigned id,unsigned x,unsigned y);
// Original: arm9/ov002 @ 0x0215B0A8; symbol: func_ov002_0215b0a8; size: 0x90.
extern "C" void Graphics_ResetFirstResourceEntryWhenFlagEight(char *self) {
    if (!(*(unsigned *)(self + 0x247c) & 8)) return;
    char *entries = *(char **)(*(char **)(self + 0x1a68) + 0x3c);
    SpriteAnimation_StartTrack(entries, 0);
    char *entry = (char *)SpriteAnimation_FindTrackByKey((List *)entries, 0);
    if (entry) *(unsigned char *)(entry + 0x15) |= 8;
    SpriteAnimation_AdvanceAllTracks(entries, *(unsigned *)(self + 0x1ba0));
    Window_SetLookupEntryPosition((Lookup *)entries, 0, 215, 150);
    SpriteAnimation_SetTrackOamStartIndex(entries, 0, 0);
    SpriteAnimation_SubmitAllTrackFrames(*(unsigned char **)(self + 0x1a68));
}
