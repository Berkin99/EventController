# Event Controller

### Dynamically allocated function pointer arrays.

Basic event controller example for interrupt request
handler function like applications. 

IRQ vector functions predefined in embedded systems. If you 
want to dynamically change called other functions in interrupt request 
function, you need to add event controller library.

### Usage

There is a example usage of event controller in main function.

- void eventInit(); // Init Function

- void eventCallAll(void); // IRQ vector 
- void eventAdd(void (*event)); // Add function (functions need to be get and return void )
- void eventRemove(); // Remove last element

- uint8_t get_eventArraySize();
- uint8_t get_eventArrayCapacity();
