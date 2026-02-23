import os
from app import create_app

config_name = os.getenv('FLASK_CONFIG') or os.getenv('FLASK_ENV') or 'default'

app = create_app(config_name)
print(f'[DEBUG] app.debug = {app.debug}')
print(f'[DEBUG] comfig.name = {config_name}')

if __name__ == '__main__':
    app.run()