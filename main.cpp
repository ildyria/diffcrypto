#include <iostream>
#include <stdio.h>
#include <gmp.h>
#include <string>
#include "includes/typedef.h"
#include "includes/args.h"
#include "includes/cipher.h"
// #include "tools/prime_list.h"
#include "tools/big_int.h"
#include "tools/Timer.h"

#include "cipher/easy1.h"
#include "cipher/feal.h"
#include "cipher/des.h"

int main(int argc, char const *argv[])
{
	printf("\n \t \tIf it compiles then it works !\n");
	printf("\t But remember, all code is guilty until proven innocent !\n");
	printf("\t \tWhen in doubt, use Brute force ! - Ken Thompson\n \n");

	int arg = read_args(argc, argv);
	Timer t = Timer();
	t.start();
	switch(arg) {
		case 1:
			printf("Easy1\n");
			Crypto_tools::testCipher<Easy1>(0xf0f0f0f,3,0,0);
			break;

		case 2:
			printf("Feal\n");
			Crypto_tools::testCipher<Feal>(0x0123456789abcdef,8,0,0xCEEF2C86F2490752);
			Crypto_tools::testCipher<Feal>(0x0123456789abcdef,16,0,0x3ADE0D2AD84D0B6F);
			Crypto_tools::testCipher<Feal>(0x0123456789abcdef,32,0,0x69B0FAE6DDED6B0B);
			break;

		case 3:
			printf("Des\n");
			Crypto_tools::testCipher<Des>(0x133457799bbcdff1,16,0x0123456789abcdef,0x85E813540F0AB405);
			break;

		default:
			printf("Easy1\n");
			Crypto_tools::testCipher<Easy1>(0xf0f0f0f,3,0,0);
	}
	t.stop();
	printf("done in : %.3lf ms\n", t.resultmus()/1000.0);


	printf("------------------------------------------------------------\n");
	Cipher* device;
	switch(arg) {
		case 1:
			printf("Easy1\n");
			device = new Easy1(0xf0f0f0f,3);
			break;

		case 2:
			printf("Feal\n");
			device = new Feal(0x0123456789abcdef,8);
			break;

		case 3:
			printf("Des\n");
			device = new Des(0x133457799bbcdff1);
			break;

		default:
			device = new Easy1(0xf0f0f0f,3);
			printf("Easy1\n");
	}
	device->test();


	return 0;
}