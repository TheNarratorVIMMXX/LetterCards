# 🃏 Memorama de Letras - Juego Clásico de Parejas

Un juego de memoria por consola desarrollado en C++ con soporte multiplataforma. Este clásico juego para dos jugadores desafía a los participantes a encontrar parejas de letras en una cuadrícula de 6x6, registrando tiempo, movimientos y errores.

## 👨‍🎓 Información del Desarrollador

- **Desarrollador:** Magallanes López Carlos Gabriel
- **Correo electrónico:** cgmagallanes23@gmail.com
- **Desarrollo:** 7 de junio de 2025

## 🎮 Descripción del Juego

Memorama de Letras es una implementación en terminal del clásico juego de memoria Memorama. Dos jugadores se turnan para voltear cartas y encontrar parejas de letras. El juego cuenta con una cuadrícula de 6x6 con 18 parejas únicas de letras (36 cartas en total), con seguimiento de movimientos, conteo de errores y cronómetro de partida.

### Características Principales
- **Modo Dos Jugadores**: Juego competitivo para dos personas
- **Cuadrícula 6x6**: 36 cartas con 18 parejas (A-R)
- **Puntuación en Tiempo Real**: Seguimiento de puntos, movimientos y errores
- **Multiplataforma**: Funciona en Windows, Linux y macOS
- **Consola con Color**: Experiencia visual mejorada con texto en color
- **Estadísticas de Juego**: Cronómetro, contador de movimientos y análisis de errores
- **Validación de Entrada**: Manejo robusto de errores en la entrada del usuario

## 🎯 Cómo Jugar

### Configuración del Juego
1. **Inicia el juego** - Haz doble clic en el archivo
2. **Ingresa los nombres** - Ambos jugadores escriben su nombre
3. **Espera la carga** - Breve animación de carga
4. **Comienza a jugar** - Las cartas se mezclan y se ocultan como 'X'

### Reglas del Juego
- **Turnos**: Los jugadores se turnan eligiendo dos cartas mediante coordenadas de fila y columna
- **Pareja encontrada**: El jugador anota un punto y continúa su turno
- **Sin pareja**: Las cartas se voltean de nuevo y el turno pasa al otro jugador
- **Ganador**: El jugador con más parejas al encontrar las 18 gana
- **Datos Extra**: El juego registra el tiempo total, movimientos y errores

### Controles del Juego
| Entrada | Descripción |
|---------|-------------|
| **Fila (0-5)** | Ingresa el número de fila de la carta |
| **Columna (0-5)** | Ingresa el número de columna de la carta |
| **Solo Números** | La validación asegura el tipo de dato correcto |

### Proceso de Selección de Cartas
1. **Primera Carta**:
   - Ingresa la coordenada de fila (0-5)
   - Ingresa la coordenada de columna (0-5)
   - La carta se revela en el tablero
2. **Segunda Carta**:
   - Ingresa la coordenada de fila (0-5)
   - Ingresa la coordenada de columna (0-5)
   - La carta se revela para comparación
3. **Lógica de Coincidencia**:
   - Si las cartas coinciden → Se otorga un punto, las cartas permanecen visibles
   - Si no coinciden → Las cartas vuelven a 'X', el turno cambia

## 📊 Diseño del Tablero
```
Coordenadas de la Cuadrícula:
        0 1 2 3 4 5
    0   X X X X X X
    1   X X X X X X
    2   X X X X X X
    3   X X X X X X
    4   X X X X X X
    5   X X X X X X

Después de revelar algunas cartas:
        0 1 2 3 4 5
    0   A X B X C X
    1   X D X D X E
    2   F X X X A X
    3   X X G X X H
    4   X B X X X X
    5   X X X X X X
```

## 🏆 Sistema de Puntuación

### Asignación de Puntos
- **+1 Punto**: Por cada pareja encontrada
- **Sin Penalización**: Los intentos fallidos no restan puntos
- **Continuación del Turno**: Encontrar una pareja mantiene tu turno activo

### Estadísticas Registradas
- **Puntuaciones Individuales**: Total de parejas encontradas por cada jugador
- **Movimientos Totales**: Número de selecciones de pares de cartas
- **Errores**: Intentos fallidos + selecciones inválidas
- **Duración de la Partida**: Tiempo total en minutos y segundos
- **Declaración del Ganador**: Anuncio del puntaje más alto o empate

### Pantalla de Resultados Finales
```
******************************************************************
*                    ¡Juego Terminado!                           *
******************************************************************
*         Jugador 1: 10 puntos                                   *
*         Jugador 2: 8 puntos                                    *
*         Movimientos Totales: 25                                *
*         Errores: 7                                             *
*         Tiempo: 5 min, 32 seg                                  *
******************************************************************
```

