#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0207C51C; symbol: func_0207c51c; size: 0xDC.
extern "C" int Inventory_CompactItemTypeGroup(char* p,unsigned id){
 int slot=-1;for(int i=0;i<8;++i){if(id==*(unsigned char*)((p+i)+0xc20)){slot=i;break;}}if(slot==-1)return 0;
 short* values=*(short**)((p+slot*4)+0xbd0);char* flags=*(char**)((p+slot*4)+0xbf0);short count=*(short*)((p+slot*2)+0xc10);int hole=0;
 for(int i=0;i<count;++i){if(hole==i){if(values[i]<0)hole=i;else ++hole;}else if(hole!=i&&values[i]>=0){values[hole]=values[i];flags[hole]=flags[i];values[i]=-1;flags[i]=0;do{++hole;}while(values[hole]>=0);}}
 return 1;
}
