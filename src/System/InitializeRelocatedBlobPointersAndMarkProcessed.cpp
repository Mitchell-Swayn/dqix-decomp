extern "C" void* memcpy(void*,const void*,unsigned);
#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C"{int ResourceHandle_ShouldDeferSequenceArchiveEntry(void*);void* ResourceManager_ExchangeGlobalValue(void*);int NNS_SndArcPlayerStartSeqArc(void*,int,int);void Text_ParseDelimitedSignedIntegerSequence(void*,void*,int);char* TextContext_GetSharedInstance();void* func_02001a40(void*,const void*,unsigned);unsigned ResourceStringTable_GetEntryStorageSize(void*);void ResourceStringTable_VisitEntries(void*,int);void System_PushInterruptFourEnabledStateAndDisable(void*);void Interrupts_UpdateTimerOneFromShiftingGlobalMask();void Network_CopyDiscoveredPeerDescriptor(void*,const void*);char* Graphics_GetCellBankOAMArrayHead(void*);char* NNS_G2dGetCellDataByIdx(void*,int);void ResourceRecord_InitializeEmbeddedOffset8State(void*);void TextCanvas_ClearGroupEntrySelection(void*);char* DisplayLayout_FindGroupById(void*,int);char* DisplayLayout_FindPartById(void*,int);void TextCanvas_CreateAndConfigureDisplayPart(void*,int);}
#pragma force_active on
// Original: arm9/main @ 0x020E0280; symbol: func_020e0280; size: 0x90.
extern "C" int InitializeRelocatedBlobPointersAndMarkProcessed(char* p,char* blob,unsigned char* changed,int mode){*changed=0;if(!blob)return 0;memcpy(p,blob,4);*(char**)(p+4)=blob+4;*(char**)(p+8)=blob+(ResourceStringTable_GetEntryStorageSize(p)+4);if(*(unsigned*)p>>31){*changed=1;return 1;}ResourceStringTable_VisitEntries(p,mode);*(unsigned*)p=(*(unsigned*)p&0x7fffffff)|0x80000000;*(unsigned*)blob=(*(unsigned*)blob&0x7fffffff)|0x80000000;return 1;}
