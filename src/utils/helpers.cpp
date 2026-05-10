// =====================================================================================================================================

// DOCUMENTACIÓN:

// Helpers

// Ultima Modificacion: 10/05/26
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas e Internas
#include <cstdlib>                                                                                           // Librería Estándar de C
#include "../utils/helpers.hpp"                                                                              // Funciones Auxiliares
#include "../utils/constants.hpp"                                                                            // Constantes

// =====================================================================================================================================
// -------------------------------------------------------------- Alías ----------------------------------------------------------------

/// Alías para Optimizar el Código
using std::cout;                                                                                             // Alías para cout
using std::cin;                                                                                              // Alías para cin

// =====================================================================================================================================
// -------------------------------------------------------------- Sistema Operativo ----------------------------------------------

/// Detectar el Sistema Operativo
#ifdef _WIN32                                                                                                // Windows
    #include <windows.h>                                                                                     // Librería de Windows
    #define IS_WINDOWS true                                                                                  // Definir Constante para Windows
#else                                                                                                        // POSIX (Linux, macOS)
    #include <unistd.h>                                                                                      // Librería de POSIX
    #include <term.h>                                                                                        // Librería de Terminal POSIX
    #define IS_WINDOWS false                                                                                 // Definir Constante para POSIX
#endif                                                                                                       // Fin de Detección del OS

// =====================================================================================================================================
// -------------------------------------------------------------- Helpers ----------------------------------------------------------------

void clearScreen(){

    /*
       - Función: Limpiar Pantalla
       - Argumentos: Ninguno 
       - Retorno: Ninguno
       - Objetivo: Limpiar la Pantalla de la Consola
    */

    /// Limpiar Pantalla
    #ifdef _WIN32                                                                                            // Windows
        system("cls");                                                                                       // Limpiar Pantalla en Windows
    #else                                                                                                    // POSIX (Linux, macOS)
        if (system("clear") != 0) cout << "\033[2J\033[1;1H";                                                // Limpiar Pantalla en POSIX
    #endif                                                                                                   // Fin de la Detección del OS

}

void printError(void(*errorFunction)()){

    /*
       - Función: Imprimir Error
       - Argumentos:
            - errorFunction (void(*)()): Función de Error a Imprimir 
       - Retorno: Ninguno
       - Objetivo: Imprimir un Mensaje de Error utilizando una Función de Error
    */

    /// Impresión de Mensaje de Error
    clearScreen();                                                                                 // Limpiar Pantalla
    errorFunction();                                                                               // Llamar a la Función de Error
    waitSeconds(2);                                                                                // Esperar 2 Segundos
    clearScreen();                                                                                 // Limpiar Pantalla

}

void setConsoleColor(int colorCode){
    
    /*
       - Función: Establecer Color de Texto
       - Argumentos: 
            - colorCode (int): Código de Color
       - Retorno: Ninguno
       - Objetivo: Establecer el Color de Texto en la Consola
    */
    
    /// Establecer Color de Texto
    #ifdef _WIN32                                                                                            // Windows
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);                                 // Establecer Color en Windows
    #else                                                                                                    // POSIX (Linux, macOS)
        if (colorCode >= 0 && colorCode < 16) cout << ANSI_COLORS[colorCode];                                // Establecer Color si el Código es Válido
    #endif

}

void pauseExecution() {

    
    /*
       - Función: Pausar Ejecución
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Pausar la Ejecución hasta que el Usuario presione Enter
    */

    /// Pausar Ejecución
    #ifdef _WIN32                                                                                            // Windows
        system("pause");                                                                                     // Comando para Pausar en Windows
    #else                                                                                                    // POSIX (Linux, macOS)
        cout << "Presiona Enter para continuar...";                                                          // Mensaje para el Usuario
        cin.ignore(MAX_LIMIT, '\n');                                                                         // Esperar Entrada del Usuario
        cin.get();                                                                                           // Esperar Enter
    #endif

}

void playBeep(){

    /*
       - Función: Emitir Sonido
       - Argumentos: Ninguno
       - Retorno: Ninguno
       - Objetivo: Emitir un Sonido (Beep) en la Consola
    */

    /// Emitir Sonido
    #ifdef _WIN32                                                                                            // Windows
        Beep(750, 300);                                                                                      // Frecuencia de 750 Hz durante 300 ms
    #else                                                                                                    // POSIX (Linux, macOS)
        cout << '\a' << std::flush;                                                                          // Emitir sonido de alerta
    #endif

}

// =====================================================================================================================================