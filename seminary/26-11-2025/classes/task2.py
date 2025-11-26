from typing import NamedTuple

class Order(NamedTuple):
    table: int
    dishes: list[str]

class Restaurant(NamedTuple):
    name: str
    address: str
    menu: dict[str, float]

    def get_order_data(self) -> Order:
        table = int(input("Table number: "))
        
        dishes: list[str] = []
        names_str = input("Ordered dishes: ")
        names = names_str.split(",")

        for name in names:
            if not name in self.menu:
                print(f"Unknown dish \"{name}\"")
                continue

            dishes.append(name)

        return Order(table, dishes)

    def calculate_order_value(self, order: Order) -> float:
        total = 0
        for dish in order.dishes:
            price = self.menu.get(dish, 0)
            total += price

        return total
    
    def generate_receipt(self, order: Order):
        print("**RECEIPT**")
        print(f"Restaurant: {self.name}")
        print(f"Address: {self.address}")
        print(f"Order No: {order.table}")

        for dish in order.dishes:
            price = self.menu.get(dish, 0)
            print(f"* {dish}: {price} BGN")

        print(f"Total: {self.calculate_order_value(order)}")

name = input("Restaurant name: ")
address = input("Address: ")
dishes = {}

while True:
    dish_name = input("Dish name: ")
    dish_price = float(input("Dish price: "))
    dishes[dish_name] = dish_price

    cont = input("Do you want to input more dishesh? (Y/N): ")
    if (cont.lower() == "n"):
        break

restaurant = Restaurant(name, address, dishes)
order = restaurant.get_order_data()
restaurant.generate_receipt(order)