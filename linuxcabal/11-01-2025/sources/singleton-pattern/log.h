#ifndef LOG_H
#define LOG_H

struct log;

struct log *log_create();
void log_msg(struct log *log, char *format, ...);
void log_destroy(struct log *log);

#endif
