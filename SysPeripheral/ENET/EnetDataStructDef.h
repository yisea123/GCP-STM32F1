#ifndef _ENET_DATA_STRUCT_DEF_H_
#define _ENET_DATA_STRUCT_DEF_H_

/*    Copyright (c) 2013, 东莞华中科技大学制造工程研究院
　　　　　　　　　　　　　　　　　　　　　　All rights reserved.
文件名称：EnetDataSturctDef.h
摘    要：
运行环境： 
*----------------------------------
修改描述：
当前版本：0.1 
修改作者：
修改了内容：
修改日期：
*----------------------------------
原 作 者：
完成日期：2013年8月30日        */

#include "../../DataType/DataType.h"


#define ENET_ERR_SUCCESS                    (0)//成功
#define ENET_ERR_CONNECT                    (1)//表示通信连接出错(接收和发送抽象层硬件出错)
#define ENET_ERR_SEND                        (2)//发送数据失败
#define ENET_ERR_EMPTY                        (3)//未收到任何数据


#define ENET_PACK_MAX_LEN                (1024)                  //以太网单次发送的最大总长度
#define ENET_LWIP_BUF_MIN_LEN        (12*1024)                //


typedef struct enet_interface
{
    /*******************************************************************************
    功      能：        计算以太网时基。
    参      数：            uint32_t   ms       - 时基长度，单位是毫秒(ms)
    返  回  值：            无
    被本函数调用的函数清单: 无
    调用本函数的函数清单:   SysTick_Handler()
    注意 事 项：            如果定时中断的周期为1ms，参数ms的值就为1，以此类推
                本函数被定时中断服务函数调用
    所在文件名：            
    作      者：                      
    *******************************************************************************/
    void (*pf_ENET_systick)(uBit32 ms);


    /*******************************************************************************
    函数名称：uBit32 COM_AL_ENET_Open(void)
    功    能：打开以太网通讯
    参    数：无
    返 回 值：ENET_ERR_SUCCESS--成功
                    ENET_ERR_CONNECT--连接失败
    注意事项：无
    *******************************************************************************/
    uBit32 (*pf_ENET_Open)(void);


    /*******************************************************************************
    功    能：关闭以太网通讯
    参    数：无
    返 回 值：ENET_ERR_SUCCESS--成功
                    ENET_ERR_CONNECT--连接失败
    注意事项：无
    *******************************************************************************/
    uBit32 (*pf_ENET_Close)(void);

    /*******************************************************************************
    功    能：发送数据包
    参    数：
                    ulID                    --数据包ID
                    pSendBuf              --待发送数据区
                    ulSendLen             --待发数据长度
    返 回 值：
                    ENET_ERR_SUCCESS       --成功
                    ENET_ERR_CONNECT       --连接失败
                    ENET_ERR_SEND_OVERFLOW --发送数据过长
                    ENET_ERR_SEND          --发送失败
    注意事项：无
    *******************************************************************************/
    uBit32 (*pf_ENET_SendPack)(uBit32 ulID, uBit8* pDataBuf, uBit32 ulDataBufLen);


    /*******************************************************************************
    功    能：接收数据包
    参    数：
                    ulID                 --数据包ID
                    pID                  --保存接收包数据ID
                    pRcvLen           --保存接收包数据长度
                    pRcvBuf           --指向接收缓冲区(内部接收数据缓冲区)
    返 回 值：  
                    ENET_ERR_SUCCESS       --成功
                    ENET_ERR_CONNECT       --连接失败
                    ENET_ERR_EMPTY         --未收到任何数据包
    注意事项：无
    *******************************************************************************/
    uBit32 (*pf_ENET_GetPack)(uBit32 *pID,  uBit32* pRcvLen, uBit8** pRcvBuf);

    /*******************************************************************************
    功    能：底层收发
    参    数：无
    返 回 值：
                        ENET_ERR_SUCCESS     --成功
                        ENET_ERR_CONNECT     --连接失败
    注意事项：                   
    *******************************************************************************/
    void (*pf_ENET_RcvHandle)();


    /*******************************************************************************
    功    能：获取最大单次发送数据长度
    参    数：无
    返 回 值：通信接口单次允许发送的最大数据长度
    注意事项：无                  
    *******************************************************************************/
    uBit32 (*pf_ENET_GetMaxSendLen)(void);
}ENET_INTERFACE;


#endif /* __ENETRS_H__ */
