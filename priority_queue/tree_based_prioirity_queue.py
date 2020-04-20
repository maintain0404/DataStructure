class EmptyPriorityQueueError(Exception):
    def __init__(self):
        super.__init__('There is no data to return in priority queue.')    

class Node:
    def __init__(self, data, priority : int):
        self.__data = data
        self.__priority = priority
        self.left = None
        self.right = None
    
    def __lt__(self, other):
        return self.priority < other.priority

    def __le__(self, other):
        return self.priority <= other.priority
    
    def __gt__(self, other):
        return self.priority > other.priority

    def __ge__(self, other):
        return self.priority >= other.priority

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, data):
        self.__data = data

    @property
    def priority(self):
        return self.__priority 

    @priority.setter
    def priority(self, priority):
        self.__priority = priority

class PriorityQueue:
    def __init__(self):
        self.__count = 0
        self.__root = None
    
    @property
    def count(self):
        return self.__count    

    def peek(self):
        if self.__root:
            return self.__root.data
        else:
            raise EmptyPriorityQueueError

    def show_all(self):
        def show_all_inner(current):
            if current.left == None and current.right == None:
                return '[d : ' + str(current.data) + ', p : ' + str(current.priority) + ']'
            lefts = ''
            rights = ''
            result = ''
            if current.left:
                lefts = show_all_inner(current.left)
                result = result + lefts + ', '
            if current.right:
                rights = show_all_inner(current.right)
                result = result + rights + ', '
            return result + '[d : ' + str(current.data) + ', p : ' + str(current.priority) + ']'
        if self.__root:
            return show_all_inner(self.__root)
        else:
            raise EmptyPriorityQueueError

    def enqueue(self, data, priority : int):
        def node_swap(a : Node, b : Node):
            temp_data, temp_priority = a.data, a.priority
            a.data, a.priority = b.data, b.priority
            b.data, b.priority = temp_data, temp_priority
        # 탐색해서 위치를 바꾸는 내부 재귀함수
        def enqueue_inner(current : Node, new : Node):
            # 종료조건 : 자식 빈 자리가 있을 떄 
            if not current.left and not current.right:
                current.left = new
                if current < new:
                    node_swap(current, new)
                return
            elif current.left and not current.right:
                current.right = new
                if current < new:
                    node_swap(current, new)
                return
            elif not current.left and current.right:
                current.left = new
                if current < new:
                    node_swap(current, new)
                return
            # 빈 자리가 없을 때
            else:
                #더 작은 자식을 선택
                if current.left < current.right:
                    # 부모 > 자식 > 새 노드가 되도록 스왑
                    if new > current > current.left:
                        node_swap(new, current)
                        node_swap(new, current.left)
                    elif current > new > current.left:
                        node_swap(current.left, new)
                    enqueue_inner(current.left, new)    
                else:
                    # 부모 > 자식 > 새 노드가 되도록 스왑
                    if new > current > current.right:
                        node_swap(new, current)
                        node_swap(new, current.right)
                    elif current > new > current.right:
                        node_swap(current.right, new)
                    enqueue_inner(current.right, new)
        # 루트가 있는 경우 새 노드 생성 후 재귀함수 실행
        if self.__root:
            new_node = Node(data, priority)
            enqueue_inner(self.__root, new_node)
        # 루트가 없는 경우 루트에 추가
        else:
            self.__root = Node(data, priority)
        self.__count = self.__count + 1

    def dequeue(self):
        def dequeue_inner(current : Node):
            if current.left and current.right:
                if current.left > current.right:
                    current.data, current.priority = current.left.data, current.left.priority
                    if not dequeue_inner(current.left):
                        current.left = None
                        return True
                    else:
                        return True
                else:
                    current.data, current.priority = current.right.data, current.right.priority
                    if not dequeue_inner(current.right):
                        current.right = None
                        return True
            elif current.left and not current.right:
                current.data, current.priority = current.left.data, current.left.priority
                if not dequeue_inner(current.left):
                    current.left = None
                    return True
                else:
                    return True
            elif not current.left and current.right:
                current.data, current.priority = current.right.data, current.right.priority
                if not dequeue_inner(current.right):
                    current.right = None
                    return True
            else:
                return False
        if self.__root.data:
            dequeue_inner(self.__root)
            self.__count = self.__count - 1
        else:
            raise EmptyPriorityQueueError
        