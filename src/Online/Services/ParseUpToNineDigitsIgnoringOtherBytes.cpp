#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02242F14; symbol: func_ov031_02242f14; size: 0x70.
// Accumulates decimal digits from a bounded byte sequence, ignoring spaces and
// other nondigits. Returns -1 for zero digits or more than nine digits.
extern "C" int ParseUpToNineDigitsIgnoringOtherBytes(const char* input,unsigned count)
{
 int digits=0;
 int value=0;
 while(count--){
  int byte=*input;
  if(byte!=' '&&byte>='0'&&byte<='9'){
   value=value*10+byte-'0';
   if(++digits>9)return -1;
  }
  input++;
 }
 if(digits==0)value=-1;
 return value;
}
