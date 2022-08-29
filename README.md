# Proyecto-Final-CC2
proyecto grupal
## Tabla del contenido
1. [Documentación]
2. [Introducción de uso]
3. [Problemas de Implementación]
4. [Desafíos superados]
### Documentación
***
Nuestro proyecto consta de siete clases, para comenzar tenemos la clase “Menu” en la cual implementamos también templates, esta clase en sí vamos a usarla para agregar las dos barras de vida de los jugadores, le asignaremos su tamaño y en sí cuando debería aparecer este, pasamos a la clase “Enemigos” en la cual vamos a darle movimiento y acciones al que sería el enemigo valga la redundancia, tendriamos tambien la barra de vida, los disparos, las colisiones, entre otros aspectos que agregamos a las acciones de los enemigos. Pasamos a la clase “Bala” por el cual cargaremos en el código la bala del personaje y la bala de los enemigos, le daremos movimiento a estas.
‘’’
Los cambios que se realizaron a la última entrega son varios empezando por la animación de los personajes, y de la calidad gráfica de los mismos, se cambió el menú de presentación que llegue a combinar con los gráficos también se le cambió la vista del personaje a una vista superior.
‘’’
La dirección que se tuvo para este era la forma de entretener al usuario mediante un juego que sería poco común a los que se encuentran en la actualidad dándole la visión de un juego que sea rápido de entender y que cada partida sea rápida y no demande mucho tiempo también añadir de que su modo cooperativo lo hace mas entretenido para jugar con los amigos el proyecto se llegó a terminar y realizar lo que queríamos aunque hubo unos inconvenientes con la implementación de algunos requerimientos pero que se han ido solucionando a medida de que se ha ido avanzando en el trabajo.
‘’’
Secuencia de ingresar al juego
1. **Ingresar**
Al ingresar nos dará tres opciones las cuales son de jugar en:
* modo solitario
* modo cooperativo
* salir del juego
2. **Jugando**
Cuando se esté jugando bien sea en modo solitario o cooperativo la misión del jugador es entrar a una base y defenderla de los enemigos y el punto más importante sería sobrevivir el mayor tiempo posible.
‘’’
En el modo cooperativo si un jugador pierde el otro jugador queda eliminado junto con el ya que el punto es sobrevivir los dos el mayor tiempo posible
3. **Acabar partida**
Como se acaba la partida, la partida termina cuando el jugador pierde toda su vida la cual se puede visualizar en la parte superior derecha del juego donde se podrá apreciar como esta va disminuyendo la vida del personaje.
### Introduccion de uso 
***
Para la ejecución del programa se instaló la versión 4 de Allegro con ayuda del DEV-C + + que se pudo instalar esta versión.
Para iniciar el juego solo basta con darle click en correr seguidamente tendremos a nuestro personaje que para moverse tiene que apretar las teclas (“Arriba -> flecha hacia arriba , Abajo -> Flecha hacia abajo ,Derecha -> Flecha hacia la derecha ,Izquierda -> Flecha hacia la izquierda,disparar -> espacio ”) esto para el personaje 1 , para el personaje 2 (“Arriba -> letra W , Abajo -> letra S ,Derecha -> letra D ,Izquierda -> letra A , disparar -> G ”) , se solicita sobrevivir para no perder el juego  esquivar las balas enemigas y disparar para destruirlas.
### Problemas de Implementación
***
Primeramente tuvimos problemas con la librería allegro debido a estábamos utilizando una versión desactualizada de la librería lo que nos ocasionó que nuestros bitmap se forzaran al momento de la ejecución y no reconociera los comando que le asignaban a cada sprite y que los bitmap se sobreposiciones  de uno a otro y este error es el principal que tuvimos por que solo nos mostraba un sprite por ejemplo el escenario se dibujaba encima de los personajes y por ende los cubría y solo se visualizaba el fondo y de igual manera el sprite 1 con el sprite 2  ,  también se tuvo problemas en el momento de implementar los patrones de diseños debido a que los BITMAP tienen poca manejabilidad y se confunden al hacer la declaración en los patrones , lo mismo para los punteros inteligentes.
### Desafíos superados
***
Superamos el obstáculo que teníamos con la sobreposicion de los bitmap y sprites  al momento de querer abrir nuestro fondo como nuestra pantalla principal del juego y eliminar los fondos a los personajes para que no se viera con el fondo negro ,también logramos poner un fondo movible para que diera la sensación de que el escenario se mueve , la parte de heredar 2 personajes también fue resuelta ya que al principio no podíamos juntarlos a los 2 en un mismo  BITMAP  esto se soluciono atraves de la herencia del personaje 1 al personaje 2 , se soluciono el problema que nos daba al implementar los patrones de diseño, functores y tambien los punteros inteligentes
