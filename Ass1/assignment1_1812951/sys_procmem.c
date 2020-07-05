#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/pid.h>
#include <asm/uaccess.h>

struct proc_segs{
	unsigned long mssv;
	unsigned long start_code;
	unsigned long end_code;
	unsigned long start_data;
	unsigned long end_data;
	unsigned long start_heap;
	unsigned long end_heap;
	unsigned long start_stack;
};
asmlinkage long sys_procmem(int pid, struct proc_segs *info){
	struct task_struct* task = pid_task(find_get_pid(pid), PIDTYPE_PID);
	if (task == NULL)
		return -1;
	struct proc_segs temp;
	temp.mssv = 1812951;
	if (task->mm != NULL){
		temp.start_code 	= task->mm->start_code;
		temp.end_code		= task->mm->end_code;
		temp.start_data 	= task->mm->start_data;
		temp.end_data		= task->mm->end_data;
		temp.start_heap		= task->mm->start_brk;
		temp.end_heap		= task->mm->brk;
		temp.start_stack	= task->mm->start_stack;
	}
	copy_to_user(info, &temp, sizeof(temp));
	return 0;

}

