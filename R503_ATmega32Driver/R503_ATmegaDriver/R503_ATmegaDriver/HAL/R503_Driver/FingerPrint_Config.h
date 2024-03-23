#include "STD.h"

#define HEADER_HIGH_BYTE 0XEF
#define HEADER_LOW_BYTE 0X01

#define ADDRESS_FIRST_BYTE 0XFF
#define ADDRESS_SECOND_BYTE 0XFF
#define ADDRESS_THIRD_BYTE 0XFF
#define ADDRESS_FOURTH_BYTE 0XFF

#define PCK_ID_COMMAND_PACK (0x01)
#define PCK_ID_DATA_PACK (0x02)
#define PCK_ID_ACK_PACK (0x07)
#define PCK_ID_END_OF_DATA_PACK (0x08)

#define HAND_SHAKE 0x40
#define COLLECT_FINGER_IMAGE 0x01
#define CONVERT_IMG_TO_CHAR 0x02
#define SEARCH_FINGER 0x04
#define GEN_TEMPLATE 0x05
#define STR_TEMPLATE 0x06
#define LOAD_CHAR 0x07
#define EMPTY_LIB 0x0D
#define DELETE_TEMP 0x0C

#define LENGTH_3BYTE 0x0003
#define LENGTH_4BYTE 0x0004
#define LENGTH_6BYTE 0x0006
#define LENGTH_7BYTE 0x0007
#define LENGTH_8BYTE 0x0008

#define CHAR_BUFFER_1 0x01
#define CHAR_BUFFER_2 0x02
#define PAGE_ID 0x0001
#define START_PAGE_ID 0x001

#define ONE_BYTE_SHIFT 8
#define NO_BYTE_SHIFT 0