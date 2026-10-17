#include <globaldefs.h>
ARM
extern "C" void Object_ReadSelectedPartXYHalfwords(char*,int,short*,short*);
extern "C" void WriteResolvedHalfwordPair6And8(char*,int,int,int);
extern "C" void SetKeyedRecordTwoHalfwordFields(unsigned char*,int,int,int);
extern "C" short data_ov003_0217f420[];
// Original: arm9/ov003 @ 0x02160794; symbol: func_ov003_02160794; size: 0xC0.
extern "C" void Graphics_UpdateFourPartsInSelectedGroup(unsigned char* p){
 short x,y;
 if(!*(void**)(p+0x470))return;
 char* object=*(char**)(p+0x324);
 for(int i=0;i<3;i++){
 short index=data_ov003_0217f420[i];
 int selected=**(short**)(p+0x470);
 if(index>selected || selected>=index+4)continue;
 for(int j=0;j<4;j++){
 Object_ReadSelectedPartXYHalfwords(object,index,&x,&y);
 WriteResolvedHalfwordPair6And8(object,index,x,y);
 SetKeyedRecordTwoHalfwordFields((unsigned char*)object,index,208,10);
 index++;
 }
 }
}
