# Bank Management System (LLD)

A C++ console application simulating a basic bank account system, 
built to practice Object-Oriented Programming and Low-Level Design (LLD) 
concepts through a small, focused project.

## 📋 Overview

moral: Learning purpose.

This project models a simple banking system where a customer can 
deposit and withdraw money from a savings account. It's designed as 
a hands-on exercise to apply core OOP pillars in a single, compact 
console program.

## ✨ Features

- Create an account with a holder name and initial balance
- Deposit money (supports both integer and decimal amounts)
- Withdraw money with balance validation (prevents overdraw)
- Display account details (holder name and balance)
- Basic arithmetic operation demo using a custom `money` class

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts Used:**
  - **Abstraction** — `Account` is an abstract base class with a pure virtual `withdraw()` function
  - **Encapsulation** — `Holder` and `balance` are protected, accessed via getter (`getbalance()`)
  - **Inheritance** — `sa` (Savings Account) class inherits from `Account`
  - **Polymorphism (runtime)** — `withdraw()` is overridden in `sa` and called via a base class pointer
  - **Function Overloading** — two `deposit()` versions, one for `int` and one for `double`
  - **Operator Overloading** — `money` class overloads the `+` operator to add two amounts
  - **Friend Function** — `showdet()` accesses private/protected data of `Account` directly
  - **Constructors & Destructors** — account creation/closure messages

## 🏗️ Design Approach

- `Account` is the abstract base class defining shared behavior (deposit, balance check) and enforcing that every account type must implement its own `withdraw()` logic.
- `sa` (Savings Account) extends `Account` and defines withdrawal rules — it blocks withdrawal if the amount requested exceeds the balance.
- `showdet()` is a friend function, used to demonstrate how a non-member function can still access an object's protected data when explicitly granted access.
- A separate `money` class demonstrates operator overloading independent of the account logic, to show the `+` operator can be customized for a user-defined type.

## 📚 What I Learned

- How to enforce a contract using abstract classes and pure virtual functions
- The difference between compile-time (function/operator overloading) and 
  runtime (virtual function) polymorphism, applied in the same project
- How friend functions break normal access rules in a controlled way

## 🔮 Future Improvements

- Add more account types (Current Account, Fixed Deposit) to properly 
  demonstrate multiple derived classes
- Add input validation from user (currently uses hardcoded values in `main()`)
- Add a transaction history log

---
**Author:** Deepak Kumar Dharmaraj