## 💻 Implementación Técnica

### Arquitectura Principal
```cpp
Componentes Principales:
1. Sistema de Cuadrícula de Cartas (matriz 6x6)
2. Motor de Validación de Entrada
3. Sistema de Gestión de Turnos
4. Rastreador de Puntuación y Estadísticas
5. Control de Consola Multiplataforma
6. Cronómetro y Temporizador
7. Algoritmo de Mezcla Aleatoria
```

### Soporte Multiplataforma

#### Sistemas Operativos Compatibles
- **Windows**: API de consola nativa (Windows.h)
- **Linux**: Control de terminal POSIX
- **macOS**: Control de terminal POSIX

#### Funcionalidades por Plataforma
```cpp
// Limpiar pantalla
#ifdef _WIN32
    system("cls");          // Windows
#else
    system("clear");        // POSIX
#endif

// Colores de consola
Windows: SetConsoleTextAttribute()
POSIX:   Códigos de escape ANSI (\033[codigo])

// Retroalimentación de audio
Windows: Beep(frecuencia, duracion)
POSIX:   Carácter de campana (\a)
```

### Estructuras de Datos
```cpp
// Almacenamiento de pares de letras
std::vector<std::string> letters(18);    // Letras únicas A-R
std::vector<std::string> pairs(36);      // 18 pares duplicados

// Matrices del tablero de juego
std::vector<std::vector<std::string>> board(6x6);         // Cartas reales
std::vector<std::vector<std::string>> visibleCards(6x6);  // Vista del jugador

// Información de jugadores
std::vector<std::string> playerNames(2);  // Nombres de los dos jugadores
```

### Algoritmos Clave

#### Mezcla de Cartas
```cpp
Algoritmo de Mezcla Fisher-Yates:
- Generar 36 posiciones aleatorias
- Intercambiar cartas para aleatorizar su posición
- Garantiza una distribución justa
```

#### Detección de Coincidencias
```cpp
Lógica de Comparación:
- Revelar primera carta en [fila1][col1]
- Revelar segunda carta en [fila2][col2]
- Comparar tablero[fila1][col1] == tablero[fila2][col2]
- Actualizar el estado del juego según el resultado
```

#### Validación de Entrada
```cpp
Validación en Múltiples Capas:
1. Verificación de tipo (solo enteros)
2. Validación de rango (0-5)
3. Verificación del estado de la carta (no revelada aún)
4. Prevención de selección duplicada (misma carta dos veces)
```

## 🎨 Diseño Visual

### Esquema de Colores de la Consola
- **Texto Principal**: Rojo (`colorCode: 4`)
- **Tablero de Juego**: Fondo blanco con texto en color
- **Mensajes de Error**: Cuadros de error resaltados
- **Mensajes de Éxito**: Cuadros de celebración con sonido

### Elementos en Arte ASCII
- **Pantalla de Título**: Banner grande "MEMORAMA"
- **Pantalla de Victoria**: "FELICIDADES"
- **Pantalla de Empate**: "EMPATE"
- **Cuadros de Error**: Notificaciones de error con borde

## 📚 Resultados de Aprendizaje

### Para los Jugadores
- ✅ **Entrenamiento de Memoria**: Mejora las habilidades de memoria a corto plazo
- ✅ **Reconocimiento de Patrones**: Identificar y recordar posiciones de cartas
- ✅ **Pensamiento Estratégico**: Decidir cuándo tomar riesgos
- ✅ **Juego Competitivo**: Experiencia de dos jugadores

### Para Desarrolladores
🎓 **Fundamentos de C++**
- Manipulación de vectores y matrices
- Manejo y comparación de cadenas
- Organización de funciones y modularidad
- Uso de namespaces y alias

