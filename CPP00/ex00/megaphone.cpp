#include <iostream>

int	main(int argc, char **argv)
{
    int i = 0;
    int j;

	if (argc >= 2)
    {
        while (++i < argc)
        {
            j = 0;
            while (argv[i][j] != '\0')
            {
                std::cout << (char)toupper(argv[i][j]);
                j++;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}