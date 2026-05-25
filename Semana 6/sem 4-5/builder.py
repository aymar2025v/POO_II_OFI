class Combo:

    def __init__(self):
        self.hamburguesa = None
        self.bebida = None
        self.papas = None

    def mostrar_combo(self):
        print("\n=== COMBO FAST FOOD ===")
        print("Hamburguesa:", self.hamburguesa)
        print("Bebida:", self.bebida)
        print("Papas fritas:", self.papas)


class ComboBuilder:

    def __init__(self):
        self.combo = Combo()

    # Agregar hamburguesa
    def add_hamburguesa(self, hamburguesa):
        self.combo.hamburguesa = hamburguesa
        return self

    # Agregar bebida
    def add_bebida(self, bebida):
        self.combo.bebida = bebida
        return self

    # Agregar papas
    def add_papas(self, papas):
        self.combo.papas = papas
        return self

    # Construir combo final
    def build(self):
        return self.combo


# Crear combo usando Builder
combo1 = (
    ComboBuilder()
    .add_hamburguesa("Hamburguesa Doble")
    .add_bebida("Coca Cola")
    .add_papas("Papas Grandes")
    .build()
)

# Mostrar combo
combo1.mostrar_combo()
