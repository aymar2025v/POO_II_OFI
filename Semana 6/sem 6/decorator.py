# Decorator
def validar(func):

    def envoltura(a, b):

        # Validación extra
        if b == 0:
            print("Error: no se puede dividir entre cero")
            return

        if a < 0 or b < 0:
            print("Error: no se permiten numeros negativos")
            return

        # Ejecutar función original
        return func(a, b)

    return envoltura


# Función matemática
@validar
def dividir(a, b):
    return a / b


# Pruebas
print(dividir(10, 2))
print()

print(dividir(8, 0))
print()

print(dividir(-5, 2))
print()

print(dividir(20, 4))
