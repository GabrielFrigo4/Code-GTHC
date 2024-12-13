#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void) {
	struct queue_t *queue = queue_new();

	{
		struct data_t data;
		strcpy(data.buf, "Message 1");
		queue_push(queue, data);
	}

	{
		struct data_t data;
		strcpy(data.buf, "Message 2");
		queue_push(queue, data);
	}

	{
		struct data_t data;
		strcpy(data.buf, "Message 3");
		queue_push(queue, data);
	}

	{
		struct data_t data;
		strcpy(data.buf, "Message 4");
		queue_push(queue, data);
	}

	printf("len:{%lu}\n", queue_len(queue));
	printf("data:{%s}\n", queue_pop(queue).buf);
	printf("len:{%lu}\n", queue_len(queue));
	printf("data:{%s}\n", queue_pop(queue).buf);
	printf("len:{%lu}\n", queue_len(queue));
	printf("data:{%s}\n", queue_pop(queue).buf);
	printf("len:{%lu}\n", queue_len(queue));
	printf("data:{%s}\n", queue_pop(queue).buf);

	queue_delete(queue);
	return 0;
}
