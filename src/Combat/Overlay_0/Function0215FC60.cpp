extern "C" int func_ov000_0215fc60(const void* object)
{
	const unsigned char* bytes = static_cast<const unsigned char*>(object);
	const unsigned short value = *reinterpret_cast<const unsigned short*>(bytes + 0x81FE);

	if (value == 0x320)
		return 1;
	if (value == 0x321)
		return 2;
	return 0;
}
