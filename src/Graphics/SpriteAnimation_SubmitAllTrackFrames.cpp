#include <globaldefs.h>
ARM
extern "C" {void SpriteAnimation_SubmitTrackFrame(void*,unsigned char);
// Original: arm9/main @ 0x0205AE8C; symbol: func_0205ae8c; size: 0x44.
void SpriteAnimation_SubmitAllTrackFrames(unsigned char* p){unsigned char* table=*(unsigned char**)(p+0x3c);if(!table)return;unsigned short count=*(unsigned short*)(table+4);for(unsigned short i=0;i<count;i++)SpriteAnimation_SubmitTrackFrame(p,(unsigned char)i);}}
