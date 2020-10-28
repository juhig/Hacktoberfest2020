import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import sys
import time

print (sys.argv[1:])
email = ' '
password = ' '

send_to_email = input("Address:")
send_num = int(sys.argv[len(sys.argv)-1])

#send_to_email = []
#for i in range(len(sys.argv)-2):
#    send_to_email.append(sys.argv[i + 1])
#print (*send_to_email, sep = ", ")
#sys.stdout = send_email = print (*send_to_email, sep = ", ")
#>>> ','.join(map(str,send_to_email))
#print ("how many  " + str(send_num))
#print ("send email  " + str(send_to_email))
subject = input("Subject: ") 
message = input("Message: ")

startTime = time.time()

#sys.exit()
msg = MIMEMultipart()
msg['From'] = email
msg['To'] = send_to_email
msg['Subject'] = subject

msg.attach(MIMEText(message, 'plain'))

counter = 0

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(email, password)
text = msg.as_string() 

while True: 
    counter += 1
    server.sendmail(email, send_to_email, text)
    if counter == send_num: 
        break
server.quit()
print ('Done! Emailed in {0} seconds!'.format(round((time.time() - startTime), 2)))
print(send_to_email)
