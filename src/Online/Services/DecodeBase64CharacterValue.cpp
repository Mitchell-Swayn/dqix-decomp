#include <globaldefs.h>
ARM
// Retain the original separate alphabet subtraction and range-base addition.
#pragma opt_propagation off
// Original: arm9/ov031 @ 0x02215AF4; symbol: func_ov031_02215af4; size: 0x70.
// Maps the Base64 alphabet to six-bit values; padding is zero, invalid input is -1.
extern "C" int DecodeBase64CharacterValue(unsigned value){
 if(value>='A'&&value<='Z')return value-'A';
 if(value>='a'&&value<='z'){value-='a';return value+26;}
 if(value>='0'&&value<='9'){value-='0';return value+52;}
 if(value=='+')return 62;if(value=='/')return 63;
 return -(value!='=');
}
