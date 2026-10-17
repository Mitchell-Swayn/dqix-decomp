#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *ReadWordFieldAtOffset1C();void Object_SetWordAtOffset1E20(char *,void *);int Object_TestNestedOffset440StateEqualsTwo(void *);void InitializeIndirectField440State(void *);void PointField1E20AtEmbedded914(void *);
// Original: arm9/main @ 0x0205CD28; symbol: func_0205cd28; size: 0x44.
void SaveContextProcessFadePredicateAndRestoreContext(char *p){char *q=ReadWordFieldAtOffset1C();Object_SetWordAtOffset1E20(q,p+0xb4);if(!Object_TestNestedOffset440StateEqualsTwo(q+0x19e0))InitializeIndirectField440State(q+0x19e0);PointField1E20AtEmbedded914(q);}
}
