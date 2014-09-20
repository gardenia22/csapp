#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	int i;
	for (i = len-1;i >= 0;i--)
		printf("%.2x ",start[i]);
	printf("\n");
}
 
void show_unsigned(unsigned x) 
{
	show_bytes((byte_pointer) &x, sizeof(unsigned));
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_short(short x)
{
	show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x)
{
	show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x)
{
	show_bytes((byte_pointer) &x, sizeof(double));
}

int is_little_endian()
{
	int x = 1;
	byte_pointer start = (byte_pointer) &x;
	int y = (int) start[0];
	if (x==y) 
		return 1;
	else
		return 0;
}

void x_connect_y(int x, int y)
{
	int ans = y;
	byte_pointer start_ans = (byte_pointer) &ans;
	byte_pointer start_x = (byte_pointer) &x;
	start_ans[0] = start_x[0];
	show_int(x);
	show_int(y);
	show_int(ans);
}

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
	byte_pointer start = (byte_pointer) &x;
	start[i] = b;
	return x;
}
int main()
{
	int a = 100;
	printf("---2.57---\n");
	printf("show_short\n");
	show_short((short) a);
	printf("show_long\n");
	show_long((long) a);
	printf("show_double\n");
	show_double((double) a);
	printf("---2.58---\n");
	printf("is_little_endian\n");
	printf("%d\n",is_little_endian());
	printf("---2.59---\n");
	int x = 0x89ABCDEF,y = 0x76543210;
	x_connect_y(x,y);
	printf("---2.60---\n");
	show_unsigned(replace_byte(0x12345678,0xAB,2));
	show_unsigned(replace_byte(0x12345678,0xAB,0));
	return 0;
}
