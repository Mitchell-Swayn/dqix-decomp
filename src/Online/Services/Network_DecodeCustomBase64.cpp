#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221AC6C; symbol: func_ov031_0221ac6c; size: 0x168.
extern "C" int Network_DecodeCustomBase64(const char* input,unsigned length,char* output,unsigned capacity) {
 if(length&3)return -1;
 int bits=0;
 unsigned i=0;
 if(i<length) do { if(input[i]!='*')bits+=6; ++i; }while(i<length);
 int size=bits/8;
 if(!output)return size;
 if(capacity<(unsigned)size)return -1;
 if(!length)return 0;
 char* dst=output;
 int written;
 do {
  char values[4];
  char* v=values; int k=0;
  do {
   int c=input[k];
   if(c>='A'&&c<='Z')*v=c-'A';
   else if(c>='a'&&c<='z')*v=c-'a'+26;
   else if(c>='0'&&c<='9')*v=c-'0'+52;
   else if(c=='.')*v=62;
   else if(c=='-')*v=63;
   else *v=0;
   ++k; ++v;
  }while(k<4);
  dst[0]=(values[0]<<2)|(values[1]>>4);
  written=dst+1-output;
  input+=4;
  if(written>=size)break;
  dst[1]=(values[1]<<4)|(values[2]>>2);
  written=dst+2-output;
  if(written>=size)break;
  dst[2]=(values[2]<<6)|values[3];
  dst+=3;
  written=dst-output;
 }while(written<size);
 return written;
}
