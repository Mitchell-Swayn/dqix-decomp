/* Read sequence bytes through a shared aligned 16-byte cache. */
#pragma dont_inline on
#include "SoundSequence.h"
extern SoundReadCache ARM7_SoundReadCache;
extern unsigned char ARM7_SoundReadBuffer[16];
extern void ARM7_FillSoundReadCache(const unsigned char*);
unsigned char ARM7_ReadSoundTrackByte(SoundTrack *track)
{
 const unsigned char *cursor=track->cursor;
 unsigned char value;
 if(cursor<ARM7_SoundReadCache.start || cursor>=ARM7_SoundReadCache.end)ARM7_FillSoundReadCache(cursor);
 value=ARM7_SoundReadBuffer[cursor-ARM7_SoundReadCache.start];
 track->cursor++;
 return value;
}
