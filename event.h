/*
 *  event.h
 *
 *  Dynamic Function Pointer Array Allocation - Basic Event Controller
 *  EventController library based on event.h 2024, Irq handle functions.
 *  Created : 08-01-2024 : BerkN
 *  Update  : 26-08-2024 : event Constructor added.
 *  Updates available at https://github.com/BerkN/EventController
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <stdlib.h>
#include <stdint.h>

#define EVENT_INIT_CAPACITY         2
#define EVENT_MAX_CAPACITY          16

typedef enum{
    EVENT_CLOSE = 0,
    EVENT_READY = 1,
    EVENT_ERROR = 2
}eventState_e;

typedef void (*event_t)(void);

typedef struct{
    event_t* arr;          /* Events for ready to call */
    uint8_t  arr_size;     /* Number of event_t in the array */
    uint8_t  arr_capacity; /* @arr length */
    eventState_e state;    /* Debugging state of the eventHandle_t */
}eventHandle_t;

/*  @brief Creates new eventHandle. Initial
 *  allocated memory for event functions is
 *  described as @EVENT_INIT_CAPACITY
 *
 *  @return eventHandle_t constructor
 *  @retval handle.state == EVENT_ERROR:
 *  memory allocation error!
 *  @retval handle.state == EVENT_READY:
 *  successful memory allocation.
 */
eventHandle_t eventNew(void);

/*  @brief Calls every event_t event function
 *  in the handle array (@handle->arr).
 *
 *  @param handle: object pointer.
 */
void eventCall(eventHandle_t* handle);

/*  @brief Adds event_t function in the handle
 *  array. If arr_size is exceeds the capacity
 *  of the event_t array, reallocates the memory
 *  as capacity multiplied by 2. If handle is not
 *  initalized (not used the construct function)
 *  @eventNew(), it constructs the object.
 *
 *  @param handle: object pointer.
 */
void eventAdd(eventHandle_t* handle, event_t event);

/*  @brief Removes last event_t function in the
 *  handle array.
 *
 *  @param handle: object pointer.
 */
void eventRemove(eventHandle_t* handle);

/*  @brief Frees the allocated event_t array
 *  memory. Deconstruction of the object. Do not
 *  use after deconstruction.
 *
 *  @param handle: object pointer.
 */
void eventFree(eventHandle_t* handle);

#endif
