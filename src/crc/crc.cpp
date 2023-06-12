#include <stdio.h>
#include "nrcl_config.h"
#include "crc.h"
 
const CRC_8 crc_8 = {0x07,0x00,0x00,FALSE,FALSE};
const CRC_8 crc_8_ITU = {0x07,0x00,0x55,FALSE,FALSE};
const CRC_8 crc_8_ROHC = {0x07,0xff,0x00,TRUE,TRUE};
const CRC_8 crc_8_MAXIM = {0x31,0x00,0x00,TRUE,TRUE};
 
const CRC_16 crc_16_IBM = {0x8005,0x0000,0x0000,TRUE,TRUE};
const CRC_16 crc_16_MAXIM = {0x8005,0x0000,0xffff,TRUE,TRUE};
const CRC_16 crc_16_USB = {0x8005,0xffff,0xffff,TRUE,TRUE};
const CRC_16 crc_16_MODBUS = {0x8005,0xffff,0x0000,TRUE,TRUE};
const CRC_16 crc_16_CCITT = {0x1021,0x0000,0x0000,TRUE,TRUE};
const CRC_16 crc_16_CCITT_FALSE = {0x1021,0xffff,0x0000,FALSE,FALSE};
const CRC_16 crc_16_X5 = {0x1021,0xffff,0xffff,TRUE,TRUE};
const CRC_16 crc_16_XMODEM = {0x1021,0x0000,0x0000,FALSE,FALSE};
const CRC_16 crc_16_DNP = {0x3d65,0x0000,0xffff,TRUE,TRUE};
 
const CRC_32 crc_32 = {0x04c11db7,0xffffffff,0xffffffff,TRUE,TRUE};
const CRC_32 crc_32_MPEG2 = {0x04c11db7,0xffffffff,0x00000000,FALSE,FALSE};
 
/*****************************************************************************
*function name:reverse8
*function: 字节反转，如1100 0101 反转后为1010 0011
*input：1字节
*output:反转后字节
******************************************************************************/
u8 reverse8(u8 data)
{
    u8 i;
    u8 temp=0;
    for(i=0;i<8;i++)	//字节反转
        temp |= ((data>>i) & 0x01)<<(7-i);
    return temp;
}
/*****************************************************************************
*function name:reverse16
*function: 双字节反转，如1100 0101 1110 0101反转后为1010 0111 1010 0011
*input：双字节
*output:反转后双字节
******************************************************************************/
u16 reverse16(u16 data)
{
    u8 i;
    u16 temp=0;
    for(i=0;i<16;i++)		//反转
        temp |= ((data>>i) & 0x0001)<<(15-i);
    return temp;
}
/*****************************************************************************
*function name:reverse32
*function: 32bit字反转
*input：32bit字
*output:反转后32bit字
******************************************************************************/
u32 reverse32(u32 data)
{
    u8 i;
    u32 temp=0;
    for(i=0;i<32;i++)		//反转
        temp |= ((data>>i) & 0x01)<<(31-i);
    return temp;
}
 
/*****************************************************************************
*function name:crc8
*function: CRC校验，校验值为8位
*input:addr-数据首地址；num-数据长度（字节）；type-CRC8的算法类型
*output:8位校验值
******************************************************************************/
u8 crc8(u8 *addr, int num,CRC_8 type)  
{  
    u8 data;
    u8 crc = type.InitValue;                   //初始值
    int i;  
    for (; num > 0; num--)               
    {  
        data = *addr++;
        if(type.InputReverse == TRUE)
        data = reverse8(data);                 //字节反转
        crc = crc ^ data ;                     //与crc初始值异或 
        for (i = 0; i < 8; i++)                //循环8位 
        {  
            if (crc & 0x80)                    //左移移出的位为1，左移后与多项式异或
                crc = (crc << 1) ^ type.poly;    
            else                               //否则直接左移
                crc <<= 1;                  
        }
    }
    if(type.OutputReverse == TRUE)             //满足条件，反转
        crc = reverse8(crc);
    crc = crc^type.xor;                        //最后返与结果异或值异或
    return(crc);                               //返回最终校验值
}
 
/*****************************************************************************
*function name:crc16
*function: CRC校验，校验值为16位
*input:addr-数据首地址；num-数据长度（字节）；type-CRC16的算法类型
*output:16位校验值
******************************************************************************/
u16 crc16(u8 *addr, int num,CRC_16 type)  
{  
    u8 data;
    u16 crc = type.InitValue;					//初始值
    int i;  
    for (; num > 0; num--)               
    {  
        data = *addr++;
        if(type.InputReverse == TRUE)
            data = reverse8(data);				//字节反转
        crc = crc ^ (data<<8) ;					//与crc初始值高8位异或 
        for (i = 0; i < 8; i++)					//循环8位 
        {  
            if (crc & 0x8000)					//左移移出的位为1，左移后与多项式异或
                crc = (crc << 1) ^ type.poly;    
            else		                        //否则直接左移
                crc <<= 1;                  
        }
    }
    if(type.OutputReverse == TRUE)              //满足条件，反转
        crc = reverse16(crc);
    crc = crc^type.xor;	                        //最后返与结果异或值异或
    return(crc);                                //返回最终校验值
}
/*****************************************************************************
*function name:crc32
*function: CRC校验，校验值为32位
*input:addr-数据首地址；num-数据长度（字节）；type-CRC32的算法类型
*output:32位校验值
******************************************************************************/
u32 crc32(u8 *addr, int num,CRC_32 type)  
{  
    u8 data;
    u32 crc = type.InitValue;					//初始值
    int i;  
    for (; num > 0; num--)               
    {  
        data = *addr++;
        if(type.InputReverse == TRUE)
            data = reverse8(data);				//字节反转
        crc = crc ^ (data<<24) ;				//与crc初始值高8位异或 
        for (i = 0; i < 8; i++)					//循环8位 
        {  
            if (crc & 0x80000000)				//左移移出的位为1，左移后与多项式异或
                crc = (crc << 1) ^ type.poly;    
            else                                //否则直接左移
                crc <<= 1;                  
        }
    }
    if(type.OutputReverse == TRUE)              //满足条件，反转
        crc = reverse32(crc);
    crc = crc^type.xor;	                        //最后返与结果异或值异或
    return(crc);                                //返回最终校验值
}