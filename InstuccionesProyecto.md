# Universidad Nacional de Costa Rica
## Escuela de Informática
### Proyecto II - Programación II 2026
#### Motor de Simulación de Aventuras y Mazmorras

**Curso:** EIF204 - Programación II  
**Carrera:** Ingeniería de Sistemas de Información  
**Nivel:** Segundo año  
**Periodo lectivo:** I Ciclo 2026  
**Modalidad:** Presencial  
**Valor:** 100 puntos  
**Lenguaje:** C++

---

### 1. Descripción general
El presente proyecto consiste en el desarrollo de un motor de simulación en consola para representar una aventura dentro de un mundo compuesto por espacios conectados, personajes, elementos interactivos, eventos y objetivos de progreso.

El sistema no tiene como finalidad construir un videojuego gráfico. Su propósito es modelar una simulación mediante objetos en C++, donde el estado del mundo cambia durante la ejecución y donde las acciones ocurridas puedan verificarse posteriormente mediante archivos de salida.

La ambientación, las reglas internas, el tipo de mundo, la forma de exploración y los elementos concretos de la aventura serán definidos por cada equipo. El escenario puede ser fantástico, medieval, futurista, histórico, científico, urbano, natural o de cualquier otra naturaleza, siempre que permita representar una simulación coherente.

La salida del programa debe ser consecuencia de los datos cargados, del estado de los objetos y de las reglas implementadas. No se aceptará una secuencia fija de texto escrita manualmente como sustituto de la simulación.

---

### 2. Relación con el curso
Este proyecto integra contenidos fundamentales de Programación II, entre ellos diseño orientado a objetos, relaciones entre clases, herencia, polimorfismo, manejo de memoria, programación genérica, iteradores, sobrecarga de operadores, archivos, excepciones y patrones de diseño.

La intención del proyecto no es que el equipo utilice todos los temas vistos en clase, sino que demuestre criterio para decidir cuáles conceptos son necesarios para resolver el problema propuesto. Una solución adecuada debe evidenciar pensamiento de diseño, comprensión del dominio y capacidad para construir software funcional en C++.

---

### 3. Objetivo general
Diseñar e implementar en C++ un motor de simulación de aventuras capaz de cargar información inicial desde archivos de texto, construir una representación interna del mundo, ejecutar una simulación verificable, registrar los hechos relevantes y generar un reporte final de la aventura.

---

### 4. Problema a resolver
Un personaje inicia una aventura en un mundo descrito mediante archivos de texto. A partir de esa información, el sistema debe construir una representación interna del escenario y ejecutar una simulación donde ocurran interacciones entre el personaje, el entorno y los demás elementos definidos por el equipo.

Durante la simulación, el estado del sistema debe cambiar. El personaje puede desplazarse, encontrar elementos, enfrentar situaciones, activar sucesos, cumplir o fallar objetivos, modificar su estado y finalizar la aventura bajo una condición determinada.

El comportamiento del programa debe poder verificarse mediante salidas generadas por el propio sistema, incluyendo una bitácora de acontecimientos y un reporte final.

---

### 5. Alcance esperado
Cada equipo tendrá libertad para definir la estructura concreta de su aventura. Sin embargo, la solución debe tener suficiente complejidad para evidenciar una simulación real y no una demostración mínima o estática.

El sistema deberá representar, de forma coherente con la propuesta del equipo:
* Un mundo compuesto por espacios relacionados.
* e Un personaje o entidad principal que participe en la simulación. Elementos del entorno con los que pueda existir interacción.
* Situaciones, eventos, amenazas, obstáculos o condiciones que modifiquen el desarrollo de la aventura.
* • Algún tipo de progreso, misión, meta, condición de éxito o condición de finalización.
* Registro de acontecimientos durante la ejecución.
* • Reporte final generado en archivo de texto.

El recorrido puede resolverse de manera automática, semiautomática, guiada por reglas, basada en decisiones programadas o mediante interacción con el usuario. La elección queda a criterio del equipo, siempre que el resultado sea reproducible y verificable.

---

### 6. Funcionamiento esperado
El programa deberá cargar información inicial desde archivos de texto y utilizarla para construir los elementos necesarios de la aventura.

Durante la ejecución debe existir una evolución observable del sistema. Esto significa que la simulación debe producir cambios de estado, interacciones y resultados derivados de las reglas implementadas.

Al finalizar, el sistema deberá generar evidencia suficiente para revisar qué ocurrió durante la aventura. Esta evidencia debe permitir comprender, al menos, el estado final del personaje o entidad principal, los principales acontecimientos ocurridos y el resultado general de la simulación.

