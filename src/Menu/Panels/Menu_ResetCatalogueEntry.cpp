#include <globaldefs.h>
ARM
struct Record {void* first;void* second;short key;unsigned short a,b;unsigned char flag0:1,flag1:1,options:6;unsigned char state;};
// Original: arm9/ov023 @ 0x021E12CC; symbol: func_ov023_021e12cc; size: 0x4C.
// Clears two links, sets three halfword sentinels, and resets packed flags and state.
extern "C" void Menu_ResetCatalogueEntry(Record* self){
 self->first=0;self->second=0;self->key=-1;self->a=0xffff;self->b=0xffff;
 self->flag0=0;self->flag1=0;self->options=0;self->state=0;
}
