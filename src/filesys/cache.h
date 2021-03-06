#include "devices/block.h"
#include "threads/thread.h"

#define MAX_BUFFER_CACHE_NUM 64

struct buffer_cache {
  int cache_id; 
  // struct inode *inode;
  // block_sector_t inode_sector;
  block_sector_t sector_id;

  int sector_ofs;
  int chunk_size;

  void *cache;
  bool is_dirty;
  struct list_elem elem;
};

/* need to init in filesys_init function */

struct lock buffer_cache_lock;

void buffer_cache_init();
struct buffer_cache *create_buffer_cache (block_sector_t sector_id, void *data);
void push_buffer_cache_to_list (struct buffer_cache *cache);
void delete_buffer_cache (struct buffer_cache *cache);
struct buffer_cache *get_buffer_cache (block_sector_t sector_id);
void buffer_cache_read(block_sector_t sector_id, void *buffer);
void buffer_cache_write(block_sector_t sector_id, void *buffer);




