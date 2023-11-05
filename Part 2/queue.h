#ifndef QUEUE_H_
#define QUEUE_H_
#include <vector>

template<typename Item_Type>
class queue {
public:
	/**Pushes an item to the back of the queue.
		@param item Item to be pushes*/
	void push(const Item_Type& item);

	/**Returns the item at the front of the queue without removing it.
		@return The item at the front of the queue*/
	const Item_Type& front();

	/**Removes the item at the front of the queue and returns it.
		@return The item being removed*/
	Item_Type pop();

	/**Checks whether queue is empty or not.
		@return True if empty, false if not empty*/
	bool empty() const;

	/**Returns the size of the queue.
		@return Size of the queue*/
	size_t size() const;

private:
	std::vector<Item_Type> container;
};

#endif
