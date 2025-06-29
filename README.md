# 🏦 Bank Management System

This is a fun and simple command-line project built in **C++**, simulating a basic bank environment. Whether you're learning file handling, object-oriented programming, or just want to try creating fake accounts, this project has a bit of everything.

---

## 📁 What’s Inside?

* `bankmanagementsys.cpp` – The main source code for the C++ banking system.
* `generation.py` – A Python helper to generate fake bank accounts with random names and balances.
* `accounts.csv` – Stores the account data. Automatically created if not present.

---

## 🧰 Features

* Add new bank accounts (auto-incremented account numbers)
* Deposit and withdraw money
* View a single account or list all of them
* Delete accounts as needed
* Data stored in `CSV` format for easy reading/editing
* Generate bulk account data using the Python script

---

## 🚀 How to Use

### ✅ Run the C++ Bank App

Make sure you have a C++ compiler like `g++`:

```bash
g++ bankmanagementsys.cpp -o bankapp
./bankapp
```

If `accounts.csv` doesn't exist, the program will create one.

### 🐍 Generate Dummy Data (Optional)

Need some accounts to play with?

```bash
python generation.py
```

This will generate 500 accounts starting from #1001 and save them into `accounts.csv`.

---

## 📄 Sample Output

```csv
AccountNumber,Name,Balance
1001,Olivia Smith,8756.34
1002,Bob Johnson,593.22
```

---

## 📝 Notes

* This is a beginner-friendly project.
* Minimal error handling is included to keep things simple.
* Python script is there just for convenience—totally optional.
* Feel free to tweak it to make it more advanced.

---

## 🤝 Contributions Welcome

Found a bug? Got an idea? Fork the repo and open a PR!

Thanks for dropping by! ✨
