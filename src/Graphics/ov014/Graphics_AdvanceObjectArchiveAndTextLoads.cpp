#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Record { unsigned value;short index;unsigned short flags;};
struct Bits {unsigned char a:1,b:1,c:1,d:1,e:4;};
struct Info {unsigned a,b,c,d,e,f,g,h;};
extern "C" {
extern char data_ov014_021895d5[],data_ov014_021895ed[],data_ov014_02189603[],data_ov014_02189615[],data_ov014_0218962c[],data_ov014_0218963f[],data_ov014_02189652[],data_ov014_02189661[],data_ov014_02189668[],data_ov014_02189680[],data_ov014_02189686[],data_ov014_0218968c[];
void* _ZN16BackgroundLoader11GetInstanceEv();void __clear(void*,unsigned);int sprintf(char*,const char*,...);
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator5ResetEv(void*);void func_ov014_02188bfc(void*,void*,int);int func_ov014_02188c34(void*);void func_ov014_021845d4(Record*);void func_ov014_02184c08(void*);
void* Object_Clear16Bytes(void*);void RelocateFileTableAndSelectRecordByKey(void*,void*,void*,unsigned,short);unsigned char* ReadWordAtOffset8_Main02097238(void*);unsigned char* Object_FindFortyEightByteRecordByKeyCallback(void*,int);
void* Object_Clear4Bytes(void*);int InitializeResourceContextWhenInputsPresent(unsigned,unsigned,unsigned);unsigned* ForwardTwoArgumentLookup(void*,int);void* memset(void*,int,unsigned);void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
void* Object_ResetEmbeddedStateAndReturnSelf(void*);void ClearRecordAndInvalidateTwoIndices(void*);char* CopyIndexedSerializedStringToOutput(char*,int,int,int);
unsigned char* GameResources_GetInstance();int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(void*,const char*,void**,unsigned*,unsigned);void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(void*,void*,unsigned*);
void _ZN8Object3D10InitializeEv(void*);void _ZN8Object3D10EnableFlagEi(void*,int);void SnapshotBlockAndVolatileWordPair(void*);void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);void Object_InvokeSaveTextureImageVRAMState(void*);void ClearEightBytes(unsigned*);void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void*,Info*,int);void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*,const char*,int);
}
#define PTR(o) (*(unsigned char**)(self+(o)))
#define SH(o) (*(short*)(self+(o)))
#define UI(o) (*(unsigned*)(self+(o)))
// Original: arm9/ov014 @ 0x021850CC; symbol: func_ov014_021850cc; size: 0x740.
extern "C" void Graphics_AdvanceObjectArchiveAndTextLoads(unsigned char* self){
 if(!(self[0x81]&1))return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(self[0x7f]==0){
 char name[64]={0};char path[64]={0};
 if(((Bits*)(self+0x82))->c)SH(0x86)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov014_021895d5,0);
 _ZN13SafeAllocator5ResetEv(PTR(0x3c)+0x14);func_ov014_02188bfc(self+0x1c,PTR(0x3c)+0x14,*(short*)(PTR(0x48)+0x1a));
 SH(0x88)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov014_021895ed,data_ov014_02189603,0);
 sprintf(name,data_ov014_02189615,self[0x80]+1);sprintf(path,data_ov014_0218962c,self[0x80]+1);
 SH(0x8a)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,name,path,0);
 SH(0x8c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov014_0218963f,data_ov014_02189652,0);
 if(((Bits*)(self+0x82))->c&&PTR(0x48)&&PTR(0x50)){
 unsigned char* r=PTR(0x48);if(((Bits*)(r+0x13))->b&&*(unsigned*)(r+4)){
 sprintf(path,data_ov014_02189661,*(unsigned*)(r+4));SH(0x8e)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov014_02189668,path,0);
 }}self[0x7f]++;
 }else if(self[0x7f]==1){
 if(((Bits*)(self+0x82))->c){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,SH(0x86))){
 void* file;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,SH(0x86),&file,&length);
 if(file){short* keys=(short*)PTR(0x98);func_ov014_021845d4((Record*)(self+0x9c));void* allocator=PTR(0x3c);
 for(;*keys;keys++){
 _ZN13SafeAllocator5ResetEv(allocator);short key=*keys;Object_Clear16Bytes(self+0xc);RelocateFileTableAndSelectRecordByKey(self+0xc,allocator,file,length,key);
 unsigned char* r=ReadWordAtOffset8_Main02097238(self+0xc);
 if(SH(0xa0)<0||(r&&(*(unsigned*)r>UI(0x9c)||*(unsigned short*)(r+6)>*(unsigned short*)(self+0xa2)))){SH(0xa0)=key;UI(0x9c)=*(unsigned*)r;*(unsigned short*)(self+0xa2)=*(unsigned short*)(r+6);}
 }
 _ZN13SafeAllocator5ResetEv(allocator);short key=*(short*)(PTR(0x48)+0xc);Object_Clear16Bytes(self+0xc);RelocateFileTableAndSelectRecordByKey(self+0xc,allocator,file,length,key);ReadWordAtOffset8_Main02097238(self+0xc);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,SH(0x86));SH(0x86)=-1;self[0x7f]++;
 }
 }else self[0x7f]++;
 }
 if(self[0x7f]==2&&func_ov014_02188c34(self+0x1c))self[0x7f]++;
 if(self[0x7f]==3&&_ZN16BackgroundLoader13GetTaskStatusEi(loader,SH(0x88))){
 void* file;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,SH(0x88),&file,&length);
 if(file){unsigned char* r=Object_FindFortyEightByteRecordByKeyCallback(self+0xc,*(short*)(PTR(0x48)+0xc));if(r){
 unsigned context[3];Object_Clear4Bytes(context);InitializeResourceContextWhenInputsPresent((unsigned)context,(unsigned)file,length);
 unsigned* string=ForwardTwoArgumentLookup(context,*(short*)(r+8));if(string){memset(PTR(0x60),0,0x48);String_ReplaceBracketedNamesByRowColumnTable((signed char*)*string,(signed char*)PTR(0x60),1,0,0,0);}
 string=ForwardTwoArgumentLookup(context,*(short*)(r+10));if(string){memset(PTR(0x64),0,0x48);String_ReplaceBracketedNamesByRowColumnTable((signed char*)*string,(signed char*)PTR(0x64),1,0,0,0);}
 }}_ZN16BackgroundLoader10RemoveTaskEi(loader,SH(0x88));SH(0x88)=-1;self[0x7f]++;
 }
 if(self[0x7f]==4&&_ZN16BackgroundLoader13GetTaskStatusEi(loader,SH(0x8a))){
 void* file;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,SH(0x8a),&file,&length);
 if(file){unsigned context[6];Object_ResetEmbeddedStateAndReturnSelf(context);ClearRecordAndInvalidateTwoIndices(context);CopyIndexedSerializedStringToOutput((char*)PTR(0x68),(int)file,length,*(short*)(PTR(0x48)+0x1a));}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,SH(0x8a));SH(0x8a)=-1;self[0x7f]++;
 }
 if(self[0x7f]==6){if(!(self[0x81]&8)&&SH(0x8e)==-1){self[0x7f]=0;self[0x81]&=~9;}self[0x7f]++;}
 if(self[0x7f]==7){if(((Bits*)(self+0x82))->c){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,SH(0x8e)))return;self[0x81]&=~4;self[0x7f]++;}else self[0x7f]++;return;}
 else if(self[0x7f]==8){
 if(((Bits*)(self+0x82))->c){void* allocator=PTR(0x3c)+0x28;_ZN13SafeAllocator5ResetEv(allocator);
 void* file;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,SH(0x8e),&file,&length);
 if(file){unsigned char* resources=GameResources_GetInstance();void* found;unsigned foundLength;
 if(_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(file,data_ov014_02189680,&found,&foundLength,1)){
 unsigned size1;void* archive1=_Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(allocator,found,&size1);
 if(_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(file,data_ov014_02189686,&found,&foundLength,1)){
 unsigned size2;void* archive2=_Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(allocator,found,&size2);
 void* config;unsigned configLength;
 if(_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(file,data_ov014_0218968c,&config,&configLength,1)){
 _ZN8Object3D10InitializeEv(PTR(0x40));*(short*)(PTR(0x40)+2)=*(short*)(PTR(0x48)+0xc);_ZN8Object3D10EnableFlagEi(PTR(0x40),4);
 SnapshotBlockAndVolatileWordPair(resources+0x2cc);Graphics_RestoreTextureImageAndPaletteVRAMState(resources+0x2cc);
 Info info;ClearEightBytes((unsigned*)&info);info.b=(unsigned)archive1;info.d=(unsigned)allocator;info.c=size1;
 _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(PTR(0x40),&info,0);
 Object_InvokeSaveTextureImageVRAMState(resources+0x2cc);ClearEightBytes((unsigned*)&info);info.d=(unsigned)allocator;info.b=(unsigned)archive2;info.c=size2;
 _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(PTR(0x40),&info,0);
 func_ov014_02184c08(self);UI(0x74)=0;unsigned char* r=Object_FindFortyEightByteRecordByKeyCallback(self+0xc,*(short*)(PTR(0x48)+0xc));if(r)_ZN8Object3D24MaybeSetRegularAnimationEPKci(PTR(0x40),**(const char***)(r+0x2c),0);self[0x81]|=4;
 }}}
 }_ZN16BackgroundLoader10RemoveTaskEi(loader,SH(0x8e));SH(0x8e)=-1;
 }
 self[0x7f]=0;self[0x81]&=~9;if(((Bits*)(self+0x82))->d)self[0x82]&=~8;self[0x94]=self[0x93];self[0x93]=0;
 }
}
