#include <stdio.h>
#include "ft_printf.h"
int main(){
	int *p  = 0;
	int count2 = printf("printf %d %i %% % u % p %s %s %c %x %X %% ASDASD\n",255,255,543,(char *)0,"","asdd",'c',345252,345252);
	int count1 = ft_printf("rintff %d %i % % % u % p %s %s %c %x %X %% ASDASD\n",255,255,543,(char *)0,"","asdd",'c',345252,345252);
	printf("%d",count2);
}