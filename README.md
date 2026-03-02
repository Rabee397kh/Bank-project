# 🏦 Bank Management System (C++)
### *A Programming Advices Project by Mohammed Abu-Hadhud*

This project is a comprehensive **Console-Based Banking Application** developed as part of the "Programming Advices" roadmap. It demonstrates the transition from basic procedural programming to building a functional, data-driven system using C++.

---

## 🚀 Key Features

### 👤 Client Management
* **Show Client List:** Displays all clients in a formatted table using `iomanip`.
* **Add New Client:** Validates and adds unique account numbers to the database.
* **Delete/Update Client:** Robust record manipulation using search-and-replace logic.
* **Find Client:** Quick lookup by Account Number.

### 💸 Transaction System
* **Deposit & Withdraw:** Real-time balance updates with validation.
* **Total Balances:** A summary view of the bank's total holdings across all accounts.

### 🔐 User Management & Permissions
* **Secure Login:** Access control with username and password.
* **Permissions System:** Granular control (e.g., specific users can add clients but cannot delete them).
* **Login Register:** Logs every login attempt with a timestamp to a separate `.txt` file.

---

## 🛠 Technical Highlights

* **File-Based Database:** Uses `.txt` files as a flat-file database to ensure data persistence.
* **Data Parsing:** Implements **"Record-to-Line"** and **"Line-to-Record"** logic using custom delimiters (e.g., `#//#`).
* **Memory Management:** Utilizes `std::vector` to manage data efficiently during runtime.
* **Input Validation:** Custom "bulletproof" functions to handle invalid user inputs and prevent system crashes.
* **Modular Code:** Organized into small, reusable functions to maintain a clean and scalable codebase.

---

## 📂 Project Structure

| Module | Description |
| :--- | :--- |
| **Global.h** | Definitions for `struct sClient`, `struct sUser`, and Enums. |
| **File Logic** | Core logic for reading from and writing to the disk. |
| **Input Lib** | Custom library for validated user inputs (Numbers, Strings). |
| **UI/Screens** | Functions dedicated to printing menus and formatted tables. |

---

## 📖 Key Learnings
Through this project, I mastered several core programming concepts:
1. **System Design:** Architecting how data flows from a file, into a vector, through logic, and back to a file.
2. **String Manipulation:** Advanced use of `string.find()` and `string.substr()` for data parsing.
3. **Permissions Logic:** Implementing a bitwise or boolean-based system to manage user access levels.
4. **Formatting:** Using `setw` and headers to create professional-looking CLI reports.

---

## 🔧 Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YourUsername/Bank-Management-System.git](https://github.com/YourUsername/Bank-Management-System.git)
