from http.server import BaseHTTPRequestHandler, HTTPServer
import json

# Simulação de um "banco de dados" em memória
USERS = [{"id": 1, "name": "Alice"}, {"id": 2, "name": "Bob"}]


class RestHTTPRequestHandler(BaseHTTPRequestHandler):

    def _set_headers(self, code=200, content_type="application/json"):
        self.send_response(code)
        self.send_header("Content-Type", content_type)
        self.end_headers()

    # -------- GET --------
    def do_GET(self):
        if self.path == "/api/users":
            self._set_headers()
            self.wfile.write(json.dumps(USERS).encode())

        elif self.path.startswith("/api/users/"):
            try:
                user_id = int(self.path.split("/")[-1])
                user = next((u for u in USERS if u["id"] == user_id), None)

                if user:
                    self._set_headers()
                    self.wfile.write(json.dumps(user).encode())
                else:
                    self._set_headers(404)
                    self.wfile.write(json.dumps({"error": "User not found"}).encode())

            except ValueError:
                self._set_headers(400)
                self.wfile.write(json.dumps({"error": "Invalid user ID"}).encode())

        else:
            self._set_headers(404)
            self.wfile.write(json.dumps({"error": "Route not found"}).encode())

    # -------- POST --------
    def do_POST(self):
        if self.path == "/api/users":
            content_length = int(self.headers["Content-Length"])
            post_data = self.rfile.read(content_length)

            try:
                new_user = json.loads(post_data)
                new_user["id"] = max(u["id"] for u in USERS) + 1 if USERS else 1
                USERS.append(new_user)

                self._set_headers(201)
                self.wfile.write(json.dumps(new_user).encode())

            except json.JSONDecodeError:
                self._set_headers(400)
                self.wfile.write(json.dumps({"error": "Invalid JSON"}).encode())

        else:
            self._set_headers(404)
            self.wfile.write(json.dumps({"error": "Route not found"}).encode())

    # -------- DELETE --------
    def do_DELETE(self):
        if self.path.startswith("/api/users/"):
            try:
                user_id = int(self.path.split("/")[-1])
                global USERS
                USERS = [u for u in USERS if u["id"] != user_id]

                self._set_headers(204)

            except ValueError:
                self._set_headers(400)
                self.wfile.write(json.dumps({"error": "Invalid user ID"}).encode())

        else:
            self._set_headers(404)
            self.wfile.write(json.dumps({"error": "Route not found"}).encode())


# -------- RUN SERVER --------
def run(server_class=HTTPServer, handler_class=RestHTTPRequestHandler, port=3001):
    server_address = ("", port)
    httpd = server_class(server_address, handler_class)
    print(f"Servidor REST rodando na porta {port}")
    httpd.serve_forever()


if __name__ == "__main__":
    run()
