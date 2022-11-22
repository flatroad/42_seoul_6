#include "so_long.h"

void	error_handle(int i, t_error errors)
{
	if (i == 0)
		error_write(errors.error0, errors.erint0);
	if (i == 1)
		error_write(errors.error1, errors.erint1);
	if (i == 2)
		error_write(errors.error2, errors.erint2);
	if (i == 3)
		error_write(errors.error3, errors.erint3);
	if (i == 4)
		error_write(errors.error4, errors.erint4);
	if (i == 5)
		error_write(errors.error5, errors.erint5);
	if (i == 6)
		error_write(errors.error6, errors.erint6);
	if (i == 7)
		error_write(errors.error7, errors.erint7);

}

void	error_handle_sb(int i, t_error_sb errors)
{
	if (i == 8)
		error_write(errors.error8, errors.erint8);
	if (i == 9)
		error_write(errors.error9, errors.erint9);
	if (i == 10)
		error_write(errors.error10, errors.erint10);
	if (i == 11)
		error_write(errors.error11, errors.erint11);
}

void	error_write(char *str, int num)
{
	write(2, str, num);
	exit(1);
}
