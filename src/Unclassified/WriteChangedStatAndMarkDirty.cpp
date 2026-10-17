#include <globaldefs.h>
extern "C" char* ReadGlobalValueAt02108844(); extern "C" void BitArray_SetIndexedBoolean(void*,void*,unsigned,int);
struct Stats { char pad[0x488]; short values[10]; char tail[0x56e - 0x49c]; unsigned char dirty; }; struct Owner { char pad[0x150]; Stats* stats; };
// Original: arm9/main @ 0x02052D7C; symbol: func_02052d7c; size: 0x7C.
extern "C" ARM void WriteChangedStatAndMarkDirty(Owner* object,int index,int value) { Stats* stats=object->stats; if(!stats || stats->values[index]==value) return; if(index!=7 && index!=8) { char* state=ReadGlobalValueAt02108844(); BitArray_SetIndexedBoolean(state,state+0x8c,0x113f,1); } object->stats->values[index]=value; if(index==9 && object->stats) object->stats->dirty=1; }
