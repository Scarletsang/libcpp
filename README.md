# libcpp

This is a small cpp library to recreate some functional types that help with chaining computation, as well as cpp features that are later than cpp98 that help with memory mangement. This is created solely for the purpose to assist projects in the 42 cirriculum, and of course, educational purposes.

## Content

### Maybe monad (std::optional)

This is a type that encapsulate the possibility that something can fail. When one is expecting a failure, instead of throwing an exception, one might as well return a Maybe object that contains the data if the computation succeed to run.

### Result monad (std::expected)

Similar use of Maybe, but when failure, one can also return an object that represents an error. It is useful when you need to know how you fail in certain computation.

### Simple parser framework

This is a simple parser framework that facilitates extendable and readable parser by using Maybe and Result type to chain parser functions. There is a `chain` method on both Maybe and Result monad that make the chaining possible. This way of function composition/chaining is called monad.

### UniquePtr

This enforce the idea of ownership on data, so that the programmer is crystal clear about where they store their data.

### SharedPtr & WeakPtr

This enables shared ownership of data, while the programmer should still be very clear of where they store the data.