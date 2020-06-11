#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#include "version.h"

int main(int argc, char *argv[])
{
	char *			pszAppName;
	int				i;

    pszAppName = strdup(argv[0]);

	if (argc > 0) {
        printf("Got cmdline parameters: ");

		for (i = 0;i < argc;i++) {
            printf("%s ", argv[i]);

			if (argv[i][0] == '-') {
				if (strcmp(&argv[i][1], "version") == 0) {
					printf("%s Version: [%s], Build date: [%s]\n\n", pszAppName, getVersion(), getBuildDate());
					return 0;
				}
			}
		}

        printf("\n\n");
	}

    while (1) {
        sleep(1);
    }

    return 0;
}
