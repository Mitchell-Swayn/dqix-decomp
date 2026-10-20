#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
struct Pair {unsigned first,second;};
extern "C" unsigned QueueTaggedRecordOperationMessage34(...);
extern "C" unsigned Network_AcknowledgeTaggedRequest(...);
extern "C" unsigned Network_InsertTaggedAcknowledgement(...);
extern "C" unsigned Network_GetTaggedAcknowledgementTable(...);
extern "C" void Network_ApplyTaggedAcknowledgementSnapshot(unsigned,int,Pair);
extern "C" unsigned Network_RemoveTaggedAcknowledgement(...);
extern "C" unsigned Network_RequestTaggedAcknowledgement(...);
extern "C" unsigned Network_IsParentOrOffline(...);
// Original: arm9/ov017 @ 0x021cec70; symbol: Network_DispatchTaggedRecordOperationMessage; size: 0xd8.
extern "C" void Network_DispatchTaggedAcknowledgementCommand(unsigned bit,unsigned message,unsigned unused2,unsigned unused3,unsigned connection){
unsigned records=Network_GetTaggedAcknowledgementTable();if(Network_IsParentOrOffline(connection)){switch(U8(message+4)){
case 0:Network_RequestTaggedAcknowledgement(records,bit,U8(message+12),U32(message+8));break;case 1:Network_AcknowledgeTaggedRequest(records,bit,U8(message+12),U32(message+8));break;case 2:Network_InsertTaggedAcknowledgement(records,U8(message+12),U32(message+8));break;case 3:QueueTaggedRecordOperationMessage34(3,U8(message+12),U32(message+8));break;}}
else if(U8(message+4)==3){int index=S8(message+5);if(index<0)Network_RemoveTaggedAcknowledgement(records,U8(message+12),U32(message+8));else Network_ApplyTaggedAcknowledgementSnapshot(records,index,*(Pair*)(message+8));}
}