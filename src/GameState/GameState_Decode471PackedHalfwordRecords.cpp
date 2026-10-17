#include <globaldefs.h>
#include <GameState/GameState.h>
struct Record { short value; unsigned short first:1; unsigned short second:1; unsigned short rest:14; };
// Original: arm9/main @ 0x020AC234; symbol: func_020ac234; size: 0xA0.
extern "C" ARM int GameState_Decode471PackedHalfwordRecords(Record* out) { char* base=(char*)GameState::GetInstance()+0x7ac0; unsigned short* values=(unsigned short*)(base+4); for(int i=0;i<471;i++) { int index=i*2; int offset=i*4; Record* item=(Record*)((char*)out+offset); out[i].value=(values[i]&0xfffc)>>2; item->first=(values[i]&2)>>1; item->second=values[i]&1; } return 1; }
