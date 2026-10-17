#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct GameState;
extern "C" signed char data_ov000_02183650[4];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned GameState_CopyField571DBufferToDestination(GameState*,void*);
extern "C" char* FindFourSlotRecordByIndex(void*,int);
// Original: arm9/ov000 @ 0x0217EDD4; symbol: func_ov000_0217edd4; size: 0xA8.
extern "C" void GameState_CollectPresentFourSlotPartyIndices(void* self,signed char* out,signed char* count) {
 signed char ids[4];
 COPY_ARRAY(ids,data_ov000_02183650);
 signed char source[4];
 signed char size=GameState_CopyField571DBufferToDestination((GameState*)_ZN9GameState11GetInstanceEv(),source);
 memcpy(ids,source,size);
 *count=0;
 for(int i=0;i<size;i++) {
  if(FindFourSlotRecordByIndex(self,ids[i])) {
   out[*count]=ids[i];
   (*count)++;
  }
 }
}
