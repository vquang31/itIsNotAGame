#pragma once
#include <vector>
#include "Item.hpp"
#include "json.hpp"
#include <fstream>

class Inventory {

private:
	std::vector<Item> items;
public:
	Inventory();
	void addNewItem(Item x); // dùng để thêm item mới 

	void increaseItem(Item x, int quantity); // dùng để thêm số lượng một item đã có 

	void increaseItemByIndex(int index, int quantity);

	void resetQuantityItemByIndex(int index);


	Item getItemByIndex(int id); // dùng cho khởi tạo item khởi đầu 

	void reset();
};