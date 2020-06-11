#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#include "version.h"

void handleSignal(int sigNum)
{
	switch (sigNum) {
		case SIGUSR1:
            fprintf(stderr, "Got capture signal...\n");
			return;
	}
}

int main(int argc, char *argv[])
{
	char *			pszAppName;
	int				i;

    pszAppName = strdup(argv[0]);

	if (argc > 0) {
        fprintf(stderr, "Got cmdline parameters: ");

		for (i = 0;i < argc;i++) {
            fprintf(stderr, "%s ", argv[i]);

			if (argv[i][0] == '-') {
				if (strcmp(&argv[i][1], "version") == 0) {
					fprintf(stderr, "%s Version: [%s], Build date: [%s]\n\n", pszAppName, getVersion(), getBuildDate());
					return 0;
				}
			}
		}

        fprintf(stderr, "\n\n");
	}

	if (signal(SIGUSR1, &handleSignal) == SIG_ERR) {
		fprintf(stderr, "Failed to register signal handler for SIGUSR1");
		return -1;
	}

    while (1) {
        sleep(1);
    }

    return 0;
}
