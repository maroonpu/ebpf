#include <stdio.h>
#include <stdlib.h>
#include <linux/bpf.h>
#include <unistd.h>
#include <bpf/bpf.h>
#include "bpf_load.h"

int main(int ac, char **argv)
{
	char *filename = "hello_kern.o";
	size_t func_offset;

	func_offset = (size_t) strtoul(argv[2], NULL, 16);

	if (load_bpf_file_uprobe(filename, argv[1], func_offset)) {
		printf("%s", bpf_log_buf);
		return 1;
	}

	read_trace_pipe();

	return 0;
}
