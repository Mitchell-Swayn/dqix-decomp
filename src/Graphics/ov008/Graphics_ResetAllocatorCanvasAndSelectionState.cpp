#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN8Object3D10InitializeEv(void*);
void SetWordMaskBits_Main020466E4(unsigned*,unsigned);
void Graphics_InitializeCanvasTransferState(char*);
void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
void InitializeSelectionDefaultsAndByteFields(char*);
void InitializeRecordGridAndFlagDefaults(void*);
void ClearWordHalfwordAndByteRecord(unsigned*);
void InitializeStoredVectorsAndInterpolationDefaults(char*);
void* GetGlobalStatePointer();
void ClearRecordAndInvalidateTwoIndices(char*);
void func_ov008_02184598(void*);
void Selection_BuildEnabledOptionList(void*);
}
struct StateBits { char pad[0x4c]; unsigned first:9,other:23; char gap[0x8c]; unsigned second; };
inline StateBits* GetStateBits(unsigned char* p) { return (StateBits*)(p+0x7504); }
// Original: arm9/ov008 @ 0x021843F8; symbol: func_ov008_021843f8; size: 0x1A0.
extern "C" void Graphics_ResetAllocatorCanvasAndSelectionState(unsigned char* p) {
 SetWordMaskBits_Main020466E4((unsigned*)GetGlobalStatePointer(),15);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x14);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x28);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x3c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x50);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x64);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x78);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x8c);
 ClearRecordAndInvalidateTwoIndices((char*)p+0xa0);
 *(unsigned*)(p+0xb8)=0;
 ClearWordHalfwordAndByteRecord((unsigned*)(p+0xbc));
 Graphics_InitializeCanvasTransferState((char*)p+0xd0);
 Graphics_InitializeCanvasTransferState((char*)p+0xf0);
 Graphics_InitializeCanvasTransferState((char*)p+0x110);
 InitializeRecordGridAndFlagDefaults(p+0x130);
 for(int i=0;i<6;i++) TextCanvas_InitializeLayoutAndTransferDefaults(p+0x1ec+i*0xe0);
 *(unsigned*)(p+0x72c)=0;
 *(unsigned*)(p+0x730)=0;
 *(unsigned*)(p+0x734)=0;
 *(unsigned*)(p+0x738)=0;
 *(unsigned*)(p+0x73c)=0;
 *(unsigned*)(p+0x734)=0;
 InitializeSelectionDefaultsAndByteFields((char*)p+0x750);
 _ZN8Object3D10InitializeEv(p+0x790);
 InitializeStoredVectorsAndInterpolationDefaults((char*)p+0x83c);
 *(unsigned*)(p+0xb04)=0; *(unsigned*)(p+0xb08)=0; *(unsigned*)(p+0xb0c)=0;
 p[0xb10]=0;p[0xb11]=0;p[0xb12]=0;p[0xb13]=0;
 *(short*)(p+0xb14)=-1; *(short*)(p+0xb16)=-1;
 *(unsigned*)(p+0xb18)=0; *(unsigned*)(p+0xb1c)=0; *(unsigned*)(p+0xb20)=0; *(unsigned*)(p+0xb24)=0;
 p[0xb28]=0;p[0xb29]=0;p[0xb2a]=0;
 *(unsigned*)(p+0xb2c)=0; *(unsigned*)(p+0xb30)=0; *(unsigned*)(p+0xb34)=0; *(unsigned*)(p+0xb38)=0; *(unsigned*)(p+0xb3c)=0;
 func_ov008_02184598(p+0xb40);
 func_ov008_02184598(p+0xb44);
 StateBits* state=GetStateBits((unsigned char*)_ZN9GameState11GetInstanceEv());
 if(state->first!=0) *(unsigned*)(p+0xb18)|=0x2000;
 if((state->second>>23)!=0) *(unsigned*)(p+0xb18)|=4;
 Selection_BuildEnabledOptionList(p);
}
