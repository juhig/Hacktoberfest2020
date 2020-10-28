# Simple WebSocket Client
require "log"
require "http/web_socket"
Log.setup :info

ws = HTTP::WebSocket.new "127.0.0.1", "/", 8080

ws.on_message { |message| Log.info { "Server: #{message}" } }

spawn do
    loop do
        gets.try do |message|
            ws.send message
            Log.info { "Client: #{message}" }
        end
    end
end

ws.run
