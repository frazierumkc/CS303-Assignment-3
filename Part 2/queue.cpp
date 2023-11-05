#include "queue.h"

template<typename Item_Type>
void queue<Item_Type>::push(const Item_Type& item) {
	container.push_back(item);
}

template<typename Item_Type>
const Item_Type& queue<Item_Type>::front() {
	return container.front();
}

template<typename Item_Type>
Item_Type queue<Item_Type>::pop() {
	Item_Type temp = container.front();
	container.erase(container.begin());
	return temp;
}

template<typename Item_Type>
bool queue<Item_Type>::empty() const {
	return container.empty();
}

	template<typename Item_Type>
size_t queue<Item_Type>::size() const {
	return container.size();
}