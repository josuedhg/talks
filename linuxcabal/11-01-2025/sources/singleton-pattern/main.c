#include "log.h"

void function()
{
	struct log *log = log_create();
	log_msg(log, "[%s]: log address %p", __FUNCTION__, log);
}

int main()
{
	struct log *log = log_create();

	log_msg(log, "[%s]: log address %p", __FUNCTION__, log);
	function();

	log_destroy(log);
	return 0;
}
