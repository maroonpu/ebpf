#include <linux/ptrace.h>
#include <uapi/linux/bpf.h>
#include <linux/version.h>
#include "bpf_helpers.h"

SEC("uprobe/")
int bpf_prog(struct pt_regs *ctx)
{
	char buf[20];
	int ret;
	char msg[] = "str = %s, ret = %d\n";

	ret = bpf_probe_read(&buf, sizeof(buf), (void *)PT_REGS_PARM1(ctx));	
	bpf_trace_printk(msg, sizeof(msg), buf, ret);

	return 0;
}

char _license[] SEC("license") = "GPL";
u32 _version SEC("version") = LINUX_VERSION_CODE;
