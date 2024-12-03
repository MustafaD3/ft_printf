#include <stdio.h>
#include "ft_printf.h"
int main(){
    int *p = NULL;
int count = printf("AAAAAA%d%p%i%s%s%c\n",425,p,0,NULL,"etwtwet",'c');

int count2 = ft_printf("AAAAAA%d%p%i%s%s%c\n",425,p,0,NULL,"etwtwet",'c');
printf("%d %d",count,count2);
}