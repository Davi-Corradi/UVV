import views
from flask import Flask

def create_app():
    """Factory Principal"""
    app = Flask(__name__)
    views.init_app(app)
    return app


# @app.route("/")
# def index():
#     return "Ola, Mundo!"
# @app.route("/contato")
# def contato():
#     return "<form><input type='text'></form>"