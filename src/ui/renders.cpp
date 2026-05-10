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
#include "../ui/renders.hpp"                                                                                 // Funciones de Renderizado

// =====================================================================================================================================
// -------------------------------------------------------------- Alías ----------------------------------------------------------------

/// Alías para Optimizar Código
using std::string;                                                                                            // Cadenas de Texto
using std::cout;                                                                                              // Salida Estándar
using std::cin;                                                                                               // Entrada Estándar

// =====================================================================================================================================
// -------------------------------------------------------------- Renders ----------------------------------------------------------------

void titleCover(){
    
    /*
       - Función: Portada del Juego
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Memorama en Arte ASCII
    */

    // Impresión de Portada del Juego
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *          **   **  *****  **   **  *****  *****   ***   **   **  ***            * \n";
    cout << "                      *          * * * *  *      * * * *  *   *  *   *  *   *  * * * * *   *           * \n";
    cout << "                      *          *  *  *  ****   *  *  *  *   *  ****   *****  *  *  * *****           * \n";
    cout << "                      *          *     *  *      *     *  *   *  *   *  *   *  *     * *   *           * \n";
    cout << "                      *          *     *  *****  *     *  *****  *   *  *   *  *     * *   *           * \n";
    cout << "                      *                                                                                * \n";
    cout << "                      ********************************************************************************** \n";

}

void rangeError(){

    /*
       - Función: Error de Rango
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario ingresa un Valor Fuera de Rango
    */

    // Impresión de Mensaje de Error
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                        ERROR                                   * \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                           Fuera de Rango (Numeros de 0-5)                      * \n";
    cout << "                      ********************************************************************************** \n";

}

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
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *       *****  *****  *      *   ****  *  *****    ***   ****   *****  ****      * \n";
    cout << "                      *       *      *      *      *  *      *  *    *  *   *  *   *  *     *          * \n";
    cout << "                      *       ****   ****   *      *  *      *  *    *  *****  *   *  ****   ****      * \n";
    cout << "                      *       *      *      *      *  *      *  *    *  *   *  *   *  *          *     * \n";
    cout << "                      *       *      *****  *****  *   ****  *  *****   *   *  ****   *****  ****      * \n";
    cout << "                      *                                                                                * \n";
    cout << "                      ********************************************************************************** \n";

}

void tie(){

    /*
       - Función: Mensaje de Empate
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Empate
    */

    // Mensaje de Empate
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *                   *****  **   **  ****    ***   *******  *****                 * \n";
    cout << "                      *                   *      * * * *  *   *  *   *     *     *                     * \n";
    cout << "                      *                   ****   *  *  *  ****   *****     *     ****                  * \n";
    cout << "                      *                   *      *     *  *      *   *     *     *                     * \n";
    cout << "                      *                   *****  *     *  *      *   *     *     *****                 * \n";
    cout << "                      *                                                                                * \n";
    cout << "                      ********************************************************************************** \n";

}

void cardDiscoveredError(bool sameCard){
    
    /*
       - Función: Error de Carta ya Descubierta
       - Argumentos:
            - sameCard (bool): Indica si la carta seleccionada es la misma que la primera
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario selecciona una Carta ya Descubierta
    */
    
    /// Impresión de Mensaje de Error
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                     ERROR                                      * \n";
    cout << "                      ********************************************************************************** \n";
    if (sameCard) cout << "                      *                   Ya elegiste esa Carta como Primera. Escoge otra.             * \n";
    else cout << "                      *                    Esa Carta ya fue descubierta. Escoge otra.                  * \n";
    cout << "                      ********************************************************************************** \n";

}

void printGeneralData(int player1Points, int player2Points, int turn, const stringVector& playersNames){

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
    validatePositiveInt(player1Points);                                                                      // Puntos del Jugador 1
    validatePositiveInt(player2Points);                                                                      // Puntos del Jugador 2
    validatePositiveInt(turn);                                                                               // Turno del Jugador Actual

    /// Impresión de Datos Generales
    cout << "                      *            " << playersNames[0] << " : " << player1Points << " puntos           |            " << playersNames[1] << " : " << player2Points << " puntos \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                               Turno del jugador: " << playersNames[turn - 1] << "\n";
    cout << "                      ********************************************************************************** \n";

}

