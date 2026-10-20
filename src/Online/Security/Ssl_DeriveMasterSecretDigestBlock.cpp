#include <globaldefs.h>
ARM
extern "C" unsigned strlen(const char*);
extern "C" void Crypto_InitializeSha1Context(void*);
extern "C" void Crypto_UpdateSha1Context(void*,const void*,unsigned);
extern "C" void Crypto_TransformAndSerializeBlockWords(void*,void*);
extern "C" void Ssl_InitializeMd5Context(void*);
extern "C" void Util_Update64ByteBlockHash(void*,const void*,unsigned);
extern "C" void System_ExpandEncodedBufferHeaderAndPayload(void*,void*);
// Original: arm9/ov031 @ 0x02208E54; symbol: BuildNestedSha1AndFourWordDigest; size: 0x9c.
// Hashes text and context blocks with SHA1, feeds digest into four-word hash and writes output.
extern "C" void Ssl_DeriveMasterSecretDigestBlock(void* out,const char* text,char* context){
 unsigned digest[5];Crypto_InitializeSha1Context(context+0x348);
 Crypto_UpdateSha1Context(context+0x348,text,strlen(text));Crypto_UpdateSha1Context(context+0x348,context,0x30);Crypto_UpdateSha1Context(context+0x348,context+0x34,0x40);
 Crypto_TransformAndSerializeBlockWords(context+0x348,digest);Ssl_InitializeMd5Context(context+0x3fc);
 Util_Update64ByteBlockHash(context+0x3fc,context,0x30);Util_Update64ByteBlockHash(context+0x3fc,digest,20);System_ExpandEncodedBufferHeaderAndPayload(context+0x3fc,out);
}
