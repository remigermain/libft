#include "includes/libft.h"

int main(int ac, char **av)
{
    usage_init("\"[souce file] ...file\"| \"ceci estr une testtttt\"| \"ceci estr une 55555\"| \"ceci estr une 44444444\"|");
    int ret = flag_init(av, ",d|flag2,t|flag3,|flag4,|yoyoy,l;set, set2, ;  unset,unset3, ;| flag8 , y (char*{5,9, \"fdfdfdfd\"}, int{,55}, size_t)|",  0);
    ft_printf("RET %d\n", ret);
    print_flags();
    flag_free();
    return (0);
}