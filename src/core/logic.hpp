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
#include "../ui/renders.hpp"                                                                                 // Funciones de Renderizado
 
// =====================================================================================================================================
// ------------------------------------------------------------ Alías--------------------------------------------------------------
   
/// Alías para Optimizar Tipos de Datos
using charVector = vector<char>;                                                                             // Vector de Caracteres

// =====================================================================================================================================
// ------------------------------------------------------------ Alías--------------------------------------------------------------
 
/**
 * @brief Creación de Arreglo de Pares.
 * @param letters (std::vector<char>): El Vector de Caracteres con las Letras Base.
 * @param pairs (std::vector<char>): El Vector de Caracteres donde se almacenarán los Pares.
 */
void createPairs(const charVector& letters, charVector& pairs);

/**
 * @brief Barajear las Cartas
 * @param pairs (std::vector<char>): El Vector de Caracteres donde se almacenan los Pares.
 */
void shuffleCards(charVector& pairs);

/**
 * @brief Crear Tablero.
 * @param visibleCards (std::vector<std::vector<char>>): La Matriz de Cartas Visibles.
 * @param board (std::vector<std::vector<char>>): La Matriz del Tablero con las Cartas.
 * @param pairs (std::vector<char>): El Vector de Caracteres donde se almacenan los Pares.
 */
void createBoard(charMatrix& visibleCards, charMatrix& board, const charVector& pairs);

/**
 * @brief Función de Bucle Principal.
 * @param minutes (int): Minutos Transcurridos.
 * @param seconds (int): Segundos Transcurridos.
 * @param errorCounter (int): Contador de Errores.
 * @param movesCounter (int): Contador de Movimientos.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param turn (int): Turno del Jugador Actual.
 * @param card1Row (int): Fila de la Primera Carta.
 * @param card1Column (int): Columna de la Primera Carta.
 * @param card2Row (int): Fila de la Segunda Carta.
 * @param card2Column (int): Columna de la Segunda Carta.
 * @param playerNames (std::vector<std::string>): Nombres de los Jugadores.
 * @param board (std::vector<std::vector<char>>): La Matriz del Tablero con las Cartas.
 * @param visibleCards (std::vector<std::vector<char>>): La Matriz de Cartas Visibles.
 * @throw std::out_of_range (int): Si algún Entero es Negativo.
 */
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
 
);

// =====================================================================================================================================