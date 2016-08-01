#include<stdint.h>
#include<stdio.h>

#if 1
/*
 * Experiment 1: Some expriments on bit fields
 */
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
	my_union.val = 0xFF5;

	printf("Size of the union is: %d\n", sizeof(my_union));
	printf ("Value of y in the union bit field is: %d\n", (int) my_union.my_struct.x);

	return 0;
}

#endif


#if 0
/*
 * Experiment 2: Forced alignment.
 * A special unnamed bit field of size 0 is used to force alignment on next boundary.
 */

// A structure without forced alignment
struct test1
{
   unsigned int x: 5;
   unsigned int y: 8;
};

// A structure with forced alignment
struct test2
{
   unsigned int x: 5;
   unsigned int: 0;
   unsigned int y: 8;
};

int main()
{
   printf("Size of test1 is %d bytes\n", sizeof(struct test1));	//This will print 4.
   printf("Size of test2 is %d bytes\n", sizeof(struct test2)); // This will print 8

   return 0;
}

#endif

#if 0
/*
 * Experiment 3: Assigning out of range values to bit fields.
 * It is implementation defined to assign an out-of-range value to a bit field member.
 */

typedef struct test
{
   unsigned int x: 2;
   unsigned int y: 2;
   unsigned int z: 2;
}test;

int main()
{
   test t;
   t.x = 5;
   printf("%d", t.x);	//This will pring 1.
   return 0;
}

#endif
