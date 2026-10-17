#include <globaldefs.h>
ARM
struct TextState { unsigned char pad[8]; unsigned char values[4][3]; unsigned char selected; };
extern "C" TextState* data_ov031_02290c98;
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x0222DD70; symbol: func_ov031_0222dd70; size: 0x94.
extern "C" int Util_TestSelectedThreeDigitValueAtLeast(int threshold) {
 TextState* state=data_ov031_02290c98;
 unsigned char* text=state->values[state->selected];
 if(text[0]!=0 && text[0]!=0x20) return 1;
 unsigned char buffer[4];
 MI_CpuCopy8(text,buffer,3);
 buffer[3]=0;
 unsigned char* p=buffer;
 for(int i=0;i<3;i++) {
  if(*p) break;
  *p++=0x20;
 }
 return Runtime_ParseStringAsBaseTenInteger((char*)buffer)>=threshold;
}
