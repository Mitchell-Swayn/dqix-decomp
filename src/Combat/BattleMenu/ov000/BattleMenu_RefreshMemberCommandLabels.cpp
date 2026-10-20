#include <globaldefs.h>
ARM
extern "C" void BattleMenu_RefreshMemberCommandLabel(unsigned char*);
// Original: arm9/ov000 @ 0x0217457C; symbol: BattleMenu_RefreshMemberCommandLabels; size: 0x98.
// Formats four selected records with nonnegative object IDs, or only the first
// selected record whose object ID matches the requested nonnegative value.
extern "C" void BattleMenu_RefreshMemberCommandLabels(unsigned char* owner,int requested)
{
 int i;
 unsigned char* self=owner;
 if(requested<0){
  for(i=0;i<4;i++){
   unsigned char* record=self+0x958+*(signed char*)(self+0x6c+i)*0x448;
   if(*(int*)(record+0x4c)>=0)BattleMenu_RefreshMemberCommandLabel(record);
  }
 }else{
  for(int j=0;j<4;j++){
   unsigned char* record=self+0x958+*(signed char*)(self+0x6c+j)*0x448;
   if(requested==*(int*)(record+0x4c)){BattleMenu_RefreshMemberCommandLabel(record);return;}
  }
 }
}
