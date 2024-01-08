// Dynamic Function Pointer Array Allocation - Basic Event Controller 
// EventController library based on event.h 2024, Irq handle functions.
// Created : 03-11-2023 : BerkN
// Updates available at https://github.com/BerkN/EventController

#ifndef EVENT_H_
#define EVENT_H_

#include <stdlib.h>
#include <stdint.h>

typedef void (*Event_t)(void);

void eventInit();
void eventCallAll(void);
void eventAdd(void (*event));
void eventRemove();

uint8_t get_eventArraySize();
uint8_t get_eventArrayCapacity();


#endif