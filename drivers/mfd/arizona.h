/*
 * wm5102.h  --  WM5102 MFD internals
 *
 * Copyright 2012 Wolfson Microelectronics plc
 *
 * Author: Mark Brown <broonie@opensource.wolfsonmicro.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _ARIZONA_H
#define _ARIZONA_H

#include <linux/of.h>
#include <linux/regmap.h>
#include <linux/pm.h>

struct wm_arizona;

extern const struct regmap_config wm5102_i2c_regmap;
extern const struct regmap_config wm5102_spi_regmap;

extern const struct regmap_config florida_i2c_regmap;
extern const struct regmap_config florida_spi_regmap;
#if defined(CONFIG_AUDIO_CODEC_FLORIDA)

extern const struct regmap_config wm5110_i2c_regmap;
extern const struct regmap_config wm5110_spi_regmap;
extern const struct regmap_config wm8285_16bit_i2c_regmap;
extern const struct regmap_config wm8285_16bit_spi_regmap;
extern const struct regmap_config wm8285_32bit_spi_regmap;
extern const struct regmap_config wm8285_32bit_i2c_regmap;
extern const struct regmap_config cs47l24_spi_regmap; 
extern const struct regmap_irq_chip wm8285_irq; 
extern const struct regmap_irq_chip cs47l24_irq;

#endif

extern const struct regmap_config wm8997_i2c_regmap;
extern const struct regmap_config wm8998_i2c_regmap;
extern const struct dev_pm_ops arizona_pm_ops;

extern const struct of_device_id arizona_of_match[];
extern const struct regmap_irq_chip wm5102_aod;
extern const struct regmap_irq_chip wm5102_irq;

extern const struct regmap_irq_chip florida_aod;
extern const struct regmap_irq_chip florida_irq;
extern const struct regmap_irq_chip florida_revd_irq;
extern const struct regmap_irq_chip wm8997_aod;
extern const struct regmap_irq_chip wm8997_irq;

extern struct regmap_irq_chip wm8998_aod;
extern struct regmap_irq_chip wm8998_irq;
int arizona_dev_init(struct arizona *arizona);
int arizona_dev_exit(struct arizona *arizona);
int arizona_irq_init(struct arizona *arizona);
int arizona_irq_exit(struct arizona *arizona);

#ifdef CONFIG_OF
int64_t arizona_of_get_type(struct device *dev);
#else
static inline int arizona_of_get_type(struct device *dev)
{
	return 0;
}
#endif
#endif
