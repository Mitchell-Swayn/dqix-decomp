#include <globaldefs.h>
ARM
struct Owner;struct Record;
extern "C" void* memset(void*,int,unsigned);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(Owner*,unsigned,void*,unsigned,unsigned char);
extern "C" Record* FindReadyRecordByIdBeforeStopIndex(Owner*,unsigned);
extern "C" void Graphics_AppendThreeIndexedTextFragments(unsigned char*,char*,int);
extern "C" void Graphics_AppendFlagAndSignedValueStatusPage(unsigned char*,char*,int);
// Original: arm9/ov003 @ 0x0216A974; symbol: func_ov003_0216a974; size: 0xB4.
extern "C" void Graphics_FormatAndReloadReadyTextRecord(unsigned char* p,unsigned id,int enabled){
 unsigned char* record=(unsigned char*)FindReadyRecordByIdBeforeStopIndex((Owner*)(p+0xe4),id);
 if(!record)return;
 if(enabled)record[0xc5]|=0x40;else record[0xc5]&=~0x40;
 int header=0;if(record[0xc5]&2)header=1;
 memset(*(void**)(p+0x7c),0,2400);
 switch(id){
 case 1:Graphics_AppendThreeIndexedTextFragments(p,*(char**)(p+0x7c),header);break;
 case 2:Graphics_AppendFlagAndSignedValueStatusPage(p,*(char**)(p+0x7c),header);break;
 }
 LoadMatchingReadyRecordAndRefreshOwner((Owner*)(p+0xe4),id,*(void**)(p+0x7c),1,0);
}
