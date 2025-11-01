#ifndef VFS_H
#define VFS_H

#include <stddef.h>

struct file_ops;

struct vfs {
	char *name;
	struct file_ops *ops;
};

struct file_ops {
	int (*read)(struct vfs *, char *, size_t);
	int (*write)(struct vfs *, char *, size_t);
};

int vfs_read(struct vfs *, char *, size_t);
int vfs_write(struct vfs *, char *, size_t);

#endif
