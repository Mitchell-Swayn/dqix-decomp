#include <globaldefs.h>
typedef unsigned(*Getter)();typedef void(*Setter)(unsigned);extern "C" Getter data_020f2bdc[];extern "C" Setter data_020f2bec[];
struct Flag {unsigned char value,bank,bit;};
// Original: arm9/main @ 0x020E2CC4; symbol: func_020e2cc4; size: 0x60.
extern "C" ARM void RegisterBit_UpdateSelectedBankWhenValueChanges(Flag* p,unsigned value){if(p->value==value)return;p->value=value;unsigned word=data_020f2bdc[p->bank]();if(value)word|=1<<p->bit;else word&=~(1<<p->bit);data_020f2bec[p->bank](word);}
