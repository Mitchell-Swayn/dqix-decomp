#include <globaldefs.h>
ARM
struct Layout { unsigned char id,width,height; signed char x,y; unsigned char a,b; };
// Original data: arm9/ov012 @ 0x218b008; symbol: data_ov012_0218b008.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 010c0b1c0f0a10020c080b0a0a12030c0811120a10040c0a0f0a0a10050c060f130a10060c0806050a10071e100c060101081e1009060101091e10090601010a ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" Layout GraphicsConfigureProfilePageLayout_UnknownRoleDataReferences[];
// Original: arm9/ov012 @ 0x021893B4; symbol: func_ov012_021893b4; size: 0x88.
extern "C" void Graphics_ConfigureProfilePageLayout(unsigned char* screen,unsigned int id,int column,int row) {
unsigned char* p=screen+0xac;
for(int i=0;GraphicsConfigureProfilePageLayout_UnknownRoleDataReferences[i].id!=255;++i){
Layout* layout=&GraphicsConfigureProfilePageLayout_UnknownRoleDataReferences[i];
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
