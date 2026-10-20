#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int Network_GetAssociationId();
// Original: arm9/main @ 0x0202C540; symbol: func_0202c540; size: 0x38.
bool Network_IsClientSession(unsigned int *p){unsigned int exists=*p!=0;if(exists)return Network_GetAssociationId()!=0;return false;}
}
