#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "vfs.h"

#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )

struct i2c_file {
	int SDA;
	int SCL;
	struct vfs vfs;
};

int i2c_read(struct vfs *vfs, char *buf, size_t len)
{
	struct i2c_file *i2c = container_of(vfs, struct i2c_file, vfs);
	printf("i2c_read from %s\n", i2c->vfs.name);
	printf("SDA: %d, SCL: %d\n", i2c->SDA, i2c->SCL);

	char *p = "Hello World from i2c!";
	int p_len = strlen(p);
	if (p_len > len)
		p_len = len;
	memcpy(buf, p, p_len);
	return 0;
}

int i2c_write(struct vfs *vfs, char *buf, size_t len)
{
	struct i2c_file *i2c = container_of(vfs, struct i2c_file, vfs);
	printf("i2c_write to %s\n", i2c->vfs.name);
	printf("SDA: %d, SCL: %d\n", i2c->SDA, i2c->SCL);
	printf("buf: %s\n", buf);
	return 0;
}

struct file_ops i2c_ops = {
	.read = i2c_read,
	.write = i2c_write,
};

struct i2c_file i2c = {
	.SDA = 1,
	.SCL = 0,
	.vfs = {
		.name = "i2c",
		.ops = &i2c_ops,
	},
};

struct uart_file {
	int baud;
	int tx;
	int rx;
	struct vfs vfs;
};

int uart_read(struct vfs *vfs, char *buf, size_t len)
{
	struct uart_file *uart = container_of(vfs, struct uart_file, vfs);
	printf("uart_read from %s\n", uart->vfs.name);
	printf("baud: %d, tx: %d, rx: %d\n", uart->baud, uart->tx, uart->rx);

	char *p = "Hello World from uart!";
	int p_len = strlen(p);
	if (p_len > len)
		p_len = len;
	memcpy(buf, p, p_len);
	return 0;
}

int uart_write(struct vfs *vfs, char *buf, size_t len)
{
	struct uart_file *uart = container_of(vfs, struct uart_file, vfs);
	printf("uart_write to %s\n", uart->vfs.name);
	printf("baud: %d, tx: %d, rx: %d\n", uart->baud, uart->tx, uart->rx);
	printf("buf: %s\n", buf);
	return 0;
}

struct file_ops uart_ops = {
	.read = uart_read,
	.write = uart_write,
};

struct uart_file uart = {
	.baud = 115200,
	.tx = 1,
	.rx = 0,
	.vfs = {
		.name = "uart",
		.ops = &uart_ops,
	},
};

int main()
{
	struct vfs *vfs[] = {
		&i2c.vfs,
		&uart.vfs,
	};

	char buf[30] = {0};

	for (int i = 0; i < 2; i++) {
		vfs_read(vfs[i], buf, 30);
		vfs_write(vfs[i], "Hello World!", 12);
	}

	return 0;
}
