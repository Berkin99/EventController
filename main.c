// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 08-01-2024 : BerkN
// Updates available at https://github.com/BerkN/EventController

#include <stdio.h>
#include "event.h"

void test_a();
void test_b();
void test_c();

EventHandle_t eventHandler;

int main (int argc, char *argv[]){
    printf("Event Controller Test \r\n");
    printf("...\r\n");
    
    eventInit(&eventHandler);
    printf("Initalized Event Array Size : %d\r\n",eventHandler.arr_size);
    printf("Initalized Event Array Capacity : %d\r\n",eventHandler.arr_capacity);

    eventAdd(&eventHandler,&test_a);
    eventAdd(&eventHandler,&test_b);
    eventAdd(&eventHandler,&test_c);
    
    printf("Added 3 Event. \r\n");
    printf("Event Array Size : %d\r\n",eventHandler.arr_size);
    printf("Event Array Capacity : %d\r\n",eventHandler.arr_capacity);
    
    printf("...\r\n");

    eventCall(&eventHandler); 
  
    printf("...\r\n");

    eventRemove(&eventHandler);
    printf("Removed Last Element. \r\n");
    printf("Event Array Size : %d\r\n",eventHandler.arr_size);
    printf("Event Array Capacity : %d\r\n",eventHandler.arr_capacity);
  
    printf("...\r\n");  
    eventCall(&eventHandler);
}

void test_a(){
    printf("test_a called.\r\n");
}
void test_b(){
    printf("test_b called.\r\n");
}
void test_c(){
    printf("test_c called.\r\n");
}
