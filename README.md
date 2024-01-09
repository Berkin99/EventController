# Event Controller

### Dynamically allocated function pointer arrays.

Basic event controller example for interrupt request
handler function like applications. 

IRQ vector functions predefined in embedded systems. If you 
want to dynamically change called other functions in interrupt request 
function, you need to add event controller library.

### Usage

There is a example usage of event controller in main function.

* void eventInit(EventHandle_t* handle);                 // Init Function
* void eventCall(EventHandle_t* handle);                 // IRQ vector 
* void eventAdd(EventHandle_t* handle, void (*event));   // Add function (functions need to be get and return void )
* void eventRemove(EventHandle_t* handle);               // Remove last element
* void eventFree(EventHandle_t* handle);                 // Free allocated memory for event functions.
