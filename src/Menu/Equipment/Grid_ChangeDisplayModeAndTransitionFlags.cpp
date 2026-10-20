#include <globaldefs.h>
ARM
extern "C" void Grid_ConfigureSelectionForDisplayMode(char*);
// Original: arm9/ov005 @ 0x0215792C; symbol: func_ov005_0215792c; size: 0xC0.
extern "C" void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char* p,unsigned char mode){
p[0x3db9]=p[0x3db8];p[0x3db8]=mode;p[0x3dba]=0;
if(p[0x3db8]==0){p[0x3dbe]=p[0x3dbc];*(unsigned*)(p+0x3dcc)|=0x400;}else *(unsigned*)(p+0x3dcc)&=~0x400;
if(p[0x3db8]==0&&p[0x3db9]==1){p[0x3df0]=3;p[0x3df1]=30;p[0x3df2]=30;*(unsigned*)(p+0x3dcc)&=~0x1000;*(unsigned*)(p+0x3dcc)&=~0x2000;}
else if(p[0x3db9]==3){p[0x3df0]=0;*(unsigned*)(p+0x3dcc)&=~0x1000;}
if(p[0x3db8]==5||p[0x3db8]==1||p[0x3db8]==7)return;
Grid_ConfigureSelectionForDisplayMode((char*)p);
}
