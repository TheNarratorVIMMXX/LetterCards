// =====================================================================================================================================

// DOCUMENTACIÓN:

// Memorama - Juego de Memoria

// Ultima Modificacion: 09/05/26
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Internas
#include "core/logic.hpp"                                                                                    // Lógica del Juego
#include "ui/renders.hpp"                                                                                    // Funciones de Renderizado
#include "utils/helpers.hpp"                                                                                 // Funciones Auxiliares

// =====================================================================================================================================
// ------------------------------------------------------- Funciones Principal --------------------------------------------------------------

/**
 * @brief Función Principal.
 * @return (int) Código de Salida
 */
int main() {

    /// Configuraciones Iniciales
    clearScreen();                                                                                           // Limpiar Pantalla
    setConsoleColor(4);                                                                                      // Color de Fuente: Rojo Fuerte

    /// Declaración de Variables Enteras
    int card1Row = 0, card1Column = 0, card2Row = 0, card2Column = 0;                                        // Coordenadas de las Cartas
    int turn = 1, player1Points = 0, player2Points = 0;                                                      // Turno y Puntos de los Jugadores
    int movesCounter = 0, errorCounter = 0;                                                                  // Contadores de Movimientos y Errores
    int minutes = 0, seconds = 0;                                                                            // Tiempo Transcurrido

    /// Declaración de Vectores y Matrices
    charVector letters(18);                                                                                  // 18 Letras Unicas
    charVector pairs(36);                                                                                    // 36 Cartas (18 Pares)
    stringVector playerNames(2);                                                                             // 2 Jugadores
    charMatrix visibleCards(6, charVector(6));                                                               // Tablero Visible 6x6
    charMatrix board(6, charVector(6));                                                                      // Tablero Real 6x6
 
    /// Inicialización de las Letras para los Pares (18 Pares)
    letters[0] = 'A';
    letters[1] = 'B';
    letters[2] = 'C';
    letters[3] = 'D';
    letters[4] = 'E';
    letters[5] = 'F';
    letters[6] = 'G';
    letters[7] = 'H';
    letters[8] = 'I';
    letters[9] = 'J';
    letters[10] = 'K';
    letters[11] = 'L';
    letters[12] = 'M';
    letters[13] = 'N';
    letters[14] = 'O';
    letters[15] = 'P';
    letters[16] = 'Q';
    letters[17] = 'R';

    /// Inicializar la Semilla con el Tiempo Actual
    srand(time(0));

    /// Ingreso de Nombres
    inputNames(playerNames);

    /// Animación Básica de Carga
    loading();

    /// Crear el Arreglo de Pares
    createPairs(letters, pairs);

    /// Barajear el Arreglo de Pares
    shuffleCards(pairs);

    /// Asignar Pares al Tablero y Ocultar
    createBoard(visibleCards, board, pairs);

    /// Ciclo Principal
    mainLoop(
        
        minutes, 
        seconds, 
        errorCounter, 
        movesCounter, 
        player1Points, 
        player2Points, 
        turn,
        card1Row, 
        card1Column, 
        card2Row, 
        card2Column,
        playerNames, 
        board, 
        visibleCards
    
    );

    /// Mostrar Resultados Finales
    printFinalResults(minutes, seconds, movesCounter, errorCounter, player1Points, player2Points, playerNames);

    /// Mensaje al Jugador Ganador
    printWinner(player1Points, player2Points, playerNames);

    /// Código de Salida
    return 0;

}

// =====================================================================================================================================