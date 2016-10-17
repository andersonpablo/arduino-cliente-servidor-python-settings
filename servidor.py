#!/usr/bin/python

import socket

UDP_IP = "10.7.12.246" # IP do meu servidor
UDP_PORT = 5000 # Aqui devo usar a mesma porta que coloquei no Arduino
SIZE_PACKET=4 # Tamanho da string que o Arduino ira enviar

sock = socket.socket(socket.AF_INET, # Internet
socket.SOCK_DGRAM) # DGRAM é para UDP e para TCP seria SOCK_STREAM
sock.bind((UDP_IP, UDP_PORT)) # Chamo o bind para associar a porta ao IP no meu sock

print ('Iniciando UDP Server Arduino...')
print ('IP: '+str(UDP_IP))
print ('Porta: '+str(UDP_PORT))

while True:
	data, addr = sock.recvfrom(SIZE_PACKET)
"""
Recebo o pacote de dados "copa2014" 8 bytes
e o endereço
"""
print ("")
print ("IP Arduino Remoto:", addr[0])
print ("Mensagem recebida:", data)

if len(data) == SIZE_PACKET:
	print ("Pacote recebido!")
else:
	print ("Falha ao receber pacote!")