---

### 7. Requerimientos no funcionales
La solución debe cumplir con las siguientes condiciones:
* • El código debe ser modular, mantenible y de bajo acoplamiento.
* Los nombres de clases, métodos, atributos y archivos de código deben escribirse en inglés.
* • La documentación interna del código debe escribirse en inglés.
* • El documento técnico puede escribirse en español.
* El proyecto debe utilizar rutas relativas para acceder a los archivos.
* • No se aceptarán rutas absolutas dependientes de la computadora del estudiante.
* El ejecución debe poder reproducirse con los archivos entregados.
* El sistema debe manejar errores de forma clara y controlada.

---

### 8. Criterios de valoración técnica
El equipo tendrá libertad para decidir la arquitectura, las clases, las relaciones, el formato de archivos, las reglas de simulación y la organización interna del sistema. La evaluación técnica se centrará en la calidad de las decisiones tomadas y en la forma en que el equipo aproveche los contenidos del curso para resolver el problema. No se espera que todos los proyectos usen exactamente las mismas técnicas ni que incluyan todos los temas vistos en clase.

Se valorará especialmente que la solución evidencie, cuando el diseño lo justifique:
* Modelado orientado a objetos con clases cohesionadas y responsabilidades claras.
* Relaciones entre clases bien definidas y coherentes con el dominio.
* Uso adecuado de abstracción, herencia y polimorfismo cuando aporten flexibilidad o claridad al diseño.
* • Manejo responsable de memoria y recursos.
* •
* Uso pertinente de programación genérica, estructuras propias o iteradores cuando el problema lo requiera.
* Sobrecarga de operadores cuando mejore la expresividad o integración del dominio.
* Manejo robusto de archivos, validaciones y errores.
* Aplicación razonada de patrones de diseño cuando exista una necesidad real de diseño.
* Separación adecuada entre datos, lógica de simulación, entidades del dominio y salidas del sistema.

No se valorará positivamente el uso forzado de técnicas que no aporten al funcionamiento del proyecto. Una solución simple, clara y bien justificada puede ser superior a una solución más extensa, pero artificial o difícil de mantener.

El documento técnico deberá explicar las principales decisiones de diseño y justificar por qué el equipo eligió determinadas estructuras, relaciones, patrones o mecanismos de implementación.

---

### 9. Archivos de entrada y salida
Cada equipo definirá el formato de sus archivos de entrada. Dicho formato debe ser claro, documentado y validado por el programa. Los archivos de entrada deben contener información suficiente para construir el estado inicial de la aventura.

Los archivos de salida deben permitir revisar el comportamiento de la simulación y el resultado final obtenido. Como mínimo, debe existir una bitácora de acontecimientos y un reporte final.

---

### 10. Entregables
Cada equipo deberá entregar:
* **E1 - Código fuente completo:** Proyecto completo en C++ que compile y ejecute sin errores.
* **E2 - Archivos de entrada:** Archivos de texto utilizados para cargar la aventura.
* **E3 - Archivos de salida:** Bitácora y reporte final generados por el programa.
* **E4-Documento técnico:** Documento en PDF donde se expliquen las principales decisiones de diseño e implementación.
* **E5 - README.md:** Archivo con instrucciones de compilación, ejecución, estructura del proyecto y descripción breve de la simulación.
* **E6 - Evidencia de ejecución:** Capturas, salida de consola, archivos generados o cualquier evidencia que demuestre que el sistema funciona.
* **E7 - Defensa técnica opcional:** El profesor podrá solicitar una defensa técnica breve si lo considera necesario. En ese caso, el equipo deberá explicar y justificar su solución.

---

### 11. Contenido sugerido del documento técnico
El documento técnico debe permitir comprender cómo fue diseñada y construida la solución. Se sugiere incluir:
* Descripción general del sistema.
* Temática de la aventura.
* Formato de los archivos de entrada.
* • Principales clases y relaciones.
* • Decisiones relevantes de diseño.
* Estrategia de manejo de memoria y recursos. Manejo de archivos y errores.
* • Técnicas del curso utilizadas y justificación de su uso.
* • Evidencia de ejecución.
* Limitaciones y posibles mejoras.

---

### 12. Rúbrica de evaluación

| Criterio | Puntaje |
| :--- | :--- |
| Simulación funcional: carga de datos, ejecución, cambios de estado, bitácora y reporte final | 25 pts |
| Diseño orientado a objetos: modelado, cohesión, responsabilidades, relaciones y claridad del dominio | 20 pts |
| Criterio técnico: uso pertinente y justificado de contenidos de Programación II | 20 pts |
| Archivos, persistencia y manejo de errores: lectura, validación, escritura y control de fallos | 15 pts |
| Documento técnico: claridad, justificación, evidencia y coherencia con la implementación | 10 pts |
| Organización general: estructura, README, compilación y buenas prácticas | 10 pts |
| **Total** | **100 pts** |

