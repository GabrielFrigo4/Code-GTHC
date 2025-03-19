struct list_it {
	struct list_it *prev;
	struct list_it *next;
	void *buff;
};

struct list {
	struct list_it *head;
	struct list_it *tail;
	int len;
};

struct list_it *list_it_new();
void list_it_delete(struct list_it *list_it, void (*delete)(void *));
struct list *list_new();
void list_delete(struct list *list, void (*delete)(void *));
void list_push_back(struct list *list, void *buff);
void list_push_front(struct list *list, void *buff);
void list_pop_back(struct list *list, void (*delete)(void *));
void list_pop_front(struct list *list, void (*delete)(void *));
