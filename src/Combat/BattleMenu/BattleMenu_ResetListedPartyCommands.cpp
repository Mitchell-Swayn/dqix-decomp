#include <globaldefs.h>
ARM
extern "C" void BattleMenu_ResetPartyCommandSelection(void*);
extern "C" unsigned char* BattleMenu_GetSelectedPartyCommandRecord(char*);
// Original: arm9/ov000 @ 0x02180404; symbol: ResetFourActiveIndexedRecords; size: 0x88.
// Resets four indexed records with valid IDs and byte 87 set, then marks the current record.
extern "C" void BattleMenu_ResetListedPartyCommands(char* p) {
 for (int i=0;i<4;i++) {
  char* r=p+0x958+ *(signed char*)(p+i+0x6c)*0x448;
  int valid=0;
  if (*(int*)(r+0x4c)>=0 && *(int*)(r+0x4c)<=3) valid=1;
  if(valid && *(unsigned char*)(r+0x87)) BattleMenu_ResetPartyCommandSelection(r);
 }
 unsigned char* r=BattleMenu_GetSelectedPartyCommandRecord(p);
 if(r) r[0x24]|=4;
}
