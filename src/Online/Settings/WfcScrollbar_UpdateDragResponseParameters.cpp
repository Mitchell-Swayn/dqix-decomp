#include <globaldefs.h>
#include <System/Matrix.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetSequenceVolume(unsigned);
extern "C" void Network_InvokePresentOwnerIdWithPair(int,int);
// Original: arm9/ov031 @ 0x02235488; symbol: func_ov031_02235488; size: 0x78.
// Maps distance from shared byte1A into optional-byte and signed pair values,
// using the original thresholds2/6 and divider6-distance for intermediate values.
extern "C" void WfcScrollbar_UpdateDragResponseParameters(int selected){
 int distance=WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[0x1a]-selected;
 if(distance<0)distance=-distance;
 unsigned value;
 if(distance<2)value=0;
 else if(distance>=6)value=127;
 else value=FastIntDivide(127,6-distance);
 WfcUtility_SetSequenceVolume(value);
 int amount;
 if(distance<2)amount=-256;
 else if(distance>=6)amount=256;
 else amount=FastIntDivide(512,6-distance)-256;
 Network_InvokePresentOwnerIdWithPair(65535,amount);
}
