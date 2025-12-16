// =====================================================================================================================================

// DOCUMENTACIÓN:

// Memorama - Juego de Memoria

// Ultima Modificacion: 6/12/25
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

#include <iostream>       // Librería Estándar
#include <string>         // Inclusión del Tipo de Dato Sring
#include <vector>         // Inclusión del Tipo de Dato Vector Dinámico
#include <time.h>         // Librería para Funciones de Tiempo
#include <chrono>         // Librería para Funciones de Tiempo y de Duración
#include <thread>         // Librería para Hilos de Ejecución
#include <algorithm>      // Librería para Algoritmos Estándar
#include <limits>         // Librería para Límites Numéricos

// =====================================================================================================================================
// -------------------------------------------------------------- Alías ----------------------------------------------------------------

namespace chrono = std::chrono;                                                   /// Alías para usar el Espacio de Nombres Chrono
using seconds = std::chrono::seconds;                                             /// Alías para usar Segundos

// =====================================================================================================================================
// -------------------------------------------------------------- Constantes ----------------------------------------------------------------

const std::streamsize MAX_LIMIT = std::numeric_limits<std::streamsize>::max();   /// Constante para el Límite Máximo de un Stream

// =====================================================================================================================================
// -------------------------------------------------------------- Sistema Operativo ----------------------------------------------

/// Detectar el Sistema Operativo
#ifdef _WIN32                          // Windows
    #include <windows.h>               // Librería de Windows
    #define IS_WINDOWS true            // Definir Constante para Windows
#else                                  // POSIX (Linux, macOS)
    #include <unistd.h>                // Librería de POSIX
    #include <term.h>                  // Librería de Terminal POSIX
    #include <cstdlib>                 // Librería Estándar de C
    #define IS_WINDOWS false           // Definir Constante para POSIX
#endif              

// =====================================================================================================================================
// -------------------------------------------------------------- Funciones Cross-Platform ----------------------------------------------

/**
 * @brief Función para Limpiar la Pantalla (Multiplataforma)
 */
void clearScreen(){

    /*
       - Función: Limpiar Pantalla
       - Argumentos: Ninguno 
       - Retorno: Ninguno
       - Objetivo: Limpiar la Pantalla de la Consola
    */

    /// Limpiar Pantalla
    #ifdef _WIN32                                                    // Windows
        system("cls");                                               // Comando para Limpiar Pantalla en Windows
    #else                                                            // POSIX (Linux, macOS)
        if (system("clear") != 0) std::cout << "\033[2J\033[1;1H";   // Comando para Limpiar Pantalla en POSIX
    #endif

}




/**
 * @brief Función para Establecer Color de Texto (Multiplataforma)
 * @param colorCode Código de color (Windows: 0-15, POSIX: códigos ANSI)
 */
void setConsoleColor(int colorCode){
    
    /*
       - Función: Establecer Color de Texto
       - Argumentos: 
            - colorCode (int): Código de Color
       - Retorno: Ninguno
       - Objetivo: Establecer el Color de Texto en la Consola
    */
    
    /// Establecer Color de Texto
    #ifdef _WIN32                                                   // Windows
        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);     // Obtener el Handle de la Consola
        SetConsoleTextAttribute(handleConsole, colorCode);          // Establecer Color en Windows
    #else                                                           // POSIX (Linux, macOS)

        /// Códigos ANSI para colores básicos
        const char* ANSI_COLORS[] = {
            
            "\033[0;30m",                          // 0: Negro
            "\033[0;34m",                          // 1: Azul
            "\033[0;32m",                          // 2: Verde
            "\033[0;36m",                          // 3: Cian
            "\033[0;31m",                          // 4: Rojo
            "\033[0;35m",                          // 5: Magenta
            "\033[0;33m",                          // 6: Amarillo
            "\033[0;37m",                          // 7: Blanco
            "\033[1;30m",                          // 8: Gris
            "\033[1;34m",                          // 9: Azul Claro
            "\033[1;32m",                          // 10: Verde Claro
            "\033[1;36m",                          // 11: Cian Claro
            "\033[1;31m",                          // 12: Rojo Claro
            "\033[1;35m",                          // 13: Magenta Claro
            "\033[1;33m",                          // 14: Amarillo Claro
            "\033[1;37m"                           // 15: Blanco Brillante

        };
        
        /// Establecer Color si el Código es Válido
        if (colorCode >= 0 && colorCode < 16) std::cout << ANSI_COLORS[colorCode];
        
    #endif

}




/**
 * @brief Función para Emitir un Sonido (Beep) - Multiplataforma
 */
void playBeep(){

    /*
       - Función: Emitir Sonido
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Emitir un Sonido (Beep) en la Consola
    */

    /// Emitir Sonido
    #ifdef _WIN32                          // Windows
        Beep(750, 300);                    // Frecuencia de 750 Hz durante 300 ms
    #else                                  // POSIX (Linux, macOS)
        std::cout << '\a' << std::flush;   // Emitir sonido de alerta
    #endif

}




/**
 * @brief Función para Pausar la Ejecución - Multiplataforma
 */
