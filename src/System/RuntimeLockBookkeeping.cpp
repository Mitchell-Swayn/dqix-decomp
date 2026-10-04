#include "System/RuntimeState.h"

// Nine owner/count slots; exit uses slot 0, signal dispatch uses slot 7.
unsigned int data_020f2f70[9];
unsigned int data_020f2f94[9];
