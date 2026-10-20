#include <globaldefs.h>
ARM
struct BytePermutationState {unsigned char first,second,permutation[256];};
// Original: arm9/ov031 @ 0x0220BAB8; symbol: func_ov031_0220bab8; size: 0x6C.
// Applies the RC4-style permutation step and XOR stream to the byte buffer, retaining its two indices.
extern "C" void ApplyBytePermutationXorStream(BytePermutationState* context,unsigned char* bytes,int length){
 int offset;unsigned char first,second;
 unsigned char* table=context->permutation;
 first=context->first;second=context->second;
 offset=0;
 if(length>0)do{
  ++first;
  unsigned char a=table[first];second+=a;
  unsigned char b=table[second];table[first]=b;table[second]=a;
  unsigned char sum=a+b;
  bytes[offset]^=table[sum];
  ++offset;
 }while(offset<length);
 context->first=first;context->second=second;
}
