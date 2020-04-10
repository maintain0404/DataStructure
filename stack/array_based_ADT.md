### void InitStack(stack * target, int stack_size)
target 변수에 스택을 생헝하고 초기화합니다. 아래 함수는 모두 초기화를 전제하기 때문에 초기화하지 않은 경우 예상할 수 없는 에러가 나타날 수 있습니다.

### int Push(stack * target, DATA input)
스택에 데이터를 삽입합니다. 정상 작동 시 0을, 이미 꽉 차 더 이상 삽입이 불가능한 경우 1을 반환합니다.

### int Pop(stack * target, DATA * output)
스택에서 가장 늦게 삽입된 데이터를 빼내어 output에 저장합니다. 정상 작동 시 0을, 빼낼 데이터가 없는 경우 1을 반환합니다.

### int Count(stack * target)
스택의 데이터 개수를 반환합니다. 초기화가 되어 있지 않다면 정상적이지 않은 값이 반환될 수 있습니다.

### void DeleteStack(stack * target)
스택 내부의 동적 할당된 메모리를 해제합니다. 스택 자체는 따로 해제해야 합니다.

