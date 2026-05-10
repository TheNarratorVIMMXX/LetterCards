// =====================================================================================================================================

// DOCUMENTACIÓN:

// Renders 

// Ultima Modificacion: 09/05/26
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Internas
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../utils/constants.hpp"                                                                            // Constantes del Juego
#include "../ui/renders.hpp"                                                                                 // Funciones de Renderizado
#include "../core/logic.hpp"                                                                                 // Funciones de Lógica del Juego

// =====================================================================================================================================
// ------------------------------------------------------------ Alías--------------------------------------------------------------

/// Alías para Optimizar Tipos de Datos
using steady_clock = chrono::steady_clock;                                                                   // Alías para el Cronómetro
using std::cin;                                                                                              // Alías para la Entrada Estándar
 
// =====================================================================================================================================
// ------------------------------------------------------------ Funciones de Lógica --------------------------------------------------------------

void createPairs(const charVector& letters, charVector& pairs){
    
    /*
       - Función: Creación de Arreglo
       - Argumentos:
            - letters (std::vector<std::char>): El Vector de Caracteres con las Letras Base.
            - pairs (std::vector<std::char>): El Vector de Caracteres donde se almacenarán los Pares.
       - Retorno: Ninguno
       - Objetivo: Crear un Arreglo de Pares de Letras
    */

    /// Creación de Arreglo de Pares
    for (int i = 0; i < 18; i++){                                                                            // Repetir 18 Veces
        
        char letter = letters[i];                                                                            // Obtener Letra del Vector de Letras
        pairs[i * 2] = letter;                                                                               // Asignar Letra a la Posición Par
        pairs[i * 2 + 1] = letter;                                                                           // Asignar Letra a la Posición Impar
    
    }

}

void shuffleCards(charVector& pairs){
      
    /*
       - Función: Barajear Arreglo
       - Argumentos:
            - pairs (std::vector<char>): El Vector de Caracteres donde se almacenan los Pares.
       - Retorno: Ninguno
       - Objetivo: Barajear un Arreglo de Pares de Letras
    */

    /// Barajear Arreglo de Pares
    for (int i = 0; i < 36; i++){

        int azar = rand() % 36;                                                                              // Generación de número aleatorio entre 0 y 36
        char temp = pairs[i];                                                                                // Variable Temporal para Intercambio
        pairs[i] = pairs[azar];                                                                              // Intercambio de Valores
        pairs[azar] = temp;                                                                                  // Asignación del Valor Temporal
    
    }
}

void createBoard(charMatrix& visibleCards, charMatrix& board, const charVector& pairs){
    
    /*
       - Función: Crear Tablero
       - Argumentos:
            - visibleCards (std::vector<std::vector<char>>): La Matriz de Cartas Visibles.
            - board (std::vector<std::vector<char>>): La Matriz del Tablero con las Cartas.
            - pairs (std::vector<char>): El Vector de Caracteres donde se almacenan los Pares.
       - Retorno: Ninguno
       - Objetivo: Crear el Tablero del Juego
    */

    /// Creación del Tablero y Ocultación de Cartas
    int k = 0;                                                                                               // Índice para el Arreglo de Pares
    for (int i = 0; i < 6; i++){                                                                             // Filas
  
        for (int j = 0; j < 6; j++){                                                                         // Columnas

            board[i][j] = pairs[k];                                                                          // Asignar Par al Tablero
            visibleCards[i][j] = 'X';                                                                        // Ocultar Carta
            k++;                                                                                             // Incrementar Índice de Pares
        }
    }
}

