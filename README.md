*This project has been created as part of the 42 curriculum by eel-kerc* 

## DESCRIPTION
This project is about reproducing the behavior of the printf fonction. It's about printing the following flags : **%c**, **%s**, **%p**, **%d**, **%i**, **%u**, **%x**, **%X**, **%%**; \
And for the bonus part printing with the following flags : **-**, **0**, **.**, **#**, , **+**. 

## INSTRUCTIONS
This project compile with the following command : ```cc *.c libftprintf.a``` . \
It has to be compile with a main.c which can be created to see how the function work. Here is a main example
```
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\nbytes : %i\n", ft_printf("Yooo la team %s, j'ai %i ans, voici mon pointer %p.", "comment ca va ?", 18, 800));
	printf("\nbytes : %i\n", printf("Yooo la team %s, j'ai %i ans, voici mon pointer %p.", "comment ca va ?", 18, 800));
}
```

## RESOURCES
Peer2peer
man 3 printf : https://man7.org/linux/man-pages/man3/printf.3.html \
man va_arg, va_start, va_end, va_list

## ALGORITHM
**Here is how my code work :** \
First I initialize a structure who will have the flags and other useful things like the lenght of flags and the lenght of the arg. \
Then I iterate the message until I found a % which mean there is a variable to print or until the end of file. \
When I see a %, I initialize the flags in my struct and get the type. \
With the type and the flags, I go to the function who will print the argument associated to the flags, with the flags.