void typeError(){

    /*
       - Función: Error de Tipo
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Error cuando el Usuario ingresa un Valor de Tipo Inválido
    */

    // Impresión de Mensaje de Error
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                     ERROR                                      * \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                      *               Entrada Invalida. Por favor ingresa un Numero Entero             * \n";
    cout << "                      ********************************************************************************** \n";

}

void emptyNameError(const stringVector& playersNames, int playerNum){

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
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                     ERROR                                      * \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                   El Nombre no puede estar Vacio, Jugador " << playerNum + 1 << "                    * \n";
    cout << "                      ********************************************************************************** \n";
 
    /// Configuraciones Finales
    waitSeconds(2);                 // Esperar 2 Segundos
    clearScreen();                  // Limpiar Pantalla

    if (playerNum == 1){

        cout << "                      ********************************************************************************** \n";
        cout << "                      *                   Escribe el Nombre del Jugador 1: " << playersNames[playerNum - 1] << " \n";
        cout << "                      ********************************************************************************** \n";

    }

}

void inputNames(stringVector& playersNames){
 
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
            if (i == 0) cout << "                      ********************************************************************************** \n";
            cout << "                      *                   Escribe el Nombre del Jugador " << i+1 << ": ";
            std::getline(cin, playersNames[i]);

            /// Si solo hay Espacios, marcar como Vacío
            if (playersNames[i].find_first_not_of(" \t\n\r") == string::npos) playersNames[i] = "";                 
                    
            /// Imprimir Error de Nombre Vacío si el Nombre de algún Jugador está Vacío 
            if (playersNames[i].empty()) emptyNameError(playersNames, i);               
            
        } while (playersNames[i].empty());                                                // Repetir hasta obtener un nombre válido
        
        cout << "                      ********************************************************************************** \n";
    
    }
    
    /// Configuraciones Finales
    waitSeconds(2);              // Esperamos 2 Segundos
    clearScreen();               // Limpiar Pantalla

}

void loading(){

    /*
       - Función: Animación de Carga
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Imprimir Animación de Carga
    */

    /// Animación de Carga
    for (int i = 0; i < 3; i++){                                                                             // Repetir 3 Veces

        cout << "Cargando";                                                                                  // Imprimir Cargando
        for (int j = 0; j < 5; j++){                                                                         // Repetir 5 Veces
            
            cout << ".";                                                                                     // Imprimir Punto
            waitMilliseconds(500);                                                                           // Esperar 500 MiliSegundos
        }
        clearScreen();                                                                                       // Limpiar Pantalla
    }

}

void printBoard(const charMatrix& visibleCards){

    /*
       - Función: Imprimir el Tablero
       - Argumentos:
            - visibleCards (std::vector<std::vector<char>>): Matriz de Cartas Visibles 
       - Retorno: Ninguno
       - Objetivo: Imprimir el Tablero con las Cartas Visibles
    */

    /// Impresión de Cartas Visibles del Tablero
    for (int i = 0; i < 6; i++){                                                                             // Recorrido de 5 Iteraciones

        cout << "                      *                                   " << i << " ";                    // Imprimimos el Número de Fila
        for (int j = 0; j < 6; j++){                                                                         // Recorrido de 5 Cartas

            if (j == 5) cout << visibleCards[i][j] << "                                * \n";                // Si Ultima Carta: Fin de Fila
            else cout << visibleCards[i][j] << " ";                                                          // Solo Imprimir la Carta
        
        }
    }

}

