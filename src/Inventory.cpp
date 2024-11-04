#include "Inventory.hpp"

using json = nlohmann::json;

Inventory::Inventory() {
    std::ifstream items_file("./assets/data/Items.json");
    json jsonItems;
    if (items_file.is_open()) {
        items_file >> jsonItems;
        for (const auto& item : jsonItems) {
            Item tmp(item["id"], item["name"], item["description"], item["type"], item["cost"] , item["duration"]);
            addNewItem(tmp);
        }
    }
}

void Inventory::addNewItem(Item x) { // dùng để thêm item mới 
	items.push_back(x);
}

void Inventory::increaseItemByIndex(int index, int quantity) {
    items[index].increaseQuantity(quantity);
}

void Inventory::resetQuantityItemByIndex(int index) {
    items[index].setQuantity(0);
}

Item Inventory::getItemByIndex(int id) {
	return items[id];
}

void Inventory::reset() {
    for (int i = 0 ; i < 12; i ++) {
        resetQuantityItemByIndex(i);
    }
}


