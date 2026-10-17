#include <globaldefs.h>
ARM
extern "C" unsigned char* ReadWordFieldAtOffset1C(void*);extern "C" void Object_SetWordAtOffset1E20(void*,void*);extern "C" void PointField1E20AtEmbedded914(void*);
// Original: arm9/main @ 0x0205CE94; symbol: func_0205ce94; size: 0x38.
extern "C" void SaveContextClearLinkedWordFieldEightAndRestoreContext(unsigned char* p){unsigned char* q=ReadWordFieldAtOffset1C(p);Object_SetWordAtOffset1E20(q,p+180);unsigned* obj=*(unsigned**)(q+0x1e20);if(obj)obj[2]=0;PointField1E20AtEmbedded914(q);}
