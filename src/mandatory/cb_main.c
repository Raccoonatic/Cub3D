#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac != 2)
    {
       printf("Error\nInvalid number of arguments\n");
       return (1);
    }
    //just checking if the file in the parameter is a .cub or not 
    if(!ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
    {
        printf("Error\nPlease provide a .cub file\n");
        return (1);
    }
    //cheecking if the file can be opened
    if (open(av[1], O_RDONLY) == -1)
    {
        printf("Error\nCould't open thhhe file\n");
        return(1);
    }
    //i've put this check in the main but it is better to have a function for that. the main function is going to be 25+lines if we do everything here
}