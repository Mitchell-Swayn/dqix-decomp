#include <globaldefs.h>
ARM
extern "C" void Text_ParseDelimitedSignedIntegerSequence(void *,int *,int);
extern "C" int ReadFontMetricByIndex(void *);
// Original: arm9/main @ 0x0206B894; symbol: func_0206b894; size: 0x38.
extern "C" int ComputeParameterMinusTextLengthAndOne(void *self,int *out,void *text) { int value; // func_020696bc initializes its output.
 Text_ParseDelimitedSignedIntegerSequence(self,&value,1); int count=ReadFontMetricByIndex(text); *out=value-(count+1); return 0; }