void pauseExecution() {
    
    /*
       - Función: Emitir Sonido
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Emitir un Sonido (Beep) en la Consola
    */

    /// Pausar Ejecución
    #ifdef _WIN32                                                            // Windows
        system("pause");                                                     // Comando para Pausar en Windows
    #else                                                                    // POSIX (Linux, macOS)
        std::cout << "Presiona Enter para continuar...";                     // Mensaje para el Usuario
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Esperar Entrada del Usuario
        std::cin.get();                                                      // Esperar Enter
    #endif

}

// =====================================================================================================================================
// -------------------------------------------------------------- Helpers ----------------------------------------------------------------

/**
 * @brief Función que Espera una Cantidad de Segundos Específica.
 * @param seconds (int): La Cantidad de Segundos a Esperar.
 */
inline void waitSeconds(int seconds){std::this_thread::sleep_for(std::chrono::seconds(seconds));}




/**
 * @brief Función que Espera una Cantidad de Milisegundos Específica.
 * @param milliseconds (int): La Cantidad de Milisegundos a Esperar.
 */
inline void waitMilliseconds(int milliseconds){std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));}




/**
 * @brief Función que Imprime un Mensaje de Error utilizando una Función de Error.
 * @param errorFunction (void(*)()): La Función de Error a Imprimir.
 */
void printError(void(*errorFunction)()){

    /*
       - Función: Imprimir Error
       - Argumentos:
            - errorFunction (void(*)()): Función de Error a Imprimir 
       - Retorno: Ninguno
       - Objetivo: Imprimir un Mensaje de Error utilizando una Función de Error
    */

    /// Impresión de Mensaje de Error
    clearScreen();                  // Limpiar Pantalla
    errorFunction();                // Llamar a la Función de Error
    waitSeconds(2);                 // Esperar 2 Segundos
    clearScreen();                  // Limpiar Pantalla

}




/**
 * @brief Función que Verifica que un Entero sea Positivo
 * @param intValue (int): El Entero a Validar.
 * @throw std::out_of_range Si el Entero no es Positivo.
 */
void validatePositiveInt(int intValue) {

    /*
       - Función: Validar Entero Positivo
       - Argumentos:
            - intValue (int): Valor a Validar 
       - Retorno: Ninguno
       - Objetivo: Validar que un Entero sea Positivo
    */

    /// Verificar que el Entero sea Positivo
    if (intValue < 0) throw std::out_of_range("El Valor debe ser un Entero Positivo");

}

// =====================================================================================================================================
// -------------------------------------------------------------- Renders ----------------------------------------------------------------

/// Función: Portada del Juego
void titleCover(){
    
    /*
       - Función: Portada del Juego
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Memorama en Arte ASCII
    */

    // Impresión de Portada del Juego
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *          **   **  *****  **   **  *****  *****   ***   **   **  ***            * \n";
    std::cout << "                      *          * * * *  *      * * * *  *   *  *   *  *   *  * * * * *   *           * \n";
    std::cout << "                      *          *  *  *  ****   *  *  *  *   *  ****   *****  *  *  * *****           * \n";
    std::cout << "                      *          *     *  *      *     *  *   *  *   *  *   *  *     * *   *           * \n";
    std::cout << "                      *          *     *  *****  *     *  *****  *   *  *   *  *     * *   *           * \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      ********************************************************************************** \n";

}




/// Función: Error de Rango
void rangeError(){

    /*
       - Función: Error de Rango
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario ingresa un Valor Fuera de Rango
    */

    // Impresión de Mensaje de Error
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                        ERROR                                   * \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                           Fuera de Rango (Numeros de 0-5)                      * \n";
    std::cout << "                      ********************************************************************************** \n";

}



/// Función: Felicitaciones al Ganador
void win(){

    /*
       - Función: Felicitaciones al Ganador
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Felicitaciones al Ganador
    */

    /// Configración Inicial
    clearScreen();                     // Limpiar Pantalla   
    waitSeconds(2);                   // Esperar 2 Segundos

    /// Mensaje de Felicitaciones
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *       *****  *****  *      *   ****  *  *****    ***   ****   *****  ****      * \n";
    std::cout << "                      *       *      *      *      *  *      *  *    *  *   *  *   *  *     *          * \n";
    std::cout << "                      *       ****   ****   *      *  *      *  *    *  *****  *   *  ****   ****      * \n";
    std::cout << "                      *       *      *      *      *  *      *  *    *  *   *  *   *  *          *     * \n";
    std::cout << "                      *       *      *****  *****  *   ****  *  *****   *   *  ****   *****  ****      * \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      ********************************************************************************** \n";

}




/// Función: Mensaje de Empate
void tie(){

    /*
       - Función: Mensaje de Empate
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Empate
    */

    // Mensaje de Empate
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *                   *****  **   **  ****    ***   *******  *****                 * \n";
    std::cout << "                      *                   *      * * * *  *   *  *   *     *     *                     * \n";
    std::cout << "                      *                   ****   *  *  *  ****   *****     *     ****                  * \n";
    std::cout << "                      *                   *      *     *  *      *   *     *     *                     * \n";
    std::cout << "                      *                   *****  *     *  *      *   *     *     *****                 * \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      ********************************************************************************** \n";

}




