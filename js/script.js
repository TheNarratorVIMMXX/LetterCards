/*****************************************************************************************************************************************************************************/
/*                                                                                                                                                                           */
/*                                                                  Scripts para el Proyecto LetterCards                                                                     */
/*                                                                                                                                                                           */
/*****************************************************************************************************************************************************************************/
/*                                                                                                                                                                           */
/* Autor: Magallanes López Carlos Gabriel                                                                                                                                    */
/* Versión del Proyecto: 1.0                                                                                                                                                 */
/* Correo: cgmagallanes23@gmail.com                                                                                                                                          */
/* Ultima Modificación: 27/03/2025                                                                                                                                           */
/*                                                                                                                                                                           */
/*****************************************************************************************************************************************************************************/

// i18n - Traducciones
const translations = {
    es: {
        // Nav
        navFeatures:        "Features",
        navScreenshots:     "Capturas",
        navBoard:           "Tablero",
        navDownload:        "Descargar",
        // Hero
        heroKicker:         "C++ · Consola · Multiplataforma",
        heroT1:             "Memorama",
        heroT2:             "de Letras",
        heroDesc:           "Juego clásico de parejas para dos jugadores en consola. Cuadrícula 6×6, 18 parejas únicas, cronómetro y estadísticas.",
        heroBtn1:           "⬇ Descargar .exe",
        heroBtn2:           "Ver Capturas",
        heroGridLabel:      "Tablero 6 × 6",
        // Stats
        stat1Key:           "Cuadrícula",
        stat2Key:           "Parejas A–R",
        stat3Key:           "Jugadores",
        stat4Key:           "Plataformas",
        // Features
        featKicker:         "Funcionalidades",
        featTitle:          "¿Qué incluye <span>el juego</span>?",
        feat1Title:         "Modo 2 Jugadores",
        feat1Desc:          "Turnos alternados. Quien encuentra la pareja continúa jugando. Puntuación individual en tiempo real.",
        feat2Title:         "Mezcla Aleatoria",
        feat2Desc:          "Distribución justa y mezcla de las 36 cartas en cada nueva partida.",
        feat3Title:         "Cronómetro",
        feat3Desc:          "Tiempo total registrado con std::chrono. Se muestra en minutos y segundos al terminar la partida.",
        feat4Title:         "Validación Robusta",
        feat4Desc:          "4 capas: tipo de dato, rango 0-5, carta ya revelada, selección duplicada. Limpieza automática de buffer.",
        feat5Title:         "Multiplataforma",
        feat5Desc:          "Windows (SetConsoleTextAttribute), Linux y macOS (ANSI escape). Compilación condicional #ifdef _WIN32.",
        feat6Title:         "Estadísticas Finales",
        feat6Desc:          "Puntos por jugador, movimientos totales, errores acumulados y tiempo de partida al finalizar.",
        // Screenshots
        screensKicker:      "Capturas de Pantalla",
        screensTitle:       "El juego en <span>acción</span>",
        sc1Name:            "Partida en curso",
        sc1Label:           "🃏 Tablero 6×6 — Turno del jugador",
        sc2Name:            "Ingreso de nombres",
        sc2Label:           "👥 Pantalla de bienvenida — Ambos jugadores",
        sc3Name:            "Pantalla de victoria",
        sc3Label:           "🏆 ¡Ganador! — Arte ASCII de celebración",
        sc4Name:            "Estadísticas finales",
        sc4Label:           "📊 Resultados — Puntos · Movimientos · Tiempo",
        // Board
        boardKicker:        "Diseño del Tablero",
        boardTitle:         "Cuadrícula <span>6 × 6</span>",
        boardDemoTitle:     "Estado durante la partida",
        bi1Title:           "Coordenadas fila-columna",
        bi1Desc:            "El jugador ingresa fila (0-5) y columna (0-5) para seleccionar una carta. Las cartas ocultas se muestran como X.",
        bi2Title:           "18 parejas A-R",
        bi2Desc:            "36 cartas en total, dos de cada letra. Se mezclan antes de cada partida para garantizar aleatoriedad.",
        bi3Title:           "Turno contínuo",
        bi3Desc:            "Encontrar una pareja mantiene tu turno activo. Solo cambias cuando fallas, incentivando concentración y memoria.",
        // Errors
        errKicker:          "Validación de Entrada",
        errTitle:           "Manejo de <span>Errores</span>",
        err1Badge:          "RANGO",
        err1Title:          "Fuera de Rango",
        err1Msg:            '"Fuera de Rango (Numeros de 0-5)"',
        err2Badge:          "TIPO",
        err2Title:          "Entrada no entera",
        err2Msg:            '"Entrada Invalida. Ingresa un Numero"',
        err3Badge:          "CARTA",
        err3Title:          "Ya descubierta",
        err3Msg:            '"Esa Carta ya fue descubierta"',
        err4Badge:          "DUPLICADO",
        err4Title:          "Misma carta",
        err4Msg:            '"Ya elegiste esa Carta como Primera"',
        // Download
        dlKicker:           "Distribución",
        dlTitle:            "Descargar <span>LetterCards</span>",
        dlDesc:             "Sin instalar compilador ni dependencias. Ejecutable listo para Windows, Linux y macOS.",
        dlBtn:              "⬇ LetterCards.exe",
        req1:               "🪟 Windows 10/11",
        req2:               "🐧 Linux Ubuntu 18+",
        req3:               "🍎 macOS 10.14+",
        req4:               "💾 ~4 MB",
        req5:               "⚡ Sin instalación",
        // Footer
        footerLeft:         "Memorama de Letras · © 2025 Carlos Gabriel Magallanes López",
        footerContact:      "Contacto",
        // Lang Button
        langBtn:            "🌐 English"
    },
    en: {
        // Nav
        navFeatures:        "Features",
        navScreenshots:     "Screenshots",
        navBoard:           "Board",
        navDownload:        "Download",
        // Hero
        heroKicker:         "C++ · Console · Multiplatform",
        heroT1:             "Letter",
        heroT2:             "Memory Game",
        heroDesc:           "Classic matching game for two console players. 6×6 grid, 18 unique pairs, timer and full statistics.",
        heroBtn1:           "⬇ Download .exe",
        heroBtn2:           "View Screenshots",
        heroGridLabel:      "Board 6 × 6",
        // Stats
        stat1Key:           "Grid",
        stat2Key:           "Pairs A–R",
        stat3Key:           "Players",
        stat4Key:           "Platforms",
        // Features
        featKicker:         "Functionalities",
        featTitle:          "What does <span>the game</span> include?",
        feat1Title:         "2-Player Mode",
        feat1Desc:          "Alternating turns. Whoever finds a pair keeps playing. Individual score updated in real time.",
        feat2Title:         "Random Shuffle",
        feat2Desc:          "Fair distribution and shuffle of all 36 cards at the start of every new game.",
        feat3Title:         "Timer",
        feat3Desc:          "Total time tracked with std::chrono. Displayed in minutes and seconds at the end of the game.",
        feat4Title:         "Robust Validation",
        feat4Desc:          "4 layers: data type, range 0-5, already revealed card, duplicate selection. Automatic buffer flush.",
        feat5Title:         "Multiplatform",
        feat5Desc:          "Windows (SetConsoleTextAttribute), Linux and macOS (ANSI escape). Conditional compilation with #ifdef _WIN32.",
        feat6Title:         "Final Statistics",
        feat6Desc:          "Points per player, total moves, accumulated errors and game time shown at the end.",
        // Screenshots
        screensKicker:      "Screenshots",
        screensTitle:       "The game in <span>action</span>",
        sc1Name:            "Game in progress",
        sc1Label:           "🃏 6×6 Board — Player's turn",
        sc2Name:            "Name entry",
        sc2Label:           "👥 Welcome screen — Both players",
        sc3Name:            "Victory screen",
        sc3Label:           "🏆 Winner! — ASCII celebration art",
        sc4Name:            "Final statistics",
        sc4Label:           "📊 Results — Points · Moves · Time",
        // Board
        boardKicker:        "Board Design",
        boardTitle:         "Grid <span>6 × 6</span>",
        boardDemoTitle:     "State during the game",
        bi1Title:           "Row-column coordinates",
        bi1Desc:            "The player enters row (0-5) and column (0-5) to select a card. Hidden cards are shown as X.",
        bi2Title:           "18 pairs A-R",
        bi2Desc:            "36 cards total, two of each letter. Shuffled before every game to guarantee randomness.",
        bi3Title:           "Continuous turn",
        bi3Desc:            "Finding a pair keeps your turn active. You only switch when you fail, encouraging focus and memory.",
        // Errors
        errKicker:          "Input Validation",
        errTitle:           "Error <span>Handling</span>",
        err1Badge:          "RANGE",
        err1Title:          "Out of Range",
        err1Msg:            '"Out of Range (Numbers from 0-5)"',
        err2Badge:          "TYPE",
        err2Title:          "Non-integer input",
        err2Msg:            '"Invalid Input. Enter a Number"',
        err3Badge:          "CARD",
        err3Title:          "Already revealed",
        err3Msg:            '"That Card has already been revealed"',
        err4Badge:          "DUPLICATE",
        err4Title:          "Same card",
        err4Msg:            '"You already chose that Card as First"',
        // Download
        dlKicker:           "Distribution",
        dlTitle:            "Download <span>LetterCards</span>",
        dlDesc:             "No compiler or dependencies needed. Ready-to-run executable for Windows, Linux and macOS.",
        dlBtn:              "⬇ LetterCards.exe",
        req1:               "🪟 Windows 10/11",
        req2:               "🐧 Linux Ubuntu 18+",
        req3:               "🍎 macOS 10.14+",
        req4:               "💾 ~4 MB",
        req5:               "⚡ No install",
        // Footer
        footerLeft:         "Letter Memory Game · © 2025 Carlos Gabriel Magallanes López",
        footerContact:      "Contact",
        // Lang Button
        langBtn:            "🌐 Español"
    }
};

