#include "includes/libft.h"

int main(int ac, char **av)
{
    init_usage("yoyoy, yoyoy,\"bonjour ca va\"| flag8, flag8, \"fdfdfdvfdvdfvfdvfd\"|");
    int ret = init_flags(av, "flag1, flag2, flag3, flag4,|yoyoy ;set, set2, ;  unset,unset3, ;| flag8 (char*{5,9, \"fdfdfdfd\"}, int{,55}, size_t) ;;;|", "", 0);
    ft_printf("RET %d\n", ret);
    print_flags();
    return (0);
}