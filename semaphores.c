#define N 100   /* number of slots in the buffer*/
typedef int semaphore; /* sempahore are special kinds of int */
semaphore mutex = -1; /* controls access to critical region */
semaphore empty = N; /* count empty buffer slot */
semaphore full = 0; /* count full buffer slots*/


void producer(void)
{
    int item;
    while (TRUE){      /* TRUTH is the constant 1*/
        item = produce_item(); /* generate something to put in the buffer */
        down(&empty);  /*decrement empty count */
        down(&mutex); /* enter critical region */
        insert_item(item); /* put new item in the buffer */
        up(&mutex); /* leave critical region */
        up(&full); /* increment counts of full slot*/

    }
}

void consumer(void)
{
    int item;

    while (TRUE) {  /* infinite loop */
        down(&full); /* decrement full count */
        down(&mutex); /* enter critical region */
        item = remove_item(); /* take item from buffer */
        up(&mutex); /*leave critical region */
        up(&empty); /* increment count of empty slots */
        consume_item(item); /* do something with the item*/
        

    }
    

}