/**
 * @brief Función de Impresión de Error de Carta ya Descubierta.
 * @param sameCard (bool): Indica si la carta seleccionada es la misma que la primera.
 */
void cardDiscoveredError(bool sameCard){
    
    /*
       - Función: Error de Carta ya Descubierta
       - Argumentos:
            - sameCard (bool): Indica si la carta seleccionada es la misma que la primera
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario selecciona una Carta ya Descubierta
    */
    
    /// Impresión de Mensaje de Error
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                     ERROR                                      * \n";
    std::cout << "                      ********************************************************************************** \n";
    if (sameCard) std::cout << "                      *                   Ya elegiste esa Carta como Primera. Escoge otra.             * \n";
    else std::cout << "                      *                    Esa Carta ya fue descubierta. Escoge otra.                  * \n";
    std::cout << "                      ********************************************************************************** \n";

}




/**
 * @brief Función de Impresión de Datos Generales del Juego.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param turn (int): Turno del Jugador Actual.
 * @param playersNames (std::vector<std::string>): Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero no es Positivo.
 */
void printGeneralData(int player1Points, int player2Points, int turn, const std::vector<std::string>& playersNames){

    /*
       - Función: Datos Generales
       - Argumentos:
            - player1Points (int): Puntos del Jugador 1 
            - player2Points (int): Puntos del Jugador 2 
            - turn (int): Turno del Jugador Actual 
            - playersNames (std::vector<std::string>): Nombres de los Jugadores 
       - Retorno: Ninguno
       - Objetivo: Imprimir Datos Generales del Juego (Puntajes y Turno Actual)
    */

    /// Validaciones de Argumentos de Tipo Entero
    validatePositiveInt(player1Points);                    // Puntos del Jugador 1
    validatePositiveInt(player2Points);                    // Puntos del Jugador 2
    validatePositiveInt(turn);                             // Turno del Jugador Actual

    /// Impresión de Datos Generales
    std::cout << "                      *            " << playersNames[0] << " : " << player1Points << " puntos           |            " << playersNames[1] << " : " << player2Points << " puntos \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                               Turno del jugador: " << playersNames[turn - 1] << "\n";
    std::cout << "                      ********************************************************************************** \n";

}




/// Función: Error de Tipo
void typeError(){

    /*
       - Función: Error de Tipo
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario ingresa un Valor de Tipo Inválido
    */

    // Impresión de Mensaje de Error
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                     ERROR                                      * \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *               Entrada Invalida. Por favor ingresa un Numero Entero             * \n";
    std::cout << "                      ********************************************************************************** \n";

}




/**
 * @brief Función de Impresión de Error de Cadena Vacía de Nombres de Jugadores.
 * @param playerNum (int): Número del Jugador (0 o 1).
 * @param playersNames (std::vector<std::string>): Vector de Nombres de los Jugadores.
 */
void emptyNameError(const std::vector<std::string>& playersNames, int playerNum){

    /*
       - Función: Error de Cadena Vacía de Nombres de Jugadores
       - Argumentos:
            - playerNum (int): Número del Jugador (0 o 1)
            - playersNames (std::vector<std::string>&): Vector de Nombres de los Jugadores
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario ingresa una Cadena Vacía como Nombre de Jugador
    */

    /// Configuraciones Iniciales
    waitSeconds(2);                 // Esperar 2 Segundos
    clearScreen();                  // Limpiar Pantalla
     
    // Impresión de Mensaje de Error
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                     ERROR                                      * \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                   El Nombre no puede estar Vacio, Jugador " << playerNum + 1 << "                    * \n";
    std::cout << "                      ********************************************************************************** \n";
 
    /// Configuraciones Finales
    waitSeconds(2);                 // Esperar 2 Segundos
    clearScreen();                  // Limpiar Pantalla

    if (playerNum == 1){

        std::cout << "                      ********************************************************************************** \n";
        std::cout << "                      *                   Escribe el Nombre del Jugador 1: " << playersNames[playerNum - 1] << " \n";
        std::cout << "                      ********************************************************************************** \n";

    }

}




/**
 * @brief Función para Leer Nombres de los Jugadores.
 * @param playersNames (std::vector<std::string>): Vector de Nombres de los Jugadores.
 */
