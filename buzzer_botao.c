#include "pico/stdlib.h"
#include <stdio.h>

// Definição do pino do buzzer
#define BUZZER_PIN  26

// Função para inicializar o buzzer
void inicializar_buzzer() {
    gpio_init(BUZZER_PIN);      // Inicializar o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Definir como saída
}

// Função para emitir som com o buzzer
void emitir_som() {
    gpio_put(BUZZER_PIN, 1);    // Ativar o buzzer (emite som)
    sleep_ms(500);              // Duração do som (500 ms)
    gpio_put(BUZZER_PIN, 0);    // Desligar o buzzer
}

// Função para verificar a tecla pressionada
void verificar_tecla(char tecla) {
    if (tecla == '#') {         // Se a tecla '#' foi pressionada
        emitir_som();           // Emitir som no buzzer
    }
}
