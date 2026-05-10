// =====================================================================================================================================

// DOCUMENTACIÓN:

// Declaración de Funciones Auxiliares (Helpers)

// Ultima Modificacion: 09/05/26
// Fecha Original de Realización: 7/11/25
// Autor: Magallanes López Carlos Gabriel
// Correo: cgmagallanes23@gmail.com

// =====================================================================================================================================
// ------------------------------------------------------------ Librerías --------------------------------------------------------------

/// Dependencias Externas
#pragma once                                                                                                 // Prevenir Inclusión Múltiple
#include <iostream>                                                                                          // Librería de Entrada y Salida
#include <chrono>                                                                                            // Tiempo y de Duración
#include <thread>                                                                                            // Hilos de Ejecución

// =====================================================================================================================================
// -------------------------------------------------------------- Alías ----------------------------------------------------------------

/// Alías para Optimizar Código
namespace chrono = std::chrono;                                                                              // Chrono
namespace this_thread = std::this_thread;                                                                    // Thread

// =====================================================================================================================================
// ------------------------------------------------------------ Helpers --------------------------------------------------------------
 
/**
 * @brief Función que Espera una Cantidad de Segundos Específica.
 * @param seconds (int): La Cantidad de Segundos a Esperar.
 */
inline void waitSeconds(int seconds){this_thread::sleep_for(chrono::seconds(seconds));}

/**
 * @brief Función que Espera una Cantidad de Milisegundos Específica.
 * @param milliseconds (int): La Cantidad de Milisegundos a Esperar.
 */
inline void waitMilliseconds(int milliseconds){this_thread::sleep_for(chrono::milliseconds(milliseconds));} 

/**
 * @brief Función que Imprime un Mensaje de Error utilizando una Función de Error.
 * @param errorFunction (void(*)()): La Función de Error a Imprimir.
 */
void printError(void(*errorFunction)());

/**
 * @brief Función que Verifica que un Entero sea Positivo
 * @param intValue (int): El Entero a Validar.
 * @throw std::out_of_range Si el Entero no es Positivo.
 */
inline void validatePositiveInt(int intValue) {

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

/**
 * @brief Función para Limpiar la Pantalla (Multiplataforma)
 */
void clearScreen();

/**
 * @brief Función para Establecer Color de Texto (Multiplataforma)
 * @param colorCode Código de color (Windows: 0-15, POSIX: códigos ANSI)
 */
void setConsoleColor(int colorCode);

/**
 * @brief Emitir un Sonido (Beep)
 */
void playBeep();
  
/**
 * @brief Pausar la Ejecución 
 */
void pauseExecution();

// =====================================================================================================================================