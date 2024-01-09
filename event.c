// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 08-01-2024 : BerkN
// Updates available at https://github.com/BerkN/EventController

#include <stdlib.h>
#include <stdint.h>
#include "event.h"


void eventInit(EventHandle_t* handle){
    handle->arr_capacity = EVENT_INIT_CAPACITY;
	handle->arr_size = 0;
	handle->arr = malloc(handle->arr_capacity * sizeof(Event_t));
}

void eventCall(EventHandle_t* handle){
    for (uint8_t i = 0; i < handle->arr_size; i++) {
        Event_t temp = handle->arr[i];
        temp();
    }
}

void eventAdd(EventHandle_t* handle, void (*event)){
	
    if(handle->arr_size == EVENT_MAX_CAPACITY) return;
    handle->arr_size++;
	if (handle->arr_size > handle->arr_capacity) {
        
		handle->arr_capacity *= 2;        
        if((handle->arr_capacity)>EVENT_MAX_CAPACITY) handle->arr_capacity = EVENT_MAX_CAPACITY;
        handle->arr = realloc(handle->arr,handle->arr_capacity * sizeof(Event_t));
	}

    if(handle->arr_size>handle->arr_capacity) return;
	handle->arr[handle->arr_size -1] = event;
}

void eventRemove(EventHandle_t* handle){
    if (!(handle->arr_size > 0)) return;
    handle->arr[handle->arr_size-1] = NULL;
    handle->arr_size--;
}

void eventFree(EventHandle_t* handle){
    free(handle->arr);
}