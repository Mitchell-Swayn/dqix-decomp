#include <globaldefs.h>
ARM
struct Buffer;struct Object;
extern "C" void __clear(void*,unsigned);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void TextContext_SetStringArgument(Buffer*,int,const char*);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
extern "C" void TextLayout_ResetPanelControlCountersAndSetMode(unsigned char*,unsigned char);
extern "C" void TextLayout_InitializeSelectionPanel(unsigned char*);
extern "C" void TextLayout_AppendConvertedLineAndUpdateWidths(char*,void*);
extern "C" void TextLayout_ComputeSelectionPanelBounds(Object*,int,short);
extern "C" void TextLayout_StartPanelOpening(char*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void* Text_LookupStandardString(unsigned);
// Original: arm9/ov017 @ 0x021AFB8C; symbol: func_ov017_021afb8c; size: 0x160.
extern "C" void TextPanel_InitializeFormattedName(unsigned char* p,const unsigned char* input) {
 unsigned char name[0x30]; unsigned char text[0x64];
 if(p[2] && p[9]!=2) {
  void* buffer=(void*)TextContext_GetSharedInstance();
  __clear(name,sizeof(name));
  Text_MapInputBytesToVariableLengthOutputSequences(input,name,1);
  TextContext_SetStringArgument((Buffer*)buffer,0,(char*)name);
  void* resource=Text_LookupStandardString(0x24);
  TextMarkup_ExpandAndWrapText(buffer,12,resource,text,256,0,1);
  TextLayout_InitializeSelectionPanel(p+0x48);
  Grid_SetOrientationAndCoordinatePointers(p+0x68,1,1,0);
  Grid_SetOrientationAndCoordinatePointers(p+0xb8,1,1,0);
  Grid_SetEntryCountAndClampSelection((int*)(p+0x68),1);
  Grid_SetEntryCountAndClampSelection((int*)(p+0xb8),1);
  TextLayout_AppendConvertedLineAndUpdateWidths((char*)p+0x48,text);
  *(short*)(p+0xfc)=12;
  *(short*)(p+0xfe)=64;
  TextLayout_ComputeSelectionPanelBounds((Object*)(p+0x48),0,-4);
  p[0x27c]=1;
  TextLayout_ResetPanelControlCountersAndSetMode(p+0x4c,1);
  p[0x27b]=1;
  p[0x27c]=1;
  TextLayout_ResetPanelControlCountersAndSetMode(p+0x4c,1);
  *(short*)(p+0xfc)=(256-*(short*)(p+0x100))/2;
  *(short*)(p+0xfe)=64;
  TextLayout_StartPanelOpening((char*)p+0x48);
  SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(),0x800000);
 }
}
