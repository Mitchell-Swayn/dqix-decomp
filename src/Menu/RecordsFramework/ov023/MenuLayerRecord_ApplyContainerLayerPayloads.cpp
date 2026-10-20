#include <globaldefs.h>
ARM
#pragma always_inline on
struct Record;
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_ParseTaggedLayerResource(char*,const void*);
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
struct Nibbles {unsigned char low:4,high:4;
 unsigned char GetLow() const {return low;}
 unsigned char GetHigh() const {return high;}
 void SetLow(unsigned char v){low=v;}
 void SetHigh(unsigned char v){high=v;}
};
struct CanvasOwner {char prefix[0x44];Nibbles nibbles;};
struct CanvasTransfer {char prefix[28];Nibbles nibbles;char tail[3];};
// Original: arm9/ov023 @ 0x021F7B98; symbol: MenuLayerRecord_ApplyContainerLayerPayloads; size: 0xD0.
// Dispatches each active resource block with transfer nibbles copied from its canvas owner.
// The unused second argument and fifth-argument guard's role remain uncertain.
extern "C" void MenuLayerRecord_ApplyContainerLayerPayloads(CanvasOwner* self,int unused,int parser,char* file,int available) {
 if(!file||!available)return;
 int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 CanvasTransfer transfer;
 unsigned size;
 char* owner;
 for(int i=0;i<count;++i) {
  char* block=ResourceFile_GetPayloadByIndex(file,i,&owner,&size);
  if(!block)continue;
  Graphics_InitializeCanvasTransferState((char*)&transfer);
  transfer.nibbles.SetLow(self->nibbles.GetLow());
  transfer.nibbles.SetHigh(self->nibbles.GetHigh());
  if(parser)Graphics_ParseTaggedLayerResource((char*)&transfer,block);
  else Graphics_DispatchResourceByFourByteMagic((unsigned char*)&transfer,block);
 }
}
