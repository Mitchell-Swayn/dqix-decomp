#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Shared{unsigned short unused,multiplier;unsigned char* view;};extern "C" Shared TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;extern "C" int FastIntDivide(int,int);extern "C" void CreateOverlaySpriteRecord(int,int,int,int,int);
// Original: arm9/ov031 @ 0x0222B870; symbol: ConfigureThreeTierProgressIndicator; size: 0xA8.
// Chooses zero/31/55 progress widths for item-count tiers and scales the progress indicator.
extern "C" void ConfigureThreeTierProgressIndicator(){*(unsigned short*)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view+0x40)=(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x51]-4)*28;int tier;int position=0;if(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x51]<=4){tier=0;TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x53]=0;}else if(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x51]<=8){TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x53]=31;tier=1;}else{TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x53]=55;tier=2;}if(tier)position=FastIntDivide(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.multiplier*TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view[0x53],*(unsigned short*)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.view+0x40));CreateOverlaySpriteRecord(tier,85,236,63,position);}
