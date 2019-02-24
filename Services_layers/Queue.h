/*
 * Queue.h
 *
 *  Created on: 1 Feb 2019
 *      Author: root
 */

#ifndef SERVICES_LAYERS_QUEUE_H_
#define SERVICES_LAYERS_QUEUE_H_

#define BUFFER_SIZE		25

typedef struct Queue Queue_t;
struct Queue
{
	unsigned char Buffer[BUFFER_SIZE];
	int head;
	int tail;
	int conut;
};

void Queue_Enqueue(Queue_t *me , unsigned char incomingdata);
void Queue_Dequeue(Queue_t *me , unsigned char *Data);
int Queue_getSize(Queue_t *me);
char Queue_isFull(Queue_t *me);
char Queue_isEmpty(Queue_t *me);


#endif /* SERVICES_LAYERS_QUEUE_H_ */
