

import gc

class Fecha:
    def __init__(self, dia=1, mes=1, anio=2000):
        self.dia = dia
        self.mes = mes
        self.anio = anio
        print(f"Constructor de Fecha: {self.dia}/{self.mes}/{self.anio}")

    def __del__(self):
        print(f"Destructor de Fecha: {self.dia}/{self.mes}/{self.anio}")

    def mostrar(self):
        print(f"{self.dia}/{self.mes}/{self.anio}", end="")


class Empleado:
    def __init__(self, nombre, fecha_nac, fecha_cont):
        self.nombre = nombre
        self.fecha_nacimiento = fecha_nac
        self.fecha_contratacion = fecha_cont
        print(f"Constructor de Empleado: {self.nombre}")

    def __del__(self):
        print(f"Destructor de Empleado: {self.nombre}")

    def mostrar(self):
        print(f"Empleado: {self.nombre}")
        print("  Fecha nacimiento: ", end="")
        self.fecha_nacimiento.mostrar()
        print()
        print("  Fecha contratacion: ", end="")
        self.fecha_contratacion.mostrar()
        print()


if __name__ == "__main__":
    nacimiento = Fecha(15, 5, 1990)
    contratacion = Fecha(1, 10, 2020)

    print("\n--- Creando empleado (sin new) ---")
    emp = Empleado("Carlos Lopez", nacimiento, contratacion)

    print("\n--- Mostrando empleado ---")
    emp.mostrar()

    print("\n--- Eliminando referencia (no obligatorio) ---")
    del emp   # Reduce el contador de referencias; el GC puede liberar en cualquier momento

    print("\n--- Forzando recolección de basura (opcional) ---")
    gc.collect()

    print("\n--- Fin del programa ---")