void inputNames(std::vector<std::string>& playersNames){

    /*
       - Función: Leer Nombres de los Jugadores
       - Argumentos:
            - playerNames (std::vector<std::string>&): Vector de Nombres de los Jugadores
       - Retorno: Ninguno
       - Objetivo: Leer Nombres de los Jugadores para su Almacenamiento
    */

    /// Lectura de Nombres
    for(int i = 0; i < 2; i++){
        
        do {                                                                                // Repetir hasta obtener un nombre válido
            
            /// Impresión y Lectura de Nombre de Jugador
            if (i == 0) std::cout << "                      ********************************************************************************** \n";
            std::cout << "                      *                   Escribe el Nombre del Jugador " << i+1 << ": ";
            std::getline(std::cin, playersNames[i]);
            
            /// Buscar Primer Carácter no Espacio
            auto start = playersNames[i].find_first_not_of(" \t\n\r");                   
            
            /// Si solo hay Espacios, marcar como Vacío
            if (start == std::string::npos) playersNames[i] = "";                 
                    
            /// Imprimir Error de Nombre Vacío si el Nombre de algún Jugador está Vacío 
            if (playersNames[i].empty()) emptyNameError(playersNames, i);               
            
        } while (playersNames[i].empty());                                                // Repetir hasta obtener un nombre válido
        
        std::cout << "                      ********************************************************************************** \n";
    
    }
    
    /// Configuraciones Finales
    waitSeconds(2);              // Esperamos 2 Segundos
    clearScreen();               // Limpiar Pantalla

}




/// Función: Animación de Carga
void loading(){

    /*
       - Función: Animación de Carga
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Animación de Carga
    */

    /// Animación de Carga
    for (int i = 0; i < 3; i++){                    // Repetir 3 Veces

        std::cout << "Cargando";                    // Imprimir Cargando
        for (int j = 0; j < 5; j++){                // Repetir 5 Veces
            
            std::cout << ".";                       // Imprimir Punto
            waitMilliseconds(500);                  // Esperar 500 MiliSegundos
        }
        clearScreen();                              // Limpiar Pantalla
    }

}




/**
 * @brief Función para Imprimir el Tablero.
 * @param visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cadenas de Cartas Visibles.
 */
void printBoard(const std::vector<std::vector<std::string>>& visibleCards){

    /*
       - Función: Imprimir el Tablero
       - Argumentos:
            - visibleCards (std::vector<std::vector<std::string>>): Matriz de Cartas Visibles 
       - Retorno: Ninguno
       - Objetivo: Imprimir el Tablero con las Cartas Visibles
    */

    /// Impresión de Cartas Visibles del Tablero
    for (int i = 0; i < 6; i++){                                                                          // Recorrido de 5 Iteraciones

        std::cout << "                      *                                   " << i << " ";            // Imprimimos el Número de Fila
        for (int j = 0; j < 6; j++){                                                                      // Recorrido de 5 Cartas

            if (j == 5) std::cout << visibleCards[i][j] << "                                * \n";        // Si Ultima Carta: Fin de Fila
            else std::cout << visibleCards[i][j] << " ";                                                  // Solo Imprimir la Carta
        
        }
    }

}




/**
 * @brief Función para Leer 1era Carta de Fila.
 * @param rowCard1 (int): La Primera Carta de Fila.
 * @param onlyPrint (bool): Indica si solo se debe Imprimir el Valor sin Leer Entrada.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void rowCard1(int& rowCard1, bool onlyPrint){

    /*
       - Función: Leer 1era Carta de Fila
       - Argumentos:
            - rowCard1 (int): Primera Carta de Fila 
       - Retorno: Ninguno
       - Objetivo: Leer 1era Carta de Fila del Usuario
    */

    /// Validación de Argumento
    validatePositiveInt(rowCard1);                             // Entero Positivo
    
    ///Impresión y Lectura de Primera Carta de Fila
    std::cout << "                      ********************************************************************************** \n";
    if (onlyPrint) std::cout << "                      *                  Elige la fila de la primera carta (0-5): " << rowCard1 << "                    *   \n";
    else{
    
        std::cout << "                      *                  Elige la fila de la primera carta (0-5): ";
        std::cin >> rowCard1;
    }

}




/**
 * @brief Función para Leer 1era Carta de Columna.
 * @param columnCard2 (int): La Primera Carta de Columna.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void columnCard1(int& columnCard1){
    
    /*
       - Función: Leer 1era Carta de Columna
       - Argumentos:
            - columnCard1 (int): Primera Carta de Columna
       - Retorno: Ninguno
       - Objetivo: Leer 1era Carta de Columna del Usuario
    */

    /// Validación de Argumento
    validatePositiveInt(columnCard1);                             // Entero Positivo

    ///Impresión y Lectura de Primera Carta de Columna
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                  Elige la columna de la primera carta (0-5): ";
    std::cin >> columnCard1;

}




/**
 * @brief Función de Impresión de Elementos Visuales del Juego.
 * @param player1Points (int): Puntos del Jugador 1
 * @param player2Points (int): Puntos del Jugador 2
 * @param turn (int): Número de Turno
 * @param visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cadenas con las Cartas Visibles.
 * @param playersName (std::vector<std::string>): El Vector de Cadenas donde que Almacenan los Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero es Negativo
 */
