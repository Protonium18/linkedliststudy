#include <stdio.h>

int main(void) {
	unsigned char* mallocarray = malloc(sizeof(int) * 8);

	int* ptrarray = mallocarray;

	ptrarray[0] = 5;
	ptrarray[1] = 258;


	for (int i = 0; i < 8; i++) {
		printf("%x\t", mallocarray[i]);
	}
	

	free(mallocarray);

}