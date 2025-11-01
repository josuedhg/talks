#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "log.h"

struct log {
	int id;
};

static int log_id = 0;

static struct log *singleton_log = NULL;

struct log *log_create()
{
	if (singleton_log)
		return singleton_log;

	singleton_log = malloc(sizeof(struct log));
	if (!singleton_log)
		return NULL;
	singleton_log->id = log_id++;
	return singleton_log;
}

void log_msg(struct log *log, char *format, ...)
{
	if (!log)
		return;

	if (!format)
		return;

	va_list args;
	va_start(args, format);
	printf("ID: %d - ", log->id);
	vprintf(format, args);
	printf("\n");
	va_end(args);
}

void log_destroy(struct log *log)
{
	if (!log)
		return;
	free(log);
	log = NULL;
}
