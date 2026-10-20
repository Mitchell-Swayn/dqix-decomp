#include <globaldefs.h>
ARM
struct List;struct Entry;struct Lookup;
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned int);
extern "C" void SpriteAnimation_StartTrack(void*,int);
extern "C" Entry* SpriteAnimation_FindTrackByKey(List*,unsigned int);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" void Window_SetLookupEntryPosition(Lookup*,unsigned int,unsigned int,unsigned int);
// Original: arm9/ov003 @ 0x0215C464; symbol: func_ov003_0215c464; size: 0xAC.
extern "C" void Graphics_ConfigureConditionalDisplayEntry(unsigned char* object) {
if(object[0x59f]&2){
void* list=*(void**)(object+0xd4);
if(list){
SpriteAnimation_StartTrack(list,1);
unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)list,1);
if(entry)entry[0x15]|=8;
SpriteAnimation_AdvanceAllTracks((char*)list,*(unsigned int*)(object+0x574));
Window_SetLookupEntryPosition((Lookup*)list,1,215,150);
SpriteAnimation_SetTrackOamStartIndex(list,1,6);
}
SpriteAnimation_SubmitAllTrackFrames(object+0x98);
}else{
void* list=*(void**)(object+0xd4);
if(list){unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)list,1);if(entry)entry[0x15]&=~8;}
}
}
