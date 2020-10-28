# Simple WebSocket Echo Server
require "log"
require "http"
Log.setup :info

wsh = HTTP::WebSocketHandler.new do |ws, ctx|
    Log.info { "WebSocket: Client connected" }

    ws.on_message do |message|
        ws.send message
    end
    ws.on_close { Log.info { "WebSocket: Client disconnected" } }

    ws.send "Hello Client!"
end

server = HTTP::Server.new [HTTP::LogHandler.new, wsh]

Log.info { "Listening on ws://#{server.bind_tcp 8080}" }

server.listen
