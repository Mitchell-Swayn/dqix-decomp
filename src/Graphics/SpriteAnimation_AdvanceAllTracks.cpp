#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void SpriteAnimation_AdvanceTrackTime(char*,unsigned char,unsigned);
// Original: arm9/main @ 0x0205A330; symbol: func_0205a330; size: 0x40.
extern "C" void SpriteAnimation_AdvanceAllTracks(char* p,unsigned value){
    for(unsigned short i=0;i<*(unsigned short*)(p+4);++i)SpriteAnimation_AdvanceTrackTime(p,(unsigned char)i,value);
}
