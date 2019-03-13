import http.server, socketserver
PORT = 8000
class Handler(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        res = "Hello!"
        self.end_headers()
        self.wfile.write(res.encode())

Handler = http.server.SimpleHTTPRequestHandler

with socketserver.TCPServer(("", PORT), )
