#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int ReadElement0At021015A0();
// Original: arm9/main @ 0x0202C540; symbol: func_0202c540; size: 0x38.
bool TestActiveWordAndGlobalStateNonzero(unsigned int *p){unsigned int exists=*p!=0;if(exists)return ReadElement0At021015A0()!=0;return false;}
}