void mainLoop(
    
    int& minutes, 
    int& seconds,
    int& errorCounter,
    int& movesCounter, 
    int& player1Points, 
    int& player2Points, 
    int& turn,
    int& card1Row, 
    int& card1Column, 
    int& card2Row, 
    int& card2Column,
    const stringVector& playerNames, 
    const charMatrix& board,
    charMatrix& visibleCards 
 
){
    
    /*
       - Función: Bucle Principal
       - Argumentos:
            - minutes (int): Minutos Transcurridos.
            - seconds (int): Segundos Transcurridos.
            - errorCounter (int): Contador de Errores.
            - movesCounter (int): Contador de Movimientos.
            - player1Points (int): Puntos del Jugador 1.
            - player2Points (int): Puntos del Jugador 2.
            - turn (int): Turno del Jugador Actual.
            - card1Row (int): Fila de la Primera Carta.
            - card1Column (int): Columna de la Primera Carta.
            - card2Row (int): Fila de la Segunda Carta.
            - card2Column (int): Columna de la Segunda Carta.
            - playerNames (std::vector<std::string>): Nombres de los Jugadores.
            - board (std::vector<std::vector<char>>): La Matriz del Tablero con las Cartas.
            - visibleCards (std::vector<std::vector<char>>): La Matriz de Cartas Visibles.
       - Retorno: Ninguno
       - Objetivo: Crear el Tablero del Juego
    */

    /// Bucle Principal del Juego
    auto start_time = steady_clock::now();                                                                   // Empezamos un cronometro
    bool validCard = false;                                                                                  // Bandera de Carta Válida
    while (player1Points + player2Points < 18){                                                              // Mientras no se acabe el Juego           
        
        do{                                                                                                  // Repetir hasta que la Carta sea Válida   
        
            validCard = false;                                                                               // Reiniciar Bandera de Carta Válida
            clearScreen();                                                                                   // Limpiar Pantalla
            printGame(player1Points, player2Points, turn, visibleCards, playerNames);                        // Actualizar Tiempo Transcurrido
            while (true){                                                                                    // Mientras

                rowCard1(card1Row, false);                                                                   // Leer Fila de la Primera Carta
                if (cin.fail()){                                                                             // Si se ingresa un Tipo Incorrecto

                    cin.clear();                                                                             // Limpiar Estado de Fallo
                    cin.ignore(MAX_LIMIT, '\n');                                                             // Ignorar Entrada Inválida
                    printError(typeError);                                                                   // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    continue;                                                                                // Continuar Bucle

                }
                if (card1Row < 0 || card1Row > 5){                                                           // Si el Valor está Fuera de Rango

                    printError(rangeError);                                                                  // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    continue;                                                                                // Continuar Bucle

                }
                break;                                                                                       // Salir del Bucle si la Entrada es Válida

            }
            clearScreen();                                                                                   // Limpiar Pantalla
            printGame(player1Points, player2Points, turn, visibleCards, playerNames);                        // Reimprimir Juego
            rowCard1(card1Row, true);                                                                        // Imprimir Fila de la Primera Carta
            while (true){                                                                                    // Mientras

            columnCard1(card1Column);                                                                        // Leer Columna de la Primera Carta
                if (cin.fail()){ 

                    cin.clear();                                                                             // Limpiar Estado de Fallo
                    cin.ignore(MAX_LIMIT, '\n');                                                             // Ignorar Entrada Inválida
                    printError(typeError);                                                                   // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    rowCard1(card1Row, true);                                                                // Imprimir Fila de la Primera Carta
                    continue;                                                                                // Continuar Bucle

                }
                if (card1Column < 0 || card1Column > 5){

                    printError(rangeError);                                                                  // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    rowCard1(card1Row, true);                                                                // Imprimir Fila de la Primera Carta
                    continue;                                                                                // Continuar Bucle
                }
                if (visibleCards[card1Row][card1Column] != 'X'){

                    errorCounter++;                                                                          // Incrementar Contador de Errores
                    clearScreen();                                                                           // Limpiar Pantalla
                    cardDiscoveredError(false);                                                              // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                                          // Esperar 2 Segundos
                    break;                                                                                   // Continuar Bucle

                }
                validCard = true;                                                                            // Marcar Carta como Válida
                break;                                                                                       // Salir del Bucle si la Entrada es Válida

            }

        }while(!validCard);                                                                                  // Repetir hasta que la Carta sea Válida
        visibleCards[card1Row][card1Column] = board[card1Row][card1Column];                                  // Revelar Primera Carta
        do{                                                                                                  // Repetir hasta que la Carta sea Válida   
        
            validCard = false;                                                                               // Reiniciar Bandera de Carta Válida
            clearScreen();                                                                                   // Limpiar Pantalla
            printGame(player1Points,player2Points,turn,visibleCards,playerNames);                            // Reimprimir Juego
            while (true){

                rowCard2(card2Row, false);                                                                   // Leer Fila de la Segunda Carta
                if (cin.fail()){                                                                             // Si se ingresa un Tipo Incorrecto
                    
                    cin.clear();                                                                             // Limpiar Estado de Fallo
                    cin.ignore(MAX_LIMIT, '\n');                                                             // Ignorar Entrada Inválida
                    printError(typeError);                                                                   // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    continue;                                                                                // Continuar Bucle

                }
                if (card2Row < 0 || card2Row > 5) {                                                          // Si el Valor está Fuera de Rango

                    printError(rangeError);                                                                  // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    continue;                                                                                // Continuar Bucle

                }
                break;                                                                                       // Salir del Bucle si la Entrada es Válida

            }
            while(true){                                                                                     // Mientras

                columnCard2(card2Column);                                                                    // Leer Columna de la Segunda Carta
                if (cin.fail()){                                                                             // Si se ingresa un Tipo Incorrecto

                    cin.clear();                                                                             // Limpiar Estado de Fallo
                    cin.ignore(MAX_LIMIT, '\n');                                                             // Ignorar Entrada Inválida
                    printError(typeError);                                                                   // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    rowCard2(card2Row, true);                                                                // Imprimir Fila de la Segunda Carta
                    continue;                                                                                // Continuar Bucle
                
                }
                if (card2Column < 0 || card2Column > 5){

                    printError(rangeError);                                                                  // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames);                // Reimprimir Juego
                    rowCard2(card2Row, true);                                                                // Imprimir Fila de la Segunda Carta
                    continue;                                                                                // Continuar Bucle

                }
                if (card2Row == card1Row && card2Column == card1Column){                                     // Si es la Misma Carta
    
                    errorCounter++;                                                                          // Incrementar Contador de Errores
                    clearScreen();                                                                           // Limpiar Pantalla
                    cardDiscoveredError(true);                                                               // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                                          // Esperar 2 Segundos
                    break;                                                                                   // Salimos del Bucle
                
                }
                if (visibleCards[card2Row][card2Column] != 'X'){                                             // Si la Carta ya fue Descubierta

                    errorCounter++;                                                                          // Incrementar Contador de Errores
                    clearScreen();                                                                           // Limpiar Pantalla
                    cardDiscoveredError(false);                                                              // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                                          // Esperar 2 Segundos
                    break;                                                                                   // Salimos del Bucle
                
                }  
                validCard = true;                                                                            // Marcamos como Selección Válida de Cartas
                break;                                                                                       // Salir del Bucle si la Entrada es Válida
            
            }
        
        }while(!validCard);                                                                                  // Hasta que Selección de Cartas sea Válida
        char boardCard2 = board[card2Row][card2Column];                                                                      // Obtener Valor de la Segunda Carta del Tablero
        visibleCards[card2Row][card2Column] = boardCard2;                                                    // Revelar Segunda Carta
        movesCounter++;                                                                                      // Incrementar Contador de Movimientos
        clearScreen();                                                                                       // Limpiar Pantalla
        printGame(player1Points, player2Points, turn, visibleCards, playerNames);                            // Reimprimir Juego
        if (board[card1Row][card1Column] == boardCard2){                                                     // Si las Cartas son Iguales
        
            cardMessage(true);                                                                               // Imprimir Mensaje de Pareja Encontrada
            waitSeconds(2);                                                                                  // Esperar 2 Segundos
            if (turn == 1) player1Points++;                                                                  // Asignar Punto al Jugador Correspondiente
            else player2Points++;                                                                            // Asignar Punto al Jugador Correspondiente
    
        }
        else{                                                                                                // Si las Cartas No Son Iguales
            
            errorCounter++;
            cardMessage(false);                                                                              // Imprimir Mensaje de No Son Iguales
            waitSeconds(2);                                                                                  // Esperamos 2 Segundos
            visibleCards[card1Row][card1Column] = 'X';                                                       // Tapamos la Primera Carta
            visibleCards[card2Row][card2Column] = 'X';                                                       // Tapamos la Segunda Carta
            turn == 1 ? turn = 2 : turn = 1;                                                                 // Alternamos el Turno
            waitSeconds(2);                                                                                  // Esperamos 2 Segundos

        }
    
    }
    auto end_time = steady_clock::now();                                                                     // Pausamos el Cronómetro
    auto game_duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);                      // Tiempo en Juego en Segundos
    int totalSeconds = game_duration.count();                                                                // Asignar Minutos
    minutes = totalSeconds / 60;                                                                             // Convertir a Minutos
    seconds = totalSeconds % 60;                                                                             // Convertir a Segundos
               
}

// =====================================================================================================================================