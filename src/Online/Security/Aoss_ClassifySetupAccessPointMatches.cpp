#include <globaldefs.h>
THUMB
#pragma optimization_level 4
extern "C" unsigned Util_GetStringLength(const char*);
extern "C" int WirelessSetup_CompareIdentifierBytes(const void*,const void*,unsigned);
extern "C" char Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS[];
// Original: arm9/ov031 @ 0x0221D294; symbol: ClassifyMatchingFlaggedRecords; size: 0x7c.
// Counts flagged records matching the fixed string: returns5 for none,4 for multiple,0 for one.
extern "C" int Aoss_ClassifySetupAccessPointMatches(char* p){
 int result=0;int matches=0;unsigned count=*(unsigned*)p;
 if(!count)return 5;if(count>64)count=64;
 int i=0;if((int)count>0){char* bytes=p+8;
 do {
 if((*(unsigned*)(p+0x54)&1) && *(unsigned*)(p+4)==Util_GetStringLength(Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS)){
 if(!WirelessSetup_CompareIdentifierBytes(bytes,Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS,Util_GetStringLength(Aoss_ClassifySetupAccessPointMatches_TextESSIDAOSS)))matches++;
 }i++;p+=0x54;bytes+=0x54;}while(i<(int)count);
 }
 if(matches>1)result=4;if(matches==0)result=5;return result;
}
