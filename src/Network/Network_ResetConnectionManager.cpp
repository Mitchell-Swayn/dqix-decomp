#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Output {unsigned char a,b,c,d;char block[20];unsigned short zero1,value1;char block2[52];unsigned short zero2,value2;};
extern "C" void OS_GetOwnerInfo(Output *);
extern "C" void Text_ConvertUnicodeToShiftJis(char *,const unsigned short *,unsigned short);
extern "C" unsigned NetworkResetConnectionManager_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202AEC0; symbol: Network_ResetConnectionManager; size: 0x134.
// Clears connection buffers and initializes the copied hardware name and state flags.
extern "C" void Network_ResetConnectionManager(char *self) {
 *(unsigned *)(self)=0;*(unsigned short *)(self+4)=0;
 *(unsigned *)(self+8)=0;*(unsigned *)(self+12)=0;
 *(unsigned *)(self+0xfc0)=0;*(unsigned *)(self+0x1004)=0;*(int *)(self+0x1008)=-1;
 memset(self+0x1014,0,0x24);memset(self+0x10,0,0x780);memset(self+0x790,0,0x28);memset(self+0x7c0,0,0x400);memset(self+0xbc0,0,0x400);memset(self+0xfc4,0,0x40);
 Output hardware;OS_GetOwnerInfo(&hardware);
 Text_ConvertUnicodeToShiftJis(self+0x1014,(const unsigned short *)hardware.block,(unsigned char)(self[0x1028]=hardware.value1));
 ((unsigned char *)self)[0x1029]&=~8;
 *(unsigned *)(self+0x1034)=0;
 self[0x100c]=1;self[0x100d]=1;self[0x100e]=0;self[0x100f]=0;self[0x1010]=0;
 NetworkResetConnectionManager_UnknownRoleZeroInitializedStorage[1]=0;
 memset(self+0x1038,0,0x10);memset(self+0x1048,0,0x10);
 self[0x1011]=1;
}
