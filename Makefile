build: client-socket.out server-socket.out

run-client: client-socket.out
	./client-socket.out

run-server: server-socket.out
	./server-socket.out

client-socket.out: client-socket.c
	cc -o client-socket.out client-socket.c

server-socket.out: server-socket.c
	cc -o server-socket.out server-socket.c

clean:
	rm server-socket.out client-socket.out
