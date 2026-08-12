typedef struct {
    int square;
    int moves;
} QueueNode;

typedef struct {
    QueueNode *data;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (QueueNode*)malloc(size * sizeof(QueueNode));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    return queue;
}

// Function to enqueue a node
void enqueue(Queue* queue, int square, int moves) {
    queue->data[queue->rear].square = square;
    queue->data[queue->rear].moves = moves;
    queue->rear = (queue->rear + 1) % queue->size;
}

// Function to dequeue a node
QueueNode dequeue(Queue* queue) {
    QueueNode node = { -1, -1 };
    if (queue->front != queue->rear) {
        node = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->size;
    }
    return node;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// Function to get the board value at a specific index
int getBoardValue(int** board, int n, int s) {
    int quot = (s - 1) / n;
    int rem = (s - 1) % n;
    int row = n - 1 - quot;
    int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
    return board[row][col];
}

// BFS function to find the minimum number of moves
int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int* visited = (int*)calloc(n * n + 1, sizeof(int));
    Queue* queue = createQueue(n * n + 1);
    enqueue(queue, 1, 0);
    visited[1] = 1;

    while (!isEmpty(queue)) {
        QueueNode node = dequeue(queue);
        int curr = node.square;
        int moves = node.moves;

        for (int i = 1; i <= 6; ++i) {
            int next_square = curr + i;
            if (next_square > n * n) {
                break;
            }
            int board_value = getBoardValue(board, n, next_square);
            if (board_value != -1) {
                next_square = board_value;
            }
            if (next_square == n * n) {
                free(visited);
                free(queue->data);
                free(queue);
                return moves + 1;
            }
            if (!visited[next_square]) {
                visited[next_square] = 1;
                enqueue(queue, next_square, moves + 1);
            }
        }
    }

    free(visited);
    free(queue->data);
    free(queue);
    return -1;
    }