void rowCard1(int& rowCard1, bool onlyPrint){

    /*
       - Función: Leer 1era Carta de Fila
       - Argumentos:
            - rowCard1 (int): Primera Carta de Fila 
       - Retorno: Ninguno
       - Objetivo: Leer 1era Carta de Fila del Usuario
    */

    /// Validación de Argumento
    validatePositiveInt(rowCard1);                                                  
    
    ///Impresión y Lectura de Primera Carta de Fila
    cout << "                      ********************************************************************************** \n";
    if (onlyPrint) cout << "                      *                  Elige la fila de la primera carta (0-5): " << rowCard1 << "                    *   \n";
    else{
    
        cout << "                      *                  Elige la fila de la primera carta (0-5): ";
        cin >> rowCard1;
    }

}

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
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                  Elige la columna de la primera carta (0-5): ";
    cin >> columnCard1;

}

void printGame(int& player1Points, int& player2Points, int& turn, const charMatrix& visibleCards, const stringVector& playersNames){
    
    /*
       - Función: Impresión de Elementos Visuales del Juego
       - Argumentos:
            - player1Points (int): Puntos del Jugador 1
            - player2Points (int): Puntos del Jugador 2
            - turn (int): Número de Turno
            - visibleCards (std::vector<std::vector<char>>): La Matriz de Cadenas con las Cartas Visibles.
            - playersName (std::vector<std::string>): El Vector de Cadenas donde que Almacenan los Nombres de los Jugadores.
       - Retorno: Ninguno
       - Objetivo: Impresión de Elementos Visuales del Juego para la visualización del Usuario
    */

    /// Imprimir Portada del Juego
    titleCover();

    /// Imprimir la Información General del Juego
    printGeneralData(player1Points, player2Points, turn, playersNames);

    /// Mostrar Tablero Visible con Coordenadas
    cout << "                      *                                                                                * \n";
    cout << "                      *                                     0 1 2 3 4 5                                * \n";
    printBoard(visibleCards);
    cout << "                      *                                                                                * \n";

}

void cardMessage(bool aMatch){
   
    /*
       - Función: Mensaje de Carta
       - Argumentos:
            - aMatch (bool): Indica si las Cartas Hicieron Pareja
       - Retorno: Ninguno
       - Objetivo: Imprimir Mensaje de Carta (Pareja Encontrada o No Son Iguales)
    */

    
    /// Impresión de Mensaje de Carta
    cout << "                      ********************************************************************************** \n";
    if (aMatch){
    
        cout << "                      *                                 ¡Pareja encontrada!                            * \n";
        playBeep();

    }
    else cout << "                      *                                   No son iguales.                              *\n";
    cout << "                      ********************************************************************************** \n";

}

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
    cout << "                      ********************************************************************************** \n";
    if (onlyPrint) cout << "                      *                  Elige la fila de la segunda carta (0-5): " << rowCard2 << "                    *   \n";
    else{
    
        cout << "                      *                  Elige la fila de la segunda carta (0-5): ";
        cin >> rowCard2;
    
    }
}

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
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                  Elige la columna de la segunda carta (0-5): ";
    cin >> columnCard2;

}

void printFinalResults(int minutes, int seconds,int movesCounter, int errorCounter, int player1Points, int player2Points, const stringVector& playerNames){

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
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                ¡Juego terminado!                               * \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *                          " << playerNames[0] << " : " << player1Points << " puntos                  \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *                          " << playerNames[1] << " : " << player2Points << " puntos                  \n";
    cout << "                      *                                                                                * \n";
    cout << "                      *                          Movimientos totales : " << movesCounter<< "                              *\n";
    cout << "                      *                          Errores             : " << errorCounter << "                              *\n";
    cout << "                      *                          Tiempo consumido    : " << minutes << " min, con " << seconds << " seg     \n";
    cout << "                      ********************************************************************************** \n";
    cout << "                                                         ";
    
    // Esperar a que el Usuario presione una Tecla para Continuar
    pauseExecution();

}

void printWinner(int player1Points, int player2Points, const stringVector& playerNames)
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
        cout << "                      *                                 " << playerNames[winner] << "  Gana! \n";
        cout << "                      ********************************************************************************** \n";
    
    }
    else{

        tie();
        cout << "                      *                                     Empate!                                    *\n";
        cout << "                      ********************************************************************************** \n";
    
    }
    cout << "\n";

    // Esperar a que el Usuario presione una Tecla para Continuar
    pauseExecution();

}

// =====================================================================================================================================