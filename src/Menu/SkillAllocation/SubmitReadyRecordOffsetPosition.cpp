struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" bool TextCanvas_IsReady(int);
extern "C" unsigned ComputeIndexedEntryAddressAtStride40(void*,unsigned);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
#pragma always_inline on
inline void ScaleCoordinates(char* ready,short* x,short* y){*x=*(short*)(ready+0xac)*8;*y=*(short*)(ready+0xae)*8;}
inline void SetFixedPosition(char* entry,short x,short y){*(int*)(entry+20)=x*4096;*(int*)(entry+24)=y*4096;}
// Original: arm9/ov013 @ 0x02186DB4; symbol: func_ov013_02186db4; size: 0xC0.
// Sets and submits a ready display record using scaled coordinates and heading offset.
extern "C" void SubmitReadyRecordOffsetPosition(unsigned char* p){
 if(!*(void**)(p+24))return;
 char* ready=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(p+0x38)),4);if(!ready||!TextCanvas_IsReady((int)ready)||(*(unsigned char*)(ready+0xc5)&32))return;
 short index=42;if(p[0x640])index=32;
 char* entry=(char*)ComputeIndexedEntryAddressAtStride40(*(void**)(p+24),(unsigned short)index);if(!entry)return;
 short x=*(short*)(ready+0xac)*8;int baseY=*(short*)(ready+0xae);
 baseY*=8;x=(*(short*)(p+0x1e)+3)+x;short y=(short)baseY;y+=3;SetFixedPosition(entry,x,y);entry[0x26]=1;entry[0x22]=32;
 Graphics_SubmitTransformedCellToOam(*(void**)(p+24),entry);
}
