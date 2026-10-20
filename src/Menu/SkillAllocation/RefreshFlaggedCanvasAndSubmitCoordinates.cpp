#include <globaldefs.h>
ARM
extern "C" void AdvanceTenEntryResourceLoading(char*);
extern "C" void SkillDetails_SubmitRewardMarkerSprites(char*);
// Original: arm9/ov013 @ 0x021870C0; symbol: func_ov013_021870c0; size: 0x30.
// Refreshes a flagged canvas and submits coordinates on display mode one.
// Original preserves the full flag byte in r1 across the first call; its callee ignores it.
extern "C" void RefreshFlaggedCanvasAndSubmitCoordinates(unsigned char* p){
 unsigned flags=p[0x69];if(flags&1)((void(*)(char*,unsigned))AdvanceTenEntryResourceLoading)((char*)p,flags);
 if(p[0x64]==1)SkillDetails_SubmitRewardMarkerSprites((char*)p);
}
