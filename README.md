# Event Controller

### Dynamically allocated function pointer arrays.

Basic event controller for calling subscribed functions for the event.

### Usage

There is a example usage of event controller in main function.

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
