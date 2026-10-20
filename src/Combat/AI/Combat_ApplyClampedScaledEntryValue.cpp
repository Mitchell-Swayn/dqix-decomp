#include <globaldefs.h>
ARM
struct Status { signed value:3; unsigned rest:29; };
struct Rating { unsigned low:7; unsigned value:7; unsigned high:18; };
extern "C" { void BattleAI_CacheActionPolicyEntry(void*,int); void SubmitPercentScaledDisplayRecord(void*,float,int); }
// Original: arm9/ov024 @ 0x021FD2B4; symbol: func_ov024_021fd2b4; size: 0xA4.
extern "C" void Combat_ApplyClampedScaledEntryValue(unsigned char* owner) {
 unsigned char* data=*(unsigned char**)(*(unsigned char**)(owner+0x668)+0x138);
 if(-2>=((Status*)(data+0x58))->value) return;
 short state;
 unsigned factor=data[0x4f];
 if(!factor) return;
 unsigned char* source=*(unsigned char**)(owner+0x64c);
 state=*(short*)(source+0x32);
 unsigned rating=((Rating*)(source+0x14))->value;
 float value=(float)rating*((float)factor/100.0f);
 if(value>100.0f) value=100.0f;
 if(state>=0) return;
 BattleAI_CacheActionPolicyEntry(owner,13);
 SubmitPercentScaledDisplayRecord(owner,value,17);
}
