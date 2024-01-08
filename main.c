// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 03-11-2023 : BerkN
// Updates available at https://github.com/BerkN/EventController

#include <stdio.h>
#include "event.h"

void test_a();
void test_b();
void test_c();

int main (int argc, char *argv[]){
    printf("Event Controller Test \r\n");
    printf("...\r\n");
    
    eventInit();
    printf("Initalized Event Array Size : %d\r\n",get_eventArraySize());
    printf("Initalized Event Array Capacity : %d\r\n",get_eventArrayCapacity());

    eventAdd(&test_a);
    eventAdd(&test_a);
    eventAdd(&test_b);
    eventAdd(&test_b);
    eventAdd(&test_c);
    eventAdd(&test_c);
    
    printf("Added 6 Event. \r\n");
    printf("Event Array Size : %d\r\n",get_eventArraySize());
    printf("Event Array Capacity : %d\r\n",get_eventArrayCapacity());
    
    printf("...\r\n");

    eventCallAll(); 
  
    printf("...\r\n");
    
    eventRemove();
    printf("Removed Last Event. \r\n");
    printf("Event Array Size : %d\r\n",get_eventArraySize());
    printf("Event Array Capacity : %d\r\n",get_eventArrayCapacity());
  
    printf("...\r\n");  
    eventCallAll();
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
