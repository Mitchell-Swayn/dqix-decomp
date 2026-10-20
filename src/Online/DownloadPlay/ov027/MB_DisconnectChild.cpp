#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" void MBi_HandleParentWirelessEvent(void*);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(int,unsigned);
extern "C" void MBi_ClearParentPieceBuffer(unsigned);
extern unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
#define P (*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+12))
// Original: arm9/ov027 @ 0x021DCD5C; symbol: MB_DisconnectChild; size: 0x18C.
// Disconnects a child, clears per-child buffers, and updates parent membership masks.
extern "C" void MB_DisconnectChild(unsigned child) {
 ValidateSlotAgainstSharedMaskAndSubmit((int)MBi_HandleParentWirelessEvent,child);
 if(child==0 || child>=16) return;
 unsigned index=child-1;
 *(unsigned short*)(P+0x148a+index*2)=0;
 VectorizedMemset(P+0x14a8+index*4,0,4);
 VectorizedMemset(P+0x1340+index*22,0,22);
 MBi_ClearParentPieceBuffer(child);
 *(unsigned short*)(P+0x1754+index*2)=0;
 signed char group=*(signed char*)(P+0x1526+index);
 if(group!=-1) {
  unsigned char file=(unsigned char)group;
  unsigned offset=file*0x5d4;
  *(unsigned short*)(P+offset+0x1d4e)&=~(1<<child);
  *(unsigned short*)(P+offset+0x1d50)|=1<<child;
  unsigned childIndex=child-1;
  *(signed char*)(P+0x1526+childIndex)=-1;
  *(unsigned short*)(P+offset+0x1d4c)&=~(1<<child);
 }
 if(*(unsigned short*)(P+0x1536)&(1<<child)) {
  P[0x1535]--;
  *(unsigned short*)(P+0x1536)&=~(1<<child);
 }
 *(unsigned*)(P+0x14e8+index*4)=0;
}
