### int PriorityQueueInit(priority_queue * pqueue)
우선순위 큐를 초기화합니다.

### int Enqueue(priority_queue * pq, DATA data, int priority)
우선순위큐에 데이터를 삽입합니다. 성공 시 0을, 새 메모리 할당에 실패하면 2를 반환합니다.

### int Dequeue(priority_queue * pq, DATA * output)
우선순위가 가장 높은 데이터를 output에 저장하고 삭제합니다. 성공 시 0을, 데이터가 없을 경우 1을 반환합니다.

### int Peek(priority_queue * pq, DATA * output)
우선순위가 가장 높은 데이터를 output에 저장합니다. 데이터는 삭제되지 않습니다. 성공 시 0을, 데이터가 없을 경우 1을 반환합니다.

### int Count(priority_queue * pq)
데이터의 개수를 반환합니다.