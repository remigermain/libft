#include "includes/libft.h"











































int main(int ac, char **av)
{
    ft_printf("argc = %d\n", ac);
    init_usage("a;pour le visu|p;test pour le p fdvovdfvfd|u;fonvfd vfdv dvfd vfd vfdvvffdvfd|");
    int i = init_flags(av, "juitpb|a{ char* {5,9, *.cor|bonjourfdcdcdc}, char {88,1, a|b|r|4}, int {55,99}, int {99, 554}};;|r{ char* {5,9, *.cor|bonjourfdcdcdc}, char {,, a|b|r|*|4}, int {55,99}, int {99, 554}};;|", "anima;a|", 0);
    ft_printf("ici");
    print_flags();
    return (0);
}

/*
    l{2, :int:, :char*:};j;o|

 */