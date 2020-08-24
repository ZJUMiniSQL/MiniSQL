#ifndef buffer_h
#define buffer_h
/*
Buffer Manager负责缓冲区的管理，主要功能有：
1.	根据需要，读取指定的数据到系统缓冲区或将缓冲区中的数据写出到文件
2.	实现缓冲区的替换算法，当缓冲区满时选择合适的页进行替换
3.	记录缓冲区中各页的状态，如是否被修改过等
4.	提供缓冲区页的pin功能，及锁定缓冲区的页，不允许替换出去
为提高磁盘I/O操作的效率，缓冲区与文件系统交互的单位是块，块的大小应为文件系统与磁盘交互单位的整数倍，一般可定为4KB或8KB。
*/

#define MAX_BUFFER_SIZE (1024 * 1024)
#include <stdio.h>
#include <vector>
#include "filesys.h"
struct Buffer_info
{
    Address address;
    Block data;
};
class Buffer
{
private:
    std::vector<Buffer_info> buffer_list;
    FileStore disk;
    void remove_block_when_full();
    void remove_block(int);

public:
    Buffer()
    {
    }
    void read_data(Address, Block *);
    void write_data(Address, const Block *);
    void remove_file(Address);
    ~Buffer();
};
#endif