#include <globaldefs.h>
ARM
extern "C" char* strcpy(char*,const char*);
extern "C" char* strrchr(const char*,int);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
struct Configuration {signed char selected;char pad[3];int values[9];};
extern "C" Configuration data_ov003_02180cd0;
extern "C" char data_ov003_02180cf8[],data_ov003_02180d08[];
// Original: arm9/ov003 @ 0x0217BB1C; symbol: func_ov003_0217bb1c; size: 0x19C.
extern "C" int Script_SetSelectedResourceNamesAndFixedValues(char* args) {
 int selected=_ZNK6Script9Parameter5ToIntEv(args);
 if(selected!=data_ov003_02180cd0.selected)return 1;
 const char* name=_ZNK6Script9Parameter8ToStringEv(args+8);
 const char* other=_ZNK6Script9Parameter8ToStringEv(args+16);
 char* slash=strrchr(name,47);
 if(slash)name=slash+1;
 strcpy(data_ov003_02180cf8,name);
 strcpy(data_ov003_02180d08,other);
 data_ov003_02180cd0.values[0]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+24)));
 data_ov003_02180cd0.values[1]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+32)));
 data_ov003_02180cd0.values[2]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+40)));
 data_ov003_02180cd0.values[3]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+48)));
 data_ov003_02180cd0.values[4]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+56)));
 data_ov003_02180cd0.values[5]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+64)));
 data_ov003_02180cd0.values[6]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+72)));
 data_ov003_02180cd0.values[7]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+80)));
 data_ov003_02180cd0.values[8]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+88)));
 return 1;
}
