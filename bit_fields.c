#include<stdint.h>
#include<stdio.h>

typedef union Union_bitFields {
	
	struct S {
		uint8_t x:3;
		uint8_t y:7;
		uint8_t z:2;
	}my_struct;
	
	uint16_t val;

} Union_bitFields;

int main()
{
	Union_bitFields my_union;

	my_union.my_struct.z = 3;
	my_union.my_struct.x = 5;
	my_union.val = 0;

	printf("Size of the union is: %d\n", sizeof(my_union));
	printf ("Value of y in the union bit field is: %d\n", (int) my_union.my_struct.y);

	return 0;
}
