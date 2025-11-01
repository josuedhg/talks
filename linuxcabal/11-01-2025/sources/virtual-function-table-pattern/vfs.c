#include "vfs.h"

int vfs_read(struct vfs *vfs, char *buf, size_t len)
{
	return vfs->ops->read(vfs, buf, len);
}

int vfs_write(struct vfs *vfs, char *buf, size_t len)
{
	return vfs->ops->write(vfs, buf, len);
}
