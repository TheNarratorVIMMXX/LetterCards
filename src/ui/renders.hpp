
// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Funciones Renders

// Ultima Modificacion: 09/05/26
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <string>                                                                                            // Cadenas de Texto
#include <vector>                                                                                            // Vectores Dinámicos
 
// =====================================================================================================================================
// -------------------------------------------------------------- Alías ----------------------------------------------------------------

/// Alías para Optimizar Código
using std::vector;                                                                                            // Vectores Dinámicos
using charMatrix = vector<vector<char>>;                                                                      // Matriz de Cadenas
using stringVector = vector<std::string>;                                                                     // Vector de Cadenas
 
// =====================================================================================================================================
// -------------------------------------------------------------- Renders ----------------------------------------------------------------
 
/**
 * @brief Imprimir Portada del Juego.
 */
void titleCover();

/**
 * @brief Imprimir Error de Rango.
 */
void rangeError();

/**
 * @brief Imprimir Felicitaciones al Ganador.
 */
void win();

/**
 * @brief Imprimir Mensaje de Empate.
 */
void tie();

/**
 * @brief Función de Impresión de Error de Carta ya Descubierta.
 * @param sameCard (bool): Indica si la carta seleccionada es la misma que la primera.
 */
void cardDiscoveredError(bool sameCard);

/**
 * @brief Función de Impresión de Datos Generales del Juego.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param turn (int): Turno del Jugador Actual.
 * @param playersNames (std::vector<std::string>): Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero no es Positivo.
 */
void printGeneralData(int player1Points, int player2Points, int turn, const stringVector& playersNames);

/**
 * @brief Imprimir Error de Tipo.
 */
void typeError();

/**
 * @brief Función de Impresión de Error de Cadena Vacía de Nombres de Jugadores.
 * @param playerNum (int): Número del Jugador (0 o 1).
 * @param playersNames (std::vector<std::string>): Vector de Nombres de los Jugadores.
 */
void emptyNameError(const stringVector& playersNames, int playerNum);

/**
 * @brief Función para Leer Nombres de los Jugadores.
 * @param playersNames (std::vector<std::string>): Vector de Nombres de los Jugadores.
 */
void inputNames(stringVector& playersNames);

/**
 * @brief Imprimir Animación de Carga.
 */
void loading();

/**
 * @brief Función para Imprimir el Tablero.
 * @param visibleCards (std::vector<std::vector<char>>): La Matriz de Cadenas de Cartas Visibles.
 */
void printBoard(const charMatrix& visibleCards);

/**
 * @brief Función para Leer 1era Carta de Fila.
 * @param rowCard1 (int): La Primera Carta de Fila.
 * @param onlyPrint (bool): Indica si solo se debe Imprimir el Valor sin Leer Entrada.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void rowCard1(int& rowCard1, bool onlyPrint);

/**
 * @brief Función para Leer 1era Carta de Columna.
 * @param columnCard2 (int): La Primera Carta de Columna.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void columnCard1(int& columnCard1);

/**
 * @brief Función de Impresión de Elementos Visuales del Juego.
 * @param player1Points (int): Puntos del Jugador 1
 * @param player2Points (int): Puntos del Jugador 2
 * @param turn (int): Número de Turno
 * @param visibleCards (std::vector<std::vector<char>>): La Matriz de Cadenas con las Cartas Visibles.
 * @param playersName (std::vector<std::string>): El Vector de Cadenas donde que Almacenan los Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero es Negativo
 */
void printGame(int& player1Points, int& player2Points, int& turn, const charMatrix& visibleCards, const stringVector& playersNames);

/**
 * @brief Función para Leer 2da Carta de Fila.
 * @param aMatch (bool): Indica si las Cartas Hicieron Pareja.
 */
void cardMessage(bool aMatch);

/**
 * @brief Función para Leer 2da Carta de Fila.
 * @param rowCard2 (int): La Segunda Carta de Fila.
 * @param onlyPrint (bool): Indica si solo se debe Imprimir el Valor sin Leer Entrada.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void rowCard2(int& rowCard2, bool onlyPrint);

/**
 * @brief Función para Leer 2da Carta de Columna.
 * @param columnCard2 (int): La Segunda Carta de Columna.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void columnCard2(int& columnCard2);

/**
 * @brief Función de Imprimir Resultados Finales.
 * @param minutes (int): Minutos Transcurridos.
 * @param seconds (int): Segundos Transcurridos.
 * @param movesCounter (int): Contador de Movimientos.
 * @param errorCounter (int): Contador de Errores.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param playerNames (std::vector<std::string>): Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero es Negativo.
 */
void printFinalResults(int minutes, int seconds,int movesCounter, int errorCounter, int player1Points, int player2Points, const stringVector& playerNames);

/**
 * @brief Función de Imprimir al Gandor.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param playerNames (std::vector<std::string>): Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero es Negativo.
 */
void printWinner(int player1Points, int player2Points, const stringVector& playerNames);


// =====================================================================================================================================