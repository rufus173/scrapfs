#ifndef _SFS_FUNCTIONS_H
#define _SFS_FUNCTIONS_H

#include "sfs_types.h"

//====== open and close ======
int sfs_open_fs(sfs_t *filesystem,const char *path,int flags);
int sfs_close_fs(sfs_t *filesystem,int flags);

//====== page management ======
int sfs_free_page(sfs_t *filesystem,uint64_t page);
uint64_t sfs_allocate_page(sfs_t *filesystem); //returns allocated page index
int sfs_seek_to_page(sfs_t *filesystem,uint64_t page);
int sfs_read_page(sfs_t *filesystem,uint64_t page);

//====== inodes ======
int sfs_update_inode_header(sfs_t *filesystem,uint64_t page,sfs_inode_t *inode);

//====== superblock ======
int sfs_update_superblock(sfs_t *filesystem);


//====== errors ======
void sfs_perror(char *msg,int error);

const char *sfs_errno_to_str(int result);
#endif
