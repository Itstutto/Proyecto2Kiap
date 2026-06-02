# Notas del Proyecto 2

## Diseño de Clases

```text
Personaje
├── PersonajePrincipal
└── Enemigo (categorías 1, 2 y 3)
```

- Dependiendo del género, se puede utilizar el patrón **Singleton** (pendiente de analizar).
- Implementar la mecánica de hacer enojar al oponente.
- Avisar cuando se utilicen objetos; esto incrementa el daño causado.
- Crear un **Factory** para generar los tipos de movimiento.
- Dependiendo de la zona de impacto, la potencia de los golpes se verá afectada.
- **Extremidad** y **Zona de Impacto** utilizarán los mismos datos.

## Singleton

- Debe contener las zonas superiores e inferiores.
- Utilizar archivos de configuración con las zonas.
- Cargar estos datos al inicio de la simulación.

## Decorador

- Equipamiento de protecciones.
- Objetos para daño o rendimiento.
  - También puede resolverse mediante **templates** o **polimorfismo**.

---

# Pendientes para el Martes 7

- Crear la clase `Enemigo` y asegurar su instancia.
- Revisar patrones de diseño y consultar cuáles podrían utilizarse.
