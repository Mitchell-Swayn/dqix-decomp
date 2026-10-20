#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma always_inline on
struct Header; struct Entry;
extern "C" Entry* NNS_G2dFindBinaryBlock(Header*,unsigned);
extern "C" void Font_RelocateResourcePointers(char*);
extern "C" void DisableInterruptsAndHaltForever(void);
inline int Signature(char* p) { if(p && *(unsigned*)p==0x4e465452) return 1; return 0; }
inline int Version(char* p,unsigned v) { if(p && *(unsigned short*)(p+6)>=v) return 1; return 0; }
inline bool SigOK(char* p) { return Signature(p)!=0; }
inline bool VerOK(char* p,unsigned v) { return Version(p,v)!=0; }
inline bool Valid(char* p,unsigned v) { if(p) { bool ok=SigOK(p); if(ok) ok=VerOK(p,v); return ok; } return false; }
// Original: arm9/main @ 0x020B27C8; symbol: func_020b27c8; size: 0x154.
extern "C" int Graphics_FindFontInformation(char* p,char** out) {
 int old=0;
 if(!Valid(p,0x101)) { if(!Valid(p,0x100)) DisableInterruptsAndHaltForever(); old=1; }
 Font_RelocateResourcePointers(p);
 Entry* e=NNS_G2dFindBinaryBlock((Header*)p,0x46494e46);
 if(!e) { *out=0; return 0; }
 *out=(char*)e+8;
 if(old) *(char*)(*(char**)(*out+8)+7)=0;
 return 1;
}
