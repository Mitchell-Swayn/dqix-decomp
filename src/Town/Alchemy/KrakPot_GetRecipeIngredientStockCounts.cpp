#include <globaldefs.h>
ARM
struct Tables{short** keys;unsigned char** values;short* counts;};
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);
extern "C" char* ScriptRecordTable_FindById(void*,int);
// Original: arm9/ov006 @ 0x02153B9C; symbol: ResolveThreeLookupBytesAcrossNineKeyTables; size: 0xc4.
extern "C" void KrakPot_GetRecipeIngredientStockCounts(char* self,int key,unsigned char* output) {
 memset(output,0,3);char* record=ScriptRecordTable_FindById(P(self,0),key);if(!record)return;
 for(int table=0;table<9;table++){Tables* tables=(Tables*)(self+4);short* keys=tables->keys[table];unsigned char* values=tables->values[table];short count=tables->counts[table];for(short i=0;i<count;i++){int value=keys[i];if(value>0){if(value==H(record,4))output[0]=values[i];else if(value==H(record,6))output[1]=values[i];else if(value==H(record,8))output[2]=values[i];}}}
}
