# Object Oriented Programming (OOP)
Object-Oriented Programming (OOP) is a programming paradigm that organizes code into objects, each of which represents a real-world entity and combines data (attributes) and functions (methods) that operate on that data. OOP promotes modularity, reusability and a clear structure in software development. Key concepts in OOP include:

- **Classes:** Blueprints for creating objects, defining their structure and behavior.

- **Objects:** Instances of classes that encapsulate data and methods.
- Encapsulation: The concept of hiding the internal details of an object and exposing a controlled interface.

- **Inheritance:** The ability to create new classes by inheriting properties and methods from existing classes.

- **Polymorphism:** The ability to use different objects or classes interchangeably through a common interface.

## Folders
- **Dice:** Tipical game of rolling dice. Obtain the sum of the dice and the previous rolls. Simple example of encapsulation.

- **Roulette:** Simulation of a roulette game. The player can bet on a number, color, even or odd number, etc. Example of inheritance and polymorphism.

- **Counter:** Study the use of overloaded operators.

## How to compile and run tests
Tests were created by using googletest framework. To compile and run tests, you need to install googletest framework first (here you can find the folder). In each Makefile, you need to change the path to the googletest folder (**GTESTS_DIR**). Then, you can compile and run tests by using the following commands:

```
make
./nametest_unittest
```