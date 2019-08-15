#include "includes/libft.h"




































#include <string.h>




#define F_INT(ptr) ((int)*((int*)ptr))
#define F_CHAR(ptr) ((int)*((int*)ptr))
#define F_CHARS(ptr) ((char*)ptr)

int main(int ac, char **av)
{ 
  /*
    ft_printf("argc = %d\n", ac);
    init_usage("a;pour le visu|p;test pour le p fdvovdfvfd|u;fonvfd vfdv dvfd vfd vfdvvffdvfd|");
    int i = init_flags(av, "juitpb|a { char* { 5, 8, *.cor}, int {5 , 88888} , int, char {8888,8888,r|f|p|*}} ;;|o;;|", "anima;a|", 0);
    print_flags();
    ft_printf("fdfddfdf");

    i = 0;
    ft_printf("\n\n[ici]\n");
    void *ptr = NULL;
    while ((ptr = get_flags_av('a', i++)))
    {
      //  ft_printf("ptr = %s\n", ptr);
        ft_printf("ptr = %d\n", F_INT(ptr));
    }
  */


    ft_printf("%s\n", strnequ(av[1], av[2][0], 100));
    ft_printf("%s\n", ft_strnequ(av[1], av[2][0], 100));








    return (0);
}

/*
    l{2, :int:, :char*:};j;o|

 */