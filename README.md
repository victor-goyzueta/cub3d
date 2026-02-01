# cub3D

## Descripción
cub3D es un motor gráfico que renderiza un entorno 3D a partir de un mapa 2D usando el algoritmo de raycasting. Permite movimiento y rotación en primera persona dentro del mapa, ofreciendo una experiencia de juego básica y visualización del entorno.

Este proyecto fue desarrollado como parte del **Common Core de 42 Madrid** en colaboración con mi compañero **[jocalder](https://github.com/jocalder)** y contiene únicamente la implementación obligatoria del enunciado.

---

## Requisitos

- **Sistema operativo:** Linux  
- **Lenguaje:** C  
- **Librería gráfica:** MiniLibX  

---

## Compilación

Compilar el proyecto mediante `make`:

````bash
make
````

Esto generará el binario:

````bash
cub3D
````

---

## Uso

Ejecutar el programa con un archivo `.cub` válido:

```bash
./cub3D maps/mapa.cub
```

* El archivo `.cub` es **obligatorio**
* Si falta o es inválido, el programa muestra un **mensaje de USAGE** y termina

### Controles del jugador

* `W` / `S`: avanzar / retroceder
* `A` / `D`: movimiento lateral izquierda / derecha
* `←` / `→`: rotación de la cámara
* `ESC` o cerrar ventana: salir del programa

### Manejo de errores

* Validación extensa de errores (mapa, archivo, texturas, colores RGB)
* Mensajes por consola
* Terminación con `exit status 1` en errores críticos

---

## Formato del mapa (`.cub`)

### Contenido

* **Texturas:** NO, SO, WE, EA
* **Colores:** Floor (F) / Ceiling (C) en RGB
* **Mapa:**

  * Muros: `1`
  * Suelo: `0`
  * Espacios permitidos si el mapa sigue siendo jugable desde la posición inicial
* **Jugador:** posición y orientación inicial (`N`, `S`, `W`, `E`)

### Restricciones

* Mapa cerrado por muros (esquinas implícitas permitidas salvo si hay `0`)
* Una única posición inicial del jugador

### Validaciones

* Bordes abiertos o mapa no cerrado
* Caracteres inválidos
* Más de un salto de línea indicando más mapa
* Más de un jugador
* Validación de rutas de texturas y colores RGB de suelo/techo

---

## Estructura del proyecto

```
cub3D/
├─ src/           # Código fuente principal
│   ├─ main.c
│   ├─ parse/     # Funciones de parsing del archivo .cub
│   ├─ play/      # Lógica del movimiento y control del jugador
│   └─ utils/     # Funciones auxiliares generales
├─ libft/         # Librería personal (funciones C reutilizables)
├─ minilibx/      # Librería gráfica MiniLibX
├─ textures/      # Texturas usadas en el juego
├─ include/       # Headers (.h)
├─ maps/          # Mapas de ejemplo (.cub)
├─ Makefile       # Para compilar el proyecto (genera binario cub3D)
├─ README.md      # Documentación
```

---

## Decisiones técnicas y limitaciones

* **Algoritmo:** raycasting para renderizado pseudo-3D
* **Librería gráfica:** MiniLibX
* **Limitaciones:**

  * Solo Linux soportado
  * Mapas rectangulares y cerrados por muros
  * Movimiento: 4 direcciones + rotación; no hay diagonal ni físicas avanzadas
  * Validación estricta de mapas
  * Solo lo obligatorio del enunciado; no hay bonus implementados

---

## Autor

* Proyecto realizado como parte del **Common Core de 42 Madrid**
* Desarrollo en colaboración a mi compañero **[jocalder](https://github.com/jocalder)**

---

