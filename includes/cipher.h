#pragma once
#include <iostream>
#include <stdio.h>
#include "../includes/typedef.h"

class Cipher
{

protected:
	uint64 _key;
	uint64 _rounds;
	bool verbose = true;

public:
	Cipher(uint64 key, uint64 rounds) : _key(key), _rounds(rounds) {};

	virtual ~Cipher(){};

	virtual uint64 encrypt(uint64 b)
	{
		return b;
	};

	virtual uint64 decrypt(uint64 b)
	{
		return b;
	};

	virtual void print(uint64 b)
	{
		uint64 mask = 1;
		mask <<= 63;
		for (int i = 0; i < 64; ++i)
		{
			printf("%li", (mask & b) >> (63 - i));
			mask >>= 1;
		}
	};

	template<typename U> void inv_box(U* in, U* out, int num)
	{
		for (int i = 0; i < num; ++i)
		{
			out[in[i]] = i;
		}
	}
};