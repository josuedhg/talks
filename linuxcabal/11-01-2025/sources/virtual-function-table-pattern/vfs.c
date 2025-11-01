#include "vfs.h"

int vfs_read(struct vfs *vfs, char *buf, size_t len)
{
	if (!vfs || !vfs->ops || !vfs->ops->read)
		return -1;
	return vfs->ops->read(vfs, buf, len);
}

int vfs_write(struct vfs *vfs, char *buf, size_t len)
{
	if (!vfs || !vfs->ops || !vfs->ops->write)
		return -1;
	return vfs->ops->write(vfs, buf, len);
}
