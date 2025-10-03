# The boys - Simulação a eventos discretos

Este é um trabalho acadêmico implementado em C, que tem como objetivo criar uma simulação onde, teremos um mundo com heróis, bases e missões.
Cada herói possui um conjunto de habilidades (vôo, invisibilidade, visão de raios X, superaudição, etc.), um nível de experiência e outros atributos. 

 As bases estão espalhadas pelo mundo e os heróis se deslocam periodicamente entre elas. Cada base possui uma lotação máxima e uma fila de espera; ao chegar na base, o herói pode decidir entre esperar na fila ou desistir, viajando para outra base. Cada base possui um porteiro que gerencia a entrada/saída dos heróis e a fila de espera.

Esporadicamente surgem missões em locais aleatórios desse mundo; cada missão exige um conjunto de habilidades específicas. A missão pode ser atendida por uma equipe de heróis que se encontre em uma base, desde que os heróis da equipe tenham, em conjunto, as habilidades requeridas. Ao ser escolhido para participar de uma missão, cada herói recebe pontos de experiência.

Este projeto consiste em simular a dinâmica desse mundo durante um ano (525.600 minutos). Ao final, a simulação deve apresentar o número de missões cumpridas (pontos ganhos) por cada herói e outras estatísticas. 

Este trabalho foi inicialmente concebido pelos profs. Fabiano Silva, Luis Bona e Marcos Castilho para as disciplinas CI1001 e CI067, levemente inspirada na série de TV The Boys.

A simulação tem uma Lista de Eventos Futuros (LEF), que é basicamente uma lista de eventos ordenada por datas de ocorrência crescentes, como em uma agenda: 

```
10:00 ir ao dentista
 : (aqui está no dentista)
11:45 voltar do dentista
12:00 almoçar
 : (aqui está almoçando)
13:00 ir à UFPR
13:30 ir à aula de Cálculo
 : (aqui está na aula)
15:20 sair da aula de Cálculo
15:30 ir à aula de Programação
 : (aqui está na aula)
17:30 sair da aula de Programação
18:00 voltar para casa
 : (aqui está voltando para casa)
...
```

Um exemplo de saída do programa seria:

```
120037: MISSAO 4150 TENT 1 HAB REQ: [ 0 2 3 4 6 7 8 9 ]
120037: MISSAO 4150 BASE 1 DIST 6461 HEROIS [ 2 6 25 47 48 ]
120037: MISSAO 4150 HAB HEROI  2: [ 0 9 ]
120037: MISSAO 4150 HAB HEROI  6: [ 8 ]
120037: MISSAO 4150 HAB HEROI 25: [ 3 7 ]
120037: MISSAO 4150 HAB HEROI 47: [ 0 1 ]
120037: MISSAO 4150 HAB HEROI 48: [ 6 ]
120037: MISSAO 4150 UNIAO HAB BASE 1: [ 0 1 3 6 7 8 9 ]
...
120037: MISSAO 4150 BASE 7 DIST 9867 HEROIS [ 16 21 22 23 24 31 33 46 ]
120037: MISSAO 4150 HAB HEROI 16: [ 3 4 8 ]
...
120037: MISSAO 4150 HAB HEROI 46: [ 2 ]
120037: MISSAO 4150 UNIAO HAB BASE 7: [ 0 1 2 3 4 5 6 7 8 9 ]
120037: MISSAO 4150 CUMPRIDA BASE 7
```
