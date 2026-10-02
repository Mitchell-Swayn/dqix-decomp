#pragma once
#include "CountCache.h"

// These UI objects are owned by overlays 011/023; no field layout is assumed here.
struct CountMenuContext;
struct CountMenuEntry;
struct CountMenuEntries;

extern "C" {
CountMenuEntries* func_ov011_021849c8(CountMenuContext*);
CountMenuEntry* func_ov023_021f6880(CountMenuEntries*, int);
CountMenuEntry* func_ov023_021f6590(CountMenuContext*, int);
unsigned short func_ov023_021f6f08(CountMenuEntry*);
unsigned short func_ov023_021f6f10(CountMenuEntry*);
void func_ov004_02153978(CountMenuContext*, short*, short*, short*);
void func_ov004_021546c0(CountCache*, int, int, unsigned char*, unsigned char*);
void func_ov023_021f645c(CountMenuContext*, int, unsigned short, int);
void func_ov023_021f64a8(CountMenuContext*, int, int, int);
void func_ov004_021536e0(CountMenuContext*, int, int);
CountMenuEntry* func_ov004_02153944(CountMenuContext*, int);
void func_ov023_021f809c(CountMenuEntry*, CountMenuContext*);
int func_ov004_02154618(CountMenuContext*);
int func_ov004_02154748(CountMenuContext*);
}