// Detección y Aplicación de Idioma
function detectLanguage() {
    const saved = localStorage.getItem('lang');                                                  // Obtener el Lenguaje del Local Storage
    if (saved) return saved;                                                                     // Si se obtuvo el Lenguaje del Local Storage Retornar
    const browserLang = navigator.language || navigator.userLanguage;                            // Obtener el Lenguaje del Browser
    return browserLang.startsWith('es') ? 'es' : 'en';                                          // Español si es es-*, inglés para todo lo demás
}

// Aplicar Traducciones al DOM
function applyLanguage(lang) {
    const t = translations[lang];
    document.querySelectorAll('[data-i18n]').forEach(el => {                                     // Traducir Elementos con Texto Simple
        const key = el.getAttribute('data-i18n');
        if (t[key]) el.textContent = t[key];
    });
    document.querySelectorAll('[data-i18n-html]').forEach(el => {                                // Traducir Elementos con HTML Interno (spans de color)
        const key = el.getAttribute('data-i18n-html');
        if (t[key]) el.innerHTML = t[key];
    });
    document.documentElement.setAttribute('lang', lang);                                         // Actualizar Atributo lang del HTML para Accesibilidad
    const btn = document.getElementById('langToggleBtn');
    if (btn) btn.textContent = t.langBtn;
    localStorage.setItem('lang', lang);                                                          // Guardar Idioma Seleccionado en localStorage
}

