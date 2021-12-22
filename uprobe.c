#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void uprobe(const char *name)
{
	printf("uprobe str: %s\n", name);
}

int main()
{
	char *name = "uprobe here";
	while (1) {
		uprobe(name);
		sleep(1);
	}
	return 0;
}