void printGame(
    
    int& player1Points, 
    int& player2Points, 
    int& turn, 
    const std::vector<std::vector<std::string>>& visibleCards, 
    const std::vector<std::string>& playersNames

){
    
    /*
       - Función: Impresión de Elementos Visuales del Juego
       - Argumentos:
            - player1Points (int): Puntos del Jugador 1
            - player2Points (int): Puntos del Jugador 2
            - turn (int): Número de Turno
            - visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cadenas con las Cartas Visibles.
            - playersName (std::vector<std::string>): El Vector de Cadenas donde que Almacenan los Nombres de los Jugadores.
       - Retorno: Ninguno
       - Objetivo: Impresión de Elementos Visuales del Juego para la visualización del Usuario
    */

    /// Imprimir Portada del Juego
    titleCover();

    /// Imprimir la Información General del Juego
    printGeneralData(player1Points, player2Points, turn, playersNames);

    /// Mostrar Tablero Visible con Coordenadas
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *                                     0 1 2 3 4 5                                * \n";
    printBoard(visibleCards);
    std::cout << "                      *                                                                                * \n";

}




/**
 * @brief Función para Leer 2da Carta de Fila.
 * @param aMatch (bool): Indica si las Cartas Hicieron Pareja.
 */
void cardMessage(bool aMatch){
   
    /*
       - Función: Mensaje de Carta
       - Argumentos:
            - aMatch (bool): Indica si las Cartas Hicieron Pareja
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Carta (Pareja Encontrada o No Son Iguales)
    */

    
    /// Impresión de Mensaje de Carta
    std::cout << "                      ********************************************************************************** \n";
    if (aMatch){
    
        std::cout << "                      *                                 ¡Pareja encontrada!                            * \n";
        playBeep();

    }
    else std::cout << "                      *                                   No son iguales.                              *\n";
    std::cout << "                      ********************************************************************************** \n";

}




/**
 * @brief Función para Leer 2da Carta de Fila.
 * @param rowCard2 (int): La Segunda Carta de Fila.
 * @param onlyPrint (bool): Indica si solo se debe Imprimir el Valor sin Leer Entrada.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void rowCard2(int& rowCard2, bool onlyPrint){

    /*
       - Función: Leer 2da Carta de Fila
       - Argumentos:
            - rowCard2 (int): Segunda Carta de Fila
            - onlyPrint (bool): Indica si solo se debe Imprimir el Valor sin Leer Entrada. 
       - Retorno: Ninguno
       - Objetivo: Leer 2da Carta de Fila del Usuario
    */

    /// Validación de Argumento
    validatePositiveInt(rowCard2);                             // Entero Positivo

    ///Impresión y Lectura de Segunda Carta de Fila    
    std::cout << "                      ********************************************************************************** \n";
    if (onlyPrint) std::cout << "                      *                  Elige la fila de la segunda carta (0-5): " << rowCard2 << "                    *   \n";
    else{
    
        std::cout << "                      *                  Elige la fila de la segunda carta (0-5): ";
        std::cin >> rowCard2;
    
    }
}




/**
 * @brief Función para Leer 2da Carta de Columna.
 * @param columnCard2 (int): La Segunda Carta de Columna.
 * @throw std::out_of_range (int): Si el Valor de la Carta no es Positivo.
 */
void columnCard2(int& columnCard2){
    
    /*
       - Función: Leer 2da Carta de Columna
       - Argumentos:
            - columnCard2 (int): Primera Carta de Columna 
       - Retorno: Ninguno
       - Objetivo: Leer 2da Carta de Columna del Usuario
    */

    /// Validación de Argumento
    validatePositiveInt(columnCard2);                             // Entero Positivo

    ///Impresión y Lectura de Segunda Carta de Columna
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                  Elige la columna de la segunda carta (0-5): ";
    std::cin >> columnCard2;

}

// =====================================================================================================================================
// ------------------------------------------------------- Funciones Core --------------------------------------------------------------

/**
 * @brief Función de Creación de Arreglo de Pares.
 * @param letters (std::vector<std::string>): El Vector de Cadenas con las Letras Base.
 * @param pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenarán los Pares.
 */
void createPairs(const std::vector<std::string>& letters, std::vector<std::string>& pairs){
    
    /*
       - Función: Creación de Arreglo
       - Argumentos:
            - letters (std::vector<std::string>): El Vector de Cadenas con las Letras Base.
            - pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenarán los Pares.
       - Retorno: Ninguno
       - Objetivo: Crear un Arreglo de Pares de Letras
    */

    /// Creación de Arreglo de Pares
    for (int i = 0; i < 18; i++){          /// Repetir 18 Veces
        
        pairs[i * 2] = letters[i];         /// Asignar Letra a la Posición Par
        pairs[i * 2 + 1] = letters[i];     /// Asignar Letra a la Posición Impar
    
    }

}




/**
 * @brief Función para Barajear.
 * @param pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenan los Pares.
 */
void shuffleCards(std::vector<std::string>& pairs){
    
    /*
       - Función: Barajear Arreglo
       - Argumentos:
            - pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenan los Pares.
       - Retorno: Ninguno
       - Objetivo: Barajear un Arreglo de Pares de Letras
    */

    /// Barajear Arreglo de Pares
    for (int i = 0; i < 36; i++){

        int azar = rand() % 36;               // Generación de número aleatorio entre 0 y 36
        std::string temp = pairs[i];          // Variable Temporal para Intercambio
        pairs[i] = pairs[azar];               // Intercambio de Valores
        pairs[azar] = temp;                   // Asignación del Valor Temporal
    
    }
}




