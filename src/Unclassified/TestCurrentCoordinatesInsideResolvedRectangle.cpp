#include <globaldefs.h>
ARM
extern unsigned char data_02114e54[];extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);extern "C" unsigned char* FindReadyRecordByIdBeforeStopIndex(void*,unsigned);
// Original: arm9/main @ 0x0205DF38; symbol: func_0205df38; size: 0xD4.
extern "C" int TestCurrentCoordinatesInsideResolvedRectangle(unsigned char* object,unsigned key){int x,y;if(!*(int*)(object+0x98))return 0;if(!*(int*)(object+0x9c))return 0;if(data_02114e54[0x55]){ReadSelectedCoordinatePair(data_02114e54,&x,&y);unsigned char* rect=FindReadyRecordByIdBeforeStopIndex(object,key);if(rect){short left=*(short*)(rect+0xac),width=*(short*)(rect+0xa8),top=*(short*)(rect+0xae),height=*(short*)(rect+0xaa);short right=left+width,bottom=top+height;if(x>(short)(left<<3)&&x<(short)(right<<3)&&y>(short)(top<<3)&&y<(short)(bottom<<3))return 1;}}return 0;}
