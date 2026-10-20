#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CDD30; symbol: func_ov017_021cdd30; size: 0x40.
// Applies the fragment only when the two low target bits match the local network member.
extern "C" int Network_GetLocalMemberId(void*);
extern "C" void Field_CopySynchronizedProgressFragment(unsigned,unsigned,void*);
extern "C" void Field_ApplyTargetedProgressFragment(void*,char* message,void*,void*,void* connection) {
 struct Packed { unsigned short member:2,index:14; };
 unsigned member=((Packed*)(message+4))->member;
 if(Network_GetLocalMemberId(connection)!=member)return;
 Field_CopySynchronizedProgressFragment(member,((Packed*)(message+4))->index,message+6);
}
