#pragma once

// SDK hardware classification flags. This release returns a fixed value;
// it does not probe hardware even though callers inspect its low bits.
unsigned int GetConsoleType();
extern unsigned int g_consoleType;
