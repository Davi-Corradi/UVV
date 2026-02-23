from flask import Flask

def create_app(config_name = 'development'):
    app = Flask(__name__)

    app.config.from_object('config.DevelopmentConfig')

    app.debug = app.config.get('DEBUG', False)

    from app.main import main as main_blueprint
    app.register_blueprint(main_blueprint)
    
    return app