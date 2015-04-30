#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <deque>

using namespace std;

#ifndef _PAGING_H_
#define _PAGING_H_


const int PAGE_MISS = 0;
const int PAGE_IN_TABLE = 1;
const int EMPTY_FRAME = 2;

struct page{
	int frame_num;
	int page_num;
};


//Paging Functions
void create_frame_table(  page **frame_table, int *frames );
void create_page_list( int *frames, page **page_list, int *pages, int *page_requests );
void paging_algorithm( int *page_table, int* pages, int *frame_table, int *frames, int *page_size, int *p, int *d);
void access_physical_mem( const int *d, const int *frame, const int *frames, const int *page);
int page_miss( page *p, page ** frame_table, int size );
int insert_in_open( page *p, page ** frame_table, int size );

void print_frame_table(page **frame_table, int frames);


#endif

