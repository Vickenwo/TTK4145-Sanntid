From running the program with multiple OS-threads activated. It is clear that the number output
is sort of random, following which function gets it priortiy. 

In Go, when we limited the OS-threads to 1, but utilizing "GOMAXPROCS(1)", I found that we get the
correct answer. This is due to the functions not having to fight for race conditions.   