/**
 * @brief Función para Crear Tablero.
 * @param visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cartas Visibles.
 * @param board (std::vector<std::vector<std::string>>): La Matriz del Tablero con las Cartas.
 * @param pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenan los Pares.
 */
void createBoard(
    
    std::vector<std::vector<std::string>>& visibleCards, 
    std::vector<std::vector<std::string>>& board, 
    const std::vector<std::string>& pairs

){
    
    /*
       - Función: Crear Tablero
       - Argumentos:
            - visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cartas Visibles.
            - board (std::vector<std::vector<std::string>>): La Matriz del Tablero con las Cartas.
            - pairs (std::vector<std::string>): El Vector de Cadenas donde se almacenan los Pares.
       - Retorno: Ninguno
       - Objetivo: Crear el Tablero del Juego
    */

    /// Creación del Tablero y Ocultación de Cartas
    int k = 0;                                            // Índice para el Arreglo de Pares
    for (int i = 0; i < 6; i++){                          // Filas
  
        for (int j = 0; j < 6; j++){                      // Columnas

            board[i][j] = pairs[k];                       // Asignar Par al Tablero
            visibleCards[i][j] = "X";                     // Ocultar Carta
            k++;                                          // Incrementar Índice de Pares
        }
    }
}




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
 * @param board (std::vector<std::vector<std::string>>): La Matriz del Tablero con las Cartas.
 * @param visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cartas Visibles.
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
    const std::vector<std::string>& playerNames, 
    const std::vector<std::vector<std::string>>& board,
    std::vector<std::vector<std::string>>& visibleCards 
 
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
            - board (std::vector<std::vector<std::string>>): La Matriz del Tablero con las Cartas.
            - visibleCards (std::vector<std::vector<std::string>>): La Matriz de Cartas Visibles.
       - Retorno: Ninguno
       - Objetivo: Crear el Tablero del Juego
    */

    /// Bucle Principal del Juego
    auto start_time = std::chrono::steady_clock::now();                                       // Empezamos un cronometro
    bool validCard = false;                                                                   // Bandera de Carta Válida
    while (player1Points + player2Points < 18){                                               // Mientras no se acabe el Juego           
        
        do{                                                                                   // Repetir hasta que la Carta sea Válida   
        
            validCard = false;                                                                // Reiniciar Bandera de Carta Válida
            clearScreen();                                                                    // Limpiar Pantalla
            printGame(player1Points, player2Points, turn, visibleCards, playerNames);         // Actualizar Tiempo Transcurrido
            while (true){                                                                     // Mientras

                rowCard1(card1Row, false);                                                    // Leer Fila de la Primera Carta
                if (std::cin.fail()){                                                         // Si se ingresa un Tipo Incorrecto

                    std::cin.clear();                                                         // Limpiar Estado de Fallo
                    std::cin.ignore(MAX_LIMIT, '\n');                                         // Ignorar Entrada Inválida
                    printError(typeError);                                                    // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    continue;                                                                 // Continuar Bucle

                }
                if (card1Row < 0 || card1Row > 5){                                            // Si el Valor está Fuera de Rango

                    printError(rangeError);                                                   // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    continue;                                                                 // Continuar Bucle

                }
                break;                                                                        // Salir del Bucle si la Entrada es Válida

            }
            clearScreen();                                                                    // Limpiar Pantalla
            printGame(player1Points, player2Points, turn, visibleCards, playerNames);         // Reimprimir Juego
            rowCard1(card1Row, true);                                                         // Imprimir Fila de la Primera Carta
            while (true){                                                                     // Mientras

            columnCard1(card1Column);                                                         // Leer Columna de la Primera Carta
                if (std::cin.fail()){ 

                    std::cin.clear();                                                         // Limpiar Estado de Fallo
                    std::cin.ignore(MAX_LIMIT, '\n');                                         // Ignorar Entrada Inválida
                    printError(typeError);                                                    // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    rowCard1(card1Row, true);                                                 // Imprimir Fila de la Primera Carta
                    continue;                                                                 // Continuar Bucle

                }
                if (card1Column < 0 || card1Column > 5){

                    printError(rangeError);                                                   // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    rowCard1(card1Row, true);                                                 // Imprimir Fila de la Primera Carta
                    continue;                                                                 // Continuar Bucle
                }
                if (visibleCards[card1Row][card1Column] != "X"){

                    errorCounter++;                                                           // Incrementar Contador de Errores
                    clearScreen();                                                            // Limpiar Pantalla
                    cardDiscoveredError(false);                                               // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                           // Esperar 2 Segundos
                    break;                                                                    // Continuar Bucle

                }
                validCard = true;                                                             // Marcar Carta como Válida
                break;                                                                        // Salir del Bucle si la Entrada es Válida

            }

        }while(!validCard);                                                                   // Repetir hasta que la Carta sea Válida
        visibleCards[card1Row][card1Column] = board[card1Row][card1Column];                   // Revelar Primera Carta
        do{                                                                                   // Repetir hasta que la Carta sea Válida   
        
            validCard = false;                                                                // Reiniciar Bandera de Carta Válida
            clearScreen();                                                                    // Limpiar Pantalla
            printGame(player1Points,player2Points,turn,visibleCards,playerNames);             // Reimprimir Juego
            while (true){

                rowCard2(card2Row, false);                                                    // Leer Fila de la Segunda Carta
                if (std::cin.fail()){                                                         // Si se ingresa un Tipo Incorrecto
                    
                    std::cin.clear();                                                         // Limpiar Estado de Fallo
                    std::cin.ignore(MAX_LIMIT, '\n');                                         // Ignorar Entrada Inválida
                    printError(typeError);                                                    // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    continue;                                                                 // Continuar Bucle

                }
                if (card2Row < 0 || card2Row > 5) {                                           // Si el Valor está Fuera de Rango

                    printError(rangeError);                                                   // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    continue;                                                                 // Continuar Bucle

                }
                break;                                                                        // Salir del Bucle si la Entrada es Válida

            }
            while(true){                                                                      // Mientras

                columnCard2(card2Column);                                                     // Leer Columna de la Segunda Carta
                if (std::cin.fail()){                                                         // Si se ingresa un Tipo Incorrecto

                    std::cin.clear();                                                         // Limpiar Estado de Fallo
                    std::cin.ignore(MAX_LIMIT, '\n');                                         // Ignorar Entrada Inválida
                    printError(typeError);                                                    // Imprimir Error de Tipo
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    rowCard2(card2Row, true);                                                 // Imprimir Fila de la Segunda Carta
                    continue;                                                                 // Continuar Bucle
                
                }
                if (card2Column < 0 || card2Column > 5){

                    printError(rangeError);                                                   // Imprimir Error de Rango
                    printGame(player1Points, player2Points, turn, visibleCards, playerNames); // Reimprimir Juego
                    rowCard2(card2Row, true);                                                 // Imprimir Fila de la Segunda Carta
                    continue;                                                                 // Continuar Bucle

                }
                if (card2Row == card1Row && card2Column == card1Column){                      // Si es la Misma Carta
    
                    errorCounter++;                                                           // Incrementar Contador de Errores
                    clearScreen();                                                            // Limpiar Pantalla
                    cardDiscoveredError(true);                                                // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                           // Esperar 2 Segundos
                    break;                                                                    // Salimos del Bucle
                
                }
                if (visibleCards[card2Row][card2Column] != "X"){                              // Si la Carta ya fue Descubierta

                    errorCounter++;                                                           // Incrementar Contador de Errores
                    clearScreen();                                                            // Limpiar Pantalla
                    cardDiscoveredError(false);                                               // Imprimir Error de Carta ya Descubierta
                    waitSeconds(2);                                                           // Esperar 2 Segundos
                    break;                                                                    // Salimos del Bucle
                
                }
                validCard = true;                                                             // Marcamos como Selección Válida de Cartas
                break;                                                                        // Salir del Bucle si la Entrada es Válida
            
            }
        
        }while(!validCard);                                                                   // Hasta que Selección de Cartas sea Válida
        visibleCards[card2Row][card2Column] = board[card2Row][card2Column];                   // Revelar Segunda Carta
        movesCounter++;                                                                       // Incrementar Contador de Movimientos
        clearScreen();                                                                        // Limpiar Pantalla
        printGame(player1Points, player2Points, turn, visibleCards, playerNames);             // Reimprimir Juego
        if (board[card1Row][card1Column] == board[card2Row][card2Column]){                    // Si las Cartas son Iguales
        
            cardMessage(true);                                                                // Imprimir Mensaje de Pareja Encontrada
            waitSeconds(2);                                                                   // Esperar 2 Segundos
            if (turn == 1) player1Points++;                                                   // Asignar Punto al Jugador Correspondiente
            else player2Points++;                                                             // Asignar Punto al Jugador Correspondiente
    
        }
        else{                                                                                 // Si las Cartas No Son Iguales
            
            errorCounter++;
            cardMessage(false);                                                               // Imprimir Mensaje de No Son Iguales
            waitSeconds(2);                                                                   // Esperamos 2 Segundos
            visibleCards[card1Row][card1Column] = "X";                                        // Tapamos la Primera Carta
            visibleCards[card2Row][card2Column] = "X";                                        // Tapamos la Segunda Carta
            turn == 1 ? turn = 2 : turn = 1;                                                  // Alternamos el Turno
            waitSeconds(2);                                                                   // Esperamos 2 Segundos

        }
    
    }
    auto end_time = std::chrono::steady_clock::now();                                         // Pausamos el Cronómetro
    auto game_duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);       // Tiempo en Juego en Segundos
    int totalSeconds = game_duration.count();                                                 // Asignar Minutos
    minutes = totalSeconds / 60;                                                              // Convertir a Minutos
    seconds = totalSeconds % 60;                                                              // Convertir a Segundos

}




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
void printFinalResults(
    
    int minutes, 
    int seconds,
    int movesCounter, 
    int errorCounter, 
    int player1Points, 
    int player2Points, 
    const std::vector<std::string>& playerNames

){

    /*
       - Función: Imprimir Resultados Finales
       - Argumentos:
            - minutes (int): Minutos Transcurridos.
            - seconds (int): Segundos Transcurridos.
            - movesCounter (int): Contador de Movimientos.
            - errorCounter (int): Contador de Errores.
            - player1Points (int): Puntos del Jugador 1.
            - player2Points (int): Puntos del Jugador 2.
            - playerNames (std::vector<std::string>): Nombres de los Jugadores.
       - Retorno: Ninguno
       - Objetivo: Imprimir los Resultados Finales del Juego
    */

    /// Validación de Argumentos Enteros
    validatePositiveInt(minutes);                      // Minutos
    validatePositiveInt(seconds);                      // Segundos
    validatePositiveInt(movesCounter);                 // Contador de Movimientos
    validatePositiveInt(errorCounter);                 // Contador de Errores
    validatePositiveInt(player1Points);                // Puntos del Jugador 1
    validatePositiveInt(player2Points);                // Puntos del Jugador 2

    /// Limpiar Pantalla e Imprimir Resultados Finales
    clearScreen();
    
    /// Imprimir Resultados Finales
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                ¡Juego terminado!                               * \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *                          " << playerNames[0] << " : " << player1Points << " puntos                  \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *                          " << playerNames[1] << " : " << player2Points << " puntos                  \n";
    std::cout << "                      *                                                                                * \n";
    std::cout << "                      *                          Movimientos totales : " << movesCounter<< "                              *\n";
    std::cout << "                      *                          Errores             : " << errorCounter << "                              *\n";
    std::cout << "                      *                          Tiempo consumido    : " << minutes << " min, con " << seconds << " seg     \n";
    std::cout << "                      ********************************************************************************** \n";
    std::cout << "                                                         ";
    
    // Esperar a que el Usuario presione una Tecla para Continuar
    pauseExecution();

}




