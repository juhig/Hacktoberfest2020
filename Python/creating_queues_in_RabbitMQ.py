#!/usr/bin/env python
#script to create a queue if queue not exists

import pika
import sys
import os, os.path

#name of the host where the RMQ application is installed
host = "localhost"
#making connection wit the channel
connection = pika.BlockingConnection(pika.ConnectionParameters(host=host))
channel = connection.channel()

#opening file in read mode
file1=open('list_of_queues','r')

for line in file1:
	list1=line.split()
	
	exch = list1[0]
	print host + " " + exch
	q = list1[1]
	r_key=list1[2]
	#declaring exchange if not present
    channel.exchange_declare(exchange=exch, type='direct', durable=True)
    #declaring queue if not present
	channel.queue_declare(queue=q, durable=True, exclusive=False, auto_delete=False)
	#binding the queue with the routing key
	channel.queue_bind(exchange=exch,queue=q,routing_key=r_key)
	print(q+" is declared and routed with :" +r_key)
    #publishing a test message to check if the queue is created and working
	channel.basic_publish(exchange=exch, routing_key=r_key, body="test message", properties=pika.BasicProperties(content_type="text/plain",delivery_mode = 2))
#closing the file
file1.close()


