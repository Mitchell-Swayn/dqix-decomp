#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma always_inline on
#pragma force_active on
struct SpriteEntry { unsigned attributes,other; };
struct SpriteGroup { unsigned reserved[2]; SpriteEntry* entries; unsigned char count; };
static inline void ReadPosition(const SpriteEntry* entry,int* x,int* y)
{
    unsigned attributes=entry->attributes;
    if(x) *x=(attributes&0x01ff0000)>>16;
    if(y) *y=attributes&255;
}
static inline void WritePosition(SpriteEntry* entry,int x,int y)
{
    entry->attributes=(entry->attributes&0xfe00ff00)|(y&255)|((unsigned(x)<<23)>>7);
}
// Original: arm9/ov031 @ 0x0223bbd8; symbol: func_ov031_0223bbd8; size: 0xf0.
// Positions one sprite, or translates the entire group while preserving each sprite's displacement from the first.
extern "C" void WfcUtility_SetSpriteGroupPosition(SpriteGroup* group,int index,int x,int y)
{
    SpriteEntry* entries=group->entries;
    if(index>=0) { WritePosition(entries+index,x,y); return; }
    int i;
    int originalX,originalY;
    ReadPosition(entries,&originalX,&originalY);
    WritePosition(entries,x,y);
    int deltaX=x-originalX,deltaY=y-originalY;
    for(i=1;i<group->count;++i) {
        int entryX,entryY;
        ReadPosition(entries+i,&entryX,&entryY);
        WritePosition(entries+i,entryX+deltaX,entryY+deltaY);
    }
}
#pragma force_active reset
