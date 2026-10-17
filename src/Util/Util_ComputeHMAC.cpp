#include <globaldefs.h>
ARM
struct HashCallbacks { int digestSize,blockSize; void* context; unsigned char* digest; void (*init)(void*); void (*update)(void*,const void*,int); void (*finish)(void*,void*); };
// Original: arm9/main @ 0x020C0CD0; symbol: func_020c0cd0; size: 0x1B8.
extern "C" void Util_ComputeHMAC(void* output,const void* message,int messageLength,const unsigned char* key,int keyLength,HashCallbacks* hash) {
 unsigned char keyDigest[64];
 unsigned char inner[64];
 unsigned char outer[64];
 if(!output||!message||!messageLength||!key||!keyLength||!hash)return;
 if(keyLength>hash->blockSize) {
  hash->init(hash->context);
  hash->update(hash->context,key,keyLength);
  hash->finish(hash->context,keyDigest);
  keyLength=hash->digestSize;key=keyDigest;
 }
 int i;
 for(i=0;i<keyLength;i++)inner[i]=key[i]^0x36;
 for(;i<hash->blockSize;i++)inner[i]=0x36;
 hash->init(hash->context);
 hash->update(hash->context,inner,hash->blockSize);
 hash->update(hash->context,message,messageLength);
 hash->finish(hash->context,hash->digest);
 for(i=0;i<keyLength;i++)outer[i]=key[i]^0x5c;
 for(;i<hash->blockSize;i++)outer[i]=0x5c;
 hash->init(hash->context);
 hash->update(hash->context,outer,hash->blockSize);
 hash->update(hash->context,hash->digest,hash->digestSize);
 hash->finish(hash->context,output);
}
