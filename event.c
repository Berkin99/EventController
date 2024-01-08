// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 03-11-2023 : BerkN
// Updates available at https://github.com/BerkN/EventController

#include <stdlib.h>
#include <stdint.h>
#include "event.h"

Event_t* arr;
static uint8_t arr_size;
static uint8_t arr_capacity;

void eventCallAll(void){
    for (uint8_t i = 0; i < arr_size; i++) {
        Event_t temp = arr[i];
        temp();
    }
}

void eventInit(){
    arr_capacity = 4;
	arr_size = 0;
	arr = malloc(arr_capacity * sizeof(Event_t));
}

void eventAdd(void (*event)){
	arr_size++;
	if (arr_size > arr_capacity) {
		arr_capacity *= 2;
		arr = realloc(arr,arr_capacity * sizeof(Event_t));
	}
	arr[arr_size-1] = event;
}


void eventRemove(){
    if (!(arr_size > 0)) return;
    arr[arr_size-1] = NULL;
    arr_size--;
}

uint8_t get_eventArraySize(){return arr_size;}
uint8_t get_eventArrayCapacity(){return arr_capacity;}
