#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void Record_ClearTwoWordsAndByteEight(void *);void ClearTwoWordsAndFourBytes(void *);
// Original: arm9/main @ 0x020E1588; symbol: func_020e1588; size: 0x70.
void Object_ResetSixtyFourByteStateAndEmbeddedRecords(unsigned char *p){*(int *)p=0;*(int *)(p+4)=0;*(int *)(p+8)=0;Record_ClearTwoWordsAndByteEight(p+12);Record_ClearTwoWordsAndByteEight(p+24);ClearTwoWordsAndFourBytes(p+36);*(int *)(p+48)=0;*(int *)(p+52)=0;p[57]=0;p[56]=0;p[59]=0;p[58]=0;p[60]=0;p[61]=0;p[62]=0;p[63]&=~1;p[63]&=~2;}
}
