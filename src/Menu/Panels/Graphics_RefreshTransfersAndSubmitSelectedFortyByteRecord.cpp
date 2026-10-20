#include <globaldefs.h>
ARM
extern "C" void Window_ClearResourceBuffers(void*);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov023 @ 0x021E761C; symbol: Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord; size: 0x8c.
// Refreshes active transfer records and submits selected forty-byte record with fixed position.
extern "C" void Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord(char* self) {
 if(!*(int*)(self+0x5dc))return;
 Window_ClearResourceBuffers(self+0x78);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(self+0x78);Graphics_ResetCountedThirtyTwoByteTransfers(self+0x78);
 if(*(int*)(self+0x3c)!=2)return;
 if(!*(void**)(self+0x604)||!*(void**)(self+0x608))return;
 char* record=*(char**)(self+0x608);int index;
 if(*(unsigned char*)(self+0x60d)){index=*(unsigned char*)(self+0x60c);record+=index*40;index+=3;}else{record+=80;index=5;}
 record[0x22]=index;*(int*)(record+0x14)=0xd0000;*(int*)(record+0x18)=0x10000;
 Graphics_SubmitTransformedCellToOam(*(void**)(self+0x604),record);
}
