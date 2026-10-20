#include <globaldefs.h>
ARM
extern "C" void* Memory_AllocateSafe(unsigned);
extern "C" void* GetOrCopyDataBlock();
extern "C" void* Filesystem_ReadNextBufferedChunk();
extern "C" void* ModsDecoder_GetSampleClampTable();
extern "C" void* GetOrCopyFixedDecoderTable();
extern "C" void MIi_CpuClearFast(int,void*,unsigned);
extern "C" void VectorizedMemset(void*,int,unsigned);
// Original data: arm9/ov016 @ 0x2191d78; symbol: data_ov016_02191d78.
// Movie coefficient variable-length decoder lookup. A 12-bit lookahead indexes packed records: consumed bit count, magnitude, zero run and last-coefficient flag. Embedded decoder at 02199f14 extracts these four fields; escape paths at 02199e34/02199e88 add magnitude/run corrections from the trailing tables. Exact codec revision and original table names remain unknown.
// Initial values: hex 010001000100010001000100010001007c807c806c806c806c016c015c015c012b842b842b842b843b823b823b823b825b805b805b805b801b1a1b1a1b1a1b1a ...; full span in module reference.
// Observed span: 8448 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char InitializeModsStreamBuffers_MovieCoefficientVariableLengthDecoderLookup[];
struct Stream { virtual void Unknown0();virtual void Unknown4();virtual int Seek(unsigned);virtual int Read(void*,unsigned);unsigned unknown;unsigned position; inline unsigned GetPosition(){return position;} };
#define W(o) (*(unsigned*)(s+(o)))
#define H(o) (*(unsigned short*)(s+(o)))
#define IO (*(Stream**)s)
#define ARRAY(o) (*(unsigned**)(s+(o)))
// Original: arm9/ov016 @ 0x0218E800; symbol: func_ov016_0218e800; size: 0x5AC.
// Validates a MODSN2/3 stream header, allocates ring buffers, and reads initial payloads.
extern "C" int InitializeModsStreamBuffers(char* s,Stream* stream,unsigned capacity) {
 unsigned word;struct {unsigned short length;char tag[2];} chunk;
 IO=stream;W(0xd4)=stream->position;
 if(!IO->Read(s+4,48))return 0;
 if(s[4]!='M'||s[5]!='O'||s[6]!='D'||s[7]!='S'||s[8]!='N'||(s[9]!='2'&&s[9]!='3')||H(10)!=10)return 0;
 if(s[8]=='N'&&s[9]=='3') {
 do {if(!IO->Read(chunk.tag,2))return 0;if(!IO->Read(&chunk.length,2))return 0;if(!IO->Seek(IO->GetPosition()+((unsigned)chunk.length<<2)))return 0;}while(chunk.tag[0]!='H'||chunk.tag[1]!='E');
 }
 if(H(0x1c)!=0&&H(0x1c)!=1&&H(0x1c)!=2&&H(0x1c)!=3&&H(0x1c)!=4)return 0;
 W(0x34)=(unsigned)Memory_AllocateSafe(0x454);MIi_CpuClearFast(0,(void*)W(0x34),0x454);
 W(0x38)=(unsigned)GetOrCopyDataBlock();
 *(unsigned*)(W(0x34)+0x3c)=(unsigned)GetOrCopyFixedDecoderTable();
 *(unsigned*)(W(0x34)+0x40)=(unsigned)InitializeModsStreamBuffers_MovieCoefficientVariableLengthDecoderLookup;
 *(unsigned*)(W(0x34)+0x44)=(unsigned)ModsDecoder_GetSampleClampTable()+0x40;
 W(0x4c)=W(0x10);W(0x50)=W(0x14);W(0x54)=(unsigned)Filesystem_ReadNextBufferedChunk();
 *(unsigned*)(W(0x34)+4)=W(0x10);*(unsigned*)(W(0x34)+8)=W(0x14);
 if(W(0x10)>256)return 0;if(capacity<6)return 0;
 W(0xa8)=capacity;W(0x5c)=(unsigned)Memory_AllocateSafe(capacity*4);if(!W(0x5c))return 0;
 W(0x60)=(unsigned)Memory_AllocateSafe(W(0xa8)*4);if(!W(0x60))return 0;
 for(unsigned i=0;i<W(0xa8);++i){
 ARRAY(0x5c)[i]=(unsigned)Memory_AllocateSafe(W(0x14)<<8);if(!ARRAY(0x5c)[i])return 0;
 ARRAY(0x60)[i]=(unsigned)Memory_AllocateSafe((W(0x14)>>1)<<8);if(!ARRAY(0x60)[i])return 0;
 MIi_CpuClearFast(0,(void*)ARRAY(0x5c)[i],W(0x14)<<8);VectorizedMemset((void*)ARRAY(0x60)[i],128,(W(0x14)>>1)<<8);
 }
 W(0x64)=(unsigned)Memory_AllocateSafe(W(0xa8)*4);if(!W(0x64))return 0;
 W(0x98)=0;W(0xac)=0;for(int i=1;i<6;++i)((unsigned*)(s+0xac))[i]=W(0xa8)-i;
 W(0xc4)=0;W(0xa0)=0;W(0x9c)=0;
 for(int i=0;i<2;++i){((unsigned*)(s+0x70))[i]=(unsigned)Memory_AllocateSafe(W(0x24)+1024);if(!((unsigned*)(s+0x70))[i])return 0;}
 if(H(0x1c)!=0){W(0x58)=(unsigned)Memory_AllocateSafe(H(0x1e)*0x14f8);if(!W(0x58))return 0;MIi_CpuClearFast(0,(void*)W(0x58),H(0x1e)*0x14f8);}
 unsigned saved=IO->position;IO->Seek(W(0x2c)+W(0xd4));
 W(0x94)=(unsigned)Memory_AllocateSafe(W(0x30)*8);if(!IO->Read((void*)W(0x94),W(0x30)*8))return 0;IO->Seek(saved);
 if(H(0x1c)==1) {
 int i;unsigned saved2=IO->position;IO->Seek(W(0x28)+W(0xd4));
 for(i=0;i<H(0x1e);++i){if(!IO->Read((void*)(W(0x58)+i*0x14f8+0x8c0),0xc34))return 0;*(unsigned*)(W(0x58)+i*0x14f8+0x14f4)=2;}
 IO->Seek(saved2);
 }else if(H(0x1c)==2){for(int i=0;i<H(0x1e);++i)*(unsigned*)(W(0x58)+i*0x14f8+0x1cc)=2;}
 IO->Read(&word,4);W(0x78)=word>>14;W(0x88)=word&0x3fff;W(0x80)=0;IO->Read((void*)W(0x70),W(0x78)+4);W(0x90)=1;return 1;
}
