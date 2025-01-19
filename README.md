# Projeto de Controle de LED RGB com Teclado Matricial

Este projeto utiliza um **Raspberry Pi Pico W** para controlar um **LED RGB** e um **buzzer** a partir das teclas de um teclado matricial 4x4.

## Componentes

- **Raspberry Pi Pico**
- **Teclado Matricial 4x4**
- **LED RGB** (Cátodo comum)
- **Buzzer**

## Funcionalidades

- **Tecla A**: Liga o LED **vermelho**.
- **Tecla B**: Liga o LED **azul**.
- **Tecla C**: Liga o LED **verde**.
- **Tecla D**: Liga os **três LEDs simultaneamente** (LED **branco**).
- **Tecla pressionada**: Exibe no **terminal** a tecla que foi pressionada.

## Como Usar

1. **Conectar os Componentes**: 
   - Conecte o teclado matricial, LED RGB e buzzer conforme o esquema de conexões descrito.
   - O LED RGB está configurado com os pinos GPIO do Raspberry Pi Pico.
   
2. **Compilar o Código**:
   - Certifique-se de que o código esteja configurado corretamente no seu ambiente de desenvolvimento.
   
3. **Execução**:
   - Conecte o Raspberry Pi Pico ao seu computador e envie o código.
   - Abra o terminal para visualizar as teclas pressionadas enquanto interage com o teclado.

4. **Testando**:
   - Pressione as teclas **A**, **B**, **C** ou **D** no teclado matricial para controlar o LED RGB.
   - As teclas pressionadas aparecerão no terminal.
   - O buzzer tocará quando a tecla for pressionada.

## Dependências

- **Raspberry Pi Pico SDK**
- Biblioteca `pico/stdlib.h` para **GPIO**

## Contribuidores

- **César Rebouças Costa** [github.com/cesarrcosta99]
- **Douglas Benevides Almeida** [github.com/almdoug]
- **Andressa Silva Santos** [https://github.com/Andressa-sstn]

