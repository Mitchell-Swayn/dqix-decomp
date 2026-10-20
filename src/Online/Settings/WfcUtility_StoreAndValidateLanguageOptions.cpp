#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[];
union Flags { unsigned raw; struct { unsigned low:4; unsigned rest:28; } bits; };
// Original: arm9/ov031 @ 0x022270AC; symbol: func_ov031_022270ac; size: 0x7C.
extern "C" int WfcUtility_StoreAndValidateLanguageOptions(int mode, int flags) {

 Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[0]=mode;
 *(unsigned*)(Ov031GetStatusCode_UnknownRoleZeroInitializedStorage+8)=flags;
 if(mode<0 || mode>6) return 0;
 if(((unsigned)(flags << 28) >> 28)>1) return 0;
 flags = (unsigned)flags >> 4;
 if(flags & 2) return 0;
 if(mode!=0 && (flags&1)) return 0;
 if(mode==0 && !(flags&1)) return 0;
 return 1;
}
