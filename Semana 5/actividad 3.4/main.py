

class Tiempo:
    def __init__(self, hora=0, minuto=0, segundo=0):
        self._hora = hora
        self._minuto = minuto
        self._segundo = segundo

    def set_hora(self, h):
        if 0 <= h < 24:
            self._hora = h
        else:
            self._hora = 0
        return self   # Retorna self para encadenar

    def set_minuto(self, m):
        if 0 <= m < 60:
            self._minuto = m
        else:
            self._minuto = 0
        return self

    def set_segundo(self, s):
        if 0 <= s < 60:
            self._segundo = s
        else:
            self._segundo = 0
        return self

    def mostrar(self):
        print(f"{self._hora}:{self._minuto}:{self._segundo}")

# Uso
t = Tiempo()
t.set_hora(10).set_minuto(30).set_segundo(15)
t.mostrar()   # 10:30:15

# También se puede asignar el resultado (aunque es el mismo objeto)
t2 = t.set_hora(8).set_minuto(45).set_segundo(0)
t2.mostrar()   # 8:45:0
t.mostrar()    # 8:45:0 (t y t2 son el mismo objeto)
