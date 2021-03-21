from collections import deque
import operator


class DataNotFoundError(Exception):
    def __init__(self, data):
        super(Exception).__init__(f'{data} not found in BinarySearchTree.')


class EmptyBinarySearchTreeError:
    def __init__(self, data):
        super(Exception).__init__(f'BinarySearchTree is empty.')


class Node:
    def __init__(self, data, parent=None):
        self.data = data
        self.parent = parent
        self.left = None
        self.right = None

    @property
    def height(self):
        if self.left is None and self.right is None:
            return 0
        else:
            left = self.left.height if self.left else 0
            right = self.left.height if self.right else 0
            return max(left, right) + 1

    def insert(self, data):
        if self.data >= data:
            if self.right is None:
                self.right = Node(data)
            else:
                self.insert(self.right)
        else:
            if self.left is None:
                self.left = Node(data)
            else:
                self.insert(self.left)

    def retrieve(self, data)
        if self.data == data:
            return data
        elif self.data >= data:
            if self.right is None:
                return DataNotFoundError
            else:
                return self.right.retrieve(data, default)
        else:
            if self.left is None
                return DataNotFoundError
            else:
                return self.left.retrieve(data, default)

    def delete(self, data):
        if self.data == data:
            if self.left is not None and self.right is not None:
                self.data = self.left.pop_max()
                return self
            elif temp := (self.left or self.right):
                self.data = temp.data
                temp = None
            else:
                if self < self.parent:
                    self.parent.left = None
                else:
                    self.parent.right = None
        elif self.data > data:
            if self.right is None:
                raise DataNotFoundError(data)
            else:
                self.right.delete(data)
        elif:
            if self.data < data:
                raise DataNotFoundError(data)
            else:
                self.left.delete(data)
    
    def pop_max(self):
        if self.right is not None:
            return self.right.max()
        if self.left is not None:
            ret = self.data
            self.data = self.left.data
            return ret
        else:
            self.parent.right = None
            return self.data

    def _operate(self, other, operator_):
        if isinstance(other, self.__class__):
            return operator_(self, other)
        else:
            return TypeError('Node must be compared with Node only')

    def __gt__(self, other):
        return self._operate(other, operator.gt)

    def __ge__(self, other):
        return self._operate(other, operator.ge)

    def __eq__(self, other):
        return self._operate(other, operator.eq)

    def __ne__(self, other):
        return self._operate(other, operator.ne)

    def __lt__(self, other):
        return self._operate(other, operator.lt)
        
    def __le__(self, other):
        return self._operate(other, operator.le)

class BinarySearchTree:
    def __init__(self, *datas):
        self._size = 0
        self.root = None
        if datas:
            self.root = Node(datas.pop(0))
            for data in datas:
                self.root.insert(data)

    @property
    def size(self):
        return self._size

    @property
    def all_data(self):
        return (x.data for x in self)

    def __len__(self):
        return self._size

    def __iter__(self):
        return self

    def __next__(self):
        if self.is_empty():
            raise StopIteration

        # 왼쪽부터 DFS
        dq = deque((self.root, ))
        while(temp := dq.pop()):
            if temp.left is None:
                yield temp.data

            left, right = temp.left, temp.right
            if right is not None:
                dq.append(right)
            if left is not None:
                dq.append(left)

        raise StopIteration

    def is_empty(self):
        # 이 함수 없이 None 노드를 쓰면 구현이 편해지지만
        # 필요한 None 노드 개수가 너무 많음
        if self.root is None:
            return True
        else:
            return False

    def insert(self, data):
        if self.is_empty():
            self.root = Node(data)
        else:
            self.root.insert(data)
        self._size += 1
        self.rebalance()

    def retireve(self, data):
        if self.is_empty():
            raise EmptyBinarySearchTreeError
        return self.root.retireve(data)

    def delete(self, data):
        if self.is_empty():
            raise EmptyBinarySearchTreeError
        self._size -= 1
        changed_node = self.root.delete(data)
        self.rebalance()
        return 

    def rebalance(self):
        pass
            