#include <globaldefs.h>
#include <System/Cache.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
typedef unsigned undefined4; // Same scalar alias as the existing wave-count owner.
struct SNDBinaryFileHeader {char signature[4];unsigned short byteOrder,version;unsigned fileSize;unsigned short headerSize,dataBlocks;};
struct SNDBinaryBlockHeader {unsigned kind,size;};
struct SNDWaveArcLink;
struct SNDWaveArc {SNDBinaryFileHeader fileHeader;SNDBinaryBlockHeader blockHeader;SNDWaveArcLink* topLink;unsigned reserved[7];unsigned waveCount;unsigned waveOffset[0];};
extern "C" {
char* ResolveRelativeOrAbsoluteTablePointerUnderLock(char*,int);
unsigned SoundWaveArchive_GetWaveCount(int);
void SoundCommand_SetCachedIndexedWordUnderLock(unsigned char*,int,unsigned);
void* ResourceAllocator_AllocateTrackedAlignedBlock(unsigned char*,unsigned,unsigned,unsigned,unsigned);
void ResourceManager_ClearMatchingRangeAndSubmit(char*,int,void*,void*);
int Filesystem_ReadIndexedResourceRangeInChunks(unsigned,char*,int,unsigned);
}
// SDK C LoadSingleWave: ntrtwl/NitroSystem d636fb5d2b212e8736f09859fff447be2bd0ac85 libraries/snd/src/sndarc_loader.c.
// SNDWaveArc layout: ntrtwl/NitroSDK 9eec6c92c9d7bba9350732b11296ed16aab3a8bc include/nitro/snd/common/bank.h and data.h.
// Original: arm9/main @ 0x020BE53C; symbol: func_020be53c; size: 0xC8.
extern "C" int SoundArchive_LoadSingleWave(SNDWaveArc* waveArc,int waveNo,unsigned fileId,unsigned char* heap) {
 char* buffer;unsigned len,begin,end,waveCount;
 if(ResolveRelativeOrAbsoluteTablePointerUnderLock((char*)waveArc,waveNo)!=0)return 1;
 waveCount=SoundWaveArchive_GetWaveCount((int)waveArc);
 // Keep a header-relative word window so both adjacent offset loads share its base.
 unsigned* offsets=(unsigned*)waveArc+(waveArc->waveCount+waveNo);
 begin=offsets[sizeof(SNDWaveArc)/4];
 if(waveNo<waveCount-1)end=offsets[sizeof(SNDWaveArc)/4+1];
 else end=waveArc->fileHeader.fileSize;
 len=end-begin;
 if(heap==0)return 0;
 buffer=(char*)ResourceAllocator_AllocateTrackedAlignedBlock(heap,len+32,(unsigned)ResourceManager_ClearMatchingRangeAndSubmit,(unsigned)waveArc,(unsigned)waveNo);
 if(!buffer)return 0;
 if(Filesystem_ReadIndexedResourceRangeInChunks(fileId,buffer,(int)len,begin)!=len)return 0;
 CleanCacheRange(buffer,len);
 SoundCommand_SetCachedIndexedWordUnderLock((unsigned char*)waveArc,waveNo,(unsigned)buffer);
 return 1;
}
