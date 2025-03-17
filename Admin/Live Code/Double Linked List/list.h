struct node {
	struct node *prev;
	struct node *next;
	void *buff;
};

struct list {
	struct node *head;
	struct node *tail;
};

struct node *node_new();
void node_delete(struct node *node);
struct list *list_new();
void list_delete(struct list *list);
void list_push_back(struct list *list, void *buff);
void list_push_front(struct list *list, void *buff);
void list_pop_back(struct list *list);
void list_pop_front(struct list *list);