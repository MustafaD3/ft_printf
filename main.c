#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
int main(){
	int *p  = 0;
	int count2 = printf("printf %d %i %% %u %p %s %s %c %x %X %% ASDASD\n",INT_MIN,INT_MAX,0,32,"","asdd",'c',0,0);
	int count1 = ft_printf("rintff %d %i %% %u %p %s %s %c %x %X %% ASDASD\n",INT_MIN,INT_MAX,0,32,"","asdd",'c',0,0);

}