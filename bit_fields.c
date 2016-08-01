#include<stdint.h>
#include<stdio.h>

union Union_bitFields {
	
	struct S {
		uint8_t x:3;
		uint8_t y:7;
		uint8_t z:2;
	}my_struct;
	
	uint16_t val;
};

int main()
{
	union Union_bitFields my_union;

	my_union.my_struct.z = 3;
	my_union.val = 0;

	printf ("%d\n", (int) my_union.my_struct.z);

	return 0;
}
