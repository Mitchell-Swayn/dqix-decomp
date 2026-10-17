#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020838C4; symbol: func_020838c4; size: 0x9C.
extern "C" int Object_RemoveHalfwordKeyAndCompactEightEntries(unsigned char* object,int key){if(key<0)return 0;int found=0;for(int i=0;i<8;i++){if(*(short*)(object+i*2+0x454)==key){*(short*)(object+i*2+0x454)=-1;found=1;break;}}if(found){for(int i=0;i<7;i++){if(*(short*)(object+i*2+0x454)<0){*(short*)(object+i*2+0x454)=*(short*)(object+(i+1)*2+0x454);*(short*)(object+(i+1)*2+0x454)=-1;}}}return found;}
