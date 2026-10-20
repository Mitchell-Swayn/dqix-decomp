#include <globaldefs.h>
ARM
struct State;
extern "C" {
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void Graphics_InitializeCanvasTransferState(char*);
void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
void TextLayout_InitializeSelectionPanel(unsigned char*);
void Selection_InitializeDisplayController(State*);
void Graphics_CacheFourMainBackgroundControlsOnce(volatile State*);
void Graphics_SnapshotSubBackgroundControlRegistersOnce(State*);
void ResourceStringLoader_Reset(char*);
}
struct Block80 {unsigned v[20];};struct Block64{unsigned v[16];};
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define W(p,o) (*(unsigned*)((p)+(o)))
// Original: arm9/ov013 @ 0x02184360; symbol: func_ov013_02184360; size: 0x340.
extern "C" void Graphics_InitializeTextCanvasPanel(char* p,char* source){
B(p,0x30)=0;B(p,0x31)=0;(*(volatile bool*)(p+0x640))=source!=0;
if((*(volatile bool*)(p+0x640))){Graphics_SnapshotSubBackgroundControlRegistersOnce((State*)(p+0x20));W(p,0x34)=(*(volatile unsigned*)0x4001000&0x1f00)>>8;}
else{Graphics_CacheFourMainBackgroundControlsOnce((State*)(p+0x20));W(p,0x34)=(*(volatile unsigned*)0x4000000&0x1f00)>>8;*(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x100;}
Selection_InitializeDisplayController((State*)(p+0x38));TextLayout_InitializeSelectionPanel((unsigned char*)p+0x3d4);
if((*(volatile bool*)(p+0x640))){char* q=source+0x188;*(Block80*)(p+0x3c)=*(Block80*)(q+4);*(Block64*)(p+0x8c)=*(Block64*)(q+0x54);
B(p,204)=B(q,148);
B(p,205)=B(q,149);
B(p,206)=B(q,150);
B(p,207)=B(q,151);
W(p,208)=W(q,152);
W(p,212)=W(q,156);
H(p,216)=H(q,160);
H(p,218)=H(q,162);
H(p,220)=H(q,164);
H(p,222)=H(q,166);
H(p,224)=H(q,168);
H(p,226)=H(q,170);
H(p,228)=H(q,172);
H(p,230)=H(q,174);
B(p,232)=B(q,176);
B(p,233)=B(q,177);
B(p,234)=B(q,178);
B(p,235)=B(q,179);
B(p,236)=B(q,180);
B(p,237)=B(q,181);
B(p,238)=B(q,182);
B(p,239)=B(q,183);
B(p,240)=B(q,184);
B(p,241)=B(q,185);
B(p,242)=B(q,186);
B(p,243)=B(q,187);
}
for(int i=0;i<2;i++)Graphics_InitializeCanvasTransferState(p+0xf4+i*32);
for(int i=0;i<3;i++)TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)p+0x134+i*0xe0);
_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x60c);ResourceStringLoader_Reset(p+0x620);_ZN13SafeAllocator21ResetAllocatorPointerEv(p);
for(int i=0;i<3;i++)B(p+i,0x638)=0;
W(p,0x14)=0;W(p,0x18)=0;H(p,0x1c)=255;H(p,0x1e)=0;
B(p,1596)=0;
B(p,1597)=0;
B(p,1598)=0;
B(p,1599)=0;
W(p,1604)=0;
W(p,1608)=0;
W(p,1612)=0;
W(p,1628)=0;
W(p,1632)=0;
B(p,1636)=0;
B(p,1637)=0;
W(p,1640)=0;
W(p,1644)=0;
W(p,1648)=0;
W(p,1712)=0;
B(p,1716)=0;
W(p,1624)=0;
W(p,1700)=0;
B(p,1704)=0;
B(p,1724)=0;
W(p,1720)=0;
H(p,1726)=0;
H(p,1728)=0;
H(p,1730)=0;
H(p,1732)=0;
H(p,1734)=0;
H(p,1736)=0;
H(p,1738)=0;
for(int i=0;i<5;i++)W(p+i*4,0x674)=0;
for(int i=0;i<5;i++)W(p+i*4,0x688)=0;
for(int i=0;i<5;i++)B(p+i,0x69c)=1;
W(p,0x654)=(*(volatile bool*)(p+0x640))?W(source,0x178):0;
for(int i=0;i<5;i++)B(p+i,0x6a9)=0;
}
