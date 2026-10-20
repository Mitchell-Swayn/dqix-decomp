#pragma thumb off
#pragma optimization_level 4

extern "C" int Text_LowercaseASCIICharacter(int);
// Original: arm9/main @ 0x020D85DC; symbol: func_020d85dc; size: 0x78.
extern "C" bool String_HasCaseInsensitivePrefix(const char* text,const char* prefix){if(!text)return false;if(!prefix)return false;if(text==prefix)return true;while(*text && *prefix && Text_LowercaseASCIICharacter(*text)==Text_LowercaseASCIICharacter(*prefix)){++text;++prefix;}return *prefix==0;}
