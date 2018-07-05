// -mllvm -fla quarkslab.c -o quarkslab.elf
// quarkslab.c -o quarkslab_org.elf
// source code taken from
// https://blog.quarkslab.com/deobfuscation-recovering-an-ollvm-protected-program.html
#include <stdio.h>
#include <stdlib.h>
unsigned int target_function(unsigned int n)
{
  unsigned int mod = n % 4;
  unsigned int result = 0;

  if (mod == 0) result = (n | 0xBAAAD0BF) * (2 ^ n);

  else if (mod == 1) result = (n & 0xBAAAD0BF) * (3 + n);

  else if (mod == 2) result = (n ^ 0xBAAAD0BF) * (4 | n);

  else result = (n + 0xBAAAD0BF) * (5 & n);

  return result;
}

int main(int argc, char **argv) {
	long input = strtoul(argv[1], 0, 0);
	unsigned int result = target_function(input);
	printf("%u\n", result);
	return 0;
}
