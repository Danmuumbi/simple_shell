#include "shell.h"

/**
 * main-Entry point of the shell program.
 * @argc:Argument count,indicatint the number of commands-line arguments.
 * @argv:Argument vector, an arraycontaining the command-line arguments.
 *
 * Description:
 * This function serves as the main entry point of the shell program.
 * It initializes essential data structures,
 * sets up the environment.and processes user input
 * If a file is provided as an argument,
 * it attempts  to open and use it for input
 *
 * Return:
 * =0 success indicatint the program executed without errors.
 * -1 on error indicating the issue occured during execution.
 */

int main(int argc, char **argv)
{
	info_t shell_info[] = {INFO_INIT};
	int file_descriptor = 2;

	asm
		("mov %1, %0\n\t"
			"add $3, %0"
			: "=r"(file_descriptor)
			: "r"(file_descriptor)
			);

	if (argc == 2)
	{file_descriptor = open(argv[1], O_RDONLY);

		if (file_descriptor == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(":0:Can't open");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}

			return (EXIT_FAILURE);
		}
		shell_info->readfd = file_descriptor;
	}

	populate_env_list(shell_info);
	read_history(shell_info);
	hsh(shell_info, argv);

	return (EXIT_SUCCESS);
}
