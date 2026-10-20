#pragma opt_strength_reduction off
#include <globaldefs.h>
ARM
extern "C" int DecodeBase64CharacterValue(unsigned);
// Original: arm9/ov031 @ 0x02215B64; symbol: func_ov031_02215b64; size: 0x168.
extern "C" int Util_DecodeBase64BlocksAndRemainder(const unsigned char* source,unsigned char* output,int length,unsigned capacity) {
 const unsigned char* tailCursor;
 int remainder,full;
 unsigned size=(unsigned)(length*3)>>2;
 if(capacity>=size) {remainder=length&3;full=length-remainder;}else return -1;
 unsigned value;
 int position=0;
 int j;
 if(full>0) {
  int block=0;
  do {
   value=0;
   j=0;
   const unsigned char* cursor=source+position;
   do {value|=(unsigned)DecodeBase64CharacterValue(*cursor++)<<((3-j)*6);j++;}while(j<4);
   unsigned word=value;
   unsigned char* dest=output+block*3;
   j=0;
   do {*dest++=((unsigned char*)&word)[2-j];j++;}while(j<3);
   position+=4;block++;
  }while(position<full);
 }
 if(remainder) {
  value=0;
  j=0;
  unsigned combined=0;
  if(remainder>0) {
   tailCursor=source+full;
   do {value|=(unsigned)DecodeBase64CharacterValue(*tailCursor++)<<((3-j)*6);j++;combined|=value;}while(j<remainder);
  }
  j=0;
  if(remainder>0) {
   unsigned char* dest=output+(full*3)/4;
   do {*dest++=((unsigned char*)&combined)[2-j];j++;}while(j<remainder);
  }
 }
 return size;
}
