#include "shell.h"

/**
 * custom exit - exit the shell
 * @info:structure containing arguments,used to mantain function prototype.
 * Return:exits with a given status(0) if info->argv[0] is not "exit".
 */
int custom exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])/*if there is an exit argument*/

	{
		exitccheck = custom atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print error(info, "illegal number:");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err num = custom atoi(info->argv[1];
				return (-2);
				}
				info->err num = -1;
				return (-2);
}

/**
 * custom cd - chages the current directory
 * @info: Pointer to information needed for the function
 * Return:Always 0
 */

				int custom cd(info_t *info)
				{
				char *s, *dir, buffer[1024];

				int chdir ret;

				s = getcwd(buffer, 1024);
				if (!s)
				_puts("TODO:>>getccwd failure emsg here<<\n");

				if (!info->argv[1])
				{
					((dir = custom getenv(info, "PWD=")) ? dir : "/");
					else
						chdir ret = chdir(dir);
				}
				else if (_strcmp(info->argv[1], "-") == 0)
				{
					if (!custom getenv(info, "OLDPWD="))
					{
						_put(s);
						_putchar('\n');
						retur n(1);
					}
					_puts(custom getenv(info, "OLDPWD=")) ?, _putchar('\n');
					chdir ret = /*TOD0:what should this be?*/

						chdir((dir = custom getenv(info, OLDPWD = ")) ? dir : " / " );
				}

				else
				{
					chdir ret = chdir(info->argv[1]);
				if(chdir ret == -1)
				{
					print error(info,"can't cd to");
				}
				else
				{
					custom setenv(info,"OLDPWD",custom getenv(info,"PWD="));
					custom setenv(info,"PWD", getcwd(buffer,1024));
				}
				return(0);
				}
/**
*custom help - changes the current directory of the proccess
*@info:structure containing potential arguments.
*used to mantain constant function prototype
*Return:Always 0
*/

int custom help(info_t *info)
{
	char**arg array;
	_puts("help call works.Function not yet implemented\n");

	if(0)
		_puts(*arg array);/*temp att unused workaround*/
	return(0);
}


