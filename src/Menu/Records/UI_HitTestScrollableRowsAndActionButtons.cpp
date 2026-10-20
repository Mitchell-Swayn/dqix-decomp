#include <globaldefs.h>
ARM
struct GridSelection;
extern "C" int Grid_GetEntryCount(void*);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" int Grid_ComputeSelectedLinearIndex(int*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[],UI_HitTestScrollableRowsAndActionButtons_TextSake[];
// Original: arm9/ov008 @ 0x02186B18; symbol: func_ov008_02186b18; size: 0x1D4.
extern "C" int UI_HitTestScrollableRowsAndActionButtons(unsigned char* p,int x,int y) {
 if(!x||!y)return -1;
 int count=Grid_GetEntryCount(p+0x750);
 if(count>6)count=6;
 int i;
 for(i=0;i<count;i++) {
  int top=i*16+8;
  int bottom=top+16;
  if(y>top&&y<bottom&&x>16&&x<152)return i+p[0xb29];
 }
 i=*(unsigned*)(p+0xb18);
 if((i&16)&&*(signed char*)(p+0xb10)!=12) {
  if(x>=70&&x<82) {
   int first=p[0xb29];
   if(first && y>=0 && y<8) {
    p[0xb29]=first-1;
    int last=p[0xb29]+5;
    if(Grid_ComputeSelectedLinearIndex((int*)(p+0x750))>last)Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x750),last);
    return -1;
   }
   if((unsigned)first<2&&y>=104&&y<112) {
    if(first+6<p[0x74c])++p[0xb29];
    int begin=p[0xb29];
    if(Grid_ComputeSelectedLinearIndex((int*)(p+0x750))<begin)Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x750),begin);
    return -1;
   }
  }
 }
 if(y>96&&y<106&&x>199&&x<242)return -2;
 if(!(i&128)&&y>16&&y<96&&x>176&&x<208&&!(i&0x4000)) {
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,94,0);
  _ZN8Object3D18SetAnimationByNameEPKci(p+0x790,UI_HitTestScrollableRowsAndActionButtons_TextSake,0);
  *(unsigned*)(p+0xb18)|=0x4000;
 }
 return -1;
}
