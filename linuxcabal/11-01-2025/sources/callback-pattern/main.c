#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )

struct callback {
	void (*action)(struct callback *);
};

struct event {
	char *event_name;
	struct callback cb;
};

struct button {
	char *name;
	int button_id;
	struct callback cb;
};

void event1_action(struct callback *cb)
{
	struct event *e = container_of(cb, struct event, cb);
	printf("event1_action: %s\n", e->event_name);
}

void button_action(struct callback *cb)
{
	struct button *b = container_of(cb, struct button, cb);
	printf("button_action: %s\n", b->name);
	printf("button_action: button_id: %d\n", b->button_id);
}

void trigger_callback(struct callback *cb)
{
	cb->action(cb);
}

int main()
{
	struct event e = {
		.event_name = "event1",
		.cb = {
			.action = event1_action,
		},
	};

	struct button b1 = {
		.name = "button1",
		.button_id = 1,
		.cb = {
			.action = button_action,
		},
	};


	trigger_callback(&e.cb);
	trigger_callback(&b1.cb);

	return 0;
}
