Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
An atomic operation is defined as program operations that run independently of any other processes.
In concurrent programming, this can be done by "locking" variable data during the dataprocessing step, if multiple instances uses the same data.

### What is a critical section?
A critical section is that part of the code where shared variables are accessed. In order to operate on this safely, we have to apply atomic action.

### What is the difference between race conditions and data races?
A race conditin is a situation where multiple operations tries to change the same data, and that the result is based upon which operation is carried out first.
While a data race is a situation where two or more threads access a shared variable at the same time. And at least one of the threads try to change it. 

### What are the differences between semaphores, binary semaphores, and mutexes?
A semaphore is an atomic non-negative integrer with two operations. Wait() - which decrements its value by 1 and Signal() - which increments by 1. 
So that if a wait() signal is ran on a zero semaphore we have to wait until we get a free thread. 
A binary semaphore has two states, 0 or 1, which can be described as unavailiable and availiable.
While the two mentioned above works as resource locking where everyone has the key, the mutex, mutual exclusion, takes ownership or its "lock".
Therefore keeping thier thread locked until they says it is done.


### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
Channels, mailboxes and queues are all used for message passing, the difference is in how it is done. 
Channels are synchronous and symmetric, like a phone call, where you have to set up a closed communication in order to send or recieve data.
A mailbox is asynchronous and asymmetric in a way that the recieve messages from all over, and then other processes can pick it up whenever.
The last element is a queue, which is FIFO. This ensures that all the tasks get a thread, but not in an optimal manner. 


### List some advantages of using message passing over lock-based synchronization primitives.
1. Message passing systems are nice for big systems which involves multiple data handelers, because it can store the data in multiple places, and send around copies of variables needed. 
This way we can recover fast if there should be a computer breakdown.
2. The messages can contain almost anything.
3. The thread is responsible for its own data. 

### List some advantages of using lock-based synchronization primitives over message passing.
1. Threadlocking gives us concurrency on systems with say one processor.
2. Messageing isn't really viable for single systems. 
