# clsInputValidate

A lightweight C++ header-only input validation library. Handles number range checks, string validation, and date validation — designed to be dropped into any project with a single include.

---

## Installation

No build system needed. Just copy `clsInputValidate.h` into your project and include it:

```cpp
#include "clsInputValidate.h"
```

> **Dependencies:** `clsDate.h` is required for date validation functions.

---

## Usage

### Number Validation

```cpp
// Check if a number is within a range
bool valid = clsInputValidate::IsNumberBetween(15, 1, 100);  // true

// Read a validated integer from user input
int age = clsInputValidate::ReadIntNumber("Enter your age: ");

// Read an integer within a range
int score = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter score (1-10): ");

// Same for doubles
double price = clsInputValidate::ReadDblNumber("Enter price: ");
double discount = clsInputValidate::ReadDblNumberBetween(0.0, 1.0, "Enter discount: ");
```

### String Validation

```cpp
// Check if a string is empty
bool empty = clsInputValidate::IsEmptyString("");  // true

// Read a non-empty string from user
string name = clsInputValidate::ReadString("Enter your name: ");
```

### Date Validation

```cpp
// Check if a date is valid
clsDate d(31, 2, 2024);
bool valid = clsInputValidate::IsValidDate(d);  // false — Feb 31 doesn't exist

// Check if date1 is before date2
bool before = clsInputValidate::IsDate1BeforeDate2(
    clsDate(1, 1, 2024),
    clsDate(1, 1, 2025)
);  // true
```

---

## API Reference

### Numbers

| Function | Description |
|----------|-------------|
| `IsNumberBetween(number, from, to)` | Returns true if number is within range (inclusive) |
| `ReadIntNumber(message)` | Prompts user and reads a valid integer |
| `ReadIntNumberBetween(from, to, message)` | Reads an integer within a specified range |
| `ReadDblNumber(message)` | Prompts user and reads a valid double |
| `ReadDblNumberBetween(from, to, message)` | Reads a double within a specified range |

### Strings

| Function | Description |
|----------|-------------|
| `IsEmptyString(string)` | Returns true if the string is empty |
| `ReadString(message)` | Prompts user and reads a non-empty string |

### Dates

| Function | Description |
|----------|-------------|
| `IsValidDate(date)` | Returns true if the date exists on the calendar |
| `IsDate1BeforeDate2(date1, date2)` | Returns true if date1 comes before date2 |

---

## Notes

- All input-reading functions loop until the user enters valid input — no crashes on bad input
- Number range checks are inclusive on both ends
- Date validation delegates to `clsDate::IsValid()`

---