/**
 * @brief Función de Imprimir al Gandor.
 * @param player1Points (int): Puntos del Jugador 1.
 * @param player2Points (int): Puntos del Jugador 2.
 * @param playerNames (std::vector<std::string>): Nombres de los Jugadores.
 * @throw std::out_of_range (int): Si algún Entero es Negativo.
 */
void printWinner(int player1Points, int player2Points, const std::vector<std::string>& playerNames)
{
    

    /// Validar Argumentos Enteros
    validatePositiveInt(player1Points);                // Puntos del Jugador 1
    validatePositiveInt(player2Points);                // Puntos del Jugador 2
 
    /// Limpiar Pantalla
    clearScreen();

    /// Impresión de Ganador
    if (player1Points > player2Points || player1Points < player2Points){
        
        win();
        int winner;
        player1Points > player2Points ? winner = 0 : winner = 1;
        std::cout << "                      *                                 " << playerNames[winner] << "  Gana! \n";
        std::cout << "                      ********************************************************************************** \n";
    
    }
    else{

        tie();
        std::cout << "                      *                                     Empate!                                    *\n";
        std::cout << "                      ********************************************************************************** \n";
    
    }
    std::cout << "\n";

}



/**
 * @brief Función Principal.
 * @return (int) Código de Salida
 */
