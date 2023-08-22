#include "main.h"

int main() {

	wchar_t name[] = L"Let's try to printf a simple sentence.!\n";
	wint_t emma = 35;
	wprintf(L"x = %d \n", emma);
	wprintf(L"Length: [%d, %i]\n", name, emma);
	return (0);
}
