/*
 *  event.c
 *
 *  Dynamic Function Pointer Array Allocation - Basic Event Controller
 *  EventController library based on event.h 2024, Irq handle functions.
 *  Created : 08-01-2024 : BerkN
 *  Update  : 26-08-2024 : event Constructor added.
 *  Updates available at https://github.com/BerkN/EventController
 */


#include <stdlib.h>
#include <stdint.h>

#include "event.h"

eventHandle_t eventNew(void){
    eventHandle_t handle;
    handle.arr_capacity = EVENT_INIT_CAPACITY;
    handle.arr_size = 0;
    handle.arr = malloc(handle.arr_capacity * sizeof(event_t));
    if(handle.arr != NULL){
        handle.state = EVENT_READY;
        return handle;
    }
    handle.state = EVENT_ERROR;
    return handle;
}

void eventCall(eventHandle_t* handle){
    if(handle->state != EVENT_READY) return;

    for (uint8_t i = 0; i < handle->arr_size; i++) {
        event_t temp = handle->arr[i];
        temp();
    }
}

void eventAdd(eventHandle_t* handle, event_t event){
    if (handle->state != EVENT_READY) {
        *handle = eventNew();
        if (handle->state != EVENT_READY) return;
    }

    if(handle->arr_size == EVENT_MAX_CAPACITY) return;
    handle->arr_size++;
    if (handle->arr_size > handle->arr_capacity) {

        handle->arr_capacity *= 2;
        if((handle->arr_capacity)>EVENT_MAX_CAPACITY) handle->arr_capacity = EVENT_MAX_CAPACITY;
        handle->arr = realloc(handle->arr,handle->arr_capacity * sizeof(event_t));
    }

    if(handle->arr_size>handle->arr_capacity) return;
    handle->arr[handle->arr_size -1] = event;
}

void eventRemove(eventHandle_t* handle){
    if(handle->state != EVENT_READY) return;

    if (!(handle->arr_size > 0)) return;
    handle->arr[handle->arr_size-1] = NULL;
    handle->arr_size--;
}

void eventFree(eventHandle_t* handle){
    if(handle->state != EVENT_READY) return;
    free(handle->arr);
}