int main() {

    /// Configuraciones Iniciales
    clearScreen();                     // Limpiar Pantalla
    setConsoleColor(4);                // Color de Fuente: Rojo Fuerte

    /// Declaración de Variables Enteras
    int card1Row = 0, card1Column = 0, card2Row = 0, card2Column = 0;                     // Coordenadas de las Cartas
    int turn = 1, player1Points = 0, player2Points = 0;                                   // Turno y Puntos de los Jugadores
    int movesCounter = 0, errorCounter = 0;                                               // Contadores de Movimientos y Errores
    int minutes = 0, seconds = 0;                                                         // Tiempo Transcurrido

    /// Declaración de Vectores y Matrices
    std::vector<std::string> letters(18);                                                 // 18 Letras Unicas
    std::vector<std::string> pairs(36);                                                   // 36 Cartas (18 Pares)
    std::vector<std::string> playerNames(2);                                              // 2 Jugadores
    std::vector<std::vector<std::string>> visibleCards(6, std::vector<std::string>(6));   // Tablero Visible 6x6
    std::vector<std::vector<std::string>> board(6, std::vector<std::string>(6));          // Tablero Real 6x6

    /// Inicialización de las Letras para los Pares (18 Pares)
    letters[0] = "A";
    letters[1] = "B";
    letters[2] = "C";
    letters[3] = "D";
    letters[4] = "E";
    letters[5] = "F";
    letters[6] = "G";
    letters[7] = "H";
    letters[8] = "I";
    letters[9] = "J";
    letters[10] = "K";
    letters[11] = "L";
    letters[12] = "M";
    letters[13] = "N";
    letters[14] = "O";
    letters[15] = "P";
    letters[16] = "Q";
    letters[17] = "R";

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