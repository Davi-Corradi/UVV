"""Extensao Flask"""

def init_app(app):
    """Inicializacao de extensoes"""
    @app.route("/")
    def index():
        return "Ola, Mundo!"
    @app.route("/contato")
    def contato():
        return "<form><input type='text'></form>"