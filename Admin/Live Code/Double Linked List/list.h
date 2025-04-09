struct list_it {
	struct list_it *prev;
	struct list_it *next;
	size_t len;
	char buff[];
};

struct list {
	struct list_it *head;
	struct list_it *tail;
	int len;
};

struct list_it *list_it_new(size_t len, char buff[len]);
void list_it_delete(struct list_it *list_it, void (*delete)(size_t, char[]));
struct list *list_new();
void list_delete(struct list *list, void (*delete)(size_t, char[]));
void list_push_back(struct list *list, size_t len, char buff[len]);
void list_push_front(struct list *list, size_t len, char buff[len]);
void list_pop_back(struct list *list, void (*delete)(size_t, char[]));
void list_pop_front(struct list *list, void (*delete)(size_t, char[]));
