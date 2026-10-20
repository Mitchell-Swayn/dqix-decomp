struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
struct WindowCanvasRecord { char pad[0xc4]; unsigned char id; char rest[0x1b]; };struct WindowCanvasOwner { char pad[0x98]; void* ready; WindowCanvasRecord* records; char pad2[0x13]; unsigned char count,stop; };
// Original: arm9/main @ 0x0205D81C; symbol: func_0205d81c; size: 0x6C.
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner* self,unsigned id) { if(!self->ready)return 0;unsigned char i; WindowCanvasRecord* records=self->records;if(!records)return 0; for(i=0;i<self->count;++i) {if(i==self->stop)break; WindowCanvasRecord* record=records+i;if(id==record->id)return record;}return 0; }
