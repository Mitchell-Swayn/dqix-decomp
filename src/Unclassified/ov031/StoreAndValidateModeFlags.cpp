#include <globaldefs.h>
ARM
extern "C" char data_ov031_02250c0c[];
union Flags { unsigned raw; struct { unsigned low:4; unsigned rest:28; } bits; };
// Original: arm9/ov031 @ 0x022270AC; symbol: func_ov031_022270ac; size: 0x7C.
extern "C" int StoreAndValidateModeFlags(int mode, int flags) {

 data_ov031_02250c0c[0]=mode;
 *(unsigned*)(data_ov031_02250c0c+8)=flags;
 if(mode<0 || mode>6) return 0;
 if(((unsigned)(flags << 28) >> 28)>1) return 0;
 flags = (unsigned)flags >> 4;
 if(flags & 2) return 0;
 if(mode!=0 && (flags&1)) return 0;
 if(mode==0 && !(flags&1)) return 0;
 return 1;
}
