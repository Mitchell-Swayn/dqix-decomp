#include <globaldefs.h>
ARM
extern "C" unsigned YssdClient_GetWorkspaceSize();
extern "C" int Network_GetYssdWorkerWorkspaceSize();
// Original: arm9/ov031 @ 0x02211410; symbol: func_ov031_02211410; size: 0x30.
extern "C" int YssdSession_GetWorkspaceSize() {
 unsigned size=0;
 size+=96;
 size+=((YssdClient_GetWorkspaceSize()+31)/32)*32;
 size+=(((unsigned)Network_GetYssdWorkerWorkspaceSize()+31)/32)*32;
 return size;
}
