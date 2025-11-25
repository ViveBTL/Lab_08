#include "header.hpp"


char* CopyString(const char* str) {
	int size = 0;
	while(str[size] != '\0' && str[size] != '\n')
		size++;
	char* new_str = new char[size + 1];
	memcpy(new_str, str, size + 1);
	return new_str;
}


char* ConcatinateStrings(const char* a, const char* b) {
	int sizea = 0;
	while (a[sizea] != '\0' && a[sizea] != '\n')
		sizea++;
	int sizeb = 0;
	while (b[sizeb] != '\0' && b[sizeb] != '\n')
		sizeb++;
	char* new_str = new char[sizea + sizeb + 1];
	memcpy(new_str, a, sizea);
	memcpy(new_str + sizea, b, sizeb + 1);	
	return new_str;
}