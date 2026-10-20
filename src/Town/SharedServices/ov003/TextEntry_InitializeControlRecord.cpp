#include <globaldefs.h>
ARM
struct StatusRecord{unsigned short first,second;unsigned words[2];unsigned char status[4];short index;};
// Original: arm9/ov003 @ 0x0215E498; symbol: TextEntry_InitializeControlRecord; size: 0x30.
// Clears the observed halfwords, words and four status bytes; invalidates index.
extern "C" void TextEntry_InitializeControlRecord(StatusRecord* record){
 record->second=0;record->first=0;
 record->words[0]=0;record->words[1]=0;
 record->status[0]=0;record->status[1]=0;record->status[2]=0;record->status[3]=0;
 record->index=-1;
}
