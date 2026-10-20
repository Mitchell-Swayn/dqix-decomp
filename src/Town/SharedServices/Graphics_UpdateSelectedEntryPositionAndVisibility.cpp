#include <globaldefs.h>
ARM
extern "C" void GuestList_GetSelectionCursorPosition(void*,short*,short*);
extern "C" void SpriteAnimation_StartTrack(void*,unsigned);
extern "C" unsigned char* SpriteAnimation_FindTrackByKey(void*,unsigned);
extern "C" void SpriteAnimation_AdvanceAllTracks(void*,unsigned);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(void*);
// Original: arm9/ov003 @ 0x0217033C; symbol: Graphics_UpdateSelectedEntryPositionAndVisibility; size: 0xb4.
// Sets entry coordinates and visibility bit8 for nonzero pair, otherwise clears bit8.
extern "C" void Graphics_UpdateSelectedEntryPositionAndVisibility(char* self) {
 void* entries=*(void**)(self+0xa4);if(!entries)return;short x,y;GuestList_GetSelectionCursorPosition(self,&x,&y);
 if(x&&y){SpriteAnimation_StartTrack(entries,0);unsigned char* entry=SpriteAnimation_FindTrackByKey(entries,0);if(entry)entry[0x15]|=8;SpriteAnimation_AdvanceAllTracks(entries,2);
 short xx;short yy=y;xx=x;entry=SpriteAnimation_FindTrackByKey(entries,0);if(entry){*(short*)(entry+4)=xx;*(short*)(entry+6)=yy;}SpriteAnimation_SubmitAllTrackFrames(self+0x68);
 }else{unsigned char* entry=SpriteAnimation_FindTrackByKey(entries,0);if(entry)entry[0x15]&=~8;}
}
