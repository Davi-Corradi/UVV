from flask import current_app
from app.main import main

@main.route('/')
@main.route('/index')

def index():
    ambiente = current_app.config.get('CONFIG_NAME', "desconhecido")
    return f'Ola, mundo! Ambiente atual: {ambiente}'  