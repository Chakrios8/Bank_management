import random

def generate_random_name():
    first_names = ["Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry", "Ivy", "Jack",
                   "Karen", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Sam", "Tina",
                   "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zack", "Laura", "David", "Emily", "George"]
    last_names = ["Smith", "Jones", "Williams", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson",
                  "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Clark"]
    return f"{random.choice(first_names)} {random.choice(last_names)}"

def generate_random_balance():
    return round(random.uniform(1, 10000),2)

def generate_accounts_csv(num_records, start_account_num, filename="accounts.csv"):
    with open(filename, 'w') as f:
       
        f.write("AccountNumber,Name,Balance\n")

        for i in range(num_records):
            account_number = start_account_num + i
            name = generate_random_name()
            balance = generate_random_balance()
            f.write(f"{account_number},{name},{balance}\n")
    print(f"Generated {num_records} records and saved to {filename}")

if __name__ == "__main__":
    generate_accounts_csv(500, 1001) 