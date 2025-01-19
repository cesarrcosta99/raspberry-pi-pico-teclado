#include "pico/stdlib.h"

#define BUZZER_PIN  17  // Pino do buzzer
#define BUTTON_PIN   18  // Pino do botão

// Função para inicializar o buzzer
void inicializar_buzzer() {
    gpio_init(BUZZER_PIN);      // Inicializar o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Definir como saída
}

// Função para inicializar o botão
void inicializar_botao() {
    gpio_init(BUTTON_PIN);      // Inicializar o pino do botão
    gpio_set_dir(BUTTON_PIN, GPIO_IN);  // Definir como entrada
    gpio_pull_up(BUTTON_PIN);   // Ativar o resistor de pull-up (pino "pressionado" será baixo)
}

// Função para emitir som com o buzzer
void emitir_som() {
    gpio_put(BUZZER_PIN, 1);    // Ativar o buzzer (emite som)
    sleep_ms(500);              // Duração do som (500 ms)
    gpio_put(BUZZER_PIN, 0);    // Desligar o buzzer
}

// Função para verificar o botão e emitir o som
void verificar_botao_e_emitir_som() {
    if (gpio_get(BUTTON_PIN) == 0) {  // Se o botão estiver pressionado (nível baixo)
        emitir_som();                 // Emitir som
        sleep_ms(1000);               // Pausa para evitar múltiplas leituras rápidas (debounce)
    }
}
