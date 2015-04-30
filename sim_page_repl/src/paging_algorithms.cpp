
#ifndef _PAGING_H_
#include "../include/paging.h"
#endif

#ifndef _PAGING_ALG_H_
#include "../include/paging_algorithms.h"
#endif

void fifo_alg(void){
    //Create table to simulate frames
    page *frame_table;
    deque<page> fifo_queue;

    // Create table to simulate list lookup
    page *page_list;
    page temp;
    //number of pages/frames
    int pages, frames;
    int page_requests;
    int page_request_key;

    //number of simulations to run
    int iterations;
    int p, d, i;

    //Generate a mock frame table, list of pages, list of pages to be requested
    create_frame_table( &frame_table, &frames );
    create_page_list( &frames, &page_list, &pages, &page_requests );

    // Create the fifo queue
    temp.page_num = -1;

    printf("Initial frame table!\n");
    print_frame_table( &frame_table, frames);


    for( i = 0; i < page_requests; i++ )
    {
    	printf("\nRequesting page %d\n", page_list[i].page_num);
    	page_request_key = page_miss( &page_list[i], &frame_table, frames);

        if(  page_request_key == PAGE_MISS ){
        	printf("Request for page %d was a miss!\n", (page_list[i]).page_num);

    		temp = fifo_queue.front();
    		fifo_queue.pop_front();
    		page_list[i].frame_num = temp.frame_num;
    		frame_table[temp.frame_num] = page_list[i];
    		fifo_queue.push_back(page_list[i]);
    	
        	print_frame_table(&frame_table, frames);
        }

        else if( page_request_key == PAGE_IN_TABLE ){
        	printf("Page already in table! No replacement necessary!\n");
        }

        else if( page_request_key == EMPTY_FRAME){
        	printf("Empty Frame Found!\n" );
        	page_list[i].frame_num = insert_in_open(&page_list[i], &frame_table, frames);
        	fifo_queue.push_back(page_list[i]);
        }

        else{
        	printf("Oops! Something weird happened!\n");
        }

        sleep(1);
    }


    printf( "\nFinal page table: \n");
    print_frame_table( &frame_table, frames );

    free(page_list);
    free(frame_table);

}


void optimal_alg(void){

	   //Create table to simulate frames
    page *frame_table;

    // Create table to simulate list lookup
    page *page_list;
    page temp;
    //number of pages/frames
    int pages, frames;
    int page_requests;
    int page_request_key;

    //number of simulations to run
    int repl_index;
    int p, d, i;

    //Generate a mock frame table, list of pages, list of pages to be requested
    create_frame_table( &frame_table, &frames );
    create_page_list( &frames, &page_list, &pages, &page_requests );

    // Create the fifo queue
    temp.page_num = -1;

    printf("Initial frame table!\n");
    print_frame_table( &frame_table, frames);

    printf("Initial page list!\n");
    print_frame_table( &page_list, page_requests );


    for( i = 0; i < page_requests; i++ )
    {
    	printf("\nRequesting page %d\n", page_list[i].page_num);
    	page_request_key = page_miss( &page_list[i], &frame_table, frames);

        if(  page_request_key == PAGE_MISS ){
        	printf("Request for page %d was a miss!\n", (page_list[i]).page_num);

        	repl_index = find_optimal_repl(&frame_table, &page_list, frames, pages, i );
        	page_list[i].frame_num = repl_index;
        	frame_table[repl_index] = page_list[i];

        	print_frame_table(&frame_table, frames);
        }

        else if( page_request_key == PAGE_IN_TABLE ){
        	printf("Page already in table! No replacement necessary!\n");
        }

        else if( page_request_key == EMPTY_FRAME){
        	printf("Empty Frame Found!\n" );
        	page_list[i].frame_num = insert_in_open(&page_list[i], &frame_table, frames);

        }

        else{
        	printf("Oops! Something weird happened!\n");
        }

        sleep(1);
    }


    printf( "\nFinal page table: \n");
    print_frame_table( &frame_table, frames );

    free(page_list);
    free(frame_table);
}

void lru_alg(void){
	printf("Made it to lru\n");
	return;
}