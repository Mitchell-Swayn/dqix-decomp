#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" {void UpdateSlotValueThroughResolver();void InitializeRelocatedBlobPointersAndMarkProcessed(void*,int,void*,void(*)());char* RecordLookup_GetSecondWordOfFoundEntry(void*,int);
// Original: arm9/main @ 0x020E046C; symbol: func_020e046c; size: 0x88.
char* CopyIndexedSerializedStringToOutput(char* out,int input,int unused,int index){if(!out||!input||!unused||index<0)return 0;unsigned char spare[4];unsigned char state[12];memset(state,0,12);InitializeRelocatedBlobPointersAndMarkProcessed(state,input,spare,UpdateSlotValueThroughResolver);char* src=RecordLookup_GetSecondWordOfFoundEntry(state,index);if(!src){*out=0;return 0;}strcpy(out,src);return out;}}
