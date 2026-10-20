extern "C" {
extern "C" void BestiaryDetail_DrawModelAndIndicators(void*);
// Original: arm9/ov014 @ 0x02186D64; symbol: func_ov014_02186d64; size: 0x18.
void BestiaryScreen_DrawMonsterDetails(unsigned char* p) { if(p[0x17a]==4) BestiaryDetail_DrawModelAndIndicators(p); }
}
