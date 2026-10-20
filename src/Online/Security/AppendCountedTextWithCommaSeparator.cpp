#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02207E24; symbol: func_ov031_02207e24; size: 0x6C.
// Appends comma-space to a nonempty destination, then copies at most count bytes within index255.
// The separator can advance past index255 when an existing string ends at254, as in the original.
extern "C" void AppendCountedTextWithCommaSeparator(char* output,const char* input,int count) {
 char* begin=output;
 if(*output) {
  while(*++output) {}
  if(output-begin>=255)return;
  *output++=',';
  *output++=' ';
 }
 while(count-- && output-begin<255) *output++=*input++;
 *output=0;
}
