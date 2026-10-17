#include <globaldefs.h>
ARM
extern "C" unsigned short data_ov017_021d6638[];
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
extern "C" void Network_QueueConnectionValueRecord(int,int,unsigned short,int);
// Original: arm9/ov017 @ 0x0219E290; symbol: func_ov017_0219e290; size: 0x80.
extern "C" void GameState_SetMatchedTableKeyBitAndNotify(void* unused,int key) {
 unsigned char* object=(unsigned char*)ReadGlobalValueAt02108844();
 int match=-1;
 for(unsigned i=0;i<18;i++) { if(key==data_ov017_021d6638[i]) match=i; }
 if(match<0) return;
 BitArray_SetIndexedBoolean(object,object+0x8c,match+0x200,1);
 if(TestInactiveOrPrimaryIndexState((unsigned*)Object_GetGlobalConnectionState()))
  Network_QueueConnectionValueRecord(1,0,(unsigned short)match,1);
}
