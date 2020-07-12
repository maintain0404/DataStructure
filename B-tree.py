class DataAleadyExistError:
    def __init__(self):
        super().__init__("Data aleady exists in B-tree")

class EmptyData:
    pass

class EmptyNode:
    pass

class Node:
    # 홀수레벨
    def __init__(self, level = 5):
        self._level = level
        self._datas = []
        self._children = []
        self._validators = []
        for x in range((level * 2) + 1):
            if x % 2 == 0:
                self._datas.append(EmptyNode)
            else:
                self._datas.append(EmptyData)

    @property
    def datas(self):
        return [self._datas[x] for x in range(1, self._level * 2, 2)]

    def _insert(self, new_data, return_min_or_max = 'max'):
        if self.is_leaf():
            if emtpy_index := self.empty_data_index(): 
                self._add_new_to_leaf(new_data)
                return None
            else:
                
        else:
            if self.include(new_data):
                raise DataAleadyExistError
            new_data_index = self.find_data_index()
            if new_data_index == self._level * 2:
                data_get_back = self.datas[new_data_index]._insert(new_data)
            else:
                data_get_back = self.datas[new_data_index]._insert(new_data, 'min')
            if data_get_back: 
                if empty_index := self.empty_data_index():
                    self._datas[emtpy_index] = data_get_back
                else: # 분할필요한 경우
                    left = Node()
                    right = Node()


    def _leaf_sort(self):
        temp = self.datas
        sort(temp)
        for x in range(self._level):
            self._datas[x * 2 + 1] = temp[x]
    
    def _add_new_to_leaf(self, new_data):
        for x in range(0 self._level * 2, 2):
            if isinstance(self._datas[x], EmptyData):
                self._datas[x] = new_data
        self._leaf_sort()

    def is_leaf(self):
        for x in range(0, self._level * 2 + 1, 2):
            if not isinstance(self._datas[x], EmptyData):
                return False
        return True

    def empty_data_index(self):
        for x in range(1, self._level * 2, 2):
            if isinstance(x, EmptyData):
                return x
        return None

    def max_data(self):
        pass

    def min_data(self):
        pass

    def include(self, new_data):
        for x in range(1, self._level * 2, 2):
            if self._datas[x] == new_data:
                return True
        return False

    def __gt__(self, other):
        return self.min_data > other

    def __lt__(self, other):
        return self.max_data < other 

    def find_data_index(self, data):
        position = 0
        for x in range(1, self._level * 2, 2):
            if data > self._datas[x]:
                position =  x + 1
        return position