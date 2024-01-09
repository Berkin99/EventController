// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 08-01-2024 : BerkN
// Updates available at https://github.com/BerkN/EventController

#ifndef EVENT_H_
#define EVENT_H_

#include <stdlib.h>
#include <stdint.h>

#define EVENT_INIT_CAPACITY         2
#define EVENT_MAX_CAPACITY          8

typedef void (*Event_t)(void);

typedef struct EventHandle_s{
    Event_t* arr;
    uint8_t  arr_size;
    uint8_t  arr_capacity;
}EventHandle_t;

void eventInit(EventHandle_t* handle);
void eventCall(EventHandle_t* handle);
void eventAdd(EventHandle_t* handle, void (*event));
void eventRemove(EventHandle_t* handle);
void eventFree(EventHandle_t* handle);

#endif