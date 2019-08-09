#include "includes/libft.h"











































int main(int ac, char **av)
{
    ft_printf("%d\n", ac);
    init_flags(av, "|A{20, char*, char, int  ,   int     };y;g|", "", 0);
    print_flags();
    return (0);
}

/*
    l{2, :int:, :char*:};j;o|

 */