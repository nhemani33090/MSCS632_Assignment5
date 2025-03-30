# Ride Sharing System – OOP Project (C++ and Smalltalk)

This project implements a class-based Ride Sharing System in two languages: **C++** and **Smalltalk**. It demonstrates key Object-Oriented Programming (OOP) principles including **encapsulation**, **inheritance**, and **polymorphism**.

---

## 📁 Folder Structure

```
├── C++/
│   ├── main.cpp
│   ├── Ride.h
│   ├── StandardRide.h
│   ├── PremiumRide.h
│   ├── Person.h
│
├── Smalltalk/
│   └── RideSharing.st
```

---

## 💡 OOP Principles Demonstrated

- **Encapsulation**: Private member variables in C++ (`assignedRides`, `requestedRides`), and controlled access via methods in Smalltalk.
- **Inheritance**: `StandardRide` and `PremiumRide` both inherit from the abstract `Ride` base class.
- **Polymorphism**: A collection of `Ride` objects contains both ride types, and overridden methods like `fare()` and `rideDetails()` are invoked polymorphically.

---

## 🚀 How to Run

### ✅ C++

1. Navigate to the `C++` folder.
2. Compile using:
   ```bash
   g++ main.cpp -o RideSharingApp
   ```
3. Run the executable:
   ```bash
   ./RideSharingApp
   ```

### ✅ Smalltalk (GNU Smalltalk)

1. Navigate to the `Smalltalk` folder.
2. Run with:
   ```bash
   gst RideSharing.st
   ```
---