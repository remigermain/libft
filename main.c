#include "includes/libft.h"









































#define F_INT(ptr) ((int)*((int*)ptr))
#define F_CHAR(ptr) ((int)*((int*)ptr))
#define F_CHARS(ptr) ((char*)ptr)

int main(int ac, char **av)
{ 
    ft_printf("argc = %d\n", ac);
    init_usage("a;pour le visu|p;test pour le p fdvovdfvfd|u;fonvfd vfdv dvfd vfd vfdvvffdvfd|");
    int i = init_flags(av, "juitpb|a{ char* , int, int, int};;|r{ char* {5,9, *.cor|bonjourfdcdcdc}, char {,, a|b|r|*|4}, int {55,99}, int {99, 554}};;|", "anima;a|", 0);
    print_flags();

    i = 0;
    ft_printf("\n\n[ici]\n");
    void *ptr = NULL;
    while ((ptr = get_flags_av('a', i++)))
    {
      //  ft_printf("ptr = %s\n", ptr);
        ft_printf("ptr = %d\n", F_INT(ptr));
    }
    return (0);
}

/*
    l{2, :int:, :char*:};j;o|

 */