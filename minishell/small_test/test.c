#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 

void	handle_signal(int sig);
int global_sig;

int main(void) {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    char *str; 
    
    str = ttyname(0);
    printf("%s\n", str);
    sleep(1000);
    return 0;
}  

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		global_sig = 130;
		// rl_replace_line("", 0);
		// rl_on_new_line();
	}
	else if (sig == SIGQUIT)
	{
		global_sig = 131;
		write(2, "exit\n", 6);
	}
}