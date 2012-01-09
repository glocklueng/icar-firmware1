/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_GSM_H
#define __APP_GSM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported macro ------------------------------------------------------------*/
//HEAD SEQ CMD Length(2 bytes) INF(Max.1024) check
#define GSM_BUF_LENGTH		1024+8 //for GSM command
//#define GSM_BUF_LENGTH		50 //for GSM command

/* Exported types ------------------------------------------------------------*/
struct gsm_status {
	bool power_on ;
	bool ask_power ;
	bool gprs_ready ;
	bool tcp_online;
	bool ask_online;
	//��Ӫ����Ϣ��+COPS: 0,0,"CHINA MOBILE"
	unsigned char carrier[32];
	unsigned char imsi[16];
	unsigned char local_ip[16];
	unsigned char *server_ip_port;
	unsigned int apn_index;
	unsigned char signal;
	unsigned char err_no;
	bool roam;
	bool cgatt;
	bool rx_empty;//GSM Module rx buffer
	unsigned int time;
};

struct gsm_command {
	bool lock ;
	unsigned char tx[GSM_BUF_LENGTH];
	unsigned int tx_len;
	unsigned char rx[GSM_BUF_LENGTH];
	unsigned char *rx_out_last;
	unsigned char *rx_in_last;
	bool rx_empty;
	bool rx_full;
	unsigned int rx_time;
};

/* Exported constants --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void  App_TaskGsm        (void        *p_arg);

#endif /* __APP_GSM_H */