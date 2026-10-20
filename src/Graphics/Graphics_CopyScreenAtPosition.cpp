#include <globaldefs.h>
extern "C" void Graphics_CopyClippedTilemapRectangle(void*,void*,const short*,int,int,unsigned,unsigned,int,int,unsigned short);
// Original: arm9/main @ 0x0204B938; symbol: func_0204b938; size: 0x50.
extern "C" ARM void Graphics_CopyScreenAtPosition(char* owner,const short* position,unsigned first,unsigned second,unsigned short color){if(position){void* resource=*(void**)(owner+20);int x=position[0];int y=position[1];if(resource)Graphics_CopyClippedTilemapRectangle(owner,resource,position,0,0,first,second,x,y,color);}}
