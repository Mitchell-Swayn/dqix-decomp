// Original field/callee argument semantics reviewed; absolute values here are hardware MMIO.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Bits{unsigned char a:1,b:1,c:6;};extern "C" {void* memcpy(void*,const void*,unsigned);int func_0202cd50(void*,void*,unsigned short);extern char Object_PrepareNameAndSubmitConnectionRecord[],data_020e73b4[];void ClearField18Flag10AndBytes7BAnd9E(void*);void ClearRecordWordsAndByteFlags(void*);int AreWordFlags80039Clear(void*);void Object_AllocateFortyFourByteEntriesAndInvalidateKeys(void*,void*,unsigned short);void AllocateSixtyFourByteRecordArrayAndResetCount(void*,void*,short);extern void* data_02108da8[],*data_02108efc[];}
// Original: arm9/main @ 0x0208B588; symbol: func_0208b588; size: 0x2C.
extern "C" void Graphics_WritePackedPolygonAttributeFields_Main0208B588(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f){*(volatile unsigned*)0x040004a4=(a|(b<<4)|(c<<6)|f|(d<<24))|(e<<16);}
