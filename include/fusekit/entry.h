/*
 * This file is part of fusekit, a c++ convenience wrapper for FUSE.
 *
 * Written by Gerhard Lipp <gerhard_lipp@gmx.de>
 *
 * this library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with fusekit.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FUX__ENTRY_H
#define __FUX__ENTRY_H

#include <errno.h>
#include <string>
#include <fuse.h>

namespace fusekit{

  /// interface base class for all entries/elements of a file hierarchy
  /// 
  /// all file operations will be forwarded by the daemon to an implementation
  /// of this interface.
  struct entry{
    virtual ~entry(){
    }
    virtual entry* child( const char* ) = 0;
    virtual int stat( struct stat& ) = 0;
    virtual int access( int ) = 0;
    virtual int chmod( mode_t ) = 0;
    virtual int open( fuse_file_info& ) = 0;
    virtual int release( fuse_file_info& ) = 0;
    virtual int read( char*, size_t, off_t, fuse_file_info& ) = 0;
    virtual int write( const char*, size_t, off_t, fuse_file_info& ) = 0;
    virtual int readdir( void*, fuse_fill_dir_t, off_t, fuse_file_info& ) = 0;
    virtual int mknod( const char*, mode_t, dev_t ) = 0;
    virtual int unlink( const char* ) = 0;
    virtual int mkdir( const char*, mode_t ) = 0;
    virtual int rmdir( const char* ) = 0;
    virtual int flush( fuse_file_info& ) = 0;
    virtual int truncate( off_t ) = 0;
    virtual int utime( utimbuf& ) = 0;
  };
}

#endif

