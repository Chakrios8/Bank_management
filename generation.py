import random

def name():
    fn = ["Amy", "Ben", "Carl", "Dana", "Eli", "Fay", "Gus", "Hank", "Ira", "Jen", "Kyle", "Leo","Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry", "Ivy", "Jack",
                   "Karen", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Sam", "Tina",
                   "Uma", "Victor", "Wendy", "Xavier", "Yara", "Zack", "Laura", "David", "Emily", "George"]
    ln = ["Hill", "Ward", "King", "Wood", "Hall", "Lee", "Young", "Allen", "Scott", "Adams","Smith", "Jones", "Williams", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson",
                  "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Clark"]
    return random.choice(fn) + " " + random.choice(ln)

def money():
    val = random.random() * 12000
    return round(val, 2)


def writefile(count, start, path="accounts.csv"):
    out = open(path, "w")
    out.write("AccountNumber,Name,Balance\n")
    n = 0
    while n < count:
        acc = start + n
        who = name()
        themmoney = money()
        out.write(str(acc) + "," + who + "," + str(themmoney) + "\n")
        n += 1
    out.close()
    print("Done: " + str(count) + " entries")


if __name__ == "__main__":
    writefile(500, 1001)
