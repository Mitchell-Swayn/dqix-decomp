#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {int WfcUtility_GetSpriteGroupCount(void*);void WfcUtility_GetSpriteGroupPosition(void*,int,unsigned*,unsigned*);void WfcUtility_SetSpriteGroupObjectMode(void*,int,unsigned,unsigned);}
// Original: arm9/ov031 @ 0x02238370; symbol: SetEntryVisibilityForCoordinateRange; size: 0x8c.
// Sets mode200 outside half-open coordinate range minimum through192.
extern "C" void WfcUtility_ClipDialogSpritesToVisibleRows(void* p,int minimum){int count=WfcUtility_GetSpriteGroupCount(p);for(int i=0;i<count;++i){unsigned high,low;WfcUtility_GetSpriteGroupPosition(p,i,&high,&low);unsigned flag;if((int)low>=minimum && (int)low<192)flag=0;else flag=512;WfcUtility_SetSpriteGroupObjectMode(p,i,flag,0);}}
