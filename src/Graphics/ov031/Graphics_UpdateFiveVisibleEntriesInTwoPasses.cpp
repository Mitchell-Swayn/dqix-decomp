#include <globaldefs.h>
ARM
struct Root {short pad;unsigned short offset;unsigned char* owner;};
extern "C" {extern Root data_ov031_02290c8c;int FastIntDivide(int,int);void Text_DrawSplitAsciiRow(int,int);void Graphics_UpdateIndexedSpriteTileFields(int,int);void Graphics_UpdateFivePairedSpriteRows();void func_ov031_0223ca40(void*,int);void MarkPrimaryOrSecondaryBufferReady(void*);}
// Original: arm9/ov031 @ 0x0222C3B4; symbol: func_ov031_0222c3b4; size: 0xA8.
extern "C" void Graphics_UpdateFiveVisibleEntriesInTwoPasses(){
int count,current,i,start;
start=FastIntDivide(data_ov031_02290c8c.offset,28);
count=data_ov031_02290c8c.owner[0x51];
func_ov031_0223ca40(*(void**)(data_ov031_02290c8c.owner+12),0);
if(count>5)count=5;
current=start;i=0;if(i<count)do{Text_DrawSplitAsciiRow(current,i);i++;current++;}while(i<count);
int j=0;if(j<count)do{Graphics_UpdateIndexedSpriteTileFields(start,j);j++;start++;}while(j<count);
MarkPrimaryOrSecondaryBufferReady(*(void**)(data_ov031_02290c8c.owner+12));Graphics_UpdateFivePairedSpriteRows();
}