---

### 13. Reglas de incumplimiento crítico
Se considerarán faltas graves las siguientes situaciones:
* El proyecto no compila.
* • No existe simulación real.
* • No se cargan datos desde archivos de texto.
* • El programa se limita a imprimir una salida fija.
* No se generaran archivos de salida.
* •
* No existe evidencia verificable de ejecución.
* No se entrega el código fuente completo.
* No es posible reproducir la ejecución con los archivos entregados.

Estas faltas podrán afectar significativamente la calificación final, aunque algunos elementos secundarios estén presentes.  
100 pts

---

### 14. Condiciones de aceptación
Para ser evaluado funcionalmente, el proyecto debe compilar y ejecutarse correctamente en el entorno indicado por el profesor. El equipo debe entregar todos los archivos necesarios para reproducir la ejecución. No se aceptarán rutas absolutas ni dependencias externas no autorizadas.

Si el proyecto no compila, no podrá evaluarse funcionalmente. En ese caso, el profesor podrá revisar únicamente aspectos documentales o fragmentos técnicamente verificables, según corresponda.

---

### 15. Criterio global de aprobación
El proyecto debe demostrar que el equipo comprende cómo construir una solución orientada a objetos en C++ con comportamiento real, manejo adecuado de datos, archivos, errores y decisiones de diseño.

La calidad de la solución no se medirá por la cantidad de técnicas utilizadas, sino por la coherencia entre el problema, el diseño, la implementación y la simulación obtenida.  
# VI. CRONOGRAMA 

[cite_start]Este es el cronograma planeado del curso: [cite: 262]

| Sem. | Sesión | Contenidos Actividades | Recursos y estrategias didácticas |
| :--- | :--- | :--- | :--- |
| 1 | 1,2 | Relaciones (repaso)<br><br>Introducción y presentación | [cite_start]Exposición de temas, [cite: 263] |
| 2 | 3,4 | [cite_start]Upcast<br>Downcast<br>Dependencia mutua<br>Principio abierto/cerrado<br>Principio de Parnas<br>Principios informales de diseño (KISS, YAGNI) | discusión y prácticas (según criterio de cada profesor)<br>Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| | | [cite_start]Principios formales de diseño (SOLID) | [cite: 263] |
| 3 | 5,6 | Patrón Delegate<br><br>Manejo de excepciones | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 4 | 7,8 | Principio de Sustitución de Entrega del primer proyecto<br><br>Liskov<br><br>Patrón Decorator | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 5 | 9, 10 | Manejo de flujos | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 6 | 11, 12 | Concepto de objeto base para el manejo de colecciones | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| | | [cite_start]Semana Santa | [cite: 263] |
| 7 | 13, 14 | Programación genérica y uso de plantillas (templates)<br><br>Uso de iteradores (patrón Iterator) | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 8 | 15, 16 | Regla de tres (Big Three Rule)<br>Regla de cinco (Big Five Rule)<br>Sobrecarga de operadores<br><br>Primer examen parcial (domingo 19 de abril, 8:00<br><br>a.m.) | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| | | [cite_start]Patrón Singleton<br>Patrón Adapter | [cite: 263] |
| 9 | 17, 18 | Patrón Composite<br><br>Entrega del primer proyecto<br><br>por parte de los estudiantes<br><br>Principio de Segregación de Interfaces | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 10 | 19, 20 | Principio de Inversión de Dependencias<br><br>Entrega del segundo proyecto<br><br>Patrón Abstract Factory | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 11 | 21, 22 | 2do examen parcial (domingo<br><br>Factory Method<br><br>10 de mayo, 8:00 a.m.) | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 263] |
| 12 | 23, 24 | Patrón Observer<br><br>Patrón Bridge | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 266] |
| 13 | 25, 26 | Patrón Strategy | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 266] |
| 14 | 27, 28 | Serialización | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 266] |
| 15 | 29, 30 | Persistencia de datos | [cite_start]Exposición de temas, discusión y prácticas (según criterio de cada profesor) [cite: 266] |
| 16 | 31, 32 | Entrega del segundo proyecto por parte de los estudiantes | [cite_start]Repaso general [cite: 266] |
| 17 | | [cite_start]Examen Final (sábado 21 de | [cite: 266] |
| | [cite_start]| junio, 8:00 a.m.) | [cite: 266] |