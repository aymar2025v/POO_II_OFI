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
        # La composición: asignamos los objetos recibidos (ojo: compartir referencia)
        # Para evitar compartir, podríamos copiar. Pero aquí mostramos la composición directa.
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

    print("\n--- Creando empleado ---")
    emp = Empleado("Ana Garcia", nacimiento, contratacion)

    print("\n--- Mostrando datos ---")
    emp.mostrar()

    print("\n--- Fin del programa (se destruirán objetos) ---")
    # Al salir, el recolector de basura destruirá los objetos

