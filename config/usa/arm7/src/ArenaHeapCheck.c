/* Validate allocated/free lists and return available payload bytes, or -1.
 * Diagnostics preserve original message addresses and line numbers; their
 * strings and formatter remain binary-owned. */
/* Blocks reserve a 0x20-byte header; size includes that header. Only the first
 * three header words participate in these list operations. */
typedef struct ArenaHeapBlock {
    struct ArenaHeapBlock *previous;
    struct ArenaHeapBlock *next;
    int size;
} ArenaHeapBlock;

typedef struct ArenaHeap {
    int size;
    ArenaHeapBlock *freeBlocks;
    ArenaHeapBlock *usedBlocks;
} ArenaHeap;

typedef struct ArenaHeapInfo {
    int currentHeap;
    int heapCount;
    void *arenaStart;
    void *arenaEnd;
    ArenaHeap *heaps;
} ArenaHeapInfo;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int state);
extern ArenaHeapInfo *ARM7_g_arenaHeapInfo[9];
extern void ARM7_HeapWarning(const char*,int);
extern const char ARM7_HeapCheckMessage0[];
#define FAIL0() { ARM7_HeapWarning(ARM7_HeapCheckMessage0, 1250); goto cleanup; }
extern const char ARM7_HeapCheckMessage1[];
#define FAIL1() { ARM7_HeapWarning(ARM7_HeapCheckMessage1, 1251); goto cleanup; }
extern const char ARM7_HeapCheckMessage2[];
#define FAIL2() { ARM7_HeapWarning(ARM7_HeapCheckMessage2, 1254); goto cleanup; }
extern const char ARM7_HeapCheckMessage3[];
#define FAIL3() { ARM7_HeapWarning(ARM7_HeapCheckMessage3, 1256); goto cleanup; }
extern const char ARM7_HeapCheckMessage4[];
#define FAIL4() { ARM7_HeapWarning(ARM7_HeapCheckMessage4, 1259); goto cleanup; }
extern const char ARM7_HeapCheckMessage5[];
#define FAIL5() { ARM7_HeapWarning(ARM7_HeapCheckMessage5, 1260); goto cleanup; }
extern const char ARM7_HeapCheckMessage6[];
#define FAIL6() { ARM7_HeapWarning(ARM7_HeapCheckMessage6, 1261); goto cleanup; }
extern const char ARM7_HeapCheckMessage7[];
#define FAIL7() { ARM7_HeapWarning(ARM7_HeapCheckMessage7, 1262); goto cleanup; }
extern const char ARM7_HeapCheckMessage8[];
#define FAIL8() { ARM7_HeapWarning(ARM7_HeapCheckMessage8, 1263); goto cleanup; }
extern const char ARM7_HeapCheckMessage9[];
#define FAIL9() { ARM7_HeapWarning(ARM7_HeapCheckMessage9, 1266); goto cleanup; }
extern const char ARM7_HeapCheckMessage10[];
#define FAIL10() { ARM7_HeapWarning(ARM7_HeapCheckMessage10, 1274); goto cleanup; }
#define FAIL11() { ARM7_HeapWarning(ARM7_HeapCheckMessage4, 1277); goto cleanup; }
#define FAIL12() { ARM7_HeapWarning(ARM7_HeapCheckMessage5, 1278); goto cleanup; }
#define FAIL13() { ARM7_HeapWarning(ARM7_HeapCheckMessage6, 1279); goto cleanup; }
#define FAIL14() { ARM7_HeapWarning(ARM7_HeapCheckMessage7, 1280); goto cleanup; }
#define FAIL15() { ARM7_HeapWarning(ARM7_HeapCheckMessage8, 1281); goto cleanup; }
extern const char ARM7_HeapCheckMessage16[];
#define FAIL16() { ARM7_HeapWarning(ARM7_HeapCheckMessage16, 1282); goto cleanup; }
#define FAIL17() { ARM7_HeapWarning(ARM7_HeapCheckMessage9, 1286); goto cleanup; }
extern const char ARM7_HeapCheckMessage18[];
#define FAIL18() { ARM7_HeapWarning(ARM7_HeapCheckMessage18, 1293); goto cleanup; }
int ARM7_CheckArenaHeap(int arena,int heap)
{
 int total=0;
 int freeSize=0;
 int result=-1;
 int state=ARM7_DisableIRQInterrupts();
 ArenaHeapInfo *info=ARM7_g_arenaHeapInfo[arena];
 ArenaHeap *desc;
 ArenaHeapBlock *used;
 ArenaHeapBlock *next;
 unsigned int size;
 ArenaHeapBlock *freeBlock;
 if(heap==-1)heap=info->currentHeap;
 if(!info->heaps)FAIL0();
 if(heap<0 || heap>=info->heapCount)FAIL1();
 desc=&info->heaps[heap];
 if(desc->size<0)FAIL2();
 used=desc->usedBlocks;
 if(used && used->previous)FAIL3();
 while(used){
  if((unsigned int)info->arenaStart>(unsigned int)used || (unsigned int)used>=(unsigned int)info->arenaEnd)FAIL4();
  if((unsigned int)used&31)FAIL5();
  if(used->next && used->next->previous!=used)FAIL6();
  if((unsigned int)used->size<64)FAIL7();
  if(used->size&31)FAIL8();
  total+=used->size;
  if(total<=0 || total>desc->size)FAIL9();
  used=used->next;
 }
 freeBlock=desc->freeBlocks;
 if(freeBlock && freeBlock->previous)FAIL10();
 while(freeBlock){

  if((unsigned int)info->arenaStart>(unsigned int)freeBlock || (unsigned int)freeBlock>=(unsigned int)info->arenaEnd)FAIL11();
  if((unsigned int)freeBlock&31)FAIL12();
  next=freeBlock->next;
  if(next && next->previous!=freeBlock)FAIL13();
  size=freeBlock->size;
  if(size<64)FAIL14();
  if(size&31)FAIL15();
  if(next && (char*)freeBlock+size>=(char*)next)FAIL16();
  total+=size;
  freeSize+=size-32;
  if(total<=0 || total>desc->size)FAIL17();
  freeBlock=next;
 }
 if(total==desc->size)result=freeSize;
 else FAIL18();
cleanup:
 ARM7_SetIRQInterruptState(state);
 return result;
}
