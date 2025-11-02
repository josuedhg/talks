---
author: Josue David Hernandez Gutierrez | linuxcabal
paging: ""
---
# Patrones de Diseño en C

> Soluciones comunes para problemas recurrentes en el desarrollo de software.

```
~~~tiv linuxcabal.jpg -h 100
-
~~~
```

---

## Contenidos

1. Homogeneizando ideas
2. Patrones creacionales
3. Patrones estructurales

---

## Homogeneizando ideas

- Programar en C

---

## Homogeneizando ideas

- Programar en C
    - es dificil?
---

## Homogeneizando ideas

- Programar en C
    - es dificil?
    - es peligroso?

---

## Homogeneizando ideas

- Programar en C
    - es dificil?
    - es peligroso?
- Patrones de diseño

---

## Patrones creacionales

- Object Pattern
- Factory Pattern
- Opaque Pattern
- Singleton Pattern

---

## Patrones estructurales

- Inheritance Pattern
- Callback Pattern
- Virtual Function Table Pattern

---

## Referencias

- 21st Century C: C tips for the new school (Chapter 11) - Ben Klemens
- Udemy: Embedded C Progamming Design Patterns - Martin Schröder
- Example of cpu device Obfuscated struct in linux kernel - https://elixir.bootlin.com/linux/v6.18-rc3/source/include/linux/cpu.h#L23
- Example of vitual function table (file_operations) in linux kernel
    - https://elixir.bootlin.com/linux/v6.18-rc3/source/include/linux/fs.h#L2268
    - https://elixir.bootlin.com/linux/v6.18-rc3/source/include/linux/fs.h#L2268
- container_of declaration in linux kerner - https://elixir.bootlin.com/linux/v6.18-rc3/source/include/linux/container_of.h#L19
- Usage of container_of in linux kernel - https://elixir.bootlin.com/linux/v6.18-rc3/A/ident/container_of
- Other project using this patterns
    - https://github.com/htop-dev/htop
    - https://github.com/josuedhg/todo
