##### class PriorityQueue
### .count (getter)
우선순위 큐의 데이터 개수입니다.

### .peek(self)
우선순위가 가장 높은 데이터를 반환합니다. 데이터가 없을 경우 EmptyPriorityQueueError를 일으킵니다.

### .show_all(self)
우선순위 큐의 모든 데이터를 출력합니다. 데이터는 다음 형식으로 출력됩니다.
[d : 데이터, p : 우선도]

### .enqueue(self, data, priority : int)
우선순위 큐에 데이터를 삽입합니다.

### .dequeue(self)
우선순위 큐에서 가장 우선순위가 높은 데이터를 반환합니다. 데이터가 없을 경우 EmptyPriorityQueueError를 일으킵니다.