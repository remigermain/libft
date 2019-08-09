#include "includes/libft.h"











































int main(int ac, char **av)
{
    ft_printf("argc = %d\n", ac);
    init_flags(av, "|A{char*,char,int{8, 88},uint{99, 554}};y;g|", "", 0);
    print_flags();
    return (0);
}

/*
    l{2, :int:, :char*:};j;o|

 */