// Crear Botón Flotante de Cambio de Idioma
function createLangButton() {
    const btn = document.createElement('button');                                                // Crear el Elemento
    btn.id = 'langToggleBtn';                                                                    // ID para Aplicar Estilos desde CSS
    btn.addEventListener('click', () => {                                                        // Agregar Callback para el Botón
        const current = localStorage.getItem('lang') || detectLanguage();                        // Obtener Lenguaje Actual
        const next = current === 'es' ? 'en' : 'es';                                            // Alternar entre Español e Inglés
        applyLanguage(next);                                                                     // Aplicar el Lenguaje
    });
    document.body.appendChild(btn);                                                              // Agregar Botón al Documento
}

// Efecto Fade In al hacer Scroll
const observer = new IntersectionObserver((entries) => {                                         // Instanciar Observador Intersección, Detección Elementos en Viewport
    entries.forEach(entry => {                                                                   // Para Cada Elemento Detectado en el Viewport
        if (entry.isIntersecting) {                                                              // Si esta en Viewport
            entry.target.classList.add('visible');                                               // Agregar Clase 'visible' para Efecto Fade In
            observer.unobserve(entry.target);                                                    // Dejar de Observar el Elemento para Mejorar Rendimiento
        }
    });
}, { threshold: 0.1 });                                                                          // Configuración del Observador: Activar cuando el 10% del Elemento sea Visible

// Observar Elementos de la Clase 'Fade-In' para Activar Efecto al Entrar en el Viewport
const fadeElements = document.querySelectorAll('.fade-in');                                      // Seleccionar Todos los Elementos con Clase 'fade-in'
fadeElements.forEach(element => observer.observe(element));                                      // Observar Cada Elemento para Activar Efecto Fade In al Entrar en el Viewport

// Efecto de Cambio de Fondo del Nav al Hacer Scroll
const nav = document.querySelector('nav');                                                       // Seleccionar el Elemento de Navegación
window.addEventListener('scroll', () => {                                                        // Añadir Evento de Scroll
    if (window.scrollY > 80) {
        nav.style.background = 'rgba(5,4,8,0.97)';
        nav.style.borderBottomColor = 'rgba(201,168,76,0.2)';
    } else {
        nav.style.background = 'linear-gradient(to bottom, rgba(5,4,8,0.95), transparent)';
        nav.style.borderBottomColor = 'rgba(201,168,76,0.1)';
    }
});

// Inicialización
createLangButton();                                                                              // Creación del Botón del Lenguaje
applyLanguage(detectLanguage());                                                                 // Aplicación del Lenguaje

/*****************************************************************************************************************************************************************************/
