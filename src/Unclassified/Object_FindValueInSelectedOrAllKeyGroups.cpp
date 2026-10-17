#include <globaldefs.h>
ARM
struct State {char pad[0xbd0];const short* keys[8];const signed char* values[8];char padc10[16];unsigned char types[8];};
extern "C" const short data_020e8a14[8];
// Original: arm9/main @ 0x0207C7A0; symbol: func_0207c7a0; size: 0xF4.
extern "C" int Object_FindValueInSelectedOrAllKeyGroups(const State* s,int key,unsigned type){
 if(key<0)return 0;int selected=-1;
 for(int i=0;i<8;++i)if(type==(reinterpret_cast<const unsigned char*>(s)+i)[0xc20]){selected=i;break;}
 if(selected<0){for(int i=0;i<8;++i){int count=data_020e8a14[i];const short* keys=s->keys[i];for(int j=0;j<count;++j)if(key==keys[j])return s->values[i][j];}}
 else {int count=data_020e8a14[selected];const short* keys=s->keys[selected];for(int j=0;j<count;++j)if(key==keys[j])return s->values[selected][j];}
 return 0;
}
