/* Read sequence bytes through a shared aligned 16-byte cache. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundReadCache ARM7_SoundReadCache;
extern unsigned char ARM7_ReadSoundTrackByte(SoundTrack*);
void ARM7_FillSoundReadCache(const unsigned char *cursor)
{
 const unsigned int *aligned=(const unsigned int*)((unsigned int)cursor&~3);
 ARM7_SoundReadCache.start=(const unsigned char*)aligned;
 ARM7_SoundReadCache.end=(const unsigned char*)aligned+16;
 ARM7_SoundReadCache.words[0]=aligned[0];
 ARM7_SoundReadCache.words[1]=aligned[1];
 ARM7_SoundReadCache.words[2]=aligned[2];
 ARM7_SoundReadCache.words[3]=aligned[3];
}
unsigned int ARM7_ReadSoundTrack24(SoundTrack *track)
{
 unsigned int value=ARM7_ReadSoundTrackByte(track);
 value|=ARM7_ReadSoundTrackByte(track)<<8;
 return value|(ARM7_ReadSoundTrackByte(track)<<16);
}
