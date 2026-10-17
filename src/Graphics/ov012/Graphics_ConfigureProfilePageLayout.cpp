#include <globaldefs.h>
ARM
struct Layout { unsigned char id,width,height; signed char x,y; unsigned char a,b; };
extern "C" Layout data_ov012_0218b008[];
// Original: arm9/ov012 @ 0x021893B4; symbol: func_ov012_021893b4; size: 0x88.
extern "C" void Graphics_ConfigureProfilePageLayout(unsigned char* screen,unsigned int id,int column,int row) {
unsigned char* p=screen+0xac;
for(int i=0;data_ov012_0218b008[i].id!=255;++i){
Layout* layout=&data_ov012_0218b008[i];
if(layout->id==id){
p[0xb1]=layout->id;
*(short*)(p+0xa4)=column;*(short*)(p+0xa6)=row;
int height=layout->height; int width=layout->width;
*(short*)(p+0xa8)=width;*(short*)(p+0xaa)=height;
int y=layout->y; int x=layout->x;
*(short*)(p+0xa0)=x;*(short*)(p+0xa2)=y;
int b=layout->b; int a=layout->a;
*(short*)(p+0xac)=a;*(short*)(p+0xae)=b;
p[0xb5]=1;return;
}
}
}
