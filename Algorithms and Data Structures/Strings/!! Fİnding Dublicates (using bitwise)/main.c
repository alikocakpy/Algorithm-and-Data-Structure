#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
create uint64_t variable, this isn't hold negative space only hold memory for >=0 and 64 bit.

send this variable function.
this functions return type is same as variable
shift rigtht some variable
after take xor
after initilize itself
after take this steps and
return value



*/



uint64_t GrayToBinary32(uint64_t num){
	//num ^=num >>64;
	num ^=num >>32;
	num ^=num >>16;
	num ^=num >>8;
	num ^=num >>4;
	num ^=num >>2;
	num ^=num >>1;
	
	return num;
}


int main(int argc, char *argv[]) {
	uint64_t a=142563;
	a=GrayToBinary32(a);
	printf("%d",a);
	return 0;
}
