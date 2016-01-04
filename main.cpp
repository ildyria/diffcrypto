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


	Cipher* device;
	switch(read_args(argc, argv)) {
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
			// device = new Des(0x8000000000000000);
			device = new Des(0x133457799bbcdff1);
			// device = new Des(0x0123456789abcdef);
			// 
			break;

		default:
			device = new Easy1(0xf0f0f0f,3);
			printf("Easy1\n");
	}
	
	Timer t = Timer();
	t.start();
	printf("result : \n");
	auto cipher = device->encrypt(0);
	printf("result of encrypt :\n");
	device->print(cipher);
	printf("====================\n");
	auto decrypt = device->decrypt(cipher);
	printf("result of decrypt :\n");
	device->print(decrypt);
	printf("\n");

	device->test();

	t.stop();

	printf("done in : %.3lf ms\n", t.resultmus()/1000.0);

	return 0;
}