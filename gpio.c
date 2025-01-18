#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos para o LED RGB
#define LED_RED 19
#define LED_GREEN 20
#define LED_BLUE 21

// Definição dos pinos do teclado matricial
const uint8_t colunas[4] = {28, 2, 3, 4}; // Pinos das colunas
const uint8_t linhas[4] = {5, 6, 7, 8};   // Pinos das linhas

// Mapeamento do teclado matricial
const char teclado[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Função para ler o teclado matricial
char leitura_teclado();

int main()
{
    // Inicializa a UART (Serial)
    stdio_init_all();

    // Configuração dos pinos do LED RGB como saída
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Inicializa os LEDs como apagados
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);

    // Configuração dos pinos das colunas como saídas digitais
    for (int i = 0; i < 4; i++)
    {
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_OUT);
        gpio_put(colunas[i], 1); // Inicializa todas as colunas como altas
    }

    // Configuração dos pinos das linhas como entradas digitais
    for (int i = 0; i < 4; i++)
    {
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_IN);
        gpio_pull_up(linhas[i]); // Habilita pull-up para as linhas
    }

    while (true)
    {
        char tecla = leitura_teclado();

        if (tecla != 'n') // Só exibe se uma tecla foi pressionada
        {
            printf("Tecla pressionada: %c\n", tecla);

            // Controle das cores do LED RGB
            if (tecla == 'A') // Vermelho
            {
                gpio_put(LED_RED, 1);
                gpio_put(LED_GREEN, 0);
                gpio_put(LED_BLUE, 0);
            }
            else if (tecla == 'B') // Azul
            {
                gpio_put(LED_RED, 0);
                gpio_put(LED_GREEN, 0);
                gpio_put(LED_BLUE, 1);
            }
            else if (tecla == 'C') // Verde
            {
                gpio_put(LED_RED, 0);
                gpio_put(LED_GREEN, 1);
                gpio_put(LED_BLUE, 0);
            }
            else if (tecla == 'D') // Branco (todas as cores ligadas)
            {
                gpio_put(LED_RED, 1);
                gpio_put(LED_GREEN, 1);
                gpio_put(LED_BLUE, 1);
            }
        }

        sleep_ms(200); // Intervalo de tempo para leitura
    }

    return 0;
}

// Função para ler o teclado matricial
char leitura_teclado()
{
    char numero = 'n'; // Valor padrão para quando nenhuma tecla for pressionada

    // Desliga todos os pinos das colunas
    for (int i = 0; i < 4; i++)
    {
        gpio_put(colunas[i], 1);
    }

    for (int coluna = 0; coluna < 4; coluna++)
    {
        // Ativa a coluna atual (coloca o pino da coluna como 0)
        gpio_put(colunas[coluna], 0);

        for (int linha = 0; linha < 4; linha++)
        {
            // Verifica o estado da linha. Se estiver em 0, a tecla foi pressionada
            if (gpio_get(linhas[linha]) == 0)
            {
                numero = teclado[linha][coluna]; // Mapeia a tecla pressionada
                // Aguarda a tecla ser liberada (debounce)
                while (gpio_get(linhas[linha]) == 0)
                {
                    sleep_ms(10); // Aguarda a tecla ser liberada
                }
                break; // Sai do laço após detectar a tecla
            }
        }

        // Desativa a coluna atual (coloca o pino da coluna como 1)
        gpio_put(colunas[coluna], 1);

        if (numero != 'n') // Se uma tecla foi pressionada, sai do laço de colunas
        {
            break;
        }
    }

    return numero; // Retorna a tecla pressionada
}
