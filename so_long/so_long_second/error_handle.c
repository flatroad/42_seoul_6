#include "so_long.h"

void	error_handle_file(int i, t_err_f err_f)
{
	if (i == 0)
		error_write(err_f.error0, err_f.erint0);
	if (i == 1)
		error_write(err_f.error1, err_f.erint1);
	if (i == 2)
		error_write(err_f.error2, err_f.erint2);
	if (i == 3)
		error_write(err_f.error3, err_f.erint3);
	if (i == 4)
		error_write(err_f.error4, err_f.erint4);
	if (i == 5)
		error_write(err_f.error5, err_f.erint5);
	if (i == 6)
		error_write(err_f.error6, err_f.erint6);
	if (i == 7)
		error_write(err_f.error7, err_f.erint7);

}

void	error_handle_content(int i, t_err_c err_c)
{
	if (i == 1)
		error_write(err_c.error1, err_c.erint1);
	if (i == 2)
		error_write(err_c.error2, err_c.erint2);
	if (i == 3)
		error_write(err_c.error3, err_c.erint3);
	if (i == 4)
		error_write(err_c.error4, err_c.erint4);
	if (i == 5)
		error_write(err_c.error5, err_c.erint5);
	if (i == 6)
		error_write(err_c.error6, err_c.erint6);
}

void	error_handle_queue(int i, t_err_c err_c)
{

}

void	error_write(char *str, int num)
{
	write(2, str, num);
	exit(1);
}
