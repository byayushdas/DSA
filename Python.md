# Python Notes

## Table of Contents

- [Class Objects](#class-objects)
- [Loops & Conditions](#loops--conditions)
- [Strings & Conversions](#strings--conversions)
- [Collections](#collections)
- [Data Types & Mutability](#data-types--mutability)
- [Functions](#functions)
- [Inheritance](#inheritance)
- [Operator Precedence](#operator-precedence)
- [Operator Reference](#operator-reference)
- [Variable Naming Conventions](#variable-naming-conventions)
- [Modules: Imports](#modules-imports)
- [Math Commands](#math-commands)

## Class Objects

### 1. Basic Class and Object

```python
class Person:
    def __init__(self, name, sex, profession):
        self.name = name
        self.sex = sex
        self.profession = profession

    def show(self):
        print("Name:", self.name, "Sex:", self.sex, "Profession:", self.profession)

    def work(self):
        print(self.name, "working as a", self.profession)

p1 = Person("Jessa", "Female", "Software Engineer")
p1.show()
p1.work()

# Output:
# Name: Jessa Sex: Female Profession: Software Engineer
# Jessa working as a Software Engineer
```

### 2. Class Variable & Instance Variable

```python
class Student:
    school_name = "ABC School"   # class variable

    def __init__(self, name, age):
        self.name = name         # instance variable
        self.age = age

s1 = Student("Harry", 12)

print("Student:", s1.name, s1.age)
print("School Name:", Student.school_name)

# Output:
# Student: Harry 12
# School Name: ABC School

s1.name = "Jessa"
s1.age = 14
print("Modified Student:", s1.name, s1.age)

# Output:
# Modified Student: Jessa 14

Student.school_name = "XYZ School"
print("Modified School Name:", Student.school_name)

# Output:
# Modified School Name: XYZ School
```

### 3. Instance Method & Class Method

```python
class Student:
    school_name = "ABC School"

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):                 # instance method
        print("Student:", self.name, self.age, Student.school_name)

    def change_age(self, new_age):  # instance method
        self.age = new_age

    @classmethod
    def modify_school_name(cls, new_name):   # class method
        cls.school_name = new_name

s1 = Student("Harry", 12)
s1.show()

# Output:
# Student: Harry 12 ABC School

s1.change_age(14)
Student.modify_school_name("XYZ School")
s1.show()

# Output:
# Student: Harry 14 XYZ School
```

### 4. Constructors

```python
# Default Constructor
class Employee:
    def display(self):
        print("Inside Display Method")

emp = Employee()
emp.display()

# Output:
# Inside Display Method


# Non-Parameterized Constructor
class Company:
    def __init__(self):
        self.name = "PYnative"
        self.address = "ABC Street"

    def show(self):
        print("Name:", self.name, "Address:", self.address)

cmp = Company()
cmp.show()

# Output:
# Name: PYnative Address: ABC Street


# Parameterized Constructor
class Employee:
    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def show(self):
        print(self.name, self.age, self.salary)

e1 = Employee("Emma", 23, 7500)
e2 = Employee("Kelly", 25, 8500)

e1.show()
e2.show()

# Output:
# Emma 23 7500
# Kelly 25 8500
```

### 5. `__str__()` Method

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"{self.name} ({self.age})"

p1 = Person("John", 36)
print(p1)

# Output:
# John (36)
```

### 6. Object Methods

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def myfunc(self):
        print("Hello my name is", self.name)

p1 = Person("John", 36)
p1.myfunc()

# Output:
# Hello my name is John
```

### 7. Modify Object Properties

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p1 = Person("John", 36)
p1.age = 40
print("Modified Age:", p1.age)

# Output:
# Modified Age: 40
```

### 8. Delete Object

```python
class Employee:
    department = "IT"

    def show(self):
        print("Department is", self.department)

emp = Employee()
emp.show()

# Output:
# Department is IT
del emp

# emp.show()

# Output:
# NameError: name 'emp' is not defined
```

## Loops & Conditions

```python
numbers = [10, 15, 20, 25, 30]

# For loop with list
for num in numbers:
    print("Value:", num)

# For with range
for i in range(5):
    print(i)

# If / elif / else
x = 20
if x > 10:
    print("Greater than 10")
elif x == 10:
    print("Equal to 10")
else:
    print("Less than 10")

# While loop
n = 0
while n < 3:
    print("n =", n)
    n += 1

# Break
for num in numbers:
    if num == 25:
        break
    print(num)

# Continue
for num in numbers:
    if num == 20:
        continue
    print(num)

# Pass
for num in numbers:
    if num == 15:
        pass
    print(num)
```

## Strings & Conversions

```python
# String literals
a = 'Hello'
b = "World"
c = """Multi-line
string"""

print(a, b, c)

# Escape sequences
print("Hello\tthere\nHow are you?")
print("Quote: \"Hello\"")
print("Backslash: \\")

# Concatenation
full = a + " " + b
print(full)

# Length
print(len(full))

# Methods
text = "Python Programming"
print(text.lower())
print(str.lower(text))
print(text.upper())
print(text[0:6])
print(text.find("Pro"))
print(text.replace("Python","Java"))
print(text.split())

# ord & chr
print(ord('A'))
print(chr(66))

# Conversions
print(int("123"))
print(float("123"))
print(str(456))

# Formatting
name = "Ayush"
age = 20
print("My name is %s and age %d" % (name, age))
print("My name is {} and age {}".format(name, age))
print(f"My name is {name} and age {age}")
```

## Collections

```python
# List
lst = [10, 20, 30]
lst.append(40)
lst.insert(1, 15)
lst[2] = 25
lst.remove(25)
print(lst)

# List addition & copy
new = lst + [50]
copy_lst = new.copy()

# Stack
stack = []
stack.append(1)
stack.append(2)
stack.pop()
print(stack)

# Tuple
t = (1, 2, 3)
print(t)

# Set
s = {1, 2, 3}
s.add(4)
s.remove(2)
print(s)

# Dictionary
d = {"name": "Ayush", "age": 20}
d["grade"] = "A"
d["age"] = 21
del d["grade"]

for k, v in d.items():
    print(k, v)

copy_d = d.copy()
```

## Data Types & Mutability

```python
# Numbers
a = 2323
f = 32.3
c = 3 + 2j
print(a, f, c)

# Collections
l = [1, 2, 3]
t = (1, 2, 3)
d = {"hello": "there", 2: 15}

# Mixed
mixed = [1, "hi", 3.5, [1, 2], (5, 6), {"a": 1}]
print(mixed)

# Mutability
l[0] = 100
d["hello"] = "hi"
print(l, d)

# References
x = [1, 2, 3]
y = x
y[0] = 999
print(x, y)
```

## Functions

```python
def greet(n): return "Hello " + n
print(greet("Ayush"))

# Function as object
def hi(): print("Hi")
f = hi
f()

# Function as parameter
def shout(t): return t.upper()
def speak(func): print(func("hello"))
speak(shout)

# Higher order
def apply(f, v): return f(v)
def sq(x): return x * x
print(apply(sq, 5))

# map, filter, reduce
from functools import reduce
nums = [1, 2, 3, 4]
print(list(map(lambda x: x * x, nums)))
print(list(filter(lambda x: x % 2 == 0, nums)))
print(reduce(lambda a, b: a + b, nums))

# Named params
def intro(name, age): print(name, age)
intro(age=20, name="Ayush")

# Lambda
double = lambda x: x * 2
print(double(5))

# __str__ demo
class Student:
    def __init__(s, n, a):
        s.name = n; s.age = a
    def __str__(s):
        return f"{s.name}-{s.age}"
print(Student("Ayush", 20))

# toString style
class Car:
    def __init__(s, b, y):
        s.brand = b; s.year = y
    def toString(s):
        return f"{s.brand}-{s.year}"
print(Car("Tesla", 2024).toString())
```

## Inheritance

```python
# Basic
class Animal:
    def __init__(s, n): s.name = n
    def speak(s): print("Animal sound")

class Dog(Animal):
    def speak(s): print(s.name, "barks")

Dog("Tommy").speak()

# super()
class Person:
    def __init__(s, n): s.name = n

class Student(Person):
    def __init__(s, n, r):
        super().__init__(n)
        s.roll = r
    def show(s):
        print(s.name, s.roll)

Student("Ayush", 101).show()

# Multilevel
class A:
    def show1(s): print("Grandparent")
class B(A):
    def show2(s): print("Parent")
class C(B):
    def show3(s): print("Child")

c = C()
c.show1(); c.show2(); c.show3()

# Multiple
class Father:
    def skill1(s): print("Driving")
class Mother:
    def skill2(s): print("Cooking")

class Son(Father, Mother): pass

son = Son()
son.skill1()
son.skill2()
```

## Operator Precedence

From highest to lowest:

| Order | Operator(s) | Description |
|---|---|---|
| 1 | `()` | Parentheses |
| 2 | `**` | Exponentiation (right to left) |
| 3 | `+x`, `-x` | Unary plus/minus |
| 4 | `*`, `/`, `//` | Multiplication, division, floor division |
| 5 | `+`, `-` | Addition, subtraction |
| 6 | `==`, `!=`, `>`, `<`, `>=`, `<=` | Comparisons |
| 7 | `not` | Logical NOT |
| 8 | `and` | Logical AND |
| 9 | `or` | Logical OR |
| 10 | `=` | Assignment |

## Operator Reference

> The tables below were embedded as slide screenshots in the original document; they're reproduced here as plain Markdown tables.

### Arithmetic Operators

| Operator | Name | Example |
|---|---|---|
| `+` | Addition | `x + y` |
| `-` | Subtraction | `x - y` |
| `*` | Multiplication | `x * y` |
| `/` | Division | `x / y` |
| `%` | Modulus | `x % y` |
| `**` | Exponentiation | `x ** y` |
| `//` | Floor division | `x // y` |

### Assignment Operators

| Operator | Example | Same As |
|---|---|---|
| `=` | `x = 5` | `x = 5` |
| `+=` | `x += 3` | `x = x + 3` |
| `-=` | `x -= 3` | `x = x - 3` |
| `*=` | `x *= 3` | `x = x * 3` |
| `/=` | `x /= 3` | `x = x / 3` |
| `%=` | `x %= 3` | `x = x % 3` |
| `//=` | `x //= 3` | `x = x // 3` |
| `**=` | `x **= 3` | `x = x ** 3` |

### Comparison Operators

| Operator | Name | Example |
|---|---|---|
| `==` | Equal | `x == y` |
| `!=` | Not equal | `x != y` |
| `>` | Greater than | `x > y` |
| `<` | Less than | `x < y` |
| `>=` | Greater than or equal to | `x >= y` |
| `<=` | Less than or equal to | `x <= y` |

### Logical Operators

| Operator | Description | Example |
|---|---|---|
| `and` | Returns `True` if both statements are true | `x < 5 and x < 10` |
| `or` | Returns `True` if one of the statements is true | `x < 5 or x < 4` |
| `not` | Reverses the result; returns `False` if the result is true | `not(x < 5 and x < 10)` |

### Bitwise Operators

| Operator | Name | Description | Example |
|---|---|---|---|
| `&` | AND | Sets each bit to 1 if both bits are 1 | `x & y` |
| `\|` | OR | Sets each bit to 1 if one of two bits is 1 | `x \| y` |
| `^` | XOR | Sets each bit to 1 if only one of two bits is 1 | `x ^ y` |
| `~` | NOT | Inverts all the bits | `~x` |
| `<<` | Zero fill left shift | Shifts left, pushing zeros in from the right, leftmost bits fall off | `x << 2` |
| `>>` | Signed right shift | Shifts right, pushing copies of the leftmost bit in from the left, rightmost bits fall off | `x >> 2` |

### String Indexing

Strings support negative indexing, counting backward from the end:

```python
name = 'edureka'
name[2]
# this will give you the output as 'u'
```

```
 E    D    U    R    E    K    A
 0    1    2    3    4    5    6
-7   -6   -5   -4   -3   -2   -1
```

## Variable Naming Conventions

Multi-word variable names in Python are commonly written using one of these styles:

- **Camel Case** — each word, except the first, starts with a capital letter: `myVariableName = "John"`
- **Pascal Case** — each word starts with a capital letter: `MyVariableName = "John"`
- **Snake Case** — each word is separated by an underscore: `my_variable_name = "John"`

## Modules: Imports

| Statement | Effect |
|---|---|
| `import mymodule` | Brings all elements of `mymodule` in, but you must refer to them as `mymodule.<elem>` |
| `from mymodule import x` | Imports `x` from `mymodule` right into this namespace |
| `from mymodule import *` | Imports all elements of `mymodule` into this namespace |

## Math Commands

Python's `math` module provides useful commands (functions) for performing calculations. To use them, import the module first:

```python
from math import *
```

| Command | Description |
|---|---|
| `abs(value)` | Absolute value |
| `ceil(value)` | Rounds up |
| `cos(value)` | Cosine, in radians |
| `floor(value)` | Rounds down |
| `log(value)` | Logarithm, base *e* |
| `log10(value)` | Logarithm, base 10 |
| `max(value1, value2)` | Larger of two values |
| `min(value1, value2)` | Smaller of two values |
| `round(value)` | Nearest whole number |
| `sin(value)` | Sine, in radians |
| `sqrt(value)` | Square root |

| Constant | Description |
|---|---|
| `e` | 2.7182818... |
| `pi` | 3.1415926... |
