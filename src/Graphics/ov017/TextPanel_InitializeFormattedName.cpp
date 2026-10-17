#include <globaldefs.h>
ARM
struct Buffer;struct Object;
extern "C" void __clear(void*,unsigned);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void CopyBoundedNameToIndexedSlot(Buffer*,int,const char*);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
extern "C" void SetWordMaskBits_Main020466E4(unsigned*,unsigned);
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void SetNonnegativeValueAndClampSelection(int*,int);
extern "C" void ClearTwoBytesAndWriteThird(unsigned char*,unsigned char);
extern "C" void InitializeSelectionControlsAndTextBuffers(unsigned char*);
extern "C" void TextLayout_AppendConvertedLineAndUpdateWidths(char*,void*);
extern "C" void ComputeRowLayoutAndAlignedDimensions(Object*,int,short);
extern "C" void SaveContextProcessFadePredicateAndRestoreContext(char*);
extern "C" void* GetGlobalStatePointer();
extern "C" void* LookupGlobalResourceByKey(unsigned);
// Original: arm9/ov017 @ 0x021AFB8C; symbol: func_ov017_021afb8c; size: 0x160.
extern "C" void TextPanel_InitializeFormattedName(unsigned char* p,const unsigned char* input) {
 unsigned char name[0x30]; unsigned char text[0x64];
 if(p[2] && p[9]!=2) {
  void* buffer=(void*)ReadWordFieldAtOffset1C();
  __clear(name,sizeof(name));
  Text_MapInputBytesToVariableLengthOutputSequences(input,name,1);
  CopyBoundedNameToIndexedSlot((Buffer*)buffer,0,(char*)name);
  void* resource=LookupGlobalResourceByKey(0x24);
  ProcessSixStagesUsingSharedWordScratchBuffer(buffer,12,resource,text,256,0,1);
  InitializeSelectionControlsAndTextBuffers(p+0x48);
  Grid_SetOrientationAndCoordinatePointers(p+0x68,1,1,0);
  Grid_SetOrientationAndCoordinatePointers(p+0xb8,1,1,0);
  SetNonnegativeValueAndClampSelection((int*)(p+0x68),1);
  SetNonnegativeValueAndClampSelection((int*)(p+0xb8),1);
  TextLayout_AppendConvertedLineAndUpdateWidths((char*)p+0x48,text);
  *(short*)(p+0xfc)=12;
  *(short*)(p+0xfe)=64;
  ComputeRowLayoutAndAlignedDimensions((Object*)(p+0x48),0,-4);
  p[0x27c]=1;
  ClearTwoBytesAndWriteThird(p+0x4c,1);
  p[0x27b]=1;
  p[0x27c]=1;
  ClearTwoBytesAndWriteThird(p+0x4c,1);
  *(short*)(p+0xfc)=(256-*(short*)(p+0x100))/2;
  *(short*)(p+0xfe)=64;
  SaveContextProcessFadePredicateAndRestoreContext((char*)p+0x48);
  SetWordMaskBits_Main020466E4((unsigned*)GetGlobalStatePointer(),0x800000);
 }
}
