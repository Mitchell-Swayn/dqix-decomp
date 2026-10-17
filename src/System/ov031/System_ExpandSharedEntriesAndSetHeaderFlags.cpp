#include <globaldefs.h>
ARM
struct Header { unsigned int flags; unsigned short extra; };
struct State { Header* output; int pad; signed char index; };
extern "C" State* data_ov031_02250bf8;
extern "C" unsigned char data_ov031_022489a4[];
extern "C" unsigned int ReadSharedHalfwordOrBusy8000();
extern "C" unsigned short ReadSharedRecordSizeForAllowedTypes();
extern "C" void ExpandPackedSixByteEntriesToEight(unsigned int,unsigned int,void*);
// Original: arm9/ov031 @ 0x02223B60; symbol: func_ov031_02223b60; size: 0xA8.
extern "C" void System_ExpandSharedEntriesAndSetHeaderFlags() {
volatile unsigned short* ime=(volatile unsigned short*)0x4000208;
unsigned int offset=0;
unsigned short saved=*ime;
*ime=0;
if(ReadSharedHalfwordOrBusy8000()!=0x8000)offset=ReadSharedRecordSizeForAllowedTypes();
(void)*ime;*ime=saved;
ExpandPackedSixByteEntriesToEight(0,(data_ov031_022489a4+data_ov031_02250bf8->index*4)[offset],data_ov031_02250bf8->output);
data_ov031_02250bf8->output->flags=(data_ov031_02250bf8->output->flags&0xfe00ff00)|0xe50026;
data_ov031_02250bf8->output->extra=(data_ov031_02250bf8->output->extra&~0xc00)|0x800;
}
