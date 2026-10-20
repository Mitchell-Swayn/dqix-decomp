#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x0217fd60; symbol: TestFourSlotRecordPendingFlag.
extern "C" int BattleMenu_IsPartyCommandInputPending(char* p,int id){int result=0;if(id<0){char* base=p+0x158;base+=0x800;for(int i=0;i<4;i++){char* record=base+S(p+i,0x6c)*0x448;if((int)U(record,0x4c)>=0)result=(result|((B(record,0x24)&1)!=0))!=0;}}else{char* base=p+0x158;base+=0x800;for(int i=0;i<4;i++){char* record=base+S(p+i,0x6c)*0x448;if(id==(int)U(record,0x4c)){result=(B(record,0x24)&1)!=0;break;}}}return result;}
