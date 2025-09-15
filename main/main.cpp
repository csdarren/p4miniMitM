#include "driver/gpio.h"
#include "driver/twai.h"

#include "CanConnect.hpp"
#include "freertos/idf_additions.h"
static constexpr bool IS_SENDER = true;

extern "C" void can_task(void * /*task_param*/) {
    CanConnect CAN;

    while (true) {
        CAN.ReceiveFrame();
        CAN.HandleRPM(IS_SENDER);
        CAN.HandleSpeed(IS_SENDER);
        CAN.HandleFuel(IS_SENDER);
        CAN.HandleTemp(IS_SENDER);

        vTaskDelay(pdMS_TO_TICKS(10)); // 10ms delay keeps scheduler happy
    }
}

extern "C" void ui_task(void * /*task_param*/) {
}

extern "C" void app_main(void) {
    xTaskCreatePinnedToCore(can_task, "CAN TASK", 4096, nullptr, 5, nullptr, 0);
    xTaskCreatePinnedToCore(ui_task, "UI TASK", 8192, nullptr, 4, nullptr, 1);
}
