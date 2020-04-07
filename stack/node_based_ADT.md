### void InitStack(stack * target)
생성된 스택을 초기화합니다. 초기화하지 않은 경우 에러가 나타날 수 있습니다.

### int Push(stack * target, DATA input)
스택에 데이터를 삽입합니다. 정상 작동 시 0을, 이미 꽉 차 더 이상 삽입이 불가능한 경우 1을 반환합니다.

### int Pop(stack * target, DATA * output)
스택에서 가장 늦게 삽입된 데이터를 빼내어 output에 저장합니다. 정상 작동 시 1을, 빼낼 데이터가 없는 경우 1을 반환합니다.

### int Count(stack * target)
스택의 데이터 개수를 반환합니다. 초기화가 되어 있지 않다면 정상적이지 않은 값이 반환될 수 있습니다.

### void DeleteStack(stack * target)
스택의 메모리 할당을 해제합니다.

