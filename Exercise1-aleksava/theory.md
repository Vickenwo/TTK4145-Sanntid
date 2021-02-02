Exercise 1 - Theory questions
-----------------------------
 
What is the difference between concurrency and parallelism?
Concurrency is when two or more tasks can start and run at overlapping time periods, but not ran at the same time. This is often done with a scheduler assigning the different tasks "time" to use the processor, and ensuring that every task gets done a little at a time. While parallelism on the other hand is when two or more tasks are ran in parallell, at the same time. This could be on a multi-core processor.

Why have machines become increasingly multicore in the past decade?
Until recently machine hardware has followed Moore's law, which has shown that the number of transistors on a single core has been increased exponetially. This has led to higher clock frequiencies, and better performance. But during 2000-2020, the number of transistors has came to a halt, since it is no long physically possible to increase the transistor amount, while keeping high clock frequencies due to overheating. Because of this constraint, the processor manufactures has instead focused on increasing the number of cores, to keep increasing the performance of the processors.

Why do we divide software (programs) into concurrently executing parts (like threads or processes)?
(Or phrased differently: What problems do concurrency help in solving?) The main reason we do this is to increase the efficiency of the program. For example if multiple processes has to read and write to IO, this is was slower than doing aritmetics in the processor. So why wait for the IO, when we instead can ask that process to tell us when the data is ready, and meanwhile calculate other problems.

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
When it comes to concurrent programs, it can greatly increase the runningtime of your program. But in order to execute it correctly, you as a programmer has to be aware of the hurdles, so that you make sure your program doesn't end up with race conditions and other interference.

What is the conceptual difference between threads and processes?
The main difference is that processes are isolated programs which could contain multiple threads. Whereas threads share memory, while processes does not.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they?
The way I understand it is that a fiber or "corutines" is a form of thread that bases on cooperative multitasking rather than preemtive multitasking. In order to let another fiber "use" the processor, it has to yield its position, almost like a queue. This is more useful than a thread which may be interrupted at any time.

What is the Go-language's "goroutine"? A C/POSIX "pthread"?
A goroutine is a lightweight thread, close related to fibers and coroutines. Pthreads are an implementation of threads for C/POSIX.

In Go, what does func GOMAXPROCS(n int) int change?
The function changes how many operating system threads that can work simultaneously with the Go-code runs.


 
 
 
 
