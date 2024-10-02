/*  Dynamic Function Pointer Array Allocation - Basic Event Controller
 *  EventController library based on event.h 2024, Irq handle functions.
 *  Created : 08-01-2024 : BerkN
 *  Update  : 26-08-2024 : event Constructor added.
 *  Updates available at https://github.com/BerkN/EventController
 */

#include <stdio.h>
#include "event.h"

void test_a();
void test_b();
void test_c();

int main (int argc, char *argv[]){

    printf("Event Controller Test \r\n");
    printf("...\r\n");

    eventHandle_t handle;

    printf("Initalized Event State : %d\r\n",handle.state);
    printf("Initalized Event Array Size : %d\r\n",handle.arr_size);
    printf("Initalized Event Array Capacity : %d\r\n",handle.arr_capacity);

    eventAdd(&handle,&test_a);
    eventAdd(&handle,&test_b);
    eventAdd(&handle,&test_c);
    
    printf("Added 3 Event. \r\n");
    printf("Event Array Size : %d\r\n",handle.arr_size);
    printf("Event Array Capacity : %d\r\n",handle.arr_capacity);
    
    printf("...\r\n");

    eventCall(&handle); 
  
    printf("...\r\n");

    eventRemove(&handle);
    printf("Removed Last Element. \r\n");
    printf("Event Array Size : %d\r\n",handle.arr_size);
    printf("Event Array Capacity : %d\r\n",handle.arr_capacity);
  
    printf("...\r\n");  
    eventCall(&handle);
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
