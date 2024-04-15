# Jogo de Perguntas para Arduino com Display LCD 16x2  💾
Este projeto consiste em um jogo de perguntas desenvolvido para um Arduino com um display LCD 16x2. O jogador será desafiado com uma série de perguntas distribuídas em três níveis de dificuldade: Fácil, Médio e Difícil.



## Componentes Utilizados ⚙️

  <img src="https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/circuitoTk.jpeg" alt="ckt" align="right" width="400" />


<br/>

- Arduíno Uno 💾
- 4 Botões 🔘
- 1 LED Vermelho 🚨 
- 1 Potenciômetro 🎛️
- 1 Piezo 🔊
- 4 resistores de 400 Ω ⚡
- 1 resistor de 220 Ω ⚡
- 1 resistor de 1 K Ω ⚡

<br/>
<br/>


## Tecnologias Utilizadas 🎯
<img align="center" alt="tinkercad" src=	"https://img.shields.io/badge/Tinkercad-1477D1.svg?style=for-the-badge&logo=Tinkercad&logoColor=white"/> 
 <img align="center" alt="c++" src=	"https://img.shields.io/badge/C++-00599C.svg?style=for-the-badge&logo=C++&logoColor=white"/>

<br/>

## Instruções de Uso ✍🏻

1. Conecte o Arduino ao display LCD 16x2 e aos botões de controle conforme as instruções do esquema de ligação fornecido.
2. Carregue o código do jogo no Arduino.
3. Inicie o jogo utilizando o botão da entrada digital '2' e responda às perguntas com "SIM" utilizando o botão da entrada digital "10" e "NÃO" utilizando o botão da entrada digital  '9'.
4. Para pular uma questão utilize o botão da entrada digital '8'.
5. Acerte as perguntas para avançar nos níveis de dificuldade.
6. Preste atenção ao LED vermelho, que pisca quando o tempo para responder a uma pergunta está acabando.
7. Caso erre uma resposta, o jogo termina automaticamente.

<br/>

## Implementação 📦

- O programa utiliza a biblioteca LiquidCrystal para controlar o display LCD. 📺
- As perguntas são selecionadas aleatoriamente em matrizes predefinidas e as respostas dos jogadores são processadas usando entradas digitais. ✅
- O feedback melódico é fornecido através da campainha usando notas musicais predefinidas. 🎶

<br/>

## Funcionalidades 🛠️

- Perguntas Gravadas na Memória: O jogo possui uma variedade de perguntas armazenadas na memória, organizadas por níveis de dificuldade. ⁉️

- Respostas Sim ou Não: O jogador responde às perguntas selecionando entre "Sim" ou "Não" através de botões. 🫡

- Feedback Sonoro: Ao responder uma pergunta, o jogo emite um som indicando se a resposta está correta ou não, também emite um som na vitória e quando o tempo estiver acabando. 📻

- Três Níveis de Dificuldade: O jogo apresenta perguntas em três níveis de dificuldade: Fácil, Médio e Difícil.💯

- Progressão do Jogo: O jogador precisa acertar cinco perguntas de cada nível de dificuldade e uma pergunta final para vencer o jogo. 🛣️

- Tempo Limite para Responder: O jogador tem um tempo limite para responder a cada pergunta. Quando o tempo está prestes a expirar, um LED vermelho pisca para indicar ao jogador.⏳

- Fim do Jogo por Resposta Incorreta ou por Excesso de pulos: Se o jogador errar uma resposta, ou pular questões mais de três vezes, ele perde o jogo automaticamente.🔚

<br/>

## Limitações  ❌

- A codificação não oferece nenhuma opção para desistir do jogo durante sua execução. 😬

<br/>

## Comportamento 🎮
1. Jogo iniciado. ▶️
2. Excesso de pulos.🔚
3. Tempo Esgotado. ⏳
4. Resposta Errada. ❌
  
<br/>



|                        |                        |
|------------------------|------------------------|
| <img src="https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/gif.gif" width="400">  | <img src="https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_pular_pergunta%20(video-converter.com).gif" width="400">  |
| <img src="https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_tempo_esgotado%20(video-converter.com).gif" width="400"> | <img src="https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_pergunta_errada%20(video-converter.com).gif" width="400"> |
<br/>

## Jogo Completo 🕹️
<br/>

|                      |                      |
|----------------------|----------------------|
| ![Parte 1](https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_jogo_completo%20(video-converter.com)%20(2).gif)  | ![Parte 2](https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_jogo_completo%20(video-converter.com)%20(3).gif) |
| ![Parte 3](https://github.com/LuiisMarim/Quiz-Arduino/blob/main/img/video_jogo_completo%20(video-converter.com)%20(4).gif) | |



  
<br/>
  

## Autores ✒️  
DevLuisMarim ⬇️ <div style="display:
 inline-block">[![E-mail](https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/LuiisMarim)

DevStellaOli ⬇️ <div style="display: inline-block">
  
[![E-mail](https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/StellaOli)

</div>
