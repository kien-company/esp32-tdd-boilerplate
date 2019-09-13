#include "I2C.hpp"

#include "driver/i2c.h"
#include "pins.h"

/*!< I2C port number for master dev */
#define I2C_MASTER_NUM I2C_NUM_1

/*!< I2C master do not need buffer */
#define I2C_MASTER_TX_BUF_DISABLE 0

/*!< I2C master do not need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0

void I2C_ESP::begin(int freq) {
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_PIN;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_MASTER_SCL_PIN;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = freq;
    i2c_param_config((i2c_port_t)I2C_MASTER_NUM, &conf);
    i2c_driver_install((i2c_port_t)I2C_MASTER_NUM, conf.mode,
                       I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

Result I2C_ESP::write(uint8_t addr, uint8_t* data, size_t len) {
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, addr << 1 | I2C_MASTER_WRITE, true);
    i2c_master_write(cmd, data, len, true);
    i2c_master_stop(cmd);
    ret = i2c_master_cmd_begin((i2c_port_t)I2C_MASTER_NUM, cmd,
                               1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);

    if (ret != ESP_OK) {
        return Result::Ok;
    } else {
        return Result::Fail;
    }
}

Result I2C_ESP::read(uint8_t addr, uint8_t* data, size_t len) {
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, addr << 1 | I2C_MASTER_READ, true);
    if (len > 1) {
        i2c_master_read(cmd, data, len - 1, I2C_MASTER_ACK);
    }
    i2c_master_read_byte(cmd, data + len - 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd);
    ret = i2c_master_cmd_begin((i2c_port_t)I2C_MASTER_NUM, cmd,
                               1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);

    if (ret != ESP_OK) {
        return Result::Ok;
    } else {
        return Result::Fail;
    }
}
