"""
Docstrings 
Revisando estruturas básicas

"""
# from flask import Flask
from math import pow
# print(pow(2,4))

# idade: int =  25
# nome: str = "João"
# altura: float = 1.78
# eh_estudante: bool = True

idade, nome, altura, eh_estudante = 2, "João", 1.78, True

# def soma(a, b, c=15):
#     return a + b + c

def soma_int(a: int, b: int, c: int = 15) -> int:
    assert isinstance(a, int) and isinstance(b, int) 
    return a + b + c

print(soma_int(5, 10, 15))
if __name__ == '__main__':
    print(soma_int(5, 10))

# idade = "Maria"

def criar_usuario(**dados):
    print("Novo Usuário", dados)

my_list = [12, "Casa", 19.9, [64, 0.8, "Bolinhas"]]
my_list[2] = "CC5MB"
print(my_list[2])

my_tuple = (12, "Casa", 19.9, [64, 0.8, "Bolinhas"])
print(my_tuple[1])

dicionario = {'Key0': "Maria", 'Key1': 30, 'Key2': 1.234, 'Key3': [64, 0.8, "Bolinhas"]}
print(dicionario)

my_set = {'12', 12, 'Casa'}
my_set.add('24')
print(my_set)

class User:
    def __init__(self, name, email, idade):
        self.name = name
        self.email = email
        self.idade = idade

class MockDB:
    def add(self, obj): print(f"-> DB: {obj.name} preparado.")
    def commit(self): print("-> DB: Alterações salvas.")

db = type('DB', (), {'session': MockDB()})()

user = User(name = "Davi", email = "davi@uvv.com", idade = 20)
db.session.add(user)
db.session.commit()
print(__doc__)

