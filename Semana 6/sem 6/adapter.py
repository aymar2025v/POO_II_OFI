# Clase original (Adaptee)
class PagoDolares:
    def pagar_dolares(self, monto):
        return "Pago realizado: " + str(monto) + " dolares"


# Adaptador (Adapter)
class AdaptadorPago:
    def __init__(self, pago):
        self.pago = pago

    def convertir_a_soles(self, monto_dolares):
        tipo_cambio = 3.70

        # Convertir dólares a soles
        monto_soles = monto_dolares * tipo_cambio

        return monto_soles


# Programa principal
pago = PagoDolares()

adaptador = AdaptadorPago(pago)

# Varias pruebas
dolar1 = 10
soles1 = adaptador.convertir_a_soles(dolar1)

dolar2 = 25
soles2 = adaptador.convertir_a_soles(dolar2)

dolar3 = 100
soles3 = adaptador.convertir_a_soles(dolar3)

print(pago.pagar_dolares(dolar1))
print("Equivale a:", soles1, "soles")
print()

print(pago.pagar_dolares(dolar2))
print("Equivale a:", soles2, "soles")
print()

print(pago.pagar_dolares(dolar3))
print("Equivale a:", soles3, "soles")
