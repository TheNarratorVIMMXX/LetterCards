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

// Efecto Fade In al hacer Scroll
const observer = new IntersectionObserver((entries) => {                                         // Instanciar Observador Intersección, Detección Elementos en Viewport 
    entries.forEach(entry => {                                                                   // Para Cada Elemento Detectado en el Viewport
        if (entry.isIntersecting){                                                               // Si esta en Viewport
            entry.target.classList.add('visible');                                               // Agregar Clase 'visible' para Efecto Fade In
            observer.unobserve(entry.target);                                                    // Dejar de Observar el Elemento para Mejorar Rendimiento
        }                         
    });
}, {threshold: 0.1});                                                                            // Configuración del Observador: Activar cuando el 10% del Elemento sea Visible

// Observar Elementos de la Clase 'Fade-In' para Activar Efecto al Entrar en el Viewport
const fadeElements = document.querySelectorAll('.fade-in');                                      // Seleccionar Todos los Elementos con Clase 'fade-in' 
fadeElements.forEach(element => observer.observe(element));                                      // Observar Cada Elemento para Activar Efecto Fade In al Entrar en el Viewport                         

// Efecto de Cambio de Fondo del Nav al Hacer Scroll
const nav = document.querySelector('nav');                                                       // Seleccionar el Elemento de Navegación para Modificar su Estilo al Hacer Scroll
window.addEventListener('scroll', () => {                                                        // Añadir Evento de Scroll para Detectar el Desplazamiento del Usuario
    if (window.scrollY > 80) {                                                                   // Si el Usuario se Desplaza Más de 80px desde la Parte Superior            
        nav.style.background = 'rgba(5,4,8,0.97)';                                             // Cambiar el Fondo del Nav a un Color Sólido para Mejorar la Legibilidad
        nav.style.borderBottomColor = 'rgba(201,168,76,0.2)';                                  // Cambiar el Color del Borde Inferior para Resaltar el Nav
    } else {                                                                                     // Si el Usuario se Encuentra Cerca de la Parte Superior
        nav.style.background = 'linear-gradient(to bottom, rgba(5,4,8,0.95), transparent)';    // Restaurar Fondo Nav a Gradiente Transparente 
        nav.style.borderBottomColor = 'rgba(201,168,76,0.1)';                                  // Restaurar Color Borde Inferior a Color Sutil 
    }
});

/*****************************************************************************************************************************************************************************/