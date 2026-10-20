#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0209FFE0; symbol: func_0209ffe0; size: 0x1C.
void ScriptListContext_AppendResultId(short *p,short v){int count=p[52];if(count<50){p[52]=count+1;*(short *)((char *)(p+count)+0x6a)=v;}}
}
