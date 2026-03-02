from flask import Flask
from sqlalchemy import db

app = Flask(__name__)

# Dic
my_dic = {'KEY_1': 45, 'KEY_2': "Delivery", 'KEY_3': [34, 'casa', [1,2]]}
print(my_dic)

# Fase de configuração
app.config['FOO'] = 'bar'
app.config['NAME_APP'] = 'delivery'
app.config['BOLINHAS'] = 'minhas bolinhas'

# Registro de rotas

app.route('/')
app.add_url_rule('/', endpoint='index') # Corrigido args[] para um parâmetro válido

# Registro dos blueprints

app.register_blueprint('name_blueprint') # Blueprint serve para gerenciar as rotas

# Registro dos métodos de autenticação
# admin = Admin(app)

admin.init_app(app)
db.init_app(app)

# Registro de hooks

@app.before_request
def before():
    pass

@app.errorhandler(404)
def not_found(error):
    return 'Não encontrado', 404


# Registro de Factories secundárias

views.init_app(app)
extension.init_app(app)

## Contexto de aplicação

current_app
g 

# Criar uma extensão
from flask import current_app

def exemplo():
    valor = current_app.config['FOO']
    return valor

## Contexto de request

# Verificar os cabeçalhos HTTP

# Parâmetros URL

# Validar os dados de formulários

# Sessões (db, cliente)

# Objeto request


from flask import request

@app.route('/')
def hello():
    name = request.args.get("nome")
    return f'Olá {name}' 