#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{unsigned short key;char pad[74];};
// Original: arm9/main @ 0x0209B9E4; symbol: func_0209b9e4; size: 0x38.
E *Script_FindWeightedGroupById(E *p,unsigned int key){for(int i=0;i<6;i++)if(p[i].key==key)return p+i;return 0;}
}
