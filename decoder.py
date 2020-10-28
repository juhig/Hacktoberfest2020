import socket

mysock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
mysock.connect(('data.pr4e.org',80))
cd='GET http://data.pr4e.org/intro-short.txt HTTP/1.0\r\n\r\n'.encode()
mysock.send(cd)

while True:
    dat=mysock.recv(512)
    if len(dat)<1:
        break
    print(dat.decode())
mysock.close()
