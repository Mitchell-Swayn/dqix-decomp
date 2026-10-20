#include "System/ConsoleType.h"

unsigned int g_consoleType = 0xffffffff;

// USA: 0x020c7dcc
// Original: arm9/main @ 0x020C7DCC; symbol: _Z14GetConsoleTypev; size: 0x18.
unsigned int GetConsoleType()
{
    g_consoleType = 0x82000001;
    return 0x82000001;
}
