#include <unistd.h>
#include "libft.h"

int main(void)
{
    write(1, "=== ft_putendl_fd ===\n\n", 24);

    ft_putendl_fd("Hello", 1);

    return (0);
}

/*
Expected Output Notes:
- Prints: Hello\n
*/