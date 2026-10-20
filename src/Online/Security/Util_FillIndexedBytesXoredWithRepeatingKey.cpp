#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x0221E3D0; symbol: func_ov031_0221e3d0; size: 0x34.
// Fills half the signed length with index bytes XORed against a repeating signed-byte key.
extern "C" void Util_FillIndexedBytesXoredWithRepeatingKey(int start,char *out,int length,const char *key,int keyLength) {
 int count=length/2;
 int keyIndex=start%keyLength;
 int index=0;
 if(count>0)do {
 out[index]=index;
 out[index]^=key[keyIndex++];
 if(keyIndex>=keyLength)keyIndex=0;
 ++index;
 }while(index<count);
}