🎓 **Desarrollo Multiplataforma**
- Compilación condicional (#ifdef)
- APIs específicas de cada plataforma
- Diferencias entre POSIX y Windows
- Diseño de código portable

🎓 **Gestión de Entrada/Salida**
- Validación de entrada por consola
- Manejo de errores de flujo (cin.fail())
- Técnicas de limpieza de búfer
- Salida formateada por consola

🎓 **Implementación de Lógica de Juego**
- Sistemas por turnos
- Gestión de estado (cartas reveladas/ocultas)
- Detección de condición de victoria
- Mecanismos de recuperación de errores

🎓 **Tiempo y Subprocesos**
- Uso de la biblioteca Chrono
- Cálculos de duración
- Pausas con hilos de ejecución
- Seguimiento en tiempo real

🎓 **Diseño de Algoritmos**
- Mezcla aleatoria
- Recorrido de cuadrículas
- Mapeo de coordenadas
- Lógica de validación

## 🎮 Desglose de Características

### Manejo de Errores
- **Errores de Tipo**: Rechazo de entradas no enteras
- **Errores de Rango**: Detección de coordenadas fuera de límites
- **Errores de Lógica**: Prevención de seleccionar la misma carta
- **Errores de Estado**: Validación de cartas ya reveladas
- **Limpieza de Búfer**: Limpieza automática del flujo de entrada

### Sistema de Validación
```
Flujo de Entrada:
Entrada → Verificación de Tipo → Verificación de Rango → Verificación de Estado → Aceptar/Rechazar
               ↓                        ↓                        ↓
          Mensaje Error            Mensaje Error            Mensaje Error
```

### Sistema de Cronómetro
- **Inicio**: El cronómetro comienza en el primer movimiento
- **Seguimiento**: Medición de duración en tiempo real
- **Fin**: El cronómetro se detiene al encontrar la última pareja
- **Visualización**: Convertido a minutos y segundos

## 🐛 Mensajes de Error

### Errores Comunes
| Tipo de Error | Mensaje | Causa |
|---------------|---------|-------|
| **Error de Rango** | "Fuera de Rango (Numeros de 0-5)" | Entrada < 0 o > 5 |
| **Error de Tipo** | "Entrada Invalida. Ingresa un Numero" | Entrada no entera |
| **Error de Carta** | "Esa Carta ya fue descubierta" | Selección de carta revelada |
| **Misma Carta** | "Ya elegiste esa Carta como Primera" | Selección duplicada |
| **Nombre Vacío** | "El Nombre no puede estar Vacio" | Nombre de jugador en blanco |

## 🌐 Nota sobre el Idioma

La interfaz del juego está actualmente en **español**. Los mensajes de error, indicaciones y pantallas de victoria se muestran en español, siendo ideal para jugadores hispanohablantes o personas que aprenden el idioma.

## 💡 Consejos de Estrategia

### Para Mejores Resultados
- **Mapeo Mental**: Crea un mapa mental de las cartas reveladas
- **Memoria de Patrones**: Recuerda las posiciones de las letras, no solo las parejas
- **Riesgo vs Recompensa**: A veces adivinar revela nueva información
- **Observación**: Aprovecha los intentos fallidos del oponente como pistas
- **Inicio del Juego**: Explora diferentes áreas del tablero
- **Final del Juego**: Usa el conocimiento acumulado para ganar rápido

## 📥 Descarga y Juega

### ¡Inicio Rápido — Sin Instalación!

¡Solo descarga y juega! Este juego se distribuye como un ejecutable independiente que corre directamente sin ningún proceso de instalación.

1. **Descarga** el archivo ejecutable (`LetterCards.exe`)
2. **Haz doble clic** para iniciar el juego
3. **Comienza a jugar** de inmediato — ¡sin configuración necesaria!

### Requisitos del Sistema
- **SO**: Windows 10/11, Linux (Ubuntu 18.04+) o macOS 10.14+
- **RAM**: Mínimo 20 MB
- **Almacenamiento**: ~3 MB de espacio libre
- **Pantalla**: Ventana de terminal/consola
- **Sin Dependencias**: Todas las bibliotecas están enlazadas estáticamente

### ¿Listo para Jugar?

- ✅ **Sin complicaciones de instalación**
- ✅ **Sin dependencias que descargar**
- ✅ **Sin configuración necesaria**
= ✅ **¡Solo descarga y juega!**

Descarga la última versión desde la sección de [Releases](../../releases) ¡y comienza a desafiar tu memoria hoy!

## 📧 Contacto y Soporte

**Desarrollador:** Carlos Gabriel Magallanes López
**Correo electrónico:** cgmagallanes23@gmail.com
**Escuela:** Centro de Bachillerato Tecnológico Industrial y de Servicios No. 128

¿Encontraste un error? ¿Tienes sugerencias? ¿Quieres reportar tu puntuación más alta? ¡No dudes en escribir!

---

### 🃏 ¡Pon a prueba tu memoria y compite con amigos en este clásico juego de parejas! 🎯

**Ideal para:**
- Entrenamiento de memoria y desarrollo cognitivo
- Juego competitivo para dos jugadores
- Aprender desarrollo de juegos en C++
- Entender la programación multiplataforma
- Estudio de diseño de interfaces en consola

**¡Desafía tu mente y diviértete!** 🧠✨
