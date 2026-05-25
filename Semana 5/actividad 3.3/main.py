

class Contador:
    def __init__(self):
        self.__x = 0   # Atributo "privado" (name mangling)
    
    def mostrar(self):
        print(f"Valor de x: {self.__x}")

# Función externa que modifica __x (simulando friend)
def modificar_x(contador, nuevo_valor):
    # Python no impide el acceso; el name mangling solo cambia el nombre
    contador._Contador__x = nuevo_valor   # Acceso directo al "privado"
    
    # También se podría simplemente asignar si fuera público o protegido
    # Pero respetamos la convención de que __x es privado

if __name__ == "__main__":
    c = Contador()
    c.mostrar()           # Valor de x: 0
    
    modificar_x(c, 99)    # Simula la función friend
    
    c.mostrar()           # Valor de x: 99
    
    # También es posible hacer esto (pero no es buena práctica)
    # c._Contador__x = 50

