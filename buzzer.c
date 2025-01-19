#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

// Definição do pino do buzzer
#define BUZZER_PIN  26

// Definição da frequência do som (em Hz)
#define FREQUENCIA_SOM 2000 // 2000 Hz - Aumente ou diminua para alterar a frequência

void inicializar_buzzer() {
    gpio_init(BUZZER_PIN);              // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Define como saída

    // Inicializa o PWM no pino do buzzer
    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, 8.f);  // Ajuste do divisor de clock para uma frequência mais alta
    pwm_config_set_wrap(&cfg, 125);    // Define o valor do wrap para ajustar a frequência
    pwm_init(pwm_gpio_to_slice_num(BUZZER_PIN), &cfg, true); // Inicializa o PWM
}

void emitir_som() {
    pwm_set_gpio_level(BUZZER_PIN, 125);  // Ativa o buzzer com 50% de ciclo de trabalho
    sleep_ms(500);                        // Duração do som (500 ms)
    pwm_set_gpio_level(BUZZER_PIN, 0);    // Desliga o buzzer
}


