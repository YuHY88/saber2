#ifndef __W1_DS2438_H__
#define __W1_DS2438_H__

#include <asm/types.h>

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/device.h>
#include <linux/types.h>

#define DS2438_DEV_NAME	"cygnus-battery"

#define DS2438_PAGE_SIZE	8
#define DS2438_PAGE_NUM		8

#define DS2438_CONVERT_TEMP	0x44
#define DS2438_CONVERT_VOLT	0xB4
#define DS2438_WRITE_SCRATCHPAD	0x4E
#define DS2438_COPY_SCRATCHPAD	0x48
#define DS2438_RECALL_MEMORY	0xB8

enum DS2438_PAGE {
	PAGE0_CONTROL = 0,
	PAGE1_ETM,
	PAGE2_STAMP,
	PAGE3_RESV3,
	PAGE4_RESV4,
	PAGE5_RESV5,
	PAGE6_RESV6,
	PAGE7_CCA,
};

enum DS2438_REG {
	/* PAGE 0 */
	PAGE0_STAT_CTRL = 0,
	PAGE0_TEMP_LSB = 1,
	PAGE0_TEMP_MSB = 2,
	PAGE0_VOLTAGE_LSB = 3,
	PAGE0_VOLTAGE_MSB = 4,
	PAGE0_CURRENT_LSB = 5,
	PAGE0_CURRENT_MSB = 6,
	PAGE0_THRESHOLD = 7,

	/* PAGE 1 */
	PAGE1_ETM_BYTE0 = 0,
	PAGE1_ETM_BYTE1 = 1,
	PAGE1_ETM_BYTE2 = 2,
	PAGE1_ETM_BYTE3 = 3,
	PAGE1_ICA = 4,
	PAGE1_OFFSET_LSB = 5,
	PAGE1_OFFSET_MSB = 6,

	/* PAGE 2 */
	PAGE2_DISCONNECT_BYTE0 = 0,
	PAGE2_DISCONNECT_BYTE1 = 1,
	PAGE2_DISCONNECT_BYTE2 = 2,
	PAGE2_DISCONNECT_BYTE3 = 3,
	PAGE2_END_CHARGE_BYTE0 = 4,
	PAGE2_END_CHARGE_BYTE1 = 5,
	PAGE2_END_CHARGE_BYTE2 = 6,
	PAGE2_END_CHARGE_BYTE3 = 7,

	/* PAGE 3 */
	/* PAGE 4 */
	/* PAGE 5 */
	/* PAGE 6 */
	/* PAGE 7 */
	PAGE7_CCA_LSB = 4,
	PAGE7_CCA_MSB = 5,
	PAGE7_DCA_LSB = 6,
	PAGE7_DCA_MSB = 7,
};

#define DS2438_CTRL_IAD		(1 << 0)
#define DS2438_CTRL_CA		(1 << 1)
#define DS2438_CTRL_EE		(1 << 2)
#define DS2438_CTRL_AD		(1 << 3)
#define DS2438_STAT_TB		(1 << 4)
#define DS2438_STAT_NVB		(1 << 5)
#define DS2438_STAT_ADB		(1 << 6)

static inline u16 ds2438_readw(u8 *raw)
{
	return ((*(raw + 1)) << 8) | (*raw);
}

static inline void ds2438_writew(u8 *raw, u16 data)
{
	*raw++ = data & 0xFF;
	*raw = (data >> 8) & 0xFF;
}
#endif				/* __W1_DS2438_H__ */