/*
   Copyright 2008 Gemius SA.

   This file is part of MooseFS.

   MooseFS is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, version 3.

   MooseFS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MooseFS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MASTERCOMM_H_
#define _MASTERCOMM_H_

#include <inttypes.h>

int fs_direct_connect(void);
void fs_direct_close(int rfd);
int fs_direct_write(int rfd,const uint8_t *buff,uint32_t size);
int fs_direct_read(int rfd,uint8_t *buff,uint32_t size);

void fs_statfs(uint64_t *totalspace,uint64_t *availspace,uint64_t *trashspace,uint64_t *reservedspace,uint32_t *inodes);
uint8_t fs_access(uint32_t inode,uint32_t uid,uint32_t gid,uint8_t modemask);
uint8_t fs_lookup(uint32_t parent,uint8_t nleng,const uint8_t *name,uint32_t uid,uint32_t gid,uint32_t *inode,uint8_t attr[35]);
uint8_t fs_getattr(uint32_t inode,uint8_t attr[35]);
uint8_t fs_setattr(uint32_t inode,uint32_t uid,uint32_t gid,uint8_t setmask,uint16_t attrmode,uint32_t attruid,uint32_t attrgid,uint32_t attratime,uint32_t attrmtime,uint8_t attr[35]);
uint8_t fs_truncate(uint32_t inode,uint32_t uid,uint32_t gid,uint64_t attrlength,uint8_t attr[35]);
uint8_t fs_readlink(uint32_t inode,uint8_t **path);
uint8_t fs_symlink(uint32_t parent,uint8_t nleng,const uint8_t *name,const uint8_t *path,uint32_t uid,uint32_t gid,uint32_t *inode,uint8_t attr[35]);
uint8_t fs_mknod(uint32_t parent,uint8_t nleng,const uint8_t *name,uint8_t type,uint16_t mode,uint32_t uid,uint32_t gid,uint32_t rdev,uint32_t *inode,uint8_t attr[35]);
uint8_t fs_mkdir(uint32_t parent,uint8_t nleng,const uint8_t *name,uint16_t mode,uint32_t uid,uint32_t gid,uint32_t *inode,uint8_t attr[35]);
uint8_t fs_unlink(uint32_t parent,uint8_t nleng,const uint8_t *name,uint32_t uid,uint32_t gid);
uint8_t fs_rmdir(uint32_t parent,uint8_t nleng,const uint8_t *name,uint32_t uid,uint32_t gid);
uint8_t fs_rename(uint32_t parent_src,uint8_t nleng_src,const uint8_t *name_src,uint32_t parent_dst,uint8_t nleng,const uint8_t *name_dst,uint32_t uid,uint32_t gid);
uint8_t fs_link(uint32_t inode_src,uint32_t parent_dst,uint8_t nleng_dst,const uint8_t *name_dst,uint32_t uid,uint32_t gid,uint32_t *inode,uint8_t attr[35]);
uint8_t fs_getdir(uint32_t inode,uint32_t uid,uint32_t gid,uint8_t **dbuff,uint32_t *dbuffsize);

uint8_t fs_check(uint32_t inode,uint8_t dbuff[22]);

uint8_t fs_opencheck(uint32_t inode,uint32_t uid,uint32_t gid,uint8_t flags);
void fs_release(uint32_t inode);

uint8_t fs_readchunk(uint32_t inode,uint32_t indx,uint64_t *length,uint64_t *chunkid,uint32_t *version,uint32_t *ip,uint16_t *port);
uint8_t fs_writechunk(uint32_t inode,uint32_t indx,uint64_t *length,uint64_t *chunkid,uint32_t *version,uint32_t *csip,uint16_t *csport,uint8_t **chain,uint32_t *chainsize);
uint8_t fs_writeend(uint64_t chunkid, uint32_t inode, uint64_t length);

//int fs_reinitchunk(uint32_t inode,uint32_t indx,uint64_t *chunkid);

uint8_t fs_getreserved(uint8_t **dbuff,uint32_t *dbuffsize);
uint8_t fs_gettrash(uint8_t **dbuff,uint32_t *dbuffsize);
uint8_t fs_getdetachedattr(uint32_t inode,uint8_t attr[35]);
uint8_t fs_gettrashpath(uint32_t inode,uint8_t **path);
uint8_t fs_settrashpath(uint32_t inode,const uint8_t *path);
uint8_t fs_undel(uint32_t inode);
uint8_t fs_purge(uint32_t inode);

// for hardlink emulation only
uint8_t fs_append(uint32_t inode,uint32_t ainode,uint32_t uid,uint32_t gid);

void fs_init(char *_ip,char *_port);

#endif