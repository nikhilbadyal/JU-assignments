#include <stdio.h>
#include <stdlib.h>

#define DEF_USR_SPACE 200
#define TRUE          1
#define FALSE         0
#define MAX_FREE_BLOCKS 20
#define SENTINEL_INDEX  -1


typedefstructblock_tag{
structblock_tag* next;
    short intinitialSize;
    short intmaxFreeSize;
    void*             FreeSpaceRoot;
}block;

typedefstructblock_info_tag{
    block* tail;
    short intnum_blocks;
} block_info;

block_infoBlocksInUse;
block_infoBlocksFree;



void init_usr_space(block *b){

    char* block_point = (char *)b;
    short int* block_write = NULL;

block_point = b->FreeSpaceRoot;
block_write = (short *)block_point;
    *block_write = (b->initialSize)<<1;


block_write += 1;
    *block_write = SENTINEL_INDEX;


block_write += 1;
    *block_write = SENTINEL_INDEX;


}

block* create_block(int size){
if(size < DEF_USR_SPACE) size = DEF_USR_SPACE;

    block* new_block = (block *)malloc(sizeof(block) + size);
new_block->next  = NULL;
new_block->initialSize = size;
new_block->maxFreeSize = size;
new_block->FreeSpaceRoot = (void *)((char *)new_block + sizeof(block));
init_usr_space(new_block);

    return new_block;
}


void add_block(block_info* info_block, block* target){
info_block->num_blocks++;
    if(info_block->tail == NULL){
info_block->tail = target;
        target->next     = target;
    }
else{
        target->next = info_block->tail->next;
info_block->tail->next = target;
info_block->tail       = target;
    }
}


void del_block(block_info *info_block, block* prev){
info_block->num_blocks --;
    block* temp = prev->next;
prev->next = temp->next;

    if(info_block->tail == temp)
info_block->tail = prev;
    free(temp);
}


block* rem_block(block_info* info_block, block* prev){
info_block->num_blocks--;
    block* temp = prev->next;
prev->next = temp->next;

    if(info_block->tail == temp)
info_block->tail = prev;

    return temp;
}



block* fetch_block(int size){
if(BlocksInUse.num_blocks != 0){
        block* iterator = BlocksInUse.tail->next;
do{
            if(iterator->maxFreeSize>= size)
                return iterator;
            iterator = iterator->next;
}while(iterator != BlocksInUse.tail->next);
    }

    block* block_to_use = NULL;

if(BlocksFree.num_blocks != 0){
        block* iterator = BlocksFree.tail;
intmin_size = -1;
        block* prev = iterator;
do{
            if(iterator->maxFreeSize>= size){
if(min_size == -1){
min_size = iterator->maxFreeSize;
block_to_use = prev;
                }
                else if(iterator->maxFreeSize<min_size){
min_size = iterator->maxFreeSize;
block_to_use = prev;
                }
            }
prev = iterator;
            iterator = iterator->next;
}while(iterator != BlocksFree.tail);
    }

if(block_to_use == NULL) block_to_use = create_block(size);
    else block_to_use = rem_block(&BlocksFree, block_to_use);

add_block(&BlocksInUse, block_to_use);
    return block_to_use;
}

void mem_alloc(int size){

}

intmain(){
fetch_block(10);
}
