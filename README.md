# ft_printf
[![Build Status](https://travis-ci.com/lgutter/ft_printf.svg?token=1XqUmANNphr1YCadgPKp&branch=master)](https://travis-ci.com/lgutter/ft_printf)
[![codecov](https://codecov.io/gh/lgutter/ft_printf/branch/master/graph/badge.svg?token=mIYsxaVIbL)](https://codecov.io/gh/lgutter/ft_printf)

[The project board for ft_printf](https://github.com/users/lgutter/projects/1)

## Make commands
### make (all)
compiles libft to .o files (unless already compiled), and compiles the **ft_printf.a** library.

### make test
Calls *all* and then it compiles the criterion tests into the **test** executable.

### make re
Calls *fclean* and then *all*

### make clean & make fclean
*Clean* cleans the repository of generated files, and *fclean* additionally removes compiled libraries and executables.

### make gcov
Generates *gcov* reports for all .c files of ft_printf.
