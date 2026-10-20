#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned GameState_SetSelectedStateWordFields(...);
extern "C" unsigned Network_RequestSharedStateSeven(...);
// Original: arm9/ov031:0221508c
extern "C" int Network_SelectPendingAccessPointAndStopScan(unsigned char* p,int state){if(state==17)return state;unsigned char i;unsigned count=B(p,0xd12);i=0;for(;i<count;i++){if(B(p+i*4,0x444)==0)break;}if(state==6){if(count==i){if(i==0)GameState_SetSelectedStateWordFields(5);else GameState_SetSelectedStateWordFields(6);return 17;}}else{if(count==0)return state;if(count==i)return state;if(B(p+i*4,0x446)<20)return state;}B(p,0xd13)=i;if(Network_RequestSharedStateSeven()!=1){B(p,0xd0e)=state;state=7;}return state;}
