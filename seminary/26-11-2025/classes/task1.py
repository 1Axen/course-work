class NegativeAmount(Exception):
    pass

class InvalidPIN(Exception):
    pass

class InsufficientFunds(Exception):
    pass

class Account():
    account_number: str
    balance: float
    pin: int

    def __init__(self, account_number: str, balance: float, pin: int):
        self.account_number = account_number
        self.balance = balance
        self.pin = pin

    def deposit(self, amount: float):
        if amount < 0:
            raise NegativeAmount

        self.balance += amount

    def withdraw(self, amount: float, pin: int):
        if amount < 0:
            raise NegativeAmount
        
        if pin != self.pin:
            raise InvalidPIN
        
        if self.balance < amount:
            raise InsufficientFunds
        
        self.balance -= amount

    def get_account_info(self):
        print(f"Account number: {self.account_number}")
        print(f"Account balance: {self.balance}")

account = Account(
    input("Enter the account number: "),
    float(input("Enter the account balance: ")),
    int(input("Enter the account PIN: "))
)

while True:
    print("============")
    print("Menu")
    print("============")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Account info")
    print("============")

    operation = int(input("Choose an operation: "))
    if operation == 1:
        amount = float(input("Deposit: "))
        try:
            account.deposit(amount)
            print(f"Deposited {amount}!")
        except(NegativeAmount):
            print(f"Cannot deposit a negative amount!")
    elif operation == 2:
        amount = float(input("Withdraw: "))
        pin = int(input("PIN: "))
        try:
            account.withdraw(amount, pin)
            print(f"Withdrew {amount}!")
        except(NegativeAmount):
            print("Cannot withdraw a negative amount!")
        except(InsufficientFunds):
            print("Insufficient account funds!")
        except(InvalidPIN):
            print("Invalid account PIN")
    elif operation == 3:
        account.get_account_info()
    else:
        print(f"Invalid operation: {operation}")