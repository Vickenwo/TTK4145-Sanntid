4: Choosing a language

In this multi elevator project i think it would be reasonable to movde data through message-passing. This way we can better controll
conflicts when multiple instances uses the same data. As well as keeping the data secure if one or more of the systems should fail.
Concurrency will most likely be used in order to process the order queue. This is due to having three elevators service one common queue.

I think the modules should be split so that functions and objects with things in common will go together.
So a line up of modules could be: Hardware, Orders, Network, States, Events and Drivers. 
This is just a mock up, as this is not discussed with my group.

For networking it seems that UDP and TCP is viable options. But that UDP is easier in use due to not having to esablish a
connection, and also having free package size. Both of which is available from go-libraries. 

When it comes to testing multithreaded code, it's not just straight forward. It seems that VS code includes some tools for debugging,
but I think we have to do most of the module testing by writing test code our self. 

