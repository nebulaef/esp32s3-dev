#include <stdio.h>
#include <string.h>
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "esp_log.h"

static const char *TAG = "esp32dev";

void app_main(void)
{
    nvs_flash_init();
    esp_event_loop_create_default();
    esp_netif_init();
    esp_netif_t *ap_netif = esp_netif_create_default_wifi_ap();
    wifi_init_config_t apinitcfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&apinitcfg);
    wifi_config_t apcfg = {
        .ap = {
            .ssid = "esp32-s3",
            .ssid_len = strlen("esp32-s3"),
            .password = "123456789",
            .channel = 6,
            .max_connection = 4,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        }
    };
    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_set_config(WIFI_IF_AP,&apcfg);
    esp_wifi_start();
    ESP_LOGI(TAG,"wifi ap 启动成功");
}
