#define STACK_MAX 100

typedef struct {
    int data[STACK_MAX];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;


void enqueue(Queue *q, int x) {
    q->data[q->rear] = x;
    q->rear++;
}

int dequeue(Queue *q) {
    int x = q->data[q->front];
    q->front++;

    // Queue became empty
    if (q->front == q->rear) {
        q->front = 0;
        q->rear = 0;
    }

    return x;
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}


MyStack* myStackCreate() {
    MyStack *obj = malloc(sizeof(MyStack));

    obj->q1 = malloc(sizeof(Queue));
    obj->q2 = malloc(sizeof(Queue));

    obj->q1->front = 0;
    obj->q1->rear = 0;

    obj->q2->front = 0;
    obj->q2->rear = 0;

    return obj;
}


void myStackPush(MyStack* obj, int x) {

    // Put the new element into q2
    enqueue(obj->q2, x);

    // Move everything from q1 to q2
    while (!isQueueEmpty(obj->q1)) {
        int temp = dequeue(obj->q1);
        enqueue(obj->q2, temp);
    }

    // Swap q1 and q2
    Queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}


int myStackPop(MyStack* obj) {

    if (isQueueEmpty(obj->q1)) {
        return 0;
    }

    return dequeue(obj->q1);
}


int myStackTop(MyStack* obj) {

    if (isQueueEmpty(obj->q1)) {
        return 0;
    }

    return obj->q1->data[obj->q1->front];
}


bool myStackEmpty(MyStack* obj) {

    return isQueueEmpty(obj->q1);
}


void myStackFree(MyStack* obj) {

    free(obj->q1);
    free(obj->q2);
    free(obj);
}