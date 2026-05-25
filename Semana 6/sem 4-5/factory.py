class Transporte:
    def entregar(self):
        pass

# Transportes concretos
class Camion(Transporte):
    def entregar(self):
        return "Entrega por carretera"

class Barco(Transporte):
    def entregar(self):
        return "Entrega por mar"

class Avion(Transporte):
    def entregar(self):
        return "Entrega por aire"

class Tren(Transporte):
    def entregar(self):
        return "Entrega por vía férre"

class Moto(Transporte):
    def entregar(self):
        return "Entrega rápida en moto"

class Bicicleta(Transporte):
    def entregar(self):
        return "Entrega ecológica en bicicleta"

class Helicoptero(Transporte):
    def entregar(self):
        return "Entrega aérea especial"

class Drone(Transporte):
    def entregar(self):
        return "Entrega automática con drone"

# Factory
class Factory:

    @staticmethod
    def get_transporte(tipo):

        if tipo == "camion":
            return Camion()

        elif tipo == "barco":
            return Barco()

        elif tipo == "avion":
            return Avion()

        elif tipo == "tren":
            return Tren()

        elif tipo == "moto":
            return Moto()

        elif tipo == "bicicleta":
            return Bicicleta()

        elif tipo == "helicoptero":
            return Helicoptero()

        elif tipo == "drone":
            return Drone()

        else:
            return None

# Programa principal
print("=== SISTEMA DE TRANSPORTE ===")
print("Opciones:")
print("- camion")
print("- barco")
print("- avion")
print("- tren")
print("- moto")
print("- bicicleta")
print("- helicoptero")
print("- drone")

tipo = input("\nIngrese tipo de transporte: ")

transporte = Factory.get_transporte(tipo)

if transporte:
    print("\n" + transporte.entregar())
else:
    print("\nTipo de transporte no válido")
