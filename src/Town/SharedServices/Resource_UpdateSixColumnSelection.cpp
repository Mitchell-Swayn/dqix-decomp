#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
// Original: arm9/ov003 @ 0x02178548; symbol: func_ov003_02178548; size: 0x8C.
extern "C" void Resource_UpdateSixColumnSelection(unsigned char* p){
 unsigned char* group=*(unsigned char**)(p+0x89c);
 int origin=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,3);
 short row=*(short*)(p+0x1014);
 short column=*(short*)(p+0x1006);
 short index=(column-origin)+(short)6*row;
 if(index>=p[0x835])index=p[0x835]-1;
 *(short*)(p+0x103a)=*(short*)(p+0x848+index*2);
 int base=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,3);
 *(short*)(p+0x1006)=index%6+